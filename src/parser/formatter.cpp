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

#include "src/parser/formatter.h"

#include "src/parser/args_parser.h"

string CustomFormatter::make_subcommand(const CLI::App *sub) const {
    stringstream out;
    string final_name = sub->get_name();
    final_name.append(" ");

    // Storing the options vector.
    auto positionals = sub->get_options({});

    for (auto positional : positionals) {
        if (positional->get_name(true).empty())
            continue;
        string current_positional = positional->get_name(true);
        if (!positional->get_required()) {
            current_positional.insert(0, "[");
            current_positional.append("]");
        }
        current_positional.append(" ");
        final_name.append(current_positional);
    }

    CLI::detail::format_help(out, final_name, sub->get_description(),
                             column_width_);

    return out.str();
}
