/*
 * cxx-case-convert
 * Copyright (C) 2022 Alexander Kraus <nr4@z10.info>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <string>
#include <vector>

namespace case_convert {
    using identifier_t = std::vector<std::string>;
    extern std::vector<char> grouping_characters;

    identifier_t identifier(std::string str);

    std::string camel_case(identifier_t identifier);
    std::string pascal_case(identifier_t identifier);
    std::string kebap_case(identifier_t identifier);
    std::string snake_case(identifier_t identifier);
    std::string macro_case(identifier_t identifier);

    std::string uppercase(std::string str);
    std::string lowercase(std::string str);
    std::string uppercase(char c);
    std::string lowercase(char c);
}
