Proper, portable exception handling with backtracing in C++11
====================================================================

[![Build Status](https://api.travis-ci.org/GPMueller/mwe-cpp-exception.svg?branch=master)](https://travis-ci.org/GPMueller/mwe-cpp-exception)

**See [GPMueller/trace](https://github.com/GPMueller/trace) for a proper exception backtracing library.**

This MWE shows how [`std::nested_exception`](http://en.cppreference.com/w/cpp/error/nested_exception) and [`std::throw_with_nested`](http://en.cppreference.com/w/cpp/error/throw_with_nested) can be applied in order to not lose information while propagating
an original `std::exception` upwards through a chain of function calls and create a **backtrace** without any overhead (compare e.g. logging of debug messages).
This avoids much of the need for any debugging and provides a way of ensuring that a library does not crash ungracefully.
Output should look something like this:
```
Library API: Exception caught in function 'api_function'
Backtrace:
~/Git/mwe-cpp-exception/src/detail/Library.cpp:17 : library_function failed
~/Git/mwe-cpp-exception/src/detail/Library.cpp:13 : could not open file "nonexistent.txt"
```

The example may seem a bit overkill, displaying a library with an API layer, but it shows a thorough way of dealing cleanly with exceptions.
`main` calls an API function, which in turn calls a library function which deliberately throws. The API function catches the exception and
calls a handler function.

Inspiration for this MWE was taken from https://stackoverflow.com/a/37227893/4069571 and https://stackoverflow.com/a/348862/4069571

Build
--------------------------------------------------------------------

CMake is used to configure the build. To build the executable:
```
mkdir -p build
cd build
cmake ..
cmake --build .
```

TODO
--------------------------------------------------------------------
- Extend this MWE with example exceptions which do not require the code to terminate.
- Create unit tests with catch, using e.g. `REQUIRE_THROWS`
