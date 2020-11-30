#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include "Date.h"
#include "Hotel.h"
#include "Chambre.h"
#include "Client.h"
#include <cassert>


namespace Reservation {

    class Reservation {

    public:

        Reservation(int id, Date::Date date_debut, Date::Date date_fin, Hotel::Hotel& hotel, Chambre::Chambre chambre, Client::Client client);
        bool Check_validite_reservation(Date::Date date_debut, Date::Date date_fin, Hotel::Hotel& hotel, Chambre::Chambre chambre); //On verifie la validité de la reservation
        //getters
        int get_id() const;
        int get_id_chambre() const;
        int get_id_client() const;
        std::string get_id_hotel() const;
        int get_montant() const;
        Date::Date get_date_debut() const;
        Date::Date get_date_fin() const;
        //setters
        void set_date_debut(Date::Date date_debut);
        void set_date_fin(Date::Date date_fin);
        void set_dates(Date::Date date_debut, Date::Date date_fin);
        void set_chambre(Chambre::Chambre chambre);
        double montant_total(int nbr_reservations_pour_remise); //offre de 10% pour un nbr de reservations en parametre
        double montant_total(int nbr_reservations_pour_remise, double remise);  //offre en parametre

    private:

        int _id;
        Date::Date _date_debut;
        Date::Date _date_fin;
        std::string _id_hotel;
        int _id_chambre;
        int _id_client;
        int _montant;

        //Pour le programme de fidélité, nous devons stocker le nbr de résérvation deja éffectué par le client
        int _nbr_reservations;


    };

} //namespace

#endif // RESERVATION_H


