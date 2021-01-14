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
void gestionUtilisateurs();

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
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (dispo == 0)gestionMagasin();
				else {
					id = easystore.getProduits().size() + 1;
					Produit produit(id, titre, desc, dispo, prix);
					easystore.AddProduit(produit);
					std::cout << "Le produit  " << produit.getTitre() << " a bien ete ajoute au magasin sous l'id : " << produit.getId() << std::endl;
					std::cout << "Appuyez pour revenir a la gestion du magasin....";
					std::getline(std::cin, temp);
					system("cls");
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
	std::getline(std::cin, temp);
	system("cls");
	gestionMagasin();
}

void AffichageProduit()
{
	std::string prd;
	std::cout << "Entrez le nom du produit a afficher" << std::endl;
	std::getline(std::cin, prd);
	easystore.AfficherProduit(prd);
	std::cout << std::endl << "Appuyez pour revenir a la gestion du magasin....";
	std::getline(std::cin, temp);
	system("cls");
	gestionMagasin();
}

void MiseAJourQtt()
{
	bool found = false;
	std::string nom;
	int i = 0,dispo;
	std::cout << "Indiquez le nom du produit pour lequel vous souhaitez modifier la quantite" << std::endl;
	std::getline(std::cin, nom);
	for (Produit* p : easystore.getProduits())
	{
		if (p->getTitre() == nom) found = true;
		if (!found)i++;
	}
	if (!found)std::cout << "Ce produit n'existe pas" << std::endl;
	else {
		std::cout << "Indiquez la nouvelle quantité disponible pour " << nom << std::endl;
		std::cin >> dispo;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		easystore.getProduits()[i]->setQqtDispo(dispo);
		std::cout << "Le produit " << easystore.getProduits()[i]->getTitre() << "a desormais une quantite disponible de " << easystore.getProduits()[i]->getQqtDispo() << std::endl;

	}
	std::cout << std::endl << "Appuyez pour revenir a la gestion du magasin....";
	std::getline(std::cin, temp);
	system("cls");
	gestionMagasin();

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
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Sert à empécher un fonctionnement pas paratique des std::getline de l'ajout d'objet,à ajouter apres chaque cin menant a des getline
	system("cls");
	switch (action)
	{
	case 1: AjoutProduit();
		break;

	case 2: AffichageProduits();
		break;

	case 3: AffichageProduit();
		break;

	case 4: MiseAJourQtt();
		break;

	case 5: accueil();
		break;
	}
}

void AjoutUtilisateur()
{
	std::string prenom, nom;
	int id;
	std::cout << "Indiquez le prenom de l'utilisateur (tapez ""0"" pour annuler l'ajout)" << std::endl;
	std::getline(std::cin, prenom);
	if (prenom == "0")gestionMagasin();
	else {
		std::cout << "Indiquez le nom de l'utilisateur(tapez ""0"" pour annuler l'ajout)" << std::endl;
		std::getline(std::cin, nom);
		if (nom == "0")gestionMagasin();
		else {
			id = easystore.getClients().size() + 1;
			Client client(id, prenom, nom);
			easystore.AddClient(client);
			std::cout << "Le client  " << client.getPrenom() << " " << client.getNom() << " a bien ete ajoute sous l'id : " << client.getId() << std::endl;
			std::cout << "Appuyez pour revenir a la gestion des utilisateurs....";
			std::getline(std::cin, temp);
			system("cls");
			gestionUtilisateurs();
				}

			}
}

void AffichageUtilisateurs()
{
	easystore.AfficherClients();

	std::cout << "Cliquez pour continuer" << std::endl;
	std::getline(std::cin, temp);
	system("cls");
	gestionUtilisateurs();

}
void AffichageUtilisateur()
{
	std::cout << "Recherchez l'utilisateur par : " << std::endl;
	std::cout << "1) son nom " << std::endl;
	std::cout << "2) son id" << std::endl;
	std::cout << "(Tapez autre chose pour annuler)" << std::endl;

	std::cin >> action;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string nom;
	switch (action)
	{
	case 1: 
			std::cout << "Indiquez le nom de l'utilisateur a afficher" << std::endl;
			std::getline(std::cin, nom);
			easystore.AfficherClient(nom);
		break;

	case 2: int id;
			std::cout << "Indiquez l'id de l'utilisateur a afficher" << std::endl;
			std::cin >> id;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			easystore.AfficherClient(id);
		break;
	}

	std::cout << std::endl << "Appuyez pour revenir a la gestion des utilisateurs....";
	std::getline(std::cin, temp);
	system("cls");
	gestionUtilisateurs();

}


void gestionUtilisateurs()
{
	std::cout << "Gestion des utilisateurs :" << std::endl;

	std::cout << "1) Ajout d'un utilisateur/client" << std::endl;
	std::cout << "2) Affichage de tous les utilisateurs" << std::endl;
	std::cout << "3) Affichage d'un utilisateur" << std::endl;
	std::cout << "4) Mise a jour des utilisateurs" << std::endl;
	std::cout << "5) Retour" << std::endl;

	std::cin >> action;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Sert à empécher un fonctionnement pas paratique des std::getline de l'ajout d'utilisateur,à ajouter apres chaque cin menant a des getline
	system("cls");
	switch (action)
	{
	case 1: AjoutUtilisateur();
		break;

	case 2: AffichageUtilisateurs();
		break;

	case 3: AffichageUtilisateur();
		break;

	case 4: MiseAJourQtt();
		break;

	case 5: accueil();
		break;
	}
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
