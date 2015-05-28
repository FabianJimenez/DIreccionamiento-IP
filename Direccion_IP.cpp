#ifndef DIRECCION_IP_CPP
#define DIRECCION_IP_CPP

#include "I_Direccion_IP.cpp"
#include <sstream>
#include <cctype>

class Direccion_IP: public I_Direccion_IP
{
    private:

        int octeto_1;
        int octeto_2;
        int octeto_3;
        int octeto_4;

        char clase;
        std::stringstream converter;

        void guardar_direccion_ip(std::string direccion_ip) override
        {
            int *ptr_octeto[4] = {&octeto_1,&octeto_2,&octeto_3,&octeto_4};
            int aux = 0;
            int j = 0;

            for(int i=0; i<direccion_ip.size(); i++)
            {
                if(isdigit(direccion_ip[i])) (aux *= 10) += (direccion_ip[i]-48);
                else
                {
                    *ptr_octeto[j++] = aux;
                    aux = 0;
                }
            }

            *ptr_octeto[j] = aux;
        }

        void determinar_clase_direccion() override
        {
            if(octeto_1 >= 1 && octeto_1 <= 126) clase = 'A';
            else if(octeto_1 >= 128 && octeto_1 <= 191) clase = 'B';
            else if(octeto_1 >= 192 && octeto_1 <= 223) clase = 'C';
        }

        void modificar_octeto(int octeto, int aumento)
        {
            int *ptr_octeto;

            switch(octeto)
            {
                case 1:
                    ptr_octeto = &octeto_1;
                    break;
                case 2:
                    ptr_octeto = &octeto_2;
                    break;
                case 3:
                    ptr_octeto = &octeto_3;
                    break;
                default:
                    ptr_octeto = &octeto_4;
            }

            *ptr_octeto += aumento;
        }

        void resta_octeto_4() override
        {
            if(octeto_4 == 0) octeto_4 = 255, resta_octeto_3();
            else octeto_4--;
        }

        void resta_octeto_3() override
        {
            if(octeto_3 == 0) octeto_3 = 255, resta_octeto_2();
            else octeto_3--;
        }

        void resta_octeto_2() override
        {
            if(octeto_2 == 0) octeto_2 = 255, resta_octeto_1();
            else octeto_2--;
        }

        void resta_octeto_1() override
        {
            octeto_1--;
        }

    public:

        Direccion_IP(std::string direccion_ip)
        {
            guardar_direccion_ip(direccion_ip);
            determinar_clase_direccion();
        }

        std::string get_direccion_ip() override
        {
            std::string direccion_ip = "";
            converter.str("");

            converter << octeto_1 << "." << octeto_2 << "." << octeto_3 << "." << octeto_4;
            direccion_ip += converter.str();

            return direccion_ip;
        }

        char get_clase() override
        {
            return clase;
        }

        void set_ip_anterior() override
        {
            resta_octeto_4();
        }

        void sumar_uno() override
        {
            octeto_4++;
        }

        friend Direccion_IP& operator += (Direccion_IP &ip1, int aumento)
        {
            switch(ip1.get_clase())
            {
                case 'A':
                    ip1.modificar_octeto(2,aumento);
                    break;
                case 'B':
                    ip1.modificar_octeto(3,aumento);
                    break;
                case 'C':
                    ip1.modificar_octeto(4,aumento);
                    break;
            }

            return ip1;
        }
};

#endif
