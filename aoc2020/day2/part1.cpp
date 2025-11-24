#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>

bool is_password_valid(std::string& line)
{
    //separate each parameter on the current line via whitespace
    std::basic_stringstream<char> ss{line};
    std::string min_max{}, ch{}, password{};
    ss >> min_max >> ch >> password;

    //break data in stringstream up into appropriate type(s) / remove remaining rubbish chars : & -
    size_t hyphen_index = min_max.find('-'); //size t here as .find() returns the index of - in string
    int min{std::stoi(min_max.substr(0, hyphen_index))}; //start at index 0 in min_max string and stop at - index
    int max{std::stoi(min_max.substr(hyphen_index + 1))}; //no length is specified here as string ends after - + 1
    char must_contain{ch[0]}; //only 1 char is ever required, and it's always at the first index in the ch string(s)
    
    //count how many times the must_contain char appears in the actual password
    long ch_count{std::count(password.begin(), password.end(), must_contain)}; //long here avoids narrowing errors and ensures the count can safely hold the value without overflow
    if(ch_count >= min && ch_count <= max){
        return true; 
    }

    return false;
}

int read_input_data(const std::string& filename)
{
    std::ifstream input_file{};
    input_file.open("input.txt");
    if(!input_file){
        std::cerr << "no such file" << std::endl;
    }
    
    int valid_passwords{};
    std::string line{};

    while(std::getline(input_file, line)){
        if(!line.empty() && is_password_valid(line)){
            valid_passwords++;
        } 
    }

    return valid_passwords;
}

int main()
{
    int valid_passwords{read_input_data("input.txt")};
    std::cout << "valid passwords: " << valid_passwords << std::endl;
    return 0;
}
