# mwe-cpp-exception
## Proper, portable exception handling in C++11 with backtracing

This MWE shows how `std::nested_exception` can be applied in order to not lose information while propagating `std::exception`s
upwards through a chain of function calls and create a **backtrace** without any overhead (compare e.g. logging of debug messages).
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

CMake is used to configure the build.

**TODO**: Extend this MWE with exceptions which do not require the code to terminate.
