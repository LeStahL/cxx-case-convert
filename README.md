# cxx-case-convert
<img src="https://ci.appveyor.com/api/projects/status/github/lestahl/cxx-case-convert?branch=main&svg=true" />

`cxx-case-convert` is a c++ library that converts strings between case types.

# Build it
You need CMake and a working C++ compiler.
* Create an out-of-source build folder and `cd` there.
* Configure it with CMake: `cmake [SOURCE_ROOT]`. If you want to run the tests,
  supply `-DCASE_CONVERT_TESTS=ON` in the CMake command.
* Use your favorite make tool to build it, for example `cmake --build . --config Release -- -m` for msvc.

# Test it
If you decided to test it, run ctest after building, for example with this command: `ctest -C Release`.

# Use it
Find an usage example below:

```CXX
#include <string>
#include <iostream>

#include <case-convert/convert.hpp>

int main(int argc, char **args)
{
    std::string str = "this/is an example.";
    case_convert::identifier_t strid = case_convert::identifier(str);
    std::cout << "Original: " << str << " "
        << "camelCase: " << case_convert::camel(strid) << " "
        << "PascalCase: " << case_convert::pascal(strid) << " "
        << "kebap-case: " << case_convert::kebap(strid) << " "
        << "snake_case: " << case_convert::snake(strid) << " "
        << "MACRO_CASE: " << case_convert::macro(strid) << " "
        << std::endl;
    return 0;
}

```

By default, group separators are `,`, `/`, `-`, `_`, `\\`, `+`, `*`, `@`, `.`, `:` and `;`. You can add additional group separators with
```CXX
    case_convert::grouping_characters.push_back('c');
```
before converting.

# License
cxx-case-convert is (c) 2022 Alexander Kraus <nr4@z10.info> and GPLv3; see LICENSE for details.
