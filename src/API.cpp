#include <API.hpp>
#include <detail/Library.hpp>
#include <detail/Exception.hpp>

int api_function() noexcept
try
{
    detail::library_function();
    return API_SUCCESS;
}
catch( const std::exception & ex )
{
    detail::library_handle_exception(ex);
    return API_FAILURE;
}