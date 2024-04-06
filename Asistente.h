#pragma once
#include <iostream>
using namespace std;

class Asistente{
    private:
        string tipo, nombre, nickname, ocupacion, empresa, carrera, universidad;
        int edad, semestre;
    public:
                /**
         * Constructor de la Clase Asistente, tipo Basico
         * @param string
         * @param int
        */
        Asistente(string nombre, int edad);
                /**
         * Constructor de la Clase Asistente, tipo Online
         * @param string
         * @param string
        */
        Asistente(string nombre, string nickname);
                
        /**
         * Constructor de la Clase Asistente, tipo T_Empresa
         * @param string
         * @param int
         * @param string
         * @param string
        */
        Asistente(string nombre, int edad, string ocupacion, string empresa);
                /**
         * Constructor de la Clase Asistente, tipo T_Docente
         * @param string
         * @param string
         * @param string
        */
        Asistente(string nombre, string ocupacion, string universidad);
                /**
         * Constructor de la Clase Asistente, tipo Estudiante
         * @param string
         * @param string
         * @param string
         * @param int
        */
        Asistente(string nombre, string carrera, string universidad, int semestre);
        /**
         * Getters de la Clase
        */
        string getTipo();
        string getNombre();
        string getNickname();
        string getOcupacion();
        string getEmpresa();
        string getCarrera();
        string getUniversidad();
        int getEdad();
        int getSemestre();

                /**
         * Destructor de la Clase Asistente
        */
        ~Asistente();
};