#ifndef I_DIRECCION_IP_CPP
#define I_DIRECCION_IP_CPP

#include <string>

class I_Direccion_IP
{
    private:

        virtual void guardar_direccion_ip(std::string direccion_ip) = 0;
        virtual void determinar_clase_direccion() = 0;
        virtual void modificar_octeto(int octeto, int aumento) = 0;
        virtual void resta_octeto_1() = 0;
        virtual void resta_octeto_2() = 0;
        virtual void resta_octeto_3() = 0;
        virtual void resta_octeto_4() = 0;

    public:

        virtual std::string get_direccion_ip() = 0;
        virtual char get_clase() = 0;
        virtual void set_ip_anterior() = 0;
        virtual void sumar_uno() = 0;
};

#endif
