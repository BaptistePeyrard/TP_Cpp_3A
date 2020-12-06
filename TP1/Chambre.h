#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>
#include <vector>
#include <iostream>
#include "Date.h"

enum class Type {Simple, Double, Suite};    //class enum contenant toutes les possibilités de type de chambre

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
        void ajouter_jours_reservations(Date::Date date_debut, Date::Date date_fin);    //Ajouter des jours résérvés
        void supprimer_jours_reservations(Date::Date date_debut, Date::Date date_fin);    //Supprimer des jours résérvés
        bool Check_disponibilite(Date::Date date_debut, Date::Date date_fin);   //Vérifier si un jour est déjà résérvé

        bool operator == (const Chambre& chambre) const; //Surchages d'opérateur pour comparer 2 chambres

        

    private:

        int _id;
        Type _type;
        double _prix;
        std::vector<Date::Date> _disponibilite; //Contient les numeros des jours où la chambre est deja résérvée

    };

    //Surcharge d'opérateur de sortie (ne peut pas etre une fonction membre et n'a pas besoin d'etre une fonction friend car on a des getters)
    std::ostream& operator << (std::ostream& os, const Chambre& chambre);   

} //namespace

#endif // CHAMBRE_H



