#include "read_env_data.hpp"
#include "get_data.hpp"

int main()
{
    std::cout << "START PROGRAM QUANT TRADING" << std::endl;

    read_env_variabel read_variabel;
    std::ifstream env_variabel_path("/home/nvoinxv/Documents/Global_Multi_Maturity_SPX_VIX_project_cpp/.env");
    read_variabel.load_env(env_variabel_path);

    std::string variabel_env_detect_test = read_variabel.get_env("FINHUB_API_KEY");

    std::cout << "FINHUB API KEY: " << variabel_env_detect_test << std::endl;

    std::string variabel_api_finhub = read_variabel.get_env("FINHUB_API_KEY");
    std::string variabel_url_finhub = read_variabel.get_env("FINHUB_URL");

    std::cout << "TESTING SHOW DATA FINHUB" << std::endl;
    Get_Data_Market data_market_finhub;
    data_market_finhub.membaca_api_key_finhub(variabel_api_finhub, variabel_url_finhub);

    std::cout << "END PROGRAM QUANT TRADING" << std::endl;

    return 0;
}