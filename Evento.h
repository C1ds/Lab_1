#pragma once
#include <iostream>
#include "Asistente.h"
using namespace std;

class Evento {
    private:
        string tipo, tema, ubicacion, plataformaTransmision, departamentoResponsable, empresa, universidad;
        int capacidad, cantidad, duracion;
        bool registroRequerido, accesoGratuito, certificadoDisponible;
        Asistente** asistentes;
    public:
        //Evento Publico
        Evento(string tema, int duracion, string ubicacion, int capacidad, bool registroRequerido);
        //Evento Digital
        Evento(string tema, int duracion, int capacidad, string plataformaTransmision, bool accesoGratuito);
        //Evento Corporativo
        Evento(string tema, int duracion, string ubicacion, int capacidad, string departamentoResponsable, string empresa);
        //Evento Academico
        Evento(string tema, int duracion, string ubicacion, int capacidad, string universidad, bool certificadoDisponible);
        //Evento Privado
        Evento(int duracion, string ubicacion, int capacidad);

        string getTipo();
        string getTema();
        string getUbicacion();
        string getPlataformaTransmision();
        string getDepartamentoResponsable();
        string getEmpresa();
        string getUniversidad();
        int getCapacidad();
        int getCantidad();
        int getDuracion();
        bool getRegistroRequerido();
        bool getAccesoGratuito();
        bool getCertificadoDisponible();

        void setUbicacion(string ubicacion);
        void setDuracion(int duracion);

        bool addAsistente(Asistente* asistente);

        ~Evento();
};