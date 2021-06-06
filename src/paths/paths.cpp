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

// clang-format off
#include "src/paths/includes.h"

#include "src/paths/paths.h"

#include "src/paths/filesystem.h"
// clang-format on

/* ------------------------------------------------------------------------- */
/*                          OS-Dependent functions                           */
/* ------------------------------------------------------------------------- */

/* ------------------------- Windows Implementation ------------------------- */
#if defined(_WIN32)
filesystem::path Paths::getUserHomeDir() {
    // Use Windows API to get User's Home folder path.
    wchar_t *home_path = nullptr;
    auto result = SHGetKnownFolderPath(FOLDERID_Profile,
                                       KF_FLAG_CREATE,
                                       nullptr,
                                       &home_path);

    if (result == E_FAIL) {
        throw runtime_error{
            __FILE__
            ":\n"
            "Error getting your Profile directory path(SHGetKnownFolderPath): "
            "Directory seems to be Virtual hence not accesible for Rimp."
            "Please file a bug report at:\n"
            "https://github.com/sepehr0eslami/Rimp/issues\n"};

    } else if (result == E_INVALIDARG) {
        throw runtime_error{
            __FILE__
            ":\n"
            "Error getting your Profile directory path(SHGetKnownFolderPath): "
            "Directory doesn't exist and Rimp was unable to create it. Run "
            "Rimp as Administrator to automatically create the directory.\n"
            "If the issue didn't resolve, Please file a bug report at:\n"
            "https://github.com/sepehr0eslami/Rimp/issues\n"};
    }

    filesystem::path path(home_path);
    CoTaskMemFree(home_path);
    return path;
}

filesystem::path Paths::getUserCacheDir() {
    // Use Windows API to get LocalAppData folder path.
    wchar_t *cache_path = nullptr;
    auto result = SHGetKnownFolderPath(FOLDERID_LocalAppData,
                                       KF_FLAG_CREATE,
                                       nullptr,
                                       &cache_path);

    if (result == E_FAIL) {
        throw runtime_error{
            __FILE__
            ":\n"
            "Error getting your LocalAppData directory path"
            "(SHGetKnownFolderPath): "
            "Directory seems to be Virtual hence not accesible for Rimp."
            "Please file a bug report at:\n"
            "https://github.com/sepehr0eslami/Rimp/issues\n"};

    } else if (result == E_INVALIDARG) {
        throw runtime_error{
            __FILE__
            ":\n"
            "Error getting your LocalAppData directory path"
            "(SHGetKnownFolderPath): "
            "Directory doesn't exist and Rimp was unable to create it. Run "
            "Rimp as Administrator to automatically create the directory.\n"
            "If the issue didn't resolve, Please file a bug report at:\n"
            "https://github.com/sepehr0eslami/Rimp/issues\n"};
    }

    filesystem::path path(cache_path);
    CoTaskMemFree(cache_path);
    return path;
}

filesystem::path Paths::getUserConfigDir() {
    // Use Windows API to get RoamingAppData folder path.
    wchar_t *config_path = nullptr;
    auto result = SHGetKnownFolderPath(FOLDERID_RoamingAppData,
                                       KF_FLAG_CREATE,
                                       nullptr,
                                       &config_path);

    if (result == E_FAIL) {
        throw runtime_error{
            __FILE__
            ":\n"
            "Error getting your RoamingAppData directory path"
            "(SHGetKnownFolderPath): "
            "Directory seems to be Virtual hence not accesible for Rimp."
            "Please file a bug report at:\n"
            "https://github.com/sepehr0eslami/Rimp/issues\n"};

    } else if (result == E_INVALIDARG) {
        throw runtime_error{
            __FILE__
            ":\n"
            "Error getting your RoamingAppData directory path"
            "(SHGetKnownFolderPath): "
            "Directory doesn't exist and Rimp was unable to create it. Run "
            "Rimp as Administrator to automatically create the directory.\n"
            "If the issue didn't resolve, Please file a bug report at:\n"
            "https://github.com/sepehr0eslami/Rimp/issues\n"};
    }

    filesystem::path path(config_path);
    CoTaskMemFree(config_path);
    return path;
}

/* -------------------------- MacOS Implementation -------------------------- */
#elif defined(__APPLE__) || defined(__MACH__)

filesystem::path Paths::getUserHomeDir() {
    // Check $HOME environment variable first.
    const char *home_env = getenv("HOME");
    if (home_env != nullptr) {
        return filesystem::path(home_env);
    }

    // If $HOME wasn't set, fallback to getpwuid.
    const struct passwd *user_info = getpwuid(getuid());  // NOLINT
    if (user_info == nullptr) {
        throw runtime_error{
            __FILE__
            ":\n"
            "Error getting your home directory path (getpwuid).\n"
            "Please file a bug report at:\n"
            "https://github.com/sepehr0eslami/Rimp/issues\n"};
    }

    home_env = user_info->pw_dir;
    if (home_env == nullptr) {
        throw runtime_error{
            __FILE__
            ":\n"
            "Error getting your home directory path (pw_dir).\n"
            "Please file a bug report at\n"
            "https://github.com/sepehr0eslami/Rimp/issues\n"};
    }

    return filesystem::path(home_env);
}

filesystem::path Paths::getUserCacheDir() {
    filesystem::path user_cache_dir = Paths::getUserHomeDir();
    return user_cache_dir.append(MAC_CACHE_DIR_SUFFIX);
}

filesystem::path Paths::getUserConfigDir() {
    filesystem::path user_config_dir = Paths::getUserHomeDir();
    return user_config_dir.append(MAC_CONFIG_DIR_SUFFIX);
}

/* -------------------------- Linux Implementation -------------------------- */
#elif defined(__unix__)

filesystem::path Paths::getUserHomeDir() {
    // Check $HOME environment variable first.
    const char *home_env = getenv("HOME");
    if (home_env != nullptr) {
        return filesystem::path(home_env);
    }

    // If $HOME wasn't set, fallback to getpwuid.
    const struct passwd *user_info = getpwuid(getuid());  // NOLINT
    if (user_info == nullptr) {
        throw runtime_error{
            __FILE__
            ":\n"
            "Error getting your home directory path (getpwuid).\n"
            "Please file a bug report at:\n"
            "https://github.com/sepehr0eslami/Rimp/issues\n"};
    }

    home_env = user_info->pw_dir;
    if (home_env == nullptr) {
        throw runtime_error{
            __FILE__
            ":\n"
            "Error getting your home directory path (pw_dir).\n"
            "Please file a bug report at\n"
            "https://github.com/sepehr0eslami/Rimp/issues\n"};
    }

    return filesystem::path(home_env);
}

filesystem::path Paths::getUserCacheDir() {
    // Check XDG_CACHE_HOME environment variable first.
    // https://wiki.archlinux.org/title/XDG_Base_Directory
    const char *xdg_cache_home_env = getenv("XDG_CACHE_HOME");
    if (xdg_cache_home_env != nullptr) {
        return filesystem::path(xdg_cache_home_env);
    }

    // If XDG_CACHE_HOME wasn't set, fallback to $HOME/.cache.
    filesystem::path user_cache_dir = Paths::getUserHomeDir();
    return user_cache_dir.append(".cache");
}

filesystem::path Paths::getUserConfigDir() {
    // Check XDG_CONFIG_HOME environment variable first.
    // https://wiki.archlinux.org/title/XDG_Base_Directory
    const char *xdg_config_home_env = getenv("XDG_CONFIG_HOME");
    if (xdg_config_home_env != nullptr) {
        return filesystem::path(xdg_config_home_env);
    }

    // If XDG_CONFIG_HOME wasn't set, fallback to $HOME/.config.
    filesystem::path user_config_dir = Paths::getUserHomeDir();
    return user_config_dir.append(".config");
}

#endif

/* -------------------------------------------------------------------------- */
/*                          OS-Independet functions                           */
/* -------------------------------------------------------------------------- */

filesystem::path Paths::getRimpCacheDir() {
    filesystem::path rimp_cache_dir = Paths::getUserCacheDir();
    return rimp_cache_dir.append(RIMP_DIRECTORY_NAME);
}

filesystem::path Paths::getRimpConfigDir() {
    filesystem::path rimp_config_dir = Paths::getUserConfigDir();
    return rimp_config_dir.append(RIMP_DIRECTORY_NAME);
}

filesystem::path Paths::getUserCacheFile() {
    filesystem::path user_cache_file = Paths::getRimpCacheDir();
    return user_cache_file.append(RIMP_CACHE_FILE_NAME);
}

filesystem::path Paths::getUserConfigFile() {
    filesystem::path user_config_file = Paths::getRimpConfigDir();
    return user_config_file.append(RIMP_CONFIG_FILE_NAME);
}
