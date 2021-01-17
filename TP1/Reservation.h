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
        int get_id_hotel() const;
        double get_montant_original() const;
        double get_montant_reel() const;
        Date::Date get_date_debut() const;
        Date::Date get_date_fin() const;
        std::string get_nom_client() const;
        Hotel::Hotel get_hotel();
        //setters
        void set_date_debut(Date::Date date_debut);
        void set_date_fin(Date::Date date_fin);
        void set_dates(Date::Date date_debut, Date::Date date_fin);
        void set_chambre(Chambre::Chambre chambre);
        void set_client(Client::Client client);
        void actualiser_montant();

        double montant_total(int nbr_reservations_pour_remise); //offre de 10% pour un nbr de reservations en parametre
        double montant_total(int nbr_reservations_pour_remise, double remise);  //offre en parametre
        void Annuler();
        ~Reservation();

        bool operator == (const Reservation& reser) const; //Surchages d'opérateur pour comparer 2 reservations

    private:

        int _id;
        Date::Date _date_debut;
        Date::Date _date_fin;
        int _id_hotel;
        int _id_chambre;
        int _id_client;
        std::string _nom_client;
        double _montant_original;
        double _montant_reel;
        Hotel::Hotel* _hotel;   //Pointeur pour pouvoir modifier les valeurs de l'hotel

        //Pour le programme de fidélité, nous devons stocker le nbr de résérvation deja éffectué par le client
        int _nbr_reservations;


    };

    //Surcharge d'opérateur de sortie (ne peut pas etre une fonction membre et n'a pas besoin d'etre une fonction friend car on a des getters)
    std::ostream& operator << (std::ostream& os, const Reservation& reser);

} //namespace

#endif // RESERVATION_H


