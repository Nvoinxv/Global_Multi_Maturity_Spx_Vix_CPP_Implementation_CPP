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
    ss.clear();
    ss.str(str);

    return_string_split.clear();

    while (std::getline(ss, token, delimiter)) {
        return_string_split.push_back(token);
    }

    return return_string_split;
}

std::vector<float> read_env_data::split_character_numeric(
    const float& value, char delimiter
) {
    ss.clear();
    ss.str(str);

    return_numeric_split.clear();
    
    while (std::getline(ss, token, delimiter)) {
        return_numeric_split.push_back(token);
    }

    return return_numeric_split;
}

void read_env_data::load_env() {
    Input_File_Env.open(".env");

    if (Input_File_Env.is_open()) {
        std::cout << "Input file .env terdeteksi!" << std::endl;

        while (std::getline(Input_File_Env, row)) {
            if (row.empty()) {
                continue;
            }

            if (row[0] == '#') {
                continue;
            }

            equal_symbol = "=";

            std::size_t position_equal = row.find(equal_symbol);

            if (posisition_equal == std::string::npos) {
                continue;
            }

            key = row.substr(0, posisition_equal);
            value = row.substr(posisition_equal + 1);

            std::cout << "Key   : " << key << std::endl;
            std::cout << "Value : " << value << std::endl;
        }

        Input_File_Env.close();
    } else {
        std::cout << "File pada .env belum terdeteksi!" << std::endl;
    }
}
