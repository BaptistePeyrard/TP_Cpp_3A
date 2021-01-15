#include "pch.h"
#include "Commande.h"

Commande::Commande(int id,Client client):_id(id),_client(client)
{
	m_produits = _client.getPanier();
	_livr�e = false;
}


Commande::~Commande()
{
}

int Commande::getId() const//Renvoie l'id de la commande
{
	return _id;
}

Client Commande::getClient() const//Renvoie le client concern� par cette commande
{
	return _client;
}

bool Commande::IsLivree() const//Indique si la commande est livr�e ou non (true = livr�e, false = non livr�e)
{
	return _livr�e;
}

void Commande::ChangerStatus()//Change le statusde la commande(elle devient livr�e elle ne l'est pas et inversement mais non utilis�)
{
	_livr�e = !_livr�e;
}

std::vector<Produit> Commande::getProduits() const//Revoie la liste de produit de cette commande
{
	return m_produits;
}

std::ostream & operator<<(std::ostream & os, const Commande & commande)//Permet d'afficher � l'�cran les infos de cette commande
{
	std::string to_display;
	to_display = "Commande de : " + commande.getClient().getPrenom() + " " + commande.getClient().getNom() + "\n Liste des produits de la commande : ";
	for (Produit p : commande.getProduits())to_display += p.getTitre() + "\n";
	if (commande.IsLivree())to_display += "Cette commande a ete livree";
	else to_display += "Cette commande n'a pas encore ete livree";
	os << to_display << std::endl;
	return os;


}
