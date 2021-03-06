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

#include "src/database/table.h"

SQLTable::SQLTable(string table_name, vector<string> table_columns)
    : name_(table_name), columns_(table_columns) {}

string SQLTable::getName() const {
    return name_;
}

vector<string> SQLTable::getColumns() const {
    return columns_;
}

string SQLTable::getSchema() const {
    string schema = "CREATE TABLE IF NOT EXISTS " + name_ + "(";
    for (int i = 0; i < columns_.size(); i++) {
        schema.append(columns_[i]);
        schema.append((i < columns_.size() - 1) ? ", " : ");");
    }

    return schema;
}
