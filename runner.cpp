#include <iostream>
#include <filesystem>
#include "config.hpp"

void run(std::string_view name, std::string_view comment)
{
    std::cout << "Running: " << comment << std::endl;
    std::system((std::filesystem::path(".") / name).string().c_str());
}

int main() 
{
    std::filesystem::current_path(EXECUTABLE_FOLDER);

    run("no_vec_no_fast", "no vectorization, no fast math");
    run("no_vec_yes_fast", "no vectorization, fast math");
    run("yes_vec_no_fast", "vectorization, no fast math");
    run("yes_vec_yes_fast", "vectorization, fast math");
    
    return 0;
}