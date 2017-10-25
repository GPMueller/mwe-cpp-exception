#include <API.hpp>
#include <iostream>

int main(int argc, char ** argv)
{
    auto value = api_function();
    std::cerr << "Library call returned " << value << std::endl;
    return EXIT_SUCCESS;
}