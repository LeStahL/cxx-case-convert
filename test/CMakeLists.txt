add_executable(cxx-case-convert-test
    test.cpp
)
target_include_directories(cxx-case-convert-test PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(cxx-case-convert-test
    cxx-case-convert
    Catch2::Catch2WithMain
)

add_test(NAME CXXCaseConvertTest COMMAND cxx-case-convert-test)
