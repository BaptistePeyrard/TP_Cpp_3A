#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include "Date.h"


namespace Reservation {

    class Reservation {

    public:

        Reservation(int id, Date::Date date_debut, Date::Date date_fin, std::string id_hotel, int id_chambre, int id_client);
       

    private:

        int _id;
        Date::Date _date_debut;
        Date::Date _date_fin;
        std::string _id_hotel;
        int _id_chambre;
        int _id_client;
        int montant;


    };

} //namespace

#endif // RESERVATION_H


