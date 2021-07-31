/** 
 * Rimp(Reimplementer). Simple and fast File Tagger.
 * 
 * Copyright (C) 2021 Sepehr Eslami <sepehr0eslami@gmail.com>
 * 
 * This file is a part of Rimp.
 *
 * Rimp is free software: you can  redistribute  it  and/or modify  it under the
 * terms of  the  GNU General Public License  as  published by the Free Software
 * Foundation, either  version 3 of  the  License, or (at your option) any later
 * version.
 *
 * Rimp  is  distributed  in  the hope that  it  will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See  the GNU General Public License  for  more details.
 *
 * You should have received  a copy of the GNU General Public License along with
 * Rimp. If not, see <https://www.gnu.org/licenses/>.
 */

#include "src/core/rimp.h"

SQLDatabase rimp::setup() {
    SQLDatabase data_file(Paths::getUserDataFile());
    string error;
    int returned = data_file.createTable(DEFAULT_TAGS_TABLE, error);

    if (returned != SQLITE_OK)
        throw runtime_error{error};

    return data_file;
}

int rimp::paste(string tag, filesystem::path dest, string &error_msg) {
    if (tag.empty()) {
        error_msg = "Please enter a non-empty Tag.";
        return EINVAL;
    }
    if (dest.empty()) {
        // If the Destination was empty, current directory is assumed.
        dest.assign(filesystem::current_path());
    }
    if (!filesystem::exists(dest)) {
        error_msg =
            "The destination directory doesn't exist. "
            "Try creating it yourself or enter an existing one.";
        return ENOENT;
    }
    if (!filesystem::is_directory(dest)) {
        error_msg =
            "The given destination is invalid. Please enter a path to an "
            "existing directory.";
        return ENOTDIR;
    }

    auto data_file = rimp::setup();

    if (!data_file.exists(DEFAULT_TAGS_TABLE, tag, error_msg)) {
        error_msg =
            "The Tag \'" + tag +
            "\' doesn't exist. You can add it by running:\n"
            "\'rimp add " +
            tag +
            " [SOURCE]\'. See \'rimp --help\' for more information.";
        return EINVAL;
    }
    Records source_path;
    data_file.select(DEFAULT_TAGS_TABLE, source_path, error_msg, "Path",
                     "Tag == \"" + tag + "\"");

    if (!filesystem::exists(source_path[1].front())) {
        error_msg = "No such file or directory \'" + source_path[1].front() +
                    "\'. The file "
                    " or directory associated with \'" +
                    tag + "\' Tag is missing.";

        return ENOENT;
    }

    error_code code;
    filesystem::copy(filesystem::path(source_path[1].front()), dest,  // NOLINT
                     filesystem::copy_options::recursive, code);
    error_msg = code.message();
    return code.value();
}

int rimp::add(string tag, filesystem::path source, string &error_msg) {
    if (tag.empty()) {
        error_msg = "Please enter a non-empty Tag.";
        return EINVAL;
    }
    if (source.empty()) {
        error_msg =
            "The given source is empty. Please enter a valid source "
            "file/directory.";
        return EINVAL;
    }
    if (!filesystem::exists(source)) {
        error_msg = "No such file or directory \'" + source.string() +
                    "\'. "
                    "Please enter a path to an existing file or directory.";
        return ENOENT;
    }

    auto data_file = rimp::setup();

    auto abs_path = filesystem::absolute(source);
    int returned = data_file.insert({"\"" + tag + "\"",
                                     "\"" + abs_path.string() + "\""},
                                    DEFAULT_TAGS_TABLE, error_msg);

    return returned;
}

int rimp::edit(string tag, filesystem::path new_source, string &error_msg) {
    if (tag.empty()) {
        error_msg = "Please enter a non-empty Tag.";
        return EINVAL;
    }
    if (new_source.empty()) {
        error_msg =
            "The given source is empty. Please enter a valid source "
            "file/directory.";
        return EINVAL;
    }
    if (!filesystem::exists(new_source)) {
        error_msg = "No such file or directory \'" + new_source.string() +
                    "\'. "
                    "Please enter a path to an existing file or directory.";
        return ENOENT;
    }

    auto data_file = rimp::setup();

    if (!data_file.exists(DEFAULT_TAGS_TABLE, tag, error_msg)) {
        error_msg = "The Tag \'" + tag +
                    "\' doesn't exist. Please enter an "
                    "existing tag.";
        return EINVAL;
    }

    auto abs_path = filesystem::absolute(new_source);
    int returned = data_file.update({"Tag = \"" + tag + "\"",
                                     "Path = \"" + abs_path.string() + "\""},
                                    "Tag == \"" + tag + "\"",
                                    DEFAULT_TAGS_TABLE, error_msg);

    return returned;
}

int rimp::remove(string tag, int flags, string &error_msg) {
    if (tag.empty()) {
        error_msg = "Please enter a non-empty Tag.";
        return EINVAL;
    }

    auto data_file = rimp::setup();

    if (!data_file.exists(DEFAULT_TAGS_TABLE, tag, error_msg)) {
        error_msg = "The Tag \'" + tag +
                    "\' doesn't exist. Please enter an "
                    "existing tag.";
        return EINVAL;
    }
    Records source;
    data_file.select(DEFAULT_TAGS_TABLE, source, error_msg,
                     "Path", "Tag == \"" + tag + "\"");

    if ((flags & REMOVE_FORCE_FLAG) == REMOVE_FORCE_FLAG) {
        error_code issue;
        filesystem::remove_all(filesystem::path(source[1].front()), issue);
        if (issue.value()) {
            error_msg = issue.message();
            return issue.value();
        }
    }

    int returned = data_file.deleteRecord(DEFAULT_TAGS_TABLE,
                                          "Tag == \"" + tag + "\"", error_msg);

    return returned;
}

int rimp::list(ostream &out, string &error_msg) {
    auto data_file = rimp::setup();

    Records records;
    int returned = data_file.select(DEFAULT_TAGS_TABLE, records, error_msg);

    if (returned != SQLITE_OK) {
        return returned;
    } else if (records.empty()) {
        out << "No tag is available!"
            << "\n";
        return 0;
    }

    string col_sep = "  ", row_sep = "\n";
    char main_sep = '-';

    vector<int> lengths;
    int total_length = (records.front().size() - 1) * col_sep.size();
    for (int i = 0; i < records.front().size(); i++) {
        int tmp = 0;
        for (int j = 0; j < records.size(); j++) {
            tmp = max(tmp, static_cast<int>(records[j][i].size()));
        }
        lengths.push_back(tmp);
        total_length += tmp;
    }

    // Printing the Top border.
    out << string(total_length, main_sep) << "\n";
    // Printing the Header.
    for (int i = 0; i < records.front().size(); i++) {
        out << setfill(' ') << setw(lengths[i]) << left << records.front()[i]
            << col_sep;
    }
    cout << "\n";
    // Printing Header seperator.
    for (int k = 0; k < records.front().size(); k++) {
        out << string(lengths[k], main_sep) << col_sep;
    }
    cout << "\n";
    // Printing the Records.
    for (int i = 1; i < records.size(); i++) {
        for (int j = 0; j < records[i].size(); j++) {
            out << setfill(' ') << setw(lengths[j]) << left << records[i][j]
                << col_sep;
        }
        out << row_sep;
    }
    // Printing the Bottom border.
    out << string(total_length, main_sep) << "\n";

    return returned;
}
