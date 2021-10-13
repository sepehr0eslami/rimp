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

#include <iostream>
#include <string>

#include "src/core/rimp.h"
#include "src/parser/args_parser.h"

using namespace std;

int main(int argc, char **argv) {
    string errors;
    int ret = 0;

    try {
        ArgsParser parser(argc, argv);
        if (parser.returned_ != 0) {
            return parser.returned_;
        }

        if (parser.given_subcmd_ == "paste") {
            ret = rimp::paste(parser.given_tag_, filesystem::path(parser.given_dest_), errors);
        } else if (parser.given_subcmd_ == "add") {
            ret = rimp::add(parser.given_tag_, filesystem::path(parser.given_source_), errors);
        } else if (parser.given_subcmd_ == "edit") {
            ret = rimp::edit(parser.given_tag_, filesystem::path(parser.given_source_), errors);
        } else if (parser.given_subcmd_ == "remove") {
            ret = rimp::remove(parser.given_tag_, parser.given_flags_, errors);
        } else if (parser.given_subcmd_ == "list") {
            ret = rimp::list(cout, parser.given_flags_, errors, parser.given_format_, parser.given_col_sep_,
                             parser.given_row_sep_);
        }
    } catch (runtime_error e) {
        cerr << e.what() << "\n";
        return 134;
    }

    if (ret != 0) {
        cerr << errors << "\n";
        return ret;
    }

    return 0;
}
