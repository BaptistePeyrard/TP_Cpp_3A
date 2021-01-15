#include "pch.h"
#include "Produit.h"


Produit::Produit(int id,std::string titre, std::string desc, int dispo, float prix): _id(id), _titre(titre), _description(desc), _qttDispo(dispo), _prix(prix)
{
}


Produit::~Produit()
{
}

int Produit::getId() const//Renvoie l'id du produit
{
	return _id;
}

std::string Produit::getTitre() const//Renvoie le titre(nom) du produit
{
	return _titre;
}

std::string Produit::getDescription()const//Renvoie la description du produit
{
	return _description;
}

int Produit::getQqtDispo()const //Renvoie la quandit� disponible de ce produit
{
	return _qttDispo;
}

float Produit::getPrix()const // Renvoie le prix de ce produit
{
	return _prix;
}

void Produit::setQqtDispo(int dispo)//Permet de modifier la quantit� disponible de ce produit
{
	_qttDispo = dispo;
}

bool Produit::operator==(const Produit & p) const //Pour comparer 2 produits (Ils sont les m�mes si m�me Id et titre)
{
	if ((getId() == p.getId()) && (getTitre() == p.getTitre())) {
		return true;
	}
	else {
		return false;
	}
}


std::ostream& operator<<(std::ostream& os, const Produit& produit)//Pour afficher � l'�cran les infos d'un produit
{
	if (produit.getTitre().length() > 4) {
		if (produit.getDescription().length() > 23)
			os << "|  " << produit.getTitre() << "\t" << produit.getDescription() << "\t" << produit.getQqtDispo() << "\t" << produit.getPrix() << "\t  |" << std::endl;
		else
			os << "|  " << produit.getTitre() << "\t" << produit.getDescription() << "\t\t" << produit.getQqtDispo() << "\t" << produit.getPrix() << "\t  |" << std::endl;
	}					//Ici il y a plusieurs "choix" juste pour cr�er un bel affichage des produits et �viter que les prix d�bordent du tableau
	else {
		if (produit.getDescription().length() > 23)
			os << "|  " << produit.getTitre() << "\t\t" << produit.getDescription() << "\t" << produit.getQqtDispo() << "\t" << produit.getPrix() << "\t  |" << std::endl;
		else
			os << "|  " << produit.getTitre() << "\t\t" << produit.getDescription() << "\t\t" << produit.getQqtDispo() << "\t" << produit.getPrix() << "\t  |" << std::endl;
	}
	return os;
}

