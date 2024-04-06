#pragma one
#include <iostream>
#include "Evento.h"
//#include "Asistente.h"
using namespace std;
/**
 * @class Clase Funciones
*/
class Funciones{
    private:
        Evento** eventos;
        int capacidad, cantidad;
    public:
            /**
         * Constructor de la Clase Funciones
         * @param int
        */
        Funciones(int capacidad);
        Evento** getEventos();
                /**
         * Getters de la Clase
        */
        int getCapacidad();
        int getCantidad();
                /**
         * Valida que el parametro entregado sea un numero
         * @param string
         * @return int
        */
        int validarOpcion(string opcion);
                /**
         * Imprime el Menu principal
        */
        void printMenu();
                /**
         * Imprime los tipos de Eventos
        */
        void printTipo();
                /**
         * Imprime los tipos de Asistentes
        */
        void printAsistTipo();
        
        /**
         * Imprime los Eventos disponibles con capacidad para la inscripcion
        */
        void listarEventos();
                /**
         * Imprime los asistentes segun la opcion
         * Opcion 1: Imprime los asistentes de un evento especifico
         * Opcion 2: Imprime los asistentes de todos los eventos
        */
        void listarAsistentes();
                /**
         * Imprime todos los eventos y su informacion
        */
        void printEventos();
                /**
         * leectores de archivos
        */
        void leerArchivoEvento();
        void leerArchivoAsistentes();
                /**
         * sobrescribe los archivos
        */
        void escribirArchivo();
                /**
         * Valida que el dato sea un 0 o 1 y retorna su forma booleana
         * @return bool
        */
        bool validarBoolean(string data);
                /**
         * Agrega un Asistente a un Evento
         * @return bool
        */
        bool registrarAsist();
                /**
         * Crea un Evento y lo agrega a eventos
         * @return bool
        */
        bool crearEvento();
                /**
         * Agrega un Evento a eventos
         * @return bool
        */
        bool addEvento(Evento* evento);
                
        /**
         * Crea un Asistente y lo devuelve
         * @return Asistente*
        */
        Asistente* crearAsistente();

        /**
         * Destructor de la Clase Funciones
        */
        ~Funciones();
};