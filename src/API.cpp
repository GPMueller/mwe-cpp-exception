#include <API.hpp>
#include <detail/Library.hpp>
#include <detail/Exception.hpp>

int api_function()
try
{
    detail::library_function();
    return EXIT_SUCCESS;
}
catch( const std::exception & ex )
{
    detail::library_handle_exception(ex);
    return EXIT_FAILURE;
}