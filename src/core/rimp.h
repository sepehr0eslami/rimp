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

#ifndef SRC_CORE_RIMP_H_
#define SRC_CORE_RIMP_H_

#include <algorithm>
#include <cerrno>
#include <string>
#include <vector>

#include "src/database/database.h"
#include "src/parser/flags.h"
#include "src/paths/paths.h"

using namespace std;  // NOLINT

const SQLTable DEFAULT_TAGS_TABLE("Mappings", {"Tag TEXT PRIMARY KEY NOT NULL",
                                               "Path TEXT NOT NULL"});

namespace rimp {
SQLDatabase setup();
int paste(string tag, filesystem::path dest, string &error_msg);           // NOLINT
int add(string tag, filesystem::path source, string &error_msg);           // NOLINT
int edit(string tag, filesystem::path new_source, string &error_msg);      // NOLINT
int remove(string tag, int flags, string &error_msg);                      // NOLINT
int list(ostream &out, int flags, string &error_msg, string format = "");  //NOLINT
}  // namespace rimp

#endif  // SRC_CORE_RIMP_H_
