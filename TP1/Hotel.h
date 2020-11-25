#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include <vector>
#include <iostream>
#include "Chambre.h"

namespace Hotel {

    class Hotel {

    public:

        //Constructeurs (avec ou sans un vector de chambre)
        Hotel(std::string id, std::string nom, std::string ville);
        Hotel(std::string id, std::string nom, std::string ville, std::vector<Chambre::Chambre> liste_chambres);
        //getters
        std::string get_id() const;
        std::string get_nom() const;
        std::string get_ville() const;
        std::vector<Chambre::Chambre> get_liste_chambres() const;
        //ajout de chambres dans la variable membre _liste_chambres
        void ajouter_chambre(Chambre::Chambre chambre);
        void ajouter_liste_chambres(std::vector<Chambre::Chambre> liste_chambres);
        //ajouter une id de client
        void ajouter_client(int id_client);
        std::vector<int> get_liste_id() const;

    private:

        std::string _id;
        std::string _nom;
        std::string _ville;
        std::vector<Chambre::Chambre> _liste_chambres;

        //Pour appliquer le systeme de fidélité, on va ajouter un tableau avec les id des clients ayant deja réservé dans cet hotel
        std::vector<int> _liste_id;


    };

} //namespace

#endif // HOTEL_H

