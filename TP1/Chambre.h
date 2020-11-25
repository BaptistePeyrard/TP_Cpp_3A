#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>

enum class Type {Simple, Double, Suite};    //class enum contenant toutes les possibilités de type de chambre

namespace Chambre {

    class Chambre {
       
    public:

        Chambre(int id, Type type, int prix);
        //getters
        int get_id() const;
        //Type get_type() const;
        std::string get_type() const;
        int get_prix() const;
        //setters
        void set_id(int id);
        void set_type(Type type);
        void set_prix(int prix);


    private:

        int _id;
        Type _type;
        int _prix;


    };

} //namespace

#endif // CHAMBRE_H



