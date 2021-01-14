#include "pch.h"
#include "Commande.h"


Commande::Commande(int id,Client client):_id(id),_client(client)
{
	_livr�e = false;
}


Commande::~Commande()
{
}

int Commande::getId() const
{
	return _id;
}

Client Commande::getClient() const
{
	return _client;
}

bool Commande::IsLivr�e() const
{
	return _livr�e;
}

void Commande::ChangerStatus()
{
	_livr�e = !_livr�e;
}

std::vector<Produit> Commande::getProduits() const
{
	return m_produits;
}

std::ostream & operator<<(std::ostream & os, const Commande & commande)
{
	std::string to_display;
	to_display = "Commande de : " + commande.getClient().getPrenom() + " " + commande.getClient().getNom() + "\n Liste des produits de la commande : ";
	for (Produit p : commande.getProduits())to_display += p.getTitre() + "\n";
	if (commande.IsLivr�e())to_display += "Cette commande a ete livree";
	else to_display += "Cette commande n'a pas encore ete livree";
	os << to_display << std::endl;
	return os;


}
