#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include <vector>
#include "Chambre.h"
#include "Client.h"

namespace Hotel {

    class Hotel {

    public:

        //Constructeurs (avec ou sans un vector de chambre et de client)
        Hotel(int id, std::string nom, std::string ville);
        Hotel(int id, std::string nom, std::string ville, std::vector<Chambre::Chambre> liste_chambres);
        Hotel(int id, std::string nom, std::string ville, std::vector<Chambre::Chambre> liste_chambres, std::vector<Client::Client> liste_clients);
        //getters
        int get_id() const;
        std::string get_nom() const;
        std::string get_ville() const;
        std::vector<Chambre::Chambre>& get_liste_chambres();    //On envoie un type reference pour pouvoir modifier les chambres
        std::vector<Client::Client>& get_liste_clients();
        //setter
        void set_nom(std::string nom);
        //ajout de chambres dans la variable membre _liste_chambres
        void ajouter_chambre(Chambre::Chambre& chambre);
        void ajouter_liste_chambres(std::vector<Chambre::Chambre> liste_chambres);
        void supprimer_chambre(Chambre::Chambre& chambre);
        //meme chose pour les clients
        void ajouter_client(Client::Client& client);
        void ajouter_liste_clients(std::vector<Client::Client> liste_clients);
        void supprimer_client(Client::Client& client); // ! Le client perdera ses reservation precedantes

    private:

        int _id;
        std::string _nom;
        std::string _ville;
        std::vector<Chambre::Chambre> _liste_chambres;
        std::vector<Client::Client> _liste_clients;
      


    };

    //Surcharge d'opérateur de sortie (ne peut pas etre une fonction membre et n'a pas besoin d'etre une fonction friend car on a des getters)
    std::ostream& operator << (std::ostream& os, const Hotel& hotel);

} //namespace

#endif // HOTEL_H

