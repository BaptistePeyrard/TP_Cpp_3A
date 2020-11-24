#include "Chambre.h"

namespace Chambre {

	Chambre::Chambre::Chambre(int id, Type type, int prix) : _id(id), _type(type), _prix(prix)
	{
	}

	int Chambre::get_id() const
	{
		return _id;
	}

	std::string Chambre::get_type() const
	{
		
		std::string str_type;
		switch (_type)
		{
		case Type::Simple: str_type = "Simple" ;   break;
		case Type::Double: str_type = "Double"; break;
		case Type::Suite: str_type = "Suite";  break;
		}
		
		return str_type;
	}

	int Chambre::get_prix() const
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

	void Chambre::set_prix(int prix)
	{
		_prix = prix;
	}



}
