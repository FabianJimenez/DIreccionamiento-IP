#include "Direccion_IP.cpp"
#include "IP_Info.cpp"
#include <vector>

class I_Subneting
{
    private:

        virtual void calcular_bits_hostid() = 0;

    public:

        virtual void calcular_subneting() = 0;
        virtual std::vector <IP_Info> get_subredes() = 0;
};
