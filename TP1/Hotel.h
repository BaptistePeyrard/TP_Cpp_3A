#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include <vector>
#include <iostream>
#include "Chambre.h"

namespace Hotel {

    class Hotel {

    public:

        Hotel(std::string id, std::string nom, std::string ville);
        Hotel(std::string id, std::string nom, std::string ville, std::vector<Chambre::Chambre> liste_chambres);
        std::string get_id() const;
        std::string get_nom() const;
        std::string get_ville() const;
        std::vector<Chambre::Chambre> get_liste_chambres() const;
        void ajouter_chambre(Chambre::Chambre chambre);
        void ajouter_liste_chambres(std::vector<Chambre::Chambre> liste_chambres);

    private:

        std::string _id;
        std::string _nom;
        std::string _ville;
        std::vector<Chambre::Chambre> _liste_chambres;


    };

} //namespace

#endif // HOTEL_H

