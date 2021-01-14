#include "pch.h"
#include "Client.h"



Client::Client(int id, std::string prenom, std::string nom):_id(id),_prenom(prenom),_nom(nom)
{
}

Client::~Client()
{
}

int Client::getId() const
{
	return _id;
}

std::string Client::getPrenom() const
{
	return _prenom;
}

std::string Client::getNom() const
{
	return _nom;
}

std::vector<Produit> Client::getPanier() const
{
	return m_panier;
}

void Client::addProduit(Produit p)
{
	m_panier.push_back(p);
	modifyQqtProduit(p);
}

void Client::clearPanier()
{
	m_panier.clear();
}

void Client::modifyQqtProduit(Produit p) const
{
	p.setQqtDispo(p.getQqtDispo() - 1);
}

void Client::delProduit(Produit p)
{
	auto it = std::remove(m_panier.begin(), m_panier.end(), p);
	m_panier.erase(it, m_panier.end());
	
	p.setQqtDispo(p.getQqtDispo() + 1);
}

bool Client::operator==(const Client & c) const
{
	return (_id == c.getId() && _prenom == c.getPrenom() && _nom == c.getNom());
}

std::ostream & operator<<(std::ostream & os, const Client & client)
{
	
	std::string to_display;
	to_display = "Client : " + client.getPrenom() + " " + client.getNom() + "\n"+"Panier du client : ";
	for (Produit p : client.getPanier())to_display += p.getTitre() + "\n";

	os << to_display << std::endl;
	return os;
}
