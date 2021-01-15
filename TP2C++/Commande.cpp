#include "pch.h"
#include "Commande.h"

Commande::Commande(int id,Client client):_id(id),_client(client)
{
	m_produits = _client.getPanier();
	_livrée = false;
}


Commande::~Commande()
{
}

int Commande::getId() const//Renvoie l'id de la commande
{
	return _id;
}

Client Commande::getClient() const//Renvoie le client concerné par cette commande
{
	return _client;
}

bool Commande::IsLivree() const//Indique si la commande est livrée ou non (true = livrée, false = non livrée)
{
	return _livrée;
}

void Commande::ChangerStatus()//Change le statusde la commande(elle devient livrée elle ne l'est pas et inversement mais non utilisé)
{
	_livrée = !_livrée;
}

std::vector<Produit> Commande::getProduits() const//Revoie la liste de produit de cette commande
{
	return m_produits;
}

std::ostream & operator<<(std::ostream & os, const Commande & commande)//Permet d'afficher à l'écran les infos de cette commande
{
	std::string to_display;
	to_display = "Commande de : " + commande.getClient().getPrenom() + " " + commande.getClient().getNom() + "\n Liste des produits de la commande : ";
	for (Produit p : commande.getProduits())to_display += p.getTitre() + "\n";
	if (commande.IsLivree())to_display += "Cette commande a ete livree";
	else to_display += "Cette commande n'a pas encore ete livree";
	os << to_display << std::endl;
	return os;


}
