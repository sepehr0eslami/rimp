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

#include "src/parser/args_parser.h"

#include <memory>

#include "build/rimp_version.h"
#include "src/parser/formatter.h"

/**
 * When constructed, Initialize all of the Descriptions, Options & Subcommands
 * and parse them to the respected variable of the object.
 * 
 * @param argc The standard arg count passed to main()
 * @param argv The standard arg array passed to main()
 */
ArgsParser::ArgsParser(int argc, char **argv) {
    /* --------------------------- Version String --------------------------- */
    version_ =
        "Rimp " RIMP_VERSION
        ".";

    /* ---------------------------- Header String --------------------------- */
    rimp_header_ =
        "Rimp(Reimplementer)\n"
        "Copyright (C) 2021 Sepehr Eslami <sepehr0eslami@gmail.com>\n\n"
        "Simple and fast File Tagger.\n"
        "Rimp is a small tool that allows you to attach tags to various files "
        "and access those files in the future using only their tags.\n\n"
        "For more information please visit:\n"
        "https://github.com/sepehr0eslami/Rimp\n";

    /* ---------------------------- Footer String --------------------------- */
    rimp_footer_ =
        "Enclosing in Square Brackets(\"[]\") means optional.\n"
        "See rimp SUBCOMMAND --help to read about a specific subcommand.";

    /* ---------------------- Main App Configurations ---------------------- */
    try {
        main_app_ = new CLI::App(rimp_header_, "rimp");
    } catch (bad_alloc e) {
        cerr << e.what() << " was catched in " << __FILE__ << "\n";
        returned_ = 112;
        return;
    }

    main_app_->set_version_flag("-v, --version", version_);
    main_app_->require_subcommand(1);
    main_app_->footer(rimp_footer_);
    auto fmt = make_shared<CustomFormatter>();
    main_app_->formatter(fmt);

    /* ---------------------- Paste App Configurations --------------------- */
    paste_app_ = main_app_->add_subcommand("paste",
                                           "Insert the file associated "
                                           "with TAG in [DEST].");
    auto paste_tag_option = paste_app_->add_option("TAG", given_tag_,
                                                   "ُThe desired Tag.");
    auto paste_dest_option = paste_app_->add_option("DEST", given_dest_,
                                                    "The path to put the file "
                                                    "associated with TAG in;\n"
                                                    "Current directory is "
                                                    "assumed when nothing is "
                                                    "given.");
    paste_tag_option->required(true);
    paste_tag_option->option_text(" ");
    paste_dest_option->option_text(" ");
    paste_app_->footer("");

    /* ----------------------- Add App Configurations ---------------------- */
    add_app_ = main_app_->add_subcommand("add",
                                         "Attach the given TAG to "
                                         "SOURCE.");
    auto add_tag_option = add_app_->add_option("TAG", given_tag_,
                                               "The desired Tag.");
    auto add_source_option = add_app_->add_option("SOURCE", given_source_,
                                                  "The path to the file which "
                                                  "TAG should attach to.");

    add_tag_option->required(true);
    add_source_option->required(true);
    add_tag_option->option_text(" ");
    add_source_option->option_text(" ");
    add_app_->footer("");

    /* ---------------------- Edit App Configurations ---------------------- */
    edit_app_ = main_app_->add_subcommand("edit",
                                          "Detach TAG from its source and "
                                          "attach it to NEW_SOURCE");
    auto edit_tag_option = edit_app_->add_option("TAG", given_tag_,
                                                 "The desired Tag");
    auto edit_source_option = edit_app_->add_option("NEW_SOURCE", given_source_,
                                                    "Path to the new file that "
                                                    "TAG should point to.");

    edit_tag_option->required(true);
    edit_source_option->required(true);
    edit_tag_option->option_text(" ");
    edit_source_option->option_text(" ");
    edit_app_->footer("");

    /* -------------------------- Parse Everything -------------------------- */
    try {
        main_app_->parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        returned_ = main_app_->exit(e);
        return;
    }

    /* ---------------------- Get the parsed Subcommand --------------------- */
    if (paste_app_->parsed() || add_app_->parsed() || edit_app_->parsed())
        given_subcmd_ = main_app_->get_subcommands().front()->get_name();
}

/**
 * Deallocate the dynamicly-allocated memory(new keyword) by "delete".
 */
ArgsParser::~ArgsParser() {
    delete main_app_;
}
