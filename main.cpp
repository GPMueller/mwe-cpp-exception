#include <API.hpp>
#include <iostream>
#include <cstdlib>

int main(int argc, char ** argv)
{
    auto value = api_function();

    if( value == API_SUCCESS )
    {
        std::cerr << "Library call returned API_SUCCESS\n";
        // In this MWE, we expect api_function to fail and therefore to
        // return API_FAILURE (normally it would be the other way around)
        std::exit(EXIT_FAILURE);
    }
    else
        std::cerr << "Library call returned API_FAILURE\n";
}