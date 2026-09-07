#ifndef GET_DATA_HPP
#define GET_DATA_HPP

#include "read_env_data.hpp"
#include <curl/curl.h>
#include <string>
#include <nlohmann/json.hpp>

class Get_Data_Market {
    private:
    CURL *curl;
    CURLCODE res;

    read_env_variabel read_variabel;
    std::ifstream env_variabel_path("/home/nvoinxv/Documents/Global_Multi_Maturity_SPX_VIX_project_cpp/.env");

    public:
    size_t WriteCallBack(
        void* contents, size_t size,
        size_t nmeb, std::string* output
    );

    void membaca_api_key_finhub();
};

#endif