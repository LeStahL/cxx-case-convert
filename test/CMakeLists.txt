# cxx-case-convert
# Copyright (C) 2022 Alexander Kraus <nr4@z10.info>

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

add_executable(cxx-case-convert-test
    test.cpp
)
target_include_directories(cxx-case-convert-test PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(cxx-case-convert-test
    cxx-case-convert
    Catch2::Catch2WithMain
)

add_test(NAME CXXCaseConvertTest COMMAND cxx-case-convert-test)
