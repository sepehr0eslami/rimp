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

#ifndef SRC_PATHS_FILESYSTEM_H_
#define SRC_PATHS_FILESYSTEM_H_

/**
 * This utility will include the proper header for std::filesystem library,
 * which is in some compilers <filesystem> and <experimental/filesystem> in
 * others. If  <experimental/filesystem>  was  included, It  will  use  the
 * std::filesystem namespace instead  of  std::experimental::filesystem  to
 * avoid complications.
 */

#if __has_include(<filesystem>)

#include <filesystem>

#else

#include <experimental/filesystem>
namespace std {
namespace filesystem = experimental::filesystem;
}

#endif

#endif  // SRC_PATHS_FILESYSTEM_H_
