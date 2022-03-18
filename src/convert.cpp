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

#include <case-convert/convert.hpp>

#include <algorithm>
#include <sstream>

case_convert::identifier_t case_convert::identifier(std::string str) {
    for(int i=0; i<case_convert::grouping_characters.size(); ++i)
    {
        std::replace(str.begin(), str.end(), case_convert::grouping_characters.at(i), ' ');
    }

    case_convert::identifier_t result;
    std::istringstream sstream(str);
    std::string buffer;

    while (std::getline(sstream, buffer, ' ')) {
        if(buffer != "") {
            result.push_back(buffer);
        }
    }

    return result;
}

std::string case_convert::uppercase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

std::string case_convert::lowercase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

std::string case_convert::uppercase(char c) {
    std::string str(1, c);
    return case_convert::uppercase(str);
}

std::string case_convert::lowercase(char c) {
    std::string str(1, c);
    return case_convert::lowercase(str);
}

std::string case_convert::camel(case_convert::identifier_t identifier) {
    if(identifier.size() == 0) {
        return "";
    }

    std::string result;
    std::ostringstream sstream(result);

    sstream << case_convert::lowercase(identifier.at(0));

    for(int i=1; i<identifier.size(); ++i) {
        sstream << case_convert::uppercase(identifier.at(i).at(0))
            << case_convert::lowercase(identifier.at(i).substr(1));
    }
    return sstream.str();
}

std::string case_convert::pascal(case_convert::identifier_t identifier) {
    if(identifier.size() == 0) {
        return "";
    }

    std::string result;
    std::ostringstream sstream(result);

    for(int i=0; i<identifier.size(); ++i) {
        sstream << case_convert::uppercase(identifier.at(i).at(0))
            << case_convert::lowercase(identifier.at(i).substr(1));
    }

    return sstream.str();
}

std::string case_convert::kebap(case_convert::identifier_t identifier) {
    if(identifier.size() == 0) {
        return "";
    }

    std::string result;
    std::ostringstream sstream(result);

    for(int i=0; i<identifier.size(); ++i) {
        sstream << case_convert::lowercase(identifier.at(i));
        if(i != identifier.size() - 1) {
            sstream << "-";
        }
    }

    return sstream.str();
}

std::string case_convert::snake(case_convert::identifier_t identifier) {
    if(identifier.size() == 0) {
        return "";
    }

    std::string result;
    std::ostringstream sstream(result);

    for(int i=0; i<identifier.size(); ++i) {
        sstream << case_convert::lowercase(identifier.at(i));
        if(i != identifier.size() - 1) {
            sstream << "_";
        }
    }

    return sstream.str();
}

std::string case_convert::macro(case_convert::identifier_t identifier) {
    if(identifier.size() == 0) {
        return "";
    }

    std::string result;
    std::ostringstream sstream(result);

    for(int i=0; i<identifier.size(); ++i) {
        sstream << case_convert::uppercase(identifier.at(i));
        if(i != identifier.size() - 1) {
            sstream << "_";
        }
    }

    return sstream.str();
}
