#include "Reservation.h"

namespace Reservation {


	Reservation::Reservation(int id, Date::Date date_debut, Date::Date date_fin, Hotel::Hotel& hotel, Chambre::Chambre chambre, Client::Client client)	//On utilise un pointeur vers l'hotel car on va modifier une de ses variables membres
	{

		_id = id;
		_id_hotel = hotel.get_id();
		_id_chambre = chambre.get_id();
		_id_client = client.get_id();

		if (date_debut <= date_fin) {

			_date_debut = date_debut;
			_date_fin = date_fin;

		}
		else {

			_date_debut = date_fin;
			_date_fin = date_debut;

		}

		_montant = (_date_fin - _date_debut)*chambre.get_prix();
		
		//On recherche le nombre de fois que le client a déjà réservé dans cet hotel
		_nbr_reservations = 0;
		if (hotel.get_liste_id().size() != 0) {
			for (int i = 0; i < hotel.get_liste_id().size(); i++) {
				if (hotel.get_liste_id().at(i) == client.get_id()) {
					_nbr_reservations++;
				}
			}
		}

		

		//Une fois le nombre de réservation récupéré, on ajoute l'id du client dans la liste de l'hotel pour la prochaine réservation
		hotel.ajouter_client(client.get_id());
		

	}

	int Reservation::get_id() const
	{
		return _id;
	}

	int Reservation::get_id_chambre() const
	{
		return _id_chambre;
	}

	int Reservation::get_id_client() const
	{
		return _id_client;
	}

	std::string Reservation::get_id_hotel() const
	{
		return _id_hotel;
	}

	int Reservation::get_montant() const
	{
		return _montant;
	}

	Date::Date Reservation::get_date_debut() const
	{
		return _date_debut;
	}

	Date::Date Reservation::get_date_fin() const
	{
		return _date_fin;
	}

	void Reservation::set_date_debut(Date::Date date_debut)
	{
		if (date_debut <= _date_fin) {
			_date_debut = date_debut;
		}
	}

	void Reservation::set_date_fin(Date::Date date_fin)
	{
		if (_date_debut <= date_fin) {
			_date_fin = date_fin;
		}
	}

	void Reservation::set_dates(Date::Date date_debut, Date::Date date_fin)
	{
		if (date_debut <= date_fin) {
			_date_debut = date_debut;
			_date_fin = date_fin;
		}
	}

	void Reservation::set_chambre(Chambre::Chambre chambre)	//On change l'id de la chambre mais aussi potentiellement son prix
	{
		_id_chambre = chambre.get_id();
		_montant = (_date_fin - _date_debut) * chambre.get_prix();
	}

	double Reservation::montant_total(int nbr_reservations_pour_remise)
	{
		double total = _montant;
		if (_nbr_reservations >= nbr_reservations_pour_remise) {
			total = _montant - _montant*0.1;	//remise de 10%
			
		}
		
		return total;
	}

	double Reservation::montant_total(int nbr_reservations_pour_remise, double remise)
	{
		double total = _montant;
		if (_nbr_reservations >= nbr_reservations_pour_remise) {
			total = _montant - _montant*remise;

		}
		return total;
	}

}	//namespace
