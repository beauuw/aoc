#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

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

int get_product(std::vector<int>& data)
{
    std::unordered_set<int> set{data.begin(), data.end()};
    int amount_remaining{}, mystery_number{}, product{};
    for(size_t i{}; i < data.size(); i++){
        amount_remaining = 2020 - data[i];
        for(size_t j{i+1}; j < data.size(); j++){
            mystery_number = amount_remaining - data[j];
            if(set.count(mystery_number)){
                product = data[i] * data[j] * mystery_number; 
                return product;
            }
        }
    }

    return product;
}

int main()
{
    std::vector<int> data = get_input(); 
    int result = get_product(data);
    std::cout << result << std::endl;

    return 0;
}
