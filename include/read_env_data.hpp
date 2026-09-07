#ifndef READ_ENV_DATA_HPP
#define READ_ENV_DATA_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <string>

class read_env_variabel {
    private:
    std::ifstream Input_File_Env;
    std::string row;
    std::string equal_symbol;
    std::string key;
    std::vector<std::string> return_string_split;
    std::stringstream ss;
    std::string token;

    std::string value;
    std::vector<float> return_numeric_split;

    public:
    read_env_variabel();
    
    std::vector<std::string> split_character_string(
        const std::string& str, char delimiter
    );

    void load_env(std::ifstream& Input_File_Env);
};

#endif