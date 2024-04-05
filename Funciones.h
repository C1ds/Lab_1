#pragma one
#include <iostream>
#include "Evento.h"
//#include "Asistente.h"
using namespace std;

class Funciones{
    private:
        Evento** eventos;
        int capacidad, cantidad;
    public:
        Funciones(int capacidad);
        Evento** getEventos();
        int getCapacidad();
        int getCantidad();
        int validarOpcion(string opcion);
        
        void printMenu();
        void printTipo();
        void printAsistTipo();
        void listarEventos();
        void printEventos();

        bool validarBoolean(string data);
        bool registrarAsist();
        bool crearEvento();
        bool addEvento(Evento* evento);
        
        Asistente* crearAsistente();

        ~Funciones();
};