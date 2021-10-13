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

#ifndef SRC_PARSER_FORMATTER_H_
#define SRC_PARSER_FORMATTER_H_

#include <string>

#include "external/CLI11/include/CLI/CLI.hpp"

using namespace std;  // NOLINT

class CustomFormatter : public CLI::Formatter {
 public:
    CustomFormatter() : Formatter() {}
    string make_subcommand(const CLI::App *sub) const override;
    string make_option_opts(const CLI::Option *opt) const override;
    string make_option_name(const CLI::Option *opt, bool is_positional) const override;
};

#endif  // SRC_PARSER_FORMATTER_H_
