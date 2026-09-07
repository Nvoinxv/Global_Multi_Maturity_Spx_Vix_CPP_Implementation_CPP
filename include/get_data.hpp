#ifndef GET_DATA_HPP
#define GET_DATA_HPP

#include "read_env_data.hpp"
#include <curl/curl.h>
#include <string>
#include <nlohmann/json.hpp>

class Get_Data_Market
{
private:
    CURL *curl;
    CURLcode res;

    read_env_variabel read_variabel;

    std::string variabel_api;
    std::string variabel_url;

public:
    Get_Data_Market();

    static size_t WriteCallBack(
        void *contents, size_t size,
        size_t nmeb, std::string *output);

    using json = nlohmann::json;

    void membaca_api_key_finhub(
        std::string variabel_api,
        std::string variabel_url);
};

#endif