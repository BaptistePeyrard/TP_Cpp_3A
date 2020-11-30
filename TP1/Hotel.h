#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include <vector>
#include "Chambre.h"
#include "Client.h"

namespace Hotel {

    class Hotel {

    public:

        //Constructeurs (avec ou sans un vector de chambre)
        Hotel(std::string id, std::string nom, std::string ville);
        Hotel(std::string id, std::string nom, std::string ville, std::vector<Chambre::Chambre> liste_chambres);
        Hotel(std::string id, std::string nom, std::string ville, std::vector<Chambre::Chambre> liste_chambres, std::vector<Client::Client> liste_clients);
        //getters
        std::string get_id() const;
        std::string get_nom() const;
        std::string get_ville() const;
        std::vector<Chambre::Chambre>& get_liste_chambres();    //On envoie un type reference pour pouvoir modifier les chambres
        std::vector<Client::Client>& get_liste_clients();
        //ajout de chambres dans la variable membre _liste_chambres
        void ajouter_chambre(Chambre::Chambre& chambre);
        void ajouter_liste_chambres(std::vector<Chambre::Chambre> liste_chambres);
        //meme chose pour les clients
        void ajouter_client(Client::Client& client);
        void ajouter_liste_clients(std::vector<Client::Client> liste_clients);

    private:

        std::string _id;
        std::string _nom;
        std::string _ville;
        std::vector<Chambre::Chambre> _liste_chambres;
        std::vector<Client::Client> _liste_clients;


    };

    //Surcharge d'opérateur de sortie (ne peut pas etre une fonction membre et n'a pas besoin d'etre une fonction friend car on a des getters)
    std::ostream& operator << (std::ostream& os, const Hotel& hotel);

} //namespace

#endif // HOTEL_H

