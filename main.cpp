#include "Direccion_IP.cpp"
#include "Subneting.cpp"
#include "IP_Info.cpp"
#include <iostream>
//*new_dir += 1;

int main()
{
    std::string net_principal;
    int subredes;

    std::cout << "Red principal: ";
    std::cin >> net_principal; std::cin.get();

    std::cout << "Número de subredes: ";
    std::cin >> subredes; std::cin.get();

    std::cout << std::endl;

    Subneting subneting = *new Subneting(subredes,net_principal);

    subneting.calcular_subneting();

    std::vector <IP_Info> arr_subredes = subneting.get_subredes();

    for(int i=0; i<arr_subredes.size()-1; i++)
    {
        std::cout << "Subred #" << i+1 << ": " << arr_subredes[i].ip_principal -> get_direccion_ip();
        std::cout << "    IP inicial: " << arr_subredes[i].ip_inicial -> get_direccion_ip();
        std::cout << "    IP final: " << arr_subredes[i].ip_final -> get_direccion_ip();
        std::cout << "    Broadcast: " << arr_subredes[i].broadcast -> get_direccion_ip() << std::endl;
    }

    return 0;
}
