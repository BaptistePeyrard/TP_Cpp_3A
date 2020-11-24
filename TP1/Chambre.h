#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>

enum class Type {Simple, Double, Suite};

namespace Chambre {

    class Chambre {
       
    public:

        Chambre(int id, Type type, int prix);
        int get_id() const;
        std::string get_type() const;
        int get_prix() const;
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



