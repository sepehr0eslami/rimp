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

#ifndef SRC_DATABASE_TABLE_H_
#define SRC_DATABASE_TABLE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;  // NOLINT

enum SQLDataTypes {
    Integral,
    Text,
    Blob
};

class SQLTable {
 public:
    SQLTable(string table_name, vector<string> table_columns,
             vector<SQLDataTypes> columns_type);

    string getSchema();

 private:
    string name_;
    vector<string> columns_;
    vector<SQLDataTypes> types_;
};

#endif  // SRC_DATABASE_TABLE_H_
