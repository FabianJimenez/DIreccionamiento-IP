#include "I_Subneting.cpp"
#include "Direccion_IP.cpp"
#include "IP_Info.cpp"
#include <cmath>
#include <vector>

class Subneting: public I_Subneting
{
    private:

        const int potencias[8] = {128,64,32,16,8,4,2,1};
        int subredes_pedidas;
        int subredes_minimas;
        int bits_requeridos;
        int aumento_bits;
        std::string net_principal;
        std::vector <IP_Info> direcciones;

        void calcular_bits_hostid() override
        {
            int potencia = 2;
            while((std::pow(2,potencia++) - 2) < subredes_pedidas);
            subredes_minimas = std::pow(2,--potencia) - 2;
            bits_requeridos = potencia;
        }

    public:

        Subneting(int redes_pedidas, std::string net_principal)
        {
            this -> subredes_pedidas = redes_pedidas;
            this -> net_principal = net_principal;
            calcular_bits_hostid();
            aumento_bits = potencias[bits_requeridos-1];
        }

        void calcular_subneting() override
        {
            Direccion_IP *aux = new Direccion_IP(net_principal);
            Direccion_IP *aux_2 = new Direccion_IP(net_principal);

            for(int i=0; i<=subredes_minimas; i++)
            {
                IP_Info info = *new IP_Info();

                aux = new Direccion_IP(net_principal);
                *aux += (i+1) * aumento_bits;
                info.ip_principal = aux;

                aux_2 = new Direccion_IP(info.ip_principal -> get_direccion_ip());
                aux_2 -> sumar_uno();
                info.ip_inicial = aux_2;

                direcciones.push_back(info);
            }

            for(int i=0; i<=direcciones.size()-2; i++)
            {
                aux_2 = new Direccion_IP(direcciones[i+1].ip_principal -> get_direccion_ip());
                aux_2 -> set_ip_anterior();
                aux_2 = new Direccion_IP(aux_2 -> get_direccion_ip());

                direcciones[i].broadcast = aux_2;

                aux_2 = new Direccion_IP(aux_2 -> get_direccion_ip());
                aux_2 -> set_ip_anterior();
                aux_2 = new Direccion_IP(aux_2 -> get_direccion_ip());

                direcciones[i].ip_final = aux_2;
            }
        }

        std::vector <IP_Info> get_subredes() override
        {
            return direcciones;
        }
};
