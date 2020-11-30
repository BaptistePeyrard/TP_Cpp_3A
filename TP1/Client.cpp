#include "Client.h"

namespace Client {

	Client::Client(int id, std::string nom, std::string prenom) : _id(id), _nom(nom), _prenom(prenom), _nbr_reservations(0)
	{
	}

	int Client::get_id() const
	{
		return _id;
	}

	std::string Client::get_nom() const
	{
		return _nom;
	}

	std::string Client::get_prenom() const
	{
		return _prenom;
	}

	int Client::get_nbr_reservations() const
	{
		return _nbr_reservations;
	}

	void Client::set_id(int id)
	{
		_id = id;
	}

	void Client::set_nom(std::string nom)
	{
		_nom = nom;
	}

	void Client::set_prenom(std::string prenom)
	{
		_prenom = prenom;
	}

	void Client::set_nbr_reservations(int nbr_reservations)
	{
		_nbr_reservations = nbr_reservations;
	}


	std::ostream& operator<<(std::ostream& os, const Client& client)
	{
		std::string to_display;
		to_display = "Ce client est " + client.get_nom() + " " + client.get_prenom();
		os << to_display << std::endl;
		return os;
	}

}//namespace