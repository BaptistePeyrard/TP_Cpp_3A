#include "pch.h"
#include "Magasin.h"
#include <iomanip>


Magasin::Magasin()
{
}

void Magasin::AddProduit(Produit& p)
{
	Produit* pro = &p;
	m_produits.push_back(pro);
}

void Magasin::AddClient(Client& c)
{
	Client* cli = &c;
	m_clients.push_back(cli);
}

void Magasin::AfficherProduit(std::string name)
{
	Produit pp;
	bool found = false;
	for (Produit* p : m_produits)
	{
		 pp = *p;
		 if (pp.getTitre() == name)
		 {
			 // Création du tableau pour afficher le produit
			 for (int i = 0; i < 11; i++)std::cout << "------";
			 std::cout << std::endl << "|  Détail du produit \t \t \t \t\t\t  |" << std::endl;     //Tous les \t sont pour créer l'affichage à l'écran d'un tableau
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


void Magasin::AfficherProduits()const
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

void Magasin::AfficherClients() const
{
	Client client;
	//Création du tableau pour  afficher la liste des clients
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

void Magasin::AfficherClient(std::string name)
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

void Magasin::AfficherClient(int id)
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

void Magasin::ValiderCommande(Commande c)
{
	m_commandes.push_back(new Commande(c));

}

void Magasin::ChangerStatusCommande(Commande c)
{
	c.ChangerStatus();
}

void Magasin::AfficherCommandes()
{
	for (Commande* c : m_commandes) {
		Commande commande = *c;
		std::cout << commande << std::endl ;
	}
}

void Magasin::AfficherCommandesDe(Client c)
{
	for (Commande* com : m_commandes) {
		Commande commande = *com;
		if(commande.getClient() == c)
		std::cout << commande << std::endl;
	}
}

std::vector<Client*> Magasin::getClients() const
{
	return m_clients;
}

std::vector<Produit*> Magasin::getProduits() const
{
	return m_produits;
}

std::vector<Commande*> Magasin::getCommandes() const
{
	return m_commandes;
}


Magasin::~Magasin()
{
}
