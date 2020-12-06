#include "Chambre.h"

namespace Chambre {

	Chambre::Chambre::Chambre(int id, Type type, double prix) : _id(id), _type(type), _prix(prix)
	{
		std::vector<Date::Date> vector_vide;
		_disponibilite = vector_vide;
	}

	int Chambre::get_id() const
	{
		return _id;
	}

	std::vector<Date::Date> Chambre::get_disponibilite() const
	{
		return _disponibilite;
	}

	std::string Chambre::get_type() const	//On renvoie un string et non une valeur de l'enumeration
	{
		
		std::string str_type;
		switch (_type)
		{
		case Type::Simple: str_type = "simple" ; break;
		case Type::Double: str_type = "double"; break;
		case Type::Suite: str_type = "suite";  break;
		}
		
		return str_type;
	}

	double Chambre::get_prix() const
	{
		return _prix;
	}

	void Chambre::set_id(int id)
	{
		_id = id;
	}

	void Chambre::set_type(Type type)
	{
		_type = type;
	}

	void Chambre::set_prix(double prix)
	{
		_prix = prix;
	}

	void Chambre::ajouter_jours_reservations(Date::Date date_debut, Date::Date date_fin)
	{
		/*
		On va ajouter dans le vector disponibilite une liste de dates correspondants aux dates où la chambre est déjà résérvé)
		*/
		
		for (Date::Date i = date_debut; i < date_fin; i++) {
			_disponibilite.push_back(i);
		}


	}

	void Chambre::supprimer_jours_reservations(Date::Date date_debut, Date::Date date_fin)
	{
		if (_disponibilite.size() > 0) {

			for (Date::Date y = date_debut; y < date_fin; y++) {
				auto it = std::remove(_disponibilite.begin(), _disponibilite.end(), y);	//iterateur remove pour enlever les dates de reservation
				_disponibilite.erase(it, _disponibilite.end());	//enleve les cases en trop
			}
		}
	}

	bool Chambre::Check_disponibilite(Date::Date date_debut, Date::Date date_fin)
	{

		if (_disponibilite.size() > 0) {

			for (int i = 0; i < _disponibilite.size(); i++) {	//On parcourt le tableau
				
				for (Date::Date y = date_debut; y < date_fin; y++) {	//On parcourt tous les jours de la nouvelle résérvation
					
					if (_disponibilite.at(i) == y) {	//Si un jour de la nouvelle résérvation est deja dans le vector, alors il y a deja une reservation le jour là
						return false;
					}
					
				}
			}
			return true;	//Si aucun jour en commun n'a été trouvé, alors la chambre est libre pendant le temps de la nouvelle résérvation
		}
		else {
			return true;	//Si le vector est vide, la chambre n'est jamais résérvé, elle est donc disponible
		}

	}

	bool Chambre::operator==(const Chambre& chambre) const
	{
		if ((get_id() == chambre.get_id()) && (get_type() == chambre.get_type())) {
			return true;
		}
		return false;
	}


	//affichage de la sortie
	std::ostream& operator<<(std::ostream& os, const Chambre& chambre)
	{
		std::string to_display;
		to_display = "Chambre numero " + std::to_string(chambre.get_id()) + " de type : " + chambre.get_type() + " avec commme prix : " + std::to_string(chambre.get_prix()) + " $ / nuit";
		os << to_display << std::endl;
		return os;
	}
	
}
