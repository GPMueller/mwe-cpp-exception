#include <detail/Library.hpp>
#include <detail/Exception.hpp>

namespace detail
{
    void library_function()
    try
    {
        // some erronous code which throws an exception...
        // let's pretend we weren't able to open a file
        std::string filename = "nonexistent.txt";
        library_throw("could not open file \"" + filename + "\"");
    }
    catch( const std::exception & )
    {
        library_rethrow("library_function failed")
    }
}