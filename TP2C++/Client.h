#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "Produit.h"

class Client
{
public:
	Client(int id = 0,std::string prenom="",std::string nom="");
	~Client();

	int getId()const;
	std::string getPrenom()const;
	std::string getNom()const;
	std::vector<Produit> getPanier()const;

	void addProduit(Produit p);
	void clearPanier();
	void modifyQqtProduit(Produit p)const;
	void delProduit(Produit p);

	bool operator == (const Client& c)const;


private:
	int _id;
	std::string _prenom;
	std::string _nom;
	std::vector<Produit> m_panier;


};
std::ostream& operator<<(std::ostream& os, const Client& produit);
