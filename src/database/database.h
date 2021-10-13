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

#ifndef SRC_DATABASE_DATABASE_H_
#define SRC_DATABASE_DATABASE_H_

#include <sqlite3.h>

#include <string>
#include <vector>

#include "src/database/table.h"
#include "src/paths/filesystem.h"

using namespace std;  // NOLINT

typedef vector<vector<string>> Records;

int getRecords(void *result, int argc, char **argv, char **columns_name);
int getRecordsNoHeader(void *result, int argc, char **argv, char **columns_name);

class SQLDatabase {
 public:
    explicit SQLDatabase(filesystem::path database_file);
    ~SQLDatabase();

    filesystem::path getDatabaseFile() const;
    sqlite3 *getSqliteObject() const;
    int createTable(SQLTable table, string &error_msg);                                                 // NOLINT
    int insert(vector<string> values, SQLTable target_table, string &error_msg);                        // NOLINT
    int update(vector<string> new_values, string condition, SQLTable target_table, string &error_msg);  // NOLINT
    int deleteRecord(SQLTable target_table, string condition, string &error_msg);                       // NOLINT
    int select(SQLTable target_table, Records &result, string &error_msg, string column = "*",          // NOLINT
               string condition = "", bool header = true);
    bool exists(SQLTable target_table, string tag, string &error_msg);  // NOLINT

 private:
    filesystem::path database_file_;
    sqlite3 *sqlite_object_;
};

#endif  // SRC_DATABASE_DATABASE_H_
