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

#ifndef SRC_PATHS_PATHS_H_
#define SRC_PATHS_PATHS_H_

#include <string>

#include "src/paths/filesystem.h"

using namespace std;  // NOLINT

const char RIMP_DIRECTORY_NAME[] = "rimp";
const char RIMP_DATA_FILE_NAME[] = "tags.yml";
const char RIMP_CONFIG_FILE_NAME[] = "settings.yml";
const char MAC_DATA_DIR_SUFFIX[] = "Library";
const char MAC_CONFIG_DIR_SUFFIX[] = "Library/Preferences";

class Paths {
 public:
    Paths() = default;
    // OS-Dependent functions.
    static filesystem::path getUserHomeDir();
    static filesystem::path getUserDataDir();
    static filesystem::path getUserConfigDir();

    // OS-Independent functions.
    static filesystem::path getRimpDataDir();
    static filesystem::path getRimpConfigDir();
    static filesystem::path getUserDataFile();
    static filesystem::path getUserConfigFile();
    static bool createDir(filesystem::path path, string &error_msg);  // NOLINT
};

#endif  // SRC_PATHS_PATHS_H_
