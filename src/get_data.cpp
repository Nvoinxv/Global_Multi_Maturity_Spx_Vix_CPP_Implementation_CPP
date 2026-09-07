#include "get_data.hpp"

Get_Data_Market::Get_Data_Market() : curl(), res(), read_variabel(),
                                     variabel_api(), variabel_url()
{
}

size_t Get_Data_Market::WriteCallBack(
    void *contents, size_t size,
    size_t nmeb, std::string *output)
{
    output->append((char *)contents, size * nmeb);

    return size * nmeb;
}

using json = nlohmann::json;

void Get_Data_Market::membaca_api_key_finhub(
    std::string variabel_api,
    std::string variabel_url)
{
    curl = curl_easy_init();
    std::string response;

    std::ifstream env_variabel("/home/nvoinxv/Documents/Global_Multi_Maturity_SPX_VIX_project_cpp/.env");
    read_variabel.load_env(env_variabel);
    std::string finhub_api_key = read_variabel.get_env("FINHUB_API_KEY");
    std::string finhub_url = read_variabel.get_env("FINHUB_URL");

    std::string full_url = finhub_url + finhub_api_key;

    std::cout << "Request URL : " << full_url << "\n";

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, full_url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Get_Data_Market::WriteCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK)
        {
            std::cerr << "ERROR: " << curl_easy_strerror(res) << "\n";

            return;
        }

        json data = json::parse(response);
        std::cout << "Price SPX : $" << data["c"] << "\n";
        std::cout << "High      : $" << data["h"] << "\n";
        std::cout << "Low       : $" << data["l"] << "\n";
        std::cout << "Prev Close: $" << data["pc"] << "\n";
    }
}