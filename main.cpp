#include "read_env_data.hpp"

int main() {
    std::cout << "START PROGRAM QUANT TRADING" << std::endl;
    
    read_env_data read_variabel;
    std::ifstream env_variabel_path("/home/nvoinxv/Documents/Global_Multi_Maturity_SPX_VIX_project_cpp/.env");
    read_variabel(env_variabel_path);

    return 0;
}