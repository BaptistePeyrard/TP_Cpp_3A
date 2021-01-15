#include "pch.h"
#include "Magasin.h"
#include <iomanip>


Magasin::Magasin()
{
}

void Magasin::AddProduit(Produit& p)//Ajoute un produit au magasin
{
	Produit* pro = &p;
	m_produits.push_back(pro);
}

void Magasin::AddClient(Client& c)//Ajoute un client au magasin
{
	Client* cli = &c;
	m_clients.push_back(cli);
}

void Magasin::AfficherProduit(std::string name)//Affiche un produit (Donner le nom en entrer) //Pour tous ce projet, les affichages peuvent �tre mal fait dans les tableaux si on met des nom trop longs 
{
	Produit pp;
	bool found = false;
	for (Produit* p : m_produits)
	{
		 pp = *p;
		 if (pp.getTitre() == name)
		 {
			 // Cr�ation du tableau pour afficher le produit
			 for (int i = 0; i < 11; i++)std::cout << "------";
			 std::cout << std::endl << "|  D�tail du produit \t \t \t \t\t\t  |" << std::endl;     //Tous les \t sont pour cr�er l'affichage � l'�cran d'un tableau
			 std::cout << "|";
			 for (int i = 0; i < 13; i++)std::cout << "-----";
			 std::cout << "|" << std::endl;
			 //
			 std::cout << pp;
			 for (int i = 0; i < 11; i++)std::cout << "------";
			 found = true;
		 }	
	}
	if (!found)std::cout << "Ce produit n'existe pas.";
}


void Magasin::AfficherProduits()const // Affiche tous les produits
{
	//Affichage du tableau pour  afficher la liste des produits
	for (int i = 0; i < 11; i++)std::cout << "------";
	std::cout<< std::endl << "|  Produit \t \t \t \t\t\t\t  |"<< std::endl;
	std::cout << "|";
	for (int i = 0; i < 13; i++)std::cout << "-----";
	std::cout << "|"<<std::endl;
	std::cout << "|  Nom \t\t Description\t\t Quantit\x82 \t Prix\t  |"<< std::endl;
	std::cout << "|";
	for (int i = 0; i < 13; i++)std::cout << "-----";
	std::cout << "|" << std::endl;
	//

	for (Produit* p : m_produits)std::cout << *p;

	//
	for (int i = 0; i < 11; i++)std::cout << "------";
	std::cout << std::endl;
	//
	
}

void Magasin::AfficherClients() const // Affiche tous les clients 
{
	Client client;
	//Cr�ation du tableau pour  afficher la liste des clients
	for (int i = 0; i < 11; i++)std::cout << "------";
	std::cout << std::endl << "|  Clients \t \t \t \t\t\t\t  |" << std::endl;
	std::cout << "|";
	for (int i = 0; i < 13; i++)std::cout << "-----";
	std::cout << "|" << std::endl;
	std::cout << "|  Uid \t\t Prenom\tNom\t\t\t\t\t  |" << std::endl;
	std::cout << "|";
	for (int i = 0; i < 13; i++)std::cout << "-----";
	std::cout << "|" << std::endl;
	//
	for (Client* c : m_clients) {
		client = *c;
		std::cout << "|  "<< client.getId() << "\t\t" << client.getPrenom() << "\t" << client.getNom() << " \t\t\t\t  |" << std::endl;
	}

}

void Magasin::AfficherClient(std::string name) //Affiche un client(Donner son nom en entr�e)
{
	Client client;
	bool found = false;
	for (Client * c : m_clients) {
		client = *c;
		if (client.getNom() == name) {
			std::cout << client;
			found = true;
		}
	}
	if (!found)std::cout << "Ce client n'existe pas";
}

void Magasin::AfficherClient(int id)//Affiche un client(Donn�e son id en entr�e)
{
	Client client;
	bool found = false;
	for (Client* c : m_clients) {
		client = *c;
		if (client.getId() == id) {
			std::cout << client;
			found = true;
		}
	}
	if (!found)std::cout << "Il n'y a aucun client avec cet Id";
}

void Magasin::ValiderCommande(Commande& c)//Cr�er une commande et l'ajoute � la liste (Vide aussi le panier du client cibl�e)
{
	Commande* pc = &c;
	m_commandes.push_back(pc);
	c.getClient().clearPanier();
}

void Magasin::ChangerStatusCommande(Commande c) //Passe une comande non livr�e � livr�e (et inversement mais pas utilis�)
{
	c.ChangerStatus();
}

void Magasin::AfficherCommandes()//Affiche la liste des commandes
{
	for (Commande* c : m_commandes) {
		std::cout << *c << std::endl ;
	}
}

void Magasin::AfficherCommandesDe(Client c)//Affiche toutes les commandes d'un client (Donner ce client en entr�e)
{
	for (Commande* com : m_commandes) {
		Commande commande = *com;
		if(commande.getClient() == c)
		std::cout << commande << std::endl;
	}
}

std::vector<Client*> Magasin::getClients() const //Renvoie la liste de clients
{
	return m_clients;
}

std::vector<Produit*> Magasin::getProduits() const //Renvoie la liste de produits
{
	return m_produits;
}

std::vector<Commande*> Magasin::getCommandes() const //Renvoie la liste de commandes
{
	return m_commandes;
}


Magasin::~Magasin()
{
}
