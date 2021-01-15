#pragma once

#include "Client.h"
#include "Produit.h"
#include "Commande.h"

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

//Voir le cpp pour avoir indication sur les méthodes
class Magasin
{
public:
	Magasin();
	~Magasin();

	void AddProduit(Produit& p);
	void AddClient(Client& c);
	void AfficherProduit(std::string name);
	void AfficherProduits() const;
	void AfficherClients() const;
	void AfficherClient(std::string name);
	void AfficherClient(int id);
	void ValiderCommande(Commande& c);
	void ChangerStatusCommande(Commande c);

	void AfficherCommandes();
	void AfficherCommandesDe(Client c);

	std::vector<Client*> getClients()const;
	std::vector<Produit*> getProduits()const;
	std::vector<Commande*> getCommandes()const;

private:
	std::vector<Produit*> m_produits;
	std::vector<Client*> m_clients;
	std::vector<Commande*> m_commandes;
};

