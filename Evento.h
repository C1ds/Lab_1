#pragma once
#include <iostream>
#include "Asistente.h"
using namespace std;
/**
 * @class Clase Evento
*/
class Evento {
    private:
        string tipo, tema, ubicacion, plataformaTransmision, departamentoResponsable, empresa, universidad;
        int capacidad, cantidad, duracion;
        bool registroRequerido, accesoGratuito, certificadoDisponible;
        Asistente** asistentes;
    public:
                /**
         * Constructor de la Clase Evento, tipo Publico
         * @param string
         * @param int
         * @param string
         * @param int
         * @param bool
        */
        Evento(string tema, int duracion, string ubicacion, int capacidad, bool registroRequerido);
               /**
         * Constructor de la Clase Evento, tipo Digital
         * @param string
         * @param int
         * @param int
         * @param string
         * @param bool
        */
        Evento(string tema, int duracion, int capacidad, string plataformaTransmision, bool accesoGratuito);
                /**
         * Constructor de la Clase Evento, tipo Corporativo
         * @param string
         * @param int
         * @param string
         * @param int
         * @param string
         * @param string
        */
        Evento(string tema, int duracion, string ubicacion, int capacidad, string departamentoResponsable, string empresa);
                /**
         * Constructor de la Clase Evento, tipo Academico
         * @param string
         * @param int
         * @param string
         * @param int
         * @param string
         * @param bool
        */
        Evento(string tema, int duracion, string ubicacion, int capacidad, string universidad, bool certificadoDisponible);
                /**
         * Constructor de la Clase Evento, tipo Privado
         * @param int
         * @param string
         * @param int
        */
        Evento(int duracion, string ubicacion, int capacidad);
        /**
         * Getters de la Clase
        */
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
        /**
         * Lista los Asistentes en el Evento
        */
        void listarAsistentes();
        /**
         * @return un string con los asistentes del evento
        */
        string getAsistentes();
        /**
         * Agrega un Asistente a asistentes
         * @return true si se agrega correctamente, false si falla
        */
        bool addAsistente(Asistente* asistente);
        /**
         * Destructor de la Clase Evento
        */
        ~Evento();
};