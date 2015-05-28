#ifndef IP_INFO_CPP
#define IP_INFO_CPP

#include "Direccion_IP.cpp"

class IP_Info
{
    public:

        Direccion_IP *ip_principal;
        Direccion_IP *broadcast;
        Direccion_IP *ip_inicial;
        Direccion_IP *ip_final;
};

#endif
