#include "pch.h"
#include "Client.h"
#include <iostream>



Client::Client(int id, std::string prenom, std::string nom):_id(id),_prenom(prenom),_nom(nom)
{
}

Client::~Client()
{
}

int Client::getId() const //Renvoie l'id du client
{
	return _id;
}

std::string Client::getPrenom() const //Renvoie le prenom du client
{
	return _prenom;
}

std::string Client::getNom() const //Renvoie le nom du client
{
	return _nom;
}

std::vector<Produit> Client::getPanier() const //Renvoie le panier du client (la liste des produits dans son panier*)
{
	return m_panier;
}

void Client::addProduit(Produit p)//Ajoute un produit au panier du client (Donner ce produit en entrée)
{
	m_panier.push_back(p);
	modifyQqtProduit(p);
}

void Client::clearPanier()//Vide le panier du client(Utilisé quand on valide une commande)
{
	m_panier.clear();
}

void Client::modifyQqtProduit(Produit p) const //Diminue de 1 la qtt d'un produit (quand l'utilisateuren ajoute un à son panier)
{
	p.setQqtDispo(p.getQqtDispo() - 1);
}

void Client::delProduit(Produit p)//Retire un produit du panier du client
{
	auto it = std::remove(m_panier.begin(), m_panier.end(), p);
	m_panier.erase(it, m_panier.end());
	
	p.setQqtDispo(p.getQqtDispo() + 1);
}

bool Client::operator==(const Client & c) const //Permet de comparer 2 clients (Ils sont les mêmes si même id,nom,prenom)
{
	return (_id == c.getId() && _prenom == c.getPrenom() && _nom == c.getNom());
}

std::ostream & operator<<(std::ostream & os, const Client & client)//Pour afficher à l'écran les infos d'un client
{
	
	std::string to_display;
	to_display = "Client : " + client.getPrenom() + " " + client.getNom() + "\n"+"Panier du client : ";
	for (Produit p : client.getPanier())to_display += p.getTitre() + "\n";

	os << to_display << std::endl;
	return os;
}
