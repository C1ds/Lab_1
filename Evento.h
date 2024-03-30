#pragma once
#include <iostream>
using namespace std;

class Evento {
    private:
        string tipo, tema, ubicacion, duracion;
    public:
        Evento(string tipo, string tema);
        string getTipo();
        string getTema();
};