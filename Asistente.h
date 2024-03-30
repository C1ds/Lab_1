#pragma once
#include <iostream>
using namespace std;

class Asistente{
    private:
        string tipo, nombre;
        int edad;
    public:
        Asistente(string tipo, string nombre, int edad);
        string getTipo();
        string getNombre();
        int getEdad();
        ~Asistente();
};
