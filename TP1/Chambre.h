#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>
#include <vector>
#include <iostream>
#include "Date.h"

enum class Type {Simple, Double, Suite};    //class enum contenant toutes les possibilit�s de type de chambre

namespace Chambre {

    class Chambre {
       
    public:

        Chambre(int id, Type type, double prix);
        //getters
        int get_id() const;
        std::vector<Date::Date> get_disponibilite() const;
        std::string get_type() const;   //Type get_type() const;
        double get_prix() const;
        //setters
        void set_id(int id);
        void set_type(Type type);
        void set_prix(double prix);
        void ajouter_jours_reservations(Date::Date date_debut, Date::Date date_fin);    //Ajouter des jours r�s�rv�s
        void supprimer_jours_reservations(Date::Date date_debut, Date::Date date_fin);    //Supprimer des jours r�s�rv�s
        bool Check_disponibilite(Date::Date date_debut, Date::Date date_fin);   //V�rifier si un jour est d�j� r�s�rv�

        bool operator == (const Chambre& chambre) const; //Surchages d'op�rateur pour comparer 2 chambres

        

    private:

        int _id;
        Type _type;
        double _prix;
        std::vector<Date::Date> _disponibilite; //Contient les numeros des jours o� la chambre est deja r�s�rv�e

    };

    //Surcharge d'op�rateur de sortie (ne peut pas etre une fonction membre et n'a pas besoin d'etre une fonction friend car on a des getters)
    std::ostream& operator << (std::ostream& os, const Chambre& chambre);   

} //namespace

#endif // CHAMBRE_H



