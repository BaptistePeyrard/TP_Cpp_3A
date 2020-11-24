#include "Reservation.h"

namespace Reservation {


	Reservation::Reservation(int id, Date::Date date_debut, Date::Date date_fin, std::string id_hotel, int id_chambre, int id_client)
	{
		_id = id;
		_date_debut = date_debut;
		_date_fin = date_fin;
		_id_hotel = id_hotel;
		_id_chambre = id_chambre;
		_id_client = id_client;




	}

}	//namespace
