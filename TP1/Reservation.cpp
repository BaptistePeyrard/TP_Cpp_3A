#include "Reservation.h"

namespace Reservation {


	Reservation::Reservation(int id, Date::Date date_debut, Date::Date date_fin, Hotel::Hotel& hotel, Chambre::Chambre chambre, Client::Client client)	//On utilise un pointeur vers l'hotel car on va modifier une de ses variables membres
	{
		bool status = Check_validite_reservation(date_debut, date_fin, hotel, chambre);	//On verifie que la reservation est possible (Dates et Disponibilité)
		assert(status == true && "Reservation non valide");


		_id = id;
		_id_hotel = hotel.get_id();
		_id_chambre = chambre.get_id();
		_id_client = client.get_id();
		_date_debut = date_debut;	//Dates vérifiées
		_date_fin = date_fin;
		_nom_client = client.get_nom();
		_hotel = &hotel;

		_montant = (_date_fin - _date_debut)*chambre.get_prix();
		
		int verif = 0;	//variable pour verifier si le client n'est pas deja dans la liste des clients de l'hotel
		_nbr_reservations = 0;
		if (hotel.get_liste_clients().size() != 0) {
			for (int i = 0; i < hotel.get_liste_clients().size(); i++) {
				if (hotel.get_liste_clients().at(i).get_id() == _id_client) {	//Si le client existait deja
					_nbr_reservations = hotel.get_liste_clients().at(i).get_nbr_reservations();	//On recupere le nombre de reservations
					hotel.get_liste_clients().at(i).set_nbr_reservations(_nbr_reservations+1);	//On ajoute 1 au nombre de résérvation
					verif++;	//Le client est deja inscrit
				}
			}
		}

		if (verif == 0) {	//Le client est un nouveau client de l'hotel
			hotel.ajouter_client(client);	//On ajoute le client
			for (int i = 0; i < hotel.get_liste_clients().size(); i++) {
				if (hotel.get_liste_clients().at(i).get_id() == _id_client) {
					hotel.get_liste_clients().at(i).set_nbr_reservations(_nbr_reservations + 1);	//On ajoute 1 au nombre de résérvation (ici c'est la premiere reservation)
				}
			}
		}


		for (int i = 0; i < hotel.get_liste_chambres().size(); i++) {
			if (hotel.get_liste_chambres().at(i).get_id() == chambre.get_id()) {	//On retrouve la chambre
				hotel.get_liste_chambres().at(i).ajouter_jours_reservations(date_debut, date_fin);	//On ajoute les dates de la reservations dans la chambre

			}

		}
	
	}

	bool Reservation::Check_validite_reservation(Date::Date date_debut, Date::Date date_fin, Hotel::Hotel& hotel, Chambre::Chambre chambre)
	{
		bool status = true;

		if (date_fin <= date_debut) {	//Si les dates ne sont pas réspéctées
			status = false;
		}
		

		for (int i = 0; i < hotel.get_liste_chambres().size(); i++) {
			if (hotel.get_liste_chambres().at(i).get_id() == chambre.get_id()) {	//On retrouve la chambre
				if (hotel.get_liste_chambres().at(i).Check_disponibilite(date_debut, date_fin) == false) {	//Si la chambre n'est pas disponible
					status = false;
				}
				
			}

		}



		return status;
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

	std::string Reservation::get_nom_client() const
	{
		return _nom_client;
	}

	Hotel::Hotel Reservation::get_hotel()
	{
		return *_hotel;
	}

	void Reservation::set_date_debut(Date::Date date_debut)
	{
		if (date_debut <= _date_fin) {
			_date_debut = date_debut;
		}
		else {
			std::cout << "Date non valide" << std::endl;
		}
	}

	void Reservation::set_date_fin(Date::Date date_fin)
	{
		if (_date_debut <= date_fin) {
			_date_fin = date_fin;
		}
		else {
			std::cout << "Date non valide" << std::endl;
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

		//On doit changer la disponibilité de l'ancienne chambre et de la nouvelle chambre
		if (_hotel->get_liste_chambres().size() > 0) {
			for (int i = 0; i < _hotel->get_liste_chambres().size(); i++) {
				if (_id_chambre == _hotel->get_liste_chambres().at(i).get_id()) {	//Ancienne chambre
					_hotel->get_liste_chambres().at(i).supprimer_jours_reservations(_date_debut, _date_fin);
				}
				else if (chambre.get_id() == _hotel->get_liste_chambres().at(i).get_id()) {	//Nouvelle chambre
					_hotel->get_liste_chambres().at(i).ajouter_jours_reservations(_date_debut, _date_fin);
				}
			}
		}

		//On change l'id et le montant de la chambre dans les variables membres 
		_id_chambre = chambre.get_id();
		_montant = (_date_fin - _date_debut) * chambre.get_prix();
	}

	void Reservation::set_client(Client::Client client)
	{

		//On doit changer le nombre de reservations de l'ancien client et du nouveau client
		if (_hotel->get_liste_clients().size() > 0) {
			for (int i = 0; i < _hotel->get_liste_clients().size(); i++) {
				if (_id_client == _hotel->get_liste_clients().at(i).get_id()) {	//Ancien client
					_hotel->get_liste_clients().at(i).set_nbr_reservations(_nbr_reservations - 1);
				}
				else if (client.get_id() == _hotel->get_liste_clients().at(i).get_id()) {	//Nouveau client
					_nbr_reservations = _hotel->get_liste_clients().at(i).get_nbr_reservations();
					_hotel->get_liste_clients().at(i).set_nbr_reservations(_nbr_reservations + 1);
				}
			}
		}

		_id_client = client.get_id();

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

	void Reservation::Annuler()
	{
		//Quand on annule une reservation, il faut annuler les dates de reservations pour la chambre et enlever une reservation pour le client


		//On doit changer la disponibilité de l'ancienne chambre
		if (_hotel->get_liste_chambres().size() > 0) {
			for (int i = 0; i < _hotel->get_liste_chambres().size(); i++) {
				if (_id_chambre == _hotel->get_liste_chambres().at(i).get_id()) {	//Ancienne chambre
					_hotel->get_liste_chambres().at(i).supprimer_jours_reservations(_date_debut, _date_fin);	//On enleve les dates résérvées
				}
			}
		}

		//On doit changer le nombre de reservations de l'ancien client et du nouveau client
		if (_hotel->get_liste_clients().size() > 0) {
			for (int i = 0; i < _hotel->get_liste_clients().size(); i++) {
				if (_id_client == _hotel->get_liste_clients().at(i).get_id()) {	//Ancien client
					int new_nbr_reservation = _hotel->get_liste_clients().at(i).get_nbr_reservations() - 1;	//On annule la reservation, donc on enleve une reservation au client
					_hotel->get_liste_clients().at(i).set_nbr_reservations(new_nbr_reservation);
				}
			}
		}
		
		//Une fois les données de l'hotel rétablies, on peut detruire la reservation
		Reservation::~Reservation();
		
	}

	Reservation::~Reservation()
	{
	}

	

}	//namespace
