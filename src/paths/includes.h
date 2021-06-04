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

#ifndef SRC_PATHS_INCLUDES_H_
#define SRC_PATHS_INCLUDES_H_

/**
 * This utility will include needed headers for each implementation of "Paths"
 * class
 */

/* -------------------------------------------------------------------------- */
/*                              Windows includes                              */
/* -------------------------------------------------------------------------- */
#if defined(_WIN32)

// clang-format off
#include <Windows.h>
#include <Knownfolders.h>
#include <Shlobj.h>
// clang-format on

/* -------------------------------------------------------------------------- */
/*                                MacOS includes                              */
/* -------------------------------------------------------------------------- */
#elif defined(__APPLE__) || defined(__MACH__)

#include <NSSystemDirectories.h>
#include <limits.h>

/* -------------------------------------------------------------------------- */
/*                               Linux includes                               */
/* -------------------------------------------------------------------------- */
#elif defined(__unix__)

#include <pwd.h>
#include <unistd.h>

#endif

#endif  // SRC_PATHS_INCLUDES_H_
