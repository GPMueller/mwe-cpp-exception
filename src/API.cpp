#include <API.hpp>
#include <detail/Library.hpp>
#include <detail/Exception.hpp>

namespace mylib
{
    API_RETURN function() noexcept
    try
    {
        detail::library_function();
        return API_RETURN::SUCCESS;
    }
    catch( const std::exception & ex )
    {
        detail::library_handle_exception(ex);
        return API_RETURN::FAILURE;
    }
}