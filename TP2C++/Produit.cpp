#include "pch.h"
#include "Produit.h"


Produit::Produit(int id,std::string titre, std::string desc, int dispo, float prix): _id(id), _titre(titre), _description(desc), _qttDispo(dispo), _prix(prix)
{
}


Produit::~Produit()
{
}

int Produit::getId() const
{
	return _id;
}

std::string Produit::getTitre() const
{
	return _titre;
}

std::string Produit::getDescription()const
{
	return _description;
}

int Produit::getQqtDispo()const
{
	return _qttDispo;
}

float Produit::getPrix()const
{
	return _prix;
}

void Produit::setQqtDispo(int dispo)
{
	_qttDispo = dispo;
}

bool Produit::operator==(const Produit & p) const
{
	if ((getId() == p.getId()) && (getTitre() == p.getTitre())) {
		return true;
	}
	else {
		return false;
	}
}


std::ostream& operator<<(std::ostream& os, const Produit& produit)
{
	if (produit.getTitre().length() > 4) {
		if (produit.getDescription().length() > 23)
			os << "|  " << produit.getTitre() << "\t" << produit.getDescription() << "\t" << produit.getQqtDispo() << "\t" << produit.getPrix() << "\t  |" << std::endl;
		else
			os << "|  " << produit.getTitre() << "\t" << produit.getDescription() << "\t\t" << produit.getQqtDispo() << "\t" << produit.getPrix() << "\t  |" << std::endl;
	}					//Ici il y a plusieurs "choix" juste pour créer un bel affichage des produits et éviter que les prix débordent du tableau
	else {
		if (produit.getDescription().length() > 23)
			os << "|  " << produit.getTitre() << "\t\t" << produit.getDescription() << "\t" << produit.getQqtDispo() << "\t" << produit.getPrix() << "\t  |" << std::endl;
		else
			os << "|  " << produit.getTitre() << "\t\t" << produit.getDescription() << "\t\t" << produit.getQqtDispo() << "\t" << produit.getPrix() << "\t  |" << std::endl;
	}
	return os;
}

