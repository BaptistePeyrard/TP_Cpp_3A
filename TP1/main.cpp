#include <iostream>
#include <vector>
#include "Date.h"
#include "Chambre.h"
#include "Hotel.h"

int main() {

	Chambre::Chambre chambre1(1, Type::Simple, 180);
	Chambre::Chambre chambre2(2, Type::Double, 750);
	Chambre::Chambre chambre3(3, Type::Simple, 180);
	Chambre::Chambre chambre4(4, Type::Suite, 1800);
	std::vector <Chambre::Chambre> liste;
	liste.push_back(chambre2);
	liste.push_back(chambre3);
	liste.push_back(chambre4);

	Hotel::Hotel hotel1("hotel_1", "THE hotel", "Ablain-Saint-Nazaire");
	hotel1.ajouter_chambre(chambre1);
	hotel1.ajouter_liste_chambres(liste);
	std::cout << hotel1.get_liste_chambres().size() << std::endl;
	std::cout << hotel1.get_liste_chambres().at(0).get_prix() << std::endl;
	std::cout << hotel1.get_liste_chambres().at(1).get_prix() << std::endl;
	std::cout << hotel1.get_liste_chambres().at(2).get_prix() << std::endl;
	std::cout << hotel1.get_liste_chambres().at(3).get_prix() << std::endl;

	return 0;

}