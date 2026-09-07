#include "read_env_data.hpp"

read_env_data::read_env_data() :
Input_File_Env(), row(), equal_symbol(),
key(), value(0.0f),
return_string_split(), ss(),
token()  {

}

std::vector<std::string> read_env_data::split_character_string(
    const std::string& str, char delimiter
) {

}

void read_env_data::load_env(
    std::ifstream& Input_File_Env(".env")
) {
    if (Input_File_Env.is_open()) {
        while (getline(Input_File_Env, row)) {
            std::cout << "Input file .env terdeteksi!" << std::endl;
        }

        if (!line || line.compare("#")) {
            continue;
        }

        equal_symbol = "=";

        if (line.find(equal_symbol) != line) {
            continue;
        }
        
        key = 
        Input_File_Env.close();
    } else {
        std::cout << "File pada .env belum terdeteksi!" << std::endl;
    }


}