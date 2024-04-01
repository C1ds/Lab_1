#pragma once
#include <iostream>
using namespace std;

class Asistente{
    private:
        string tipo, nombre, nickname, ocupacion, empresa, est_Educativo;
        int edad, semestre;
    public:
        //Asistente Basico
        Asistente(string nombre);
        //Asistente en Linea
        Asistente(string nombre, string nickname);
        //Trabajador Empresa
        Asistente(string nombre, string ocupacion, string empresa);
        //Trabajador Docente
        Asistente(string nombre, int edad, string ocupacion, string est_Educativo);
        //Estudiante
        Asistente(string nombre, string est_Educativo, int semestre);

        string getTipo();
        string getNombre();
        string getNickname();
        string getOcupacion();
        string getEmpresa();
        string getEstablecimiento();
        int getEdad();
        int getSemestre();

        void setEdad(int edad);
        
        ~Asistente();
};
