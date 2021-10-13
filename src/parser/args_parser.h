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

#ifndef SRC_PARSER_ARGS_PARSER_H_
#define SRC_PARSER_ARGS_PARSER_H_

#include <string>

#include "external/CLI11/include/CLI/CLI.hpp"
#include "src/parser/flags.h"

using namespace std;

class ArgsParser {
 public:
    ArgsParser(int argc, char **argv);
    ~ArgsParser();
    string version_;
    string rimp_header_;
    string rimp_footer_;
    string given_tag_ = "";
    string given_dest_ = "";
    string given_source_ = "";
    string given_subcmd_ = "";
    string given_format_ = "";
    string given_col_sep_ = "  ";
    string given_row_sep_ = "\n";
    int given_flags_ = 0;
    int returned_ = 0;

 private:
    CLI::App *main_app_;
    CLI::App *paste_app_;
    CLI::App *add_app_;
    CLI::App *edit_app_;
    CLI::App *remove_app_;
    CLI::App *list_app_;
};

#endif  // SRC_PARSER_ARGS_PARSER_H_
