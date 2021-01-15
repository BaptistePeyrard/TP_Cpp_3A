#pragma once

#include "Client.h"
class Commande
{
public:
	Commande(int id,Client client);
	~Commande();

	int getId() const;
	Client getClient() const;
	bool IsLivree() const;
	void ChangerStatus();
	std::vector<Produit> getProduits()const;

private:
	int _id;
	Client _client;
	bool _livrée;

	std::vector<Produit> m_produits;
};
std::ostream& operator<<(std::ostream& os, const Commande& commande);

