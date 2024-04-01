#pragma once
#include <iostream>
#include "Asistente.h"
using namespace std;

class Evento {
    private:
        string tipo, tema, ubicacion;
        int capacidad, cantidad, duracion;
        Asistente** asistentes;
    public:
        //Evento Publico
        Evento(string tema, int duracion, string ubicacion, int capacidad);
        //Evento Digital
        Evento(string tema, int capacidad, int duracion);
        //Evento Corporativo
        Evento(string tema, string ubicacion, int capacidad, int duracion);
        //Evento Academico
        Evento(int capacidad, int duracion, string tema, string ubicacion);
        //Evento Privado
        Evento(int capacidad, string ubicacion, int duracion);

        string getTipo();
        string getTema();
        string getUbicacion();
        int getCapacidad();
        int getCantidad();
        int getDuracion();

        void setUbicacion(string ubicacion);
        void setDuracion(int duracion);

        bool addAsistente(Asistente* asistente);

        ~Evento();
};