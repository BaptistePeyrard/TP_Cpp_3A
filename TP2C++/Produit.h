#pragma once

#include <string>
#include <iomanip>
class Produit
{
public:
	Produit(int id=0, std::string titre="",std::string desc="",int dispo=0,float prix=0.0);
	~Produit();

	int getId() const;
	std::string getTitre() const;
	std::string getDescription() const;
	int getQqtDispo()const;
	float getPrix()const;

	void setQqtDispo(int dispo);

	bool operator == (const Produit& p) const;

private:
	int _id;
	std::string _titre;
	std::string _description;
	int _qttDispo;
	float _prix;

};
std::ostream& operator<<(std::ostream& os, const Produit& produit);
