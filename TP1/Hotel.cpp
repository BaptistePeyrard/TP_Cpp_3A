#include "Hotel.h"

namespace Hotel {




	Hotel::Hotel(std::string id, std::string nom, std::string ville)
	{
		_id = id;
		_nom = nom;
		_ville = ville;
		std::vector<Chambre::Chambre> vector_vide;
		_liste_chambres = vector_vide;
	}

	Hotel::Hotel(std::string id, std::string nom, std::string ville, std::vector<Chambre::Chambre> liste_chambres) : _id(id), _nom(nom), _ville(ville), _liste_chambres(liste_chambres)
	{
	}

	std::string Hotel::get_id() const
	{
		return _id;
	}

	std::string Hotel::get_nom() const
	{
		return _nom;
	}

	std::string Hotel::get_ville() const
	{
		return _ville;
	}

	std::vector<Chambre::Chambre> Hotel::get_liste_chambres() const
	{
		return _liste_chambres;
	}

	void Hotel::ajouter_chambre(Chambre::Chambre chambre)
	{
		_liste_chambres.push_back(chambre);
	}

	void Hotel::ajouter_liste_chambres(std::vector<Chambre::Chambre> liste_chambres)
	{
		if (liste_chambres.size() == 0) {
			std::cout << "L'ajout n'a pas pu etre effectue (ajout d'un tableau nul)" << std::endl;
		}
		else {
			for (int i = 0; i < liste_chambres.size(); i++) {	//On parcourt le tableau et on ajoute 1 à 1 les chambres
				ajouter_chambre(liste_chambres.at(i));
			}
		}

	}

	void Hotel::ajouter_client(int id_client)
	{
		_liste_id.push_back(id_client);
	}

	std::vector<int> Hotel::get_liste_id() const
	{
		return _liste_id;
	}

	

}
