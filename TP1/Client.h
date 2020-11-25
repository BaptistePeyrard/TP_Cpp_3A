#ifndef CLIENT_H
#define CLIENT_H
#include <string>


namespace Client {

    class Client {
    public:
        
        //Constructeur
        Client(int id, std::string nom, std::string prenom);
        //getters
        int get_id() const;
        std::string get_nom() const;
        std::string get_prenom() const;
        int get_nbr_reservations() const;
        //setters
        void set_id(int id);
        void set_nom(std::string nom);
        void set_prenom(std::string prenom);
        void set_nbr_reservations(int nbr_reservations);
        


    private:

        int _id;
        std::string _nom;
        std::string _prenom;
        int _nbr_reservations;

       
    };

} //namespace

#endif // CLIENT_H

