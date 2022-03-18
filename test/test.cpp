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
#include <iostream>
#include <map>
#include <vector>

#include <case-convert/convert.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Converting different cases", "[case_conversion]") {
    std::map<std::string, std::vector<std::string>> test_data = {
        {"this/is an example...", {"thisIsAnExample", "ThisIsAnExample", "this-is-an-example", "this_is_an_example","THIS_IS_AN_EXAMPLE"}}
    };

    for(std::map<std::string, std::vector<std::string>>::iterator it = test_data.begin(); it != test_data.end(); it++) {
        case_convert::identifier_t strid = case_convert::identifier(it->first);

        REQUIRE(it->second.size() == 5);

        REQUIRE(it->second.at(0) == case_convert::camel(strid));
        REQUIRE(it->second.at(1) == case_convert::pascal(strid));
        REQUIRE(it->second.at(2) == case_convert::kebap(strid));
        REQUIRE(it->second.at(3) == case_convert::snake(strid));
        REQUIRE(it->second.at(4) == case_convert::macro(strid));
    }
}
