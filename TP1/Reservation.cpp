#include "Reservation.h"

namespace Reservation {


	Reservation::Reservation(int id, Date::Date date_debut, Date::Date date_fin, Hotel::Hotel& hotel, Chambre::Chambre chambre, Client::Client client)	//On utilise une reference vers l'hotel car on va modifier une de ses variables membres
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

		_montant_original = (_date_fin - _date_debut)*chambre.get_prix();
		_montant_reel = _montant_original;
		
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

	int Reservation::get_id_hotel() const
	{
		return _id_hotel;
	}

	double Reservation::get_montant_original() const
	{
		return _montant_original;
	}

	double Reservation::get_montant_reel() const
	{
		return _montant_reel;
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
		if (date_debut < _date_fin) {

			for (int i = 0; i < _hotel->get_liste_chambres().size(); i++) {	//On doit changer la date de début dans la chambre
				if (_id_chambre == _hotel->get_liste_chambres().at(i).get_id()) {	//On retrouve la chambre dans l'hotel

					

						if (_date_debut < date_debut) {
							_hotel->get_liste_chambres().at(i).supprimer_jours_reservations(_date_debut, date_debut);	//On supprime les jours entre l'ancienne date debut et la nouvelle si la nouvelle est plus proche de la date de fin
							_date_debut = date_debut;
						}
						else if((date_debut < _date_debut ) && (_hotel->get_liste_chambres().at(i).Check_disponibilite(date_debut, _date_debut) == true)){
							_hotel->get_liste_chambres().at(i).ajouter_jours_reservations(date_debut, _date_debut);	//On ajoute des jours si la nouvelle date de debut est avant l'ancienne
							_date_debut = date_debut;
						}
				}
		
				
			}
		}
		else {
			std::cout << "Date non valide" << std::endl;
		}
		actualiser_montant();
	}

	void Reservation::set_date_fin(Date::Date date_fin)
	{
		if (_date_debut < date_fin) {

			for (int i = 0; i < _hotel->get_liste_chambres().size(); i++) {	//On doit changer la date de fin dans la chambre
				if (_id_chambre == _hotel->get_liste_chambres().at(i).get_id()) {	//On retrouve la chambre dans l'hotel

					

						if (date_fin < _date_fin) {	//Si la chambre est disponible pour la nouvelle date de fin
							_hotel->get_liste_chambres().at(i).supprimer_jours_reservations(date_fin, _date_fin);	//On supprime les jours si la nouvelle date de fin est avant l'ancienne
							_date_fin = date_fin;
						}
						else if((_date_fin < date_fin) && (_hotel->get_liste_chambres().at(i).Check_disponibilite(_date_fin, date_fin) == true)){	//Si la cambre est disponible pour la nouvelle date de fin
							_hotel->get_liste_chambres().at(i).ajouter_jours_reservations(_date_fin, date_fin);	//On ajoute des jours si la nouvelle date de fin est après l'ancienne
							_date_fin = date_fin;
						}

				}

			}

		}
		else {
			std::cout << "Date non valide" << std::endl;
		}
		actualiser_montant();
	}

	void Reservation::set_dates(Date::Date date_debut, Date::Date date_fin)
	{
		if (date_debut <= date_fin) {


			for (int i = 0; i < _hotel->get_liste_chambres().size(); i++) {	//On doit changer la date de fin dans la chambre
				if (_id_chambre == _hotel->get_liste_chambres().at(i).get_id()) {	//On retrouve la chambre dans l'hotel
					
					_hotel->get_liste_chambres().at(i).supprimer_jours_reservations(_date_debut, _date_fin);	//On supprime les anciennes disponibilités
					if (_hotel->get_liste_chambres().at(i).Check_disponibilite(date_debut, date_fin)) {	//Si la cambre est disponible pour les nouvelles dates
						_hotel->get_liste_chambres().at(i).ajouter_jours_reservations(date_debut, date_fin);	//On ajoute les nouvelles

						_date_debut = date_debut;
						_date_fin = date_fin;
					}
					else {
						_hotel->get_liste_chambres().at(i).ajouter_jours_reservations(_date_debut, _date_fin);	//On rétablie les anciennes dates
					}
				}
			}
		}
		actualiser_montant();
	}

	void Reservation::set_chambre(Chambre::Chambre chambre)	//On change l'id de la chambre mais aussi potentiellement son prix
	{

		//On doit changer la disponibilité de l'ancienne chambre et de la nouvelle chambre
		if (_hotel->get_liste_chambres().size() > 0) {

			for (int i = 0; i < _hotel->get_liste_chambres().size(); i++) {

				if ((chambre.get_id() == _hotel->get_liste_chambres().at(i).get_id()) && (_hotel->get_liste_chambres().at(i).Check_disponibilite(_date_debut, _date_fin))) {	//Si la nouvelle chambre est disponible

					for (int y = 0; y < _hotel->get_liste_chambres().size(); y++) {	//On reparcourt la liste des chambres pour annuler l'ancienne chambre et reserver la nouvelle

						if (_id_chambre == _hotel->get_liste_chambres().at(y).get_id()) {	//Ancienne chambre
							_hotel->get_liste_chambres().at(y).supprimer_jours_reservations(_date_debut, _date_fin);
						}
						else if (chambre.get_id() == _hotel->get_liste_chambres().at(i).get_id()) {	//Nouvelle chambre
							_hotel->get_liste_chambres().at(y).ajouter_jours_reservations(_date_debut, _date_fin);
						}
					}

					//On change l'id et le montant de la chambre dans les variables membres 
					_id_chambre = chambre.get_id();
				}
			}
		}

		actualiser_montant();
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

	void Reservation::actualiser_montant()
	{
		//Pour actualier la variable membre _montant lors d'un changment

		for (int i = 0; i < _hotel->get_liste_chambres().size(); i++) {
			if (_hotel->get_liste_chambres().at(i).get_id() == _id_chambre) {
				_montant_original = (_date_fin - _date_debut) * _hotel->get_liste_chambres().at(i).get_prix();
			}
		}
		
	}

	double Reservation::montant_total(int nbr_reservations_pour_remise)
	{;
		
		if (_nbr_reservations >= nbr_reservations_pour_remise) {
			double montant_reel = _montant_original - _montant_original*0.1;	//remise de 10%
			return montant_reel;
		}
		else {
			return _montant_original;
		}
	}

	double Reservation::montant_total(int nbr_reservations_pour_remise, double remise)
	{
		
		if (_nbr_reservations >= nbr_reservations_pour_remise) {
			double montant_reel = _montant_original - _montant_original *remise;
			return montant_reel;
		}
		else {
			return _montant_original;
		}
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

		//On doit changer le nombre de reservations de l'ancien client
		if (_hotel->get_liste_clients().size() > 0) {
			for (int i = 0; i < _hotel->get_liste_clients().size(); i++) {
				if (_id_client == _hotel->get_liste_clients().at(i).get_id()) {	//Ancien client
					int new_nbr_reservation = _hotel->get_liste_clients().at(i).get_nbr_reservations() - 1;	//On annule la reservation, donc on enleve une reservation au client
					_hotel->get_liste_clients().at(i).set_nbr_reservations(new_nbr_reservation);
				}
			}
		}
		
		delete _hotel;	//On detruit le pointeur

		//Une fois les données de l'hotel rétablies, on peut detruire la reservation
		Reservation::~Reservation();
		
	}

	Reservation::~Reservation()
	{
	}

	bool Reservation::operator==(const Reservation& reser) const
	{
		if (get_id() == reser.get_id()) {
			return true;
		}
		return false;
	}

	

	std::ostream& operator<<(std::ostream& os, const Reservation& reser)
	{
		std::string to_display;
		to_display = "Reservation numero " + std::to_string(reser.get_id()) + " , Client : id = " + std::to_string(reser.get_id_client()) + " du " + reser.get_date_debut().toString() + " au " + reser.get_date_fin().toString() + " chambre numero " + std::to_string(reser.get_id_chambre()) + " dans l'hotel numero " + std::to_string(reser.get_id_hotel()) + " Prix (sans reduction) : " + std::to_string(reser.get_montant_original()) + " $ ";
		os << to_display << std::endl;
		return os;
	}

}	//namespace
