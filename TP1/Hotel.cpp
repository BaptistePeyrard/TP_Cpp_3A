#include "Hotel.h"

namespace Hotel {



	
	Hotel::Hotel(int id, std::string nom, std::string ville) : _id(id), _nom(nom), _ville(ville)
	{
	}
	
	Hotel::Hotel(int id, std::string nom, std::string ville, std::vector<Chambre::Chambre> liste_chambres) : _id(id), _nom(nom), _ville(ville), _liste_chambres(liste_chambres)
	{
	}

	Hotel::Hotel(int id, std::string nom, std::string ville, std::vector<Chambre::Chambre> liste_chambres, std::vector<Client::Client> liste_clients) : _id(id), _nom(nom), _ville(ville), _liste_chambres(liste_chambres), _liste_clients(liste_clients)
	{
	}

	int Hotel::get_id() const
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
	
	std::vector<Chambre::Chambre>& Hotel::get_liste_chambres()	//Pour changer la disponibilité des chambres
	{
		return _liste_chambres;
	}

	std::vector<Client::Client>& Hotel::get_liste_clients()		//Pour changer le nombre de résérvations
	{
		return _liste_clients;
	}

	void Hotel::set_nom(std::string nom)
	{
		_nom = nom;
	}
	
	void Hotel::ajouter_chambre(Chambre::Chambre& chambre)
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

	void Hotel::supprimer_chambre(Chambre::Chambre& chambre)
	{
		
		if (_liste_chambres.size() > 0) {

			auto it = std::remove(_liste_chambres.begin(), _liste_chambres.end(), chambre);	//iterateur remove pour enlever la chambre
			_liste_chambres.erase(it, _liste_chambres.end());	//enleve les cases en trop
			
		}
		
	}

	void Hotel::ajouter_client(Client::Client& client)
	{
		_liste_clients.push_back(client);
	}

	void Hotel::ajouter_liste_clients(std::vector<Client::Client> liste_clients)
	{
		if (liste_clients.size() == 0) {
			std::cout << "L'ajout n'a pas pu etre effectue (ajout d'un tableau nul)" << std::endl;
		}
		else {
			for (int i = 0; i < liste_clients.size(); i++) {	//On parcourt le tableau et on ajoute 1 à 1 les clients
				ajouter_client(liste_clients.at(i));
			}
		}
	}

	void Hotel::supprimer_client(Client::Client& client)
	{
		if (_liste_clients.size() > 0) {

			auto it = std::remove(_liste_clients.begin(), _liste_clients.end(), client);	//iterateur remove pour enlever le client
			_liste_clients.erase(it, _liste_clients.end());	//enleve les cases en trop

		}
	}


	
	//affichage de la sortie
	std::ostream& operator<<(std::ostream& os, Hotel& hotel)
	{
		std::string to_display;
		to_display = "Cet Hotel est le " + hotel.get_nom() + " situe a : " + hotel.get_ville() + " avec " + std::to_string(hotel.get_liste_chambres().size()) + " chambres";
		os << to_display << std::endl;
		return os;
	}

}
