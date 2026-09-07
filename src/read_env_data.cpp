#include "read_env_data.hpp"

read_env_variabel::read_env_variabel() : Input_File_Env(), row(), equal_symbol(),
                                         key(), value(),
                                         return_string_split(), ss(),
                                         token(), return_numeric_split(),
                                         env_data()
{
}

std::vector<std::string> read_env_variabel::split_character_string(
    const std::string &str, char delimiter)
{
    ss.clear();
    ss.str(str);

    return_string_split.clear();

    while (std::getline(ss, token, delimiter))
    {
        return_string_split.push_back(token);
    }

    return return_string_split;
}

void read_env_variabel::load_env(std::ifstream &Input_File_Env)
{
    if (Input_File_Env.is_open())
    {
        std::cout << "INPUT FILE DETECTED!" << std::endl;

        while (std::getline(Input_File_Env, row))
        {
            if (row.empty())
            {
                continue;
            }

            if (row[0] == '#')
            {
                continue;
            }

            equal_symbol = "=";

            std::size_t position_equal = row.find(equal_symbol);

            if (position_equal == std::string::npos)
            {
                continue;
            }

            key = row.substr(0, position_equal);
            value = row.substr(position_equal + 1);

            while (!key.empty() && (key.back() == ' ' || key.back() == '\t' || key.back() == '\r' || key.back() == '\n'))
            {
                key.pop_back();
            }
            while (!key.empty() && (key.front() == ' ' || key.front() == '\t'))
            {
                key.erase(0, 1);
            }
            while (!value.empty() && (value.back() == ' ' || value.back() == '\t' || value.back() == '\r' || value.back() == '\n'))
            {
                value.pop_back();
            }
            while (!value.empty() && (value.front() == ' ' || value.front() == '\t'))
            {
                value.erase(0, 1);
            }
            if (value.size() >= 2 && ((value.front() == '"' && value.back() == '"') || (value.front() == '\'' && value.back() == '\'')))
            {
                value = value.substr(1, value.size() - 2);
            }

            env_data[key] = value;

            std::cout << "Key   : " << key << std::endl;
            std::cout << "Value : " << value << std::endl;
        }

        Input_File_Env.close();
    }
    else
    {
        std::cout << "FILE .env Doesn't Detected!" << std::endl;
    }
}

std::string read_env_variabel::get_env(
    const std::string &key)
{
    auto data = env_data.find(key);

    if (data != env_data.end())
    {
        return data->second;
    }

    return "";
}