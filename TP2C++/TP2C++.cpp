// TP2C++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include "Magasin.h"
#include <iostream>

int action;
std::string temp;  //Variable utilisé pour les moments ou il faut cliquer
Magasin easystore;
void accueil();
void gestionMagasin();

void AjoutProduit()
{
	std::string titre,desc;
	int id,dispo;
	float prix;
	std::cout << "Indiquez le nom du produit (tapez ""0"" pour annuler l'ajout)" << std::endl;
	std::getline(std::cin, titre);
	if (titre == "0")gestionMagasin();
	else {
		std::cout << "Donnez une description de ce produit (tapez ""0"" pour annuler l'ajout)" << std::endl;
		std::getline(std::cin,desc);
		if (desc == "0")gestionMagasin();
		else {
			std::cout << "Indiquez le prix du produit (tapez ""0"" pour annuler l'ajout)" << std::endl;
			std::cin >> prix;
			if (prix == 0)gestionMagasin();
			else {
				std::cout << "Indiquez la quantité disponible de ce produit (tapez ""0"" pour annuler l'ajout)" << std::endl;
				std::cin >> dispo;
				if (dispo == 0)gestionMagasin();
				else {
					id = easystore.getProduits().size() + 1;
					Produit produit(id, titre, desc, dispo, prix);
					easystore.AddProduit(produit);
					std::cout << "Le produit : " << produit.getTitre() << " a bien ete ajoute au magasin sous l'id : " << produit.getId() << std::endl;
					gestionMagasin();
				}

			}
		}
	}

}

void AffichageProduits()
{
	easystore.AfficherProduits();
	std::cout << "Cliquez pour continuer" << std::endl;
	std::cin >> temp;
	gestionMagasin();
}

void AffichageProduit()
{

}

void gestionMagasin()
{
	std::cout << "Gestion du magasin :" << std::endl;

	std::cout << "1) Ajout d'un produit" << std::endl;
	std::cout << "2) Affichage de tous les produits" << std::endl;
	std::cout << "3) Affichage d'un produit" << std::endl;
	std::cout << "4) Mise a jour des quantites" << std::endl;
	std::cout << "5) Retour" << std::endl;

	std::cin >> action;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("cls");
	switch (action)
	{
	case 1: AjoutProduit();
		break;

	case 2: AffichageProduits();
		break;

	case 3: AffichageProduit();
		break;
	case 5: accueil();
		break;
	}
}

void gestionUtilisateurs()
{

}

void gestionCommandes()
{

}

void accueil()
{
	std::cout << "EasyStore" << std::endl;
	std::cout << "1) Gestion du magasin" << std::endl;				//Création du menu pour choisir l'action a effectuer
	std::cout << "2) Gestion des utilisateurs" << std::endl;		//par exemple , tapez 1 pour gestion du magasin ...
	std::cout << "3) Gestion des commandes" << std::endl;

	std::cin >> action;
	system("cls");
	switch (action)
	{
	case 1: gestionMagasin();
		break;

	case 2: gestionUtilisateurs();
		break;
	
	case 3: gestionCommandes();
		break;
	}
	
}
int main()
{

	accueil();
	
	/*
	//Ajout de produits et clients de base dans le magasin 
	Produit p(1, "PS4", "Console de jeu Sony", 10, 249.99);
	Produit p2(2, "Switch", "Console de jeu Nintendo", 20, 179.99);
	Produit p3(3, "Xbox One", "Console de jeu Microsoft", 15, 299.99);

	Magasin magasin;
	Client ruben(1, "Ruben", "Laghouati");
	Client client2(2, "Client", "Le2eme");
	ruben.addProduit(p);
	magasin.AddProduit(p);
	magasin.AddProduit(p2);
	magasin.AddProduit(p3);

	magasin.AddClient(ruben);
	magasin.AddClient(client2);
	/////////////////////////////////////////////////////////////

	magasin.AfficherClient(1);
	ruben.addProduit(p2);
	ruben.addProduit(p3);
	
	magasin.AfficherClient("Laghouati");
	*/


	//magasin.AfficherClient("Laghouati");
	//magasin.AfficherClient(2);
	//magasin.AfficherClient("wawa");
	
	//ruben.addProduit(p);
	//ruben.addProduit(p2);

	//std::cout << ruben;

	//ruben.delProduit(p);
	//std::cout << ruben;
	//magasin.AfficherProduits();
	//magasin.AfficherProduit("PS4");
	//magasin.AfficherProduit("wawa");
	
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
