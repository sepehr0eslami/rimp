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

#include "src/database/database.h"

int select_callback(void *result, int argc, char **argv, char **columns_name) {
    for (int i = 0; i < argc; i++) {
        string str = argv[i];
        *reinterpret_cast<string *>(result) = str;
    }
    return 0;
}

SQLDatabase::SQLDatabase(filesystem::path database_path)
    : database_file_(database_path) {
    int returned = 0;
    returned = sqlite3_open(database_file_.c_str(), &sqlite_object_);
    if (returned) {
        string error_msg = sqlite3_errmsg(sqlite_object_);
        error_msg.append(": " + database_file_.string() + "\n");
        error_msg.append(
            "Please make sure the file and Its parent directory are accessible "
            "for you(You have Read/Write access to both); and if the issue "
            "didn't resolve, Please file a bug report at:\n"
            "https://github.com/sepehr0eslami/rimp/issues\n");
        throw runtime_error{error_msg};
    }
}

SQLDatabase::~SQLDatabase() {
    sqlite3_close(sqlite_object_);
}

filesystem::path SQLDatabase::getDatabaseFile() const {
    return database_file_;
}

sqlite3 *SQLDatabase::getSqliteObject() const {
    return sqlite_object_;
}

int SQLDatabase::createTable(SQLTable table, string &error_msg) {
    int returned = 0;
    char *error_char = nullptr;
    returned = sqlite3_exec(sqlite_object_, table.getSchema().c_str(), nullptr,
                            nullptr, &error_char);

    if (error_char != nullptr)
        error_msg = error_char;
    sqlite3_free(error_char);
    return returned;
}

int SQLDatabase::insert(vector<string> values, SQLTable target_table, string &error_msg) {  // NOLINT
    string query = "INSERT INTO " + target_table.getName() + " VALUES(";
    for (int i = 0; i < values.size(); i++) {
        query.append(values[i]);
        query.append((i < values.size() - 1) ? ", " : ");");
    }

    int returned = 0;
    char *error_char = nullptr;
    returned = sqlite3_exec(sqlite_object_, query.c_str(), nullptr, nullptr,
                            &error_char);

    if (error_char != nullptr)
        error_msg = error_char;
    sqlite3_free(error_char);
    return returned;
}

int SQLDatabase::update(vector<string> new_values, string condition,
                        SQLTable target_table, string &error_msg) {
    string query = "UPDATE " + target_table.getName() + " SET ";
    for (int i = 0; i < new_values.size(); i++) {
        query.append(new_values[i]);
        query.append((i < new_values.size() - 1) ? ", " : " ");
    }
    query.append("WHERE " + condition + ";");

    int returned = 0;
    char *error_char = nullptr;
    returned = sqlite3_exec(sqlite_object_, query.c_str(), nullptr, nullptr,
                            &error_char);

    if (error_char != nullptr)
        error_msg = error_char;
    sqlite3_free(error_char);
    return returned;
}

int SQLDatabase::deleteRecord(SQLTable target_table, string condition,
                              string &error_msg) {
    string query = "DELETE FROM " + target_table.getName() +
                   " WHERE " + condition + ";";

    int returned = 0;
    char *error_char = nullptr;
    returned = sqlite3_exec(sqlite_object_, query.c_str(), nullptr, nullptr,
                            &error_char);

    if (error_char != nullptr)
        error_msg = error_char;
    sqlite3_free(error_char);
    return returned;
}

int SQLDatabase::select(SQLTable target_table, string column, string condition,
                        string &result, string &error_msg) {
    string query = "SELECT " + column + " FROM " + target_table.getName() +
                   " WHERE " + condition;

    int returned = 0;
    char *error_char = nullptr;
    returned = sqlite3_exec(sqlite_object_, query.c_str(), select_callback,
                            &result, &error_char);

    if (error_char != nullptr)
        error_msg = error_char;
    sqlite3_free(error_char);
    return returned;
}
