#include <string>
#include <vector>

namespace case_convert {
    using identifier_t = std::vector<std::string>;
    const std::vector<char> grouping_characters = {
        ',',
        '/',
        '-',
        '_',
        '\\',
        '+',
        '*',
        '@',
        '.',
        ':',
        ';'
    };

    identifier_t identifier(std::string str);

    std::string camel(identifier_t identifier);
    std::string pascal(identifier_t identifier);
    std::string kebap(identifier_t identifier);
    std::string snake(identifier_t identifier);
    std::string macro(identifier_t identifier);

    std::string uppercase(std::string str);
    std::string lowercase(std::string str);
    std::string uppercase(char c);
    std::string lowercase(char c);
}
