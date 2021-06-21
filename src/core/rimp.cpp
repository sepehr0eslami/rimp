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

    string source_path;
    int returned = data_file.select(DEFAULT_TAGS_TABLE, "Path",
                                    "Tag == \"" + tag + "\"", source_path,
                                    error_msg);

    if (returned != SQLITE_OK)
        return returned;
    if (source_path.empty()) {
        error_msg =
            "The Tag \'" + tag +
            "\' doesn't exist. You can add it by running:\n"
            "\'rimp add " +
            tag +
            " [SOURCE]\'. See \'rimp --help\' for more information.";
        return EINVAL;
    }
    if (!filesystem::exists(source_path)) {
        error_msg = "No such file or directory \'" + source_path +
                    "\'. The file "
                    " or directory associated with \'" +
                    tag + "\' Tag is missing.";

        return ENOENT;
    }

    error_code code;
    filesystem::copy(filesystem::path(source_path), dest,  // NOLINT
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

    int returned = data_file.insert({"\"" + tag + "\"",
                                     "\"" + source.string() + "\""},
                                    DEFAULT_TAGS_TABLE, error_msg);

    return returned;
}
