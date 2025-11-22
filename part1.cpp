#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> get_input()
{
    std::ifstream input_file{};
    input_file.open("input.txt");
    if(!input_file){
        std::cerr << "no such file" << std::endl;
    }

    std::string line{};
    std::vector<int> entries{};
    while(std::getline(input_file, line)){
        if(!line.empty()){
            entries.push_back(std::stoi(line));
        }
    }

    return entries;
}

int main()
{
    std::vector<int> data = get_input(); 
    for(size_t i{}; i < data.size(); i++){
        int current_num{data[i]};
        for(size_t j{i+1}; j < data.size(); j++){
            if(current_num + data[j] == 2020){
                std::cout << "current num:" << current_num << '\n' << "data:" << data[j] << '\n';
                int answer{current_num * data[j]}; 
                std::cout << "answer:" << answer << std::endl;
                break;
            }
        }
    }

    return 0;
}
