#include <iostream>
#include <vector>
#include "Date.h"
#include "Client.h"
#include "Chambre.h"
#include "Hotel.h"
#include "Reservation.h"

class Stockage {	//Classe pour sauvegarder tous les objets et permet de g�n�rer des id
public:
	Stockage() : _id_hotel(0), _id_chambre(0), _id_client(0), _id_reservation(0) {}

	int get_id_hotel() {
		_id_hotel++;	//Premiere id = 1
		return _id_hotel;
	}
	int get_id_chambre() {
		_id_chambre++;	//Premiere id = 1
		return _id_chambre;
	}
	int get_id_client() {
		_id_client++;	//Premiere id = 1
		return _id_client;
	}
	int get_id_reservation() {
		_id_reservation++;	//Premiere id = 1
		return _id_reservation;
	}

	void Ajouter_hotel(Hotel::Hotel& hotel) {
		_liste_hotel.push_back(hotel);
	}

	void Ajouter_reservation(Reservation::Reservation& reser) {
		_liste_reservation.push_back(reser);
	}

	std::vector<Hotel::Hotel> get_liste_hotel() const {
		return _liste_hotel;
	}
	
	std::vector<Reservation::Reservation> get_liste_reservation() const {
		return _liste_reservation;
	}

	Hotel::Hotel& get_hotel(int id) {
		if (_liste_hotel.size() > 0) {
			for (int i = 0; i < _liste_hotel.size(); i++) {
				if (id == _liste_hotel.at(i).get_id()) {
					return _liste_hotel.at(i);
				}
			}
		}
	}

	Reservation::Reservation& get_reservation(int id) {
		if (_liste_reservation.size() > 0) {
			for (int i = 0; i < _liste_reservation.size(); i++) {
				if (id == _liste_reservation.at(i).get_id()) {
					return _liste_reservation.at(i);
				}
			}
		}
	}

	void supprimer_reservation(Reservation::Reservation reser)
	{
		if (_liste_reservation.size() > 0) {
			auto it = std::remove(_liste_reservation.begin(), _liste_reservation.end(), reser);	//iterateur remove pour enlever le client
			_liste_reservation.erase(it, _liste_reservation.end());	//enleve les cases en trop
		}
	}

	int get_nbr_reser() {
		return _nombre_reservation_pour_reduction;
	}
	double get_pourcentage_reduc() {
		return _pourcentage_reduction;
	}
	void set_nbr_reser(int nombre) {
		_nombre_reservation_pour_reduction = nombre;
	}
	void set_pourcentage_reduc(double pourcentage) {
		_pourcentage_reduction = pourcentage;
	}
	
private:
	int _id_hotel;
	int _id_chambre;
	int _id_client;
	int _id_reservation;
	std::vector<Hotel::Hotel> _liste_hotel;
	std::vector<Reservation::Reservation> _liste_reservation;

	//Programme de fidelite
	int _nombre_reservation_pour_reduction;
	double _pourcentage_reduction;
};

Reservation::Reservation ajouter_reservation(int id, Hotel::Hotel& hotel);
int nbr_nuits(Date::Date date_debut, Date::Date date_fin);
Chambre::Chambre choisir_chambre(Date::Date date_debut, Date::Date date_fin, Hotel::Hotel& hotel);
Client::Client choisir_client(Hotel::Hotel& hotel);
void afficher_reservations(std::vector<Reservation::Reservation> liste);
void afficher_reservations_par_numero(std::vector<Reservation::Reservation> liste, int numero);
void afficher_reservations_par_client(std::vector<Reservation::Reservation> liste, int id_client);
void afficher_reservations_par_client(std::vector<Reservation::Reservation> liste, std::string nom_client);
void modifier_reservation(Reservation::Reservation& reservation);
//Interface console pour tester toutes les fonctions
void afficher_menu();
void afficher_menu_modif_hotel();
void afficher_menu_modif_chambre();
void afficher_menu_modif_reservation();
void afficher_menu_informations();
void start(Stockage& save);

int main() {

	Stockage save;

	Hotel::Hotel hotel(save.get_id_hotel(), "Hotel1", "Dijon");

	Type typeenum = Type::Simple;
	Chambre::Chambre chambre1(save.get_id_chambre(), typeenum, 100);
	Client::Client client1(save.get_id_client(), "Nom1", "Prenom1");
	Client::Client client2(save.get_id_client(), "Nom2", "Prenom2");

	Chambre::Chambre chambre2(save.get_id_chambre(), typeenum, 110);

	typeenum = Type::Double;
	Chambre::Chambre chambre3(save.get_id_chambre(), typeenum, 200);

	typeenum = Type::Suite;
	Chambre::Chambre chambre4(save.get_id_chambre(), typeenum, 400);

	hotel.ajouter_chambre(chambre1);
	hotel.ajouter_chambre(chambre2);
	hotel.ajouter_chambre(chambre3);
	hotel.ajouter_chambre(chambre4);
	hotel.ajouter_client(client1);
	hotel.ajouter_client(client2);
	save.Ajouter_hotel(hotel);

	Date::Date date(2020, 6, 1);
	Date::Date datefin(2020, 7, 1);
	Reservation::Reservation reser1(save.get_id_reservation(), date, datefin, save.get_hotel(1), chambre1, client1);
	date = date+60;
	datefin = datefin + 60;
	Reservation::Reservation reser2(save.get_id_reservation(), date, datefin, save.get_hotel(1), chambre1, client2);
	date = date + 60;
	datefin = datefin + 60;
	Reservation::Reservation reser3(save.get_id_reservation(), date, datefin, save.get_hotel(1), chambre2, client1);
	date = date + 60;
	datefin = datefin + 60;
	Reservation::Reservation reser4(save.get_id_reservation(), date, datefin, save.get_hotel(1), chambre1, client1);

	save.Ajouter_reservation(reser1);
	save.Ajouter_reservation(reser2);
	save.Ajouter_reservation(reser3);
	save.Ajouter_reservation(reser4);

	start(save);

	/*
	//initialisation des 10 chambres de l'hotel
	std::vector<Chambre::Chambre> liste;
	Chambre::Chambre chambre1(save.get_id(), Type::Simple, 100);
	liste.push_back(chambre1);
	Chambre::Chambre chambre2(save.get_id(), Type::Simple, 100);
	liste.push_back(chambre2);
	Chambre::Chambre chambre3(save.get_id(), Type::Simple, 100);
	liste.push_back(chambre3);
	Chambre::Chambre chambre4(save.get_id(), Type::Double, 125);
	liste.push_back(chambre4);
	Chambre::Chambre chambre5(save.get_id(), Type::Double, 125);
	liste.push_back(chambre5);
	Chambre::Chambre chambre6(save.get_id(), Type::Double, 125);
	liste.push_back(chambre6);
	Chambre::Chambre chambre7(save.get_id(), Type::Double, 125);
	liste.push_back(chambre7);
	Chambre::Chambre chambre8(save.get_id(), Type::Double, 125);
	liste.push_back(chambre8);
	Chambre::Chambre chambre9(save.get_id(), Type::Suite, 210);
	liste.push_back(chambre9);
	Chambre::Chambre chambre10(save.get_id(), Type::Suite, 210);
	liste.push_back(chambre10);

	//initialisation des 10 clients
	std::vector<Client::Client> liste_clients;
	Client::Client client1(save.get_id(), "Nom1", "Prenom1");
	liste_clients.push_back(client1);
	Client::Client client2(save.get_id(), "Nom2", "Prenom2");
	liste_clients.push_back(client2);
	Client::Client client3(save.get_id(), "Nom3", "Prenom3");
	liste_clients.push_back(client3);
	Client::Client client4(save.get_id(), "Nom4", "Prenom4");
	liste_clients.push_back(client4);
	Client::Client client5(save.get_id(), "Nom5", "Prenom5");
	liste_clients.push_back(client5);
	Client::Client client6(save.get_id(), "Nom6", "Prenom6");
	liste_clients.push_back(client6);
	Client::Client client7(save.get_id(), "Nom7", "Prenom7");
	liste_clients.push_back(client7);
	Client::Client client8(save.get_id(), "Nom8", "Prenom8");
	liste_clients.push_back(client8);
	Client::Client client9(save.get_id(), "Nom9", "Prenom9");
	liste_clients.push_back(client9);
	Client::Client client100(save.get_id(), "Nom10", "Prenom10");
	liste_clients.push_back(client100);
	
	//Creation de l'hotel
	
	Hotel::Hotel hotel1(save.get_id(), "L'hotel", "Dijon", liste, liste_clients);
	std::vector<Reservation::Reservation> liste_reservations;
	
	//liste_reservations.push_back(ajouter_reservation(id.get_id(), hotel1));
	*/

	/*
	liste_reservations.push_back(ajouter_reservation(1, hotel1));
	liste_reservations.push_back(ajouter_reservation(2, hotel1));
	liste_reservations.push_back(ajouter_reservation(3, hotel1));
	*/

	/*	Test avec les r�s�rvations
	Date::Date date(2020, 6, 1);
	Date::Date date_fin = date + 30;
	Reservation::Reservation reser(1, date, date_fin, hotel1, chambre1, client1);
	liste_reservations.push_back(reser);
	date = date + 35;
	date_fin = date_fin + 35;
	Reservation::Reservation reser2(2, date, date_fin, hotel1, chambre2, client1);
	liste_reservations.push_back(reser2);
	date = date + 35;
	date_fin = date_fin + 35;
	Reservation::Reservation reser3(3, date, date_fin, hotel1, chambre3, client1);
	liste_reservations.push_back(reser3);
	afficher_reservations_par_client(liste_reservations, "Nom1");
	*/

	/* Test modification chambre
	std::cout << reser3.get_montant() << std::endl;
	modifier_reservation(reser3);
	std::cout << reser3.get_montant() << std::endl;
	*/

	/* Test annulation r�s�rvation
	std::cout << reser3.get_hotel().get_liste_clients().at(0).get_nbr_reservations() << std::endl;
	reser3.Annuler();
	reser2.Annuler();
	reser.Annuler();
	std::cout << reser3.get_hotel().get_liste_clients().at(0).get_nbr_reservations() << std::endl;
	*/

	//hotel1.get_liste_chambres().at(0).ajouter_jours_reservations(test, test_fin);
	//std::cout << hotel1.get_liste_chambres().at(0).Check_disponibilite(test, test_fin) << std::endl;
	

	/* TESTS PARTIE 1
	Chambre::Chambre chambre1(1, Type::Simple, 180);
	Chambre::Chambre chambre2(2, Type::Double, 750);
	Chambre::Chambre chambre3(3, Type::Simple, 180);
	Chambre::Chambre chambre4(4, Type::Suite, 1800);
	std::vector <Chambre::Chambre> liste;
	liste.push_back(chambre2);
	liste.push_back(chambre3);
	liste.push_back(chambre4);

	Hotel::Hotel hotel1("hotel_1", "THE hotel", "Ablain-Saint-Nazaire");
	hotel1.ajouter_chambre(chambre1);
	hotel1.ajouter_liste_chambres(liste);
	*/

	/*	
	std::cout << hotel1.get_liste_chambres().size() << std::endl;
	std::cout << hotel1.get_liste_chambres().at(0).get_prix() << std::endl;
	std::cout << hotel1.get_liste_chambres().at(1).get_prix() << std::endl;
	std::cout << hotel1.get_liste_chambres().at(2).get_prix() << std::endl;
	std::cout << hotel1.get_liste_chambres().at(3).get_prix() << std::endl;
	*/

	/*
	Client::Client client1(1, "Gelus", "Jules");
	Client::Client client2(2, "Villaverde", "Lucas");
	Date::Date date2(2021, 1, 28);
	Date::Date datefin2(2021, 2, 4);
	Reservation::Reservation reser0(2, date2, datefin2, hotel1, chambre4, client2);
	Reservation::Reservation reser01(2, date2, datefin2, hotel1, chambre4, client2);
	Reservation::Reservation reser02(2, date2, datefin2, hotel1, chambre4, client2);
	std::cout << (datefin2 - date2) << std::endl;
	std::cout << "Le sejour va couter : " << reser02.montant_total(2) << std::endl;
	std::cout << "Le sejour va couter : " << reser02.montant_total(2, 0.9) << std::endl;

	Date::Date date(2020, 1, 1);
	Date::Date datefin(2021, 6, 1);
	Date::Date datetest = (datefin + -366);
	std::cout << "test : " << date.toString() << std::endl;
	std::cout << "test : " << datetest.toString() << std::endl;
	
	Reservation::Reservation reser1(1, date, datefin ,hotel1 ,chambre3 ,client1);
	Reservation::Reservation reser2(1, date, datefin, hotel1, chambre3, client1);
	Reservation::Reservation reser3(1, date, datefin, hotel1, chambre3, client1);
	*/
	

	return 0;

}

Reservation::Reservation ajouter_reservation(int id, Hotel::Hotel& hotel)
{
	//On demande la date de d�but
	int ann�e;
	std::cout << "Saisir l'annee de debut" << std::endl;
	std::cin >> ann�e;
	std::cout << std::endl;
	int mois;
	std::cout << "Saisir le mois de debut" << std::endl;
	std::cin >> mois;
	std::cout << std::endl;
	int jour;
	std::cout << "Saisir le jour de debut" << std::endl;
	std::cin >> jour;
	std::cout << std::endl;

	Date::Date date_debut(ann�e, mois, jour);	//Le constructeur de Date appelle la fonction CheckDate()

	//On demande la date de fin
	std::cout << "Saisir l'annee de fin" << std::endl;
	std::cin >> ann�e;
	std::cout << std::endl;
	std::cout << "Saisir le mois de fin" << std::endl;
	std::cin >> mois;
	std::cout << std::endl;
	std::cout << "Saisir le jour de fin" << std::endl;
	std::cin >> jour;
	std::cout << std::endl;

	Date::Date date_fin(ann�e, mois, jour);

	//Si la date de fin est bien apr�s la date de d�but, on return la Reservation sinon on recommence
	if ((date_debut <= date_fin) == true) {

		std::cout << "Nombre de nuits reserves : " << nbr_nuits(date_debut, date_fin) << std::endl;	//On affiche le nombre de nuits

		Chambre::Chambre chambre_choisi = choisir_chambre(date_debut, date_fin, hotel);
		Client::Client client_choisi = choisir_client(hotel);
		std::cout << "Client :" << client_choisi.get_nom() << " " << client_choisi.get_prenom() << "( id = " << client_choisi.get_id() << " )" << std::endl;
		Reservation::Reservation reser(id, date_debut, date_fin, hotel, chambre_choisi, client_choisi);
		std::cout << "Le montant sans reduction de fidelite est de " << reser.get_montant_original() << " $";
		return reser;
	}
	else {
		Reservation::Reservation reser = ajouter_reservation(id, hotel);
		return reser;
	}

	
}

int nbr_nuits(Date::Date date_debut, Date::Date date_fin)
{
	int nbr = date_fin - date_debut;	//Surcharge d'op�rateur - dans la classe Date
	return nbr;
}

Chambre::Chambre choisir_chambre(Date::Date date_debut, Date::Date date_fin, Hotel::Hotel& hotel)
{

	std::string type_chambre;
	std::cout << "Choisir un type de chambre (simple, double ou suite)" << std::endl;
	std::cin >> type_chambre;
	std::cout << std::endl;


	
	for (int i = 0; i < hotel.get_liste_chambres().size(); i++) {
		//Le chambre correspond si elle a la meme type et si elle est disponible aux dates de reservation
		if ((hotel.get_liste_chambres().at(i).get_type() == type_chambre) && (hotel.get_liste_chambres().at(i).Check_disponibilite(date_debut, date_fin) == true)) {
			Chambre::Chambre chambre_choisi = hotel.get_liste_chambres().at(i);
			std::cout << "Identifiant de la chambre choisi :" << hotel.get_liste_chambres().at(i).get_id() << std::endl;
			return chambre_choisi;	//On return la premiere chambre choisi
		}

	}
	std::cout << "Aucune chambre n'a ete trouve aux dates demandes" << std::endl;
	choisir_chambre(date_debut, date_fin, hotel);
	
}

Client::Client choisir_client(Hotel::Hotel& hotel)
{
	std::string nom_client;
	std::cout << "Saisir le nom du client" << std::endl;
	std::cin >> nom_client;
	std::cout << std::endl;
	int nbr_homonyme = 0;
	std::vector<Client::Client> clients;

	for (int i = 0; i < hotel.get_liste_clients().size(); i++) {
		//On cherche un ou plusieurs clients ayant le nom du client
		if (hotel.get_liste_clients().at(i).get_nom() == nom_client) {
			
			clients.push_back(hotel.get_liste_clients().at(i));	//On ajoute le client au tableau
			nbr_homonyme++;	//On rajoute un client ayant le nom du client
		}

	}

	if (nbr_homonyme == 0) {	//Si aucun client ne correspond au nom
		std::cout << "Aucun client avec ce nom n'a ete trouve" << std::endl;
		choisir_client(hotel);
	}
	else if (nbr_homonyme == 1) {	//S'il n'y a qu'un seul client possible avec ce nom
		return clients.at(0);
	}
	else {	//S'il y a plusieurs homonymes

		for (int i = 0; i < clients.size(); i++) {
			std::cout << "Saisir " << i << " si le client est : " << clients.at(i).get_nom() << " " << clients.at(i).get_prenom() << " ( id = " << clients.at(i).get_id() << " )" << std::endl;
		}
		int numero;
		std::cin >> numero;
		std::cout << std::endl;
		Client::Client client = clients.at(numero);
		return client;
	}
}

void afficher_reservations(std::vector<Reservation::Reservation> liste)
{
	if (liste.size() > 0) {
		for (int i = 0; i < liste.size(); i++) {
			std::cout << liste.at(i) << std::endl;
		}
	}
}

void afficher_reservations_par_numero(std::vector<Reservation::Reservation> liste, int numero)
{
	if (liste.size() > 0) {
		for (int i = 0; i < liste.size(); i++) {
			if (liste.at(i).get_id() == numero) {
				std::cout << liste.at(i) << std::endl;
			}
		}
	}
}

void afficher_reservations_par_client(std::vector<Reservation::Reservation> liste, int id_client)
{
	if (liste.size() > 0) {
		for (int i = 0; i < liste.size(); i++) {
			if (liste.at(i).get_id_client() == id_client) {
				std::cout << liste.at(i) << std::endl;
			}
		}
	}
}

void afficher_reservations_par_client(std::vector<Reservation::Reservation> liste, std::string nom_client)
{
	if (liste.size() > 0) {
		for (int i = 0; i < liste.size(); i++) {
			if (liste.at(i).get_nom_client() == nom_client) {
				std::cout << liste.at(i) << std::endl;
			}
		}
	}
}

void modifier_reservation(Reservation::Reservation& reservation)
{
	std::cout << " Que voulez vous modifier ?" << std::endl;
	std::cout << " 1 : Changer la date de d�but" << std::endl;
	std::cout << " 2 : Changer la date de fin" << std::endl;
	std::cout << " 3 : Changer la chambre" << std::endl;
	std::cout << " 4 : Changer le client" << std::endl;

	int choix;
	std::cin >> choix;

	if ((choix == 1) || (choix == 2)) {	//Changement de date de d�but ou de date de fin
		std::cout << std::endl << "Saisir la nouvelle ann�e" << std::endl;
		int ann�e;
		std::cin >> ann�e;
		std::cout << std::endl << "Saisir le nouveau mois" << std::endl;
		int mois;
		std::cin >> mois;
		std::cout << std::endl << "Saisir le nouveau jour" << std::endl;
		int jour;
		std::cin >> jour;
		Date::Date new_date(ann�e, mois, jour);
		if (choix == 1) {
			reservation.set_date_debut(new_date);
		}
		else {
			reservation.set_date_fin(new_date);
		}
	}
	else if (choix == 3) {
		Hotel::Hotel hotel = reservation.get_hotel();
		reservation.set_chambre(choisir_chambre(reservation.get_date_debut(), reservation.get_date_fin(), hotel));
	}
	else if (choix == 4) {
		Hotel::Hotel hotel = reservation.get_hotel();
		reservation.set_client(choisir_client(hotel));
	}
}

void afficher_menu()
{
	system("CLS");	//Pour effacer le contenu de la console
	std::cout << std::endl <<  "        MENU     " << std::endl << std::endl;
	std::cout << " 1 : Ajouter un hotel" << std::endl;
	std::cout << " 2 : Modifier un hotel" << std::endl;
	std::cout << " 3 : Ajouter une reservation" << std::endl;
	std::cout << " 4 : Modifier une reservation" << std::endl;
	std::cout << " 5 : Afficher des informations" << std::endl;
	std::cout << " 6 : Quitter " << std::endl << std::endl;
	
}

void afficher_menu_modif_hotel()
{
	system("CLS");
	std::cout << std::endl << "        MENU MODIFICATION     " << std::endl << std::endl;
	std::cout << " 1 : Ajouter une chambre" << std::endl;
	std::cout << " 2 : Modifier une chambre" << std::endl;
	std::cout << " 3 : Ajouter un client" << std::endl;
	std::cout << " 4 : Supprimer un client" << std::endl;
	std::cout << " 5 : Modifier le nom de l'hotel" << std::endl;
	std::cout << " 6 : Appliquer un programme de fidelite" << std::endl;	//
	std::cout << " 7 : Retour au menu " << std::endl << std::endl;
}

void afficher_menu_modif_chambre()
{
	system("CLS");
	std::cout << std::endl << "        MENU MODIFICATION CHAMBRE    " << std::endl << std::endl;
	std::cout << " 1 : Changer le type" << std::endl;
	std::cout << " 2 : Changer le prix" << std::endl;
	std::cout << " 3 : Supprimer la chambre" << std::endl;
	std::cout << " 4 : Retour au menu " << std::endl << std::endl;
}

void afficher_menu_modif_reservation()
{
	system("CLS");
	std::cout << std::endl << "        MENU MODIFICATION RESERVATION    " << std::endl << std::endl;
	std::cout << " 1 : Changer la chambre" << std::endl;
	std::cout << " 2 : Changer le client" << std::endl;
	std::cout << " 3 : Changer la date de d�but" << std::endl;
	std::cout << " 4 : Changer la date de fin" << std::endl;
	std::cout << " 5 : Changer les deux dates" << std::endl;
	std::cout << " 6 : Supprimer la reservation" << std::endl;
	std::cout << " 7 : Retour au menu " << std::endl << std::endl;
}

void afficher_menu_informations()
{
	system("CLS");
	std::cout << std::endl << "        MENU INFORMATIONS     " << std::endl << std::endl;
	std::cout << " 1 : Afficher la liste des hotels" << std::endl;
	std::cout << " 2 : Afficher la liste des chambres d'un hotel" << std::endl;
	std::cout << " 3 : Afficher la liste des clients d'un hotel" << std::endl;
	std::cout << " 4 : Afficher la liste des reservations" << std::endl;
	std::cout << " 5 : Afficher une reservation avec son id" << std::endl;
	std::cout << " 6 : Afficher la liste des reservations pour un client avec son id" << std::endl;
	std::cout << " 7 : Afficher la liste des reservations pour un client avec son nom" << std::endl;
	std::cout << " 8 : Retour au menu " << std::endl << std::endl;
}

void start(Stockage& save)
{

	afficher_menu();

	int choix;
	std::cin >> choix;
	std::cout << std::endl;

	if (choix == 1) {
		//Ajout d'un hotel

		system("CLS");
		std::cout << "Rentrer le nom du nouvel hotel" << std::endl;
		std::string nom;
		std::cin >> nom;
		std::cout << std::endl << "Rentrer la ville du nouvel hotel" << std::endl;
		std::string ville;
		std::cin >> ville;
		std::cout << std::endl;
		Hotel::Hotel hotel(save.get_id_hotel(), nom, ville);
		save.Ajouter_hotel(hotel);
		start(save);
	}
	else if (choix == 2) {
		//Modification d'un hotel
		afficher_menu_modif_hotel();

		int choix_2;
		std::cin >> choix_2;
		std::cout << std::endl;
		
		int id_hotel = 0;
		if ((choix_2 == 1) || (choix_2 == 2) || (choix_2 == 3) || (choix_2 == 4) || (choix_2 == 5)) {
			system("CLS");
			std::cout << "Rentrer l'id de l'hotel" << std::endl;
			std::cin >> id_hotel;
		}

		int id_chambre = 0;
		if ((choix_2 == 2)) {
			system("CLS");
			std::cout << "Rentrer l'id de la chambre" << std::endl;
			std::cin >> id_chambre;
		}

		int id_client = 0;
		if (choix_2 == 4) {
			system("CLS");
			std::cout << "Rentrer l'id du client" << std::endl;
			std::cin >> id_client;
		}
		

		if (choix_2 == 1) {
			//Ajout d'une chambre

			system("CLS");
			std::cout << "Rentrer le type de la nouvelle chambre (simple, double ou suite)" << std::endl;
			std::string type;
			std::cin >> type;
			Type type_enum = Type::Simple;
			if(type == "simple"){
				type_enum = Type::Simple;
			}
			else if (type == "double") {
				type_enum = Type::Double;
			}
			else if (type == "suite") {
				type_enum = Type::Suite;
			}
			else {
				start(save);
			}
			std::cout << std::endl << "Rentrer le prix de la chambre" << std::endl;
			double prix;
			std::cin >> prix;
			std::cout << std::endl;
			Chambre::Chambre chambre(save.get_id_chambre(), type_enum, prix);
			save.get_hotel(id_hotel).ajouter_chambre(chambre);	//On ajoute la chambre dans save
			start(save);
			
		}
		else if (choix_2 == 2) {
			//Modification d'une chambre
			afficher_menu_modif_chambre();

			int choix_2_2;
			std::cin >> choix_2_2;
			std::cout << std::endl;

			

			if (choix_2_2 == 1) {
				//Changement Type

				std::cout << "Rentrer le type de la chambre (simple/double/suite)" << std::endl;
				std::string type;
				std::cin >> type;
				Type type_enum = Type::Simple;

				if (type == "simple") {
					type_enum = Type::Simple;
				}
				else if (type == "double"){
					type_enum = Type::Double;
				}
				else if (type == "suite") {
					type_enum = Type::Suite;
				}
				else {
					start(save);
				}

				for (int i = 0; i < save.get_hotel(id_hotel).get_liste_chambres().size(); i++) {
					if (save.get_hotel(id_hotel).get_liste_chambres().at(i).get_id() == id_chambre) {	//On retrouve la chambre

						save.get_hotel(id_hotel).get_liste_chambres().at(i).set_type(type_enum);
					}
				}

				start(save);

			}
			else if (choix_2_2 == 2) {
				//Changement prix

				std::cout << "Rentrer le prix de la chambre" << std::endl;
				int prix;
				std::cin >> prix;
				for (int i = 0; i < save.get_hotel(id_hotel).get_liste_chambres().size(); i++) {
					if (save.get_hotel(id_hotel).get_liste_chambres().at(i).get_id() == id_chambre) {	//On retrouve la chambre

						save.get_hotel(id_hotel).get_liste_chambres().at(i).set_prix(prix);
					}
				}

				start(save);

			}
			else if (choix_2_2 == 3) {
				//Suppression d'une chambre

				system("CLS");
				std::cout << "Etes-vous sur de vouloir supprimer cette chambre ? (oui/non)" << std::endl;
				std::string choix_2_2_3;
				std::cin >> choix_2_2_3;
				if (choix_2_2_3 == "oui") {

					for (int i = 0; i < save.get_hotel(id_hotel).get_liste_chambres().size(); i++) {
						if (save.get_hotel(id_hotel).get_liste_chambres().at(i).get_id() == id_chambre) {	//On retrouve la chambre

							save.get_hotel(id_hotel).supprimer_chambre(save.get_hotel(id_hotel).get_liste_chambres().at(i));
						}
					}

					for (int i = 0; i < save.get_liste_reservation().size(); i++) {	//Suppression des reservations de la chambre dans cet hotel
						if ((save.get_liste_reservation().at(i).get_id_chambre() == id_chambre) && (save.get_liste_reservation().at(i).get_id_hotel() == id_hotel)) {
							save.get_liste_reservation().at(i).Annuler();
							save.supprimer_reservation(save.get_liste_reservation().at(i));
							i--;	//On supprime une reservation de la liste, toutes les reservations vont etre decal�s vers la gauche
						}
					}

					start(save);
				}
				else {
					start(save);
				}

			}
			else if (choix_2_2 == 4) {
				//Retour au menu
				start(save);
			}
			else {
				start(save);
			}


		}
		else if (choix_2 == 3) {
			//Ajout d'un client

			system("CLS");
			std::cout << "Rentrer le nom du client" << std::endl;
			std::string nom;
			std::cin >> nom;
			std::cout << std::endl << "Rentrer le prenom du client" << std::endl;
			std::string prenom;
			std::cin >> prenom;
			std::cout << std::endl;
			Client::Client client(save.get_id_client(), nom, prenom);
			save.get_hotel(id_hotel).ajouter_client(client);	//On ajoute la chambre dans save
			start(save);
		}
		else if (choix_2 == 4) {
			//Suppression d'un client

			system("CLS");
			std::cout << "Etes-vous sur de vouloir supprimer ce client ? (oui/non)" << std::endl;
			std::string choix_2_5;
			std::cin >> choix_2_5;
			if (choix_2_5 == "oui") {

				for (int i = 0; i < save.get_hotel(id_hotel).get_liste_clients().size(); i++) {
					if (save.get_hotel(id_hotel).get_liste_clients().at(i).get_id() == id_client) {	//On retrouve le client
						save.get_hotel(id_hotel).supprimer_client(save.get_hotel(id_hotel).get_liste_clients().at(i));
					}
				}

				for (int i = 0; i < save.get_liste_reservation().size(); i++) {	//Suppression des reservations du client dans cet hotel

					if ((save.get_liste_reservation().at(i).get_id_client() == id_client) && (save.get_liste_reservation().at(i).get_id_hotel() == id_hotel)) {
						save.get_liste_reservation().at(i).Annuler();
						save.supprimer_reservation(save.get_liste_reservation().at(i));
						i--;	//On supprime une reservation de la liste, toutes les reservations vont etre decal�s vers la gauche
					}
				}

				start(save);
			}
			else {
				start(save);
			}

		}
		else if (choix_2 == 5) {
			//Modification du nom de l'hotel

			std::cout << "Rentrer le nom de l'hotel" << std::endl;
			std::string nom;
			std::cin >> nom;
			std::cout << std::endl;

			save.get_hotel(id_hotel).set_nom(nom);
			start(save);
		}
		else if (choix_2 == 6) {
			//Programme de fidelite

			system("CLS");
			std::cout << "Rentrer le nombre de reservation necessaire pour avoir une reduction" << std::endl;
			int nombre;
			std::cin >> nombre;
			std::cout << std::endl;
			std::cout << "Rentrer le pourcentage de reduction (0.1 pour 10%...)" << std::endl;
			double pourcentage;
			std::cin >> pourcentage;
			std::cout << std::endl;
			save.set_nbr_reser(nombre);
			save.set_pourcentage_reduc(pourcentage);
			start(save);

		}
		else if (choix_2 == 7) {
			start(save);
		}
		else {
			start(save);	//Aucune entr�e ne correspond
		}
	}
	else if (choix == 3) {
		//Ajout d'une reservation

		system("CLS");
		int id_hotel;
		std::cout << "Rentrer l'id de l'hotel" << std::endl;
		std::cin >> id_hotel;
		Reservation::Reservation reser = ajouter_reservation(save.get_id_reservation(), save.get_hotel(id_hotel));
		save.Ajouter_reservation(reser);
		start(save);


	}
	else if (choix == 4) {
		//Modification d'une reservation
		afficher_menu_modif_reservation();


		int choix_4;
		std::cin >> choix_4;
		std::cout << std::endl;

		int id_reservation = 0;
		if ((choix_4 == 1) || (choix_4 == 2) || (choix_4 == 3) || (choix_4 == 4) || (choix_4 == 5) || (choix_4 == 6)) {
			system("CLS");
			std::cout << "Rentrer l'id de la reservation" << std::endl;
			std::cin >> id_reservation;
		}

		if (choix_4 == 1) {
			//Changement chambre
			save.get_reservation(id_reservation).set_chambre(choisir_chambre(save.get_reservation(id_reservation).get_date_debut(), save.get_reservation(id_reservation).get_date_fin(), save.get_hotel(save.get_reservation(id_reservation).get_id_hotel())));
			start(save);
		}
		else if (choix_4 == 2) {
			//Changement client
			save.get_reservation(id_reservation).set_client(choisir_client(save.get_hotel(save.get_reservation(id_reservation).get_id_hotel())));
			start(save);
		}
		else if (choix_4 == 3) {
			//Changement date debut


			//On demande la date de d�but
			int ann�e;
			std::cout << "Saisir l'annee de debut" << std::endl;
			std::cin >> ann�e;
			std::cout << std::endl;
			int mois;
			std::cout << "Saisir le mois de debut" << std::endl;
			std::cin >> mois;
			std::cout << std::endl;
			int jour;
			std::cout << "Saisir le jour de debut" << std::endl;
			std::cin >> jour;
			std::cout << std::endl;

			Date::Date date_debut(ann�e, mois, jour);

			save.get_reservation(id_reservation).set_date_debut(date_debut);
			start(save);
		}
		else if (choix_4 == 4) {
			//Changement date fin

			//On demande la date de fin
			int ann�e;
			std::cout << "Saisir l'annee de fin" << std::endl;
			std::cin >> ann�e;
			std::cout << std::endl;
			int mois;
			std::cout << "Saisir le mois de fin" << std::endl;
			std::cin >> mois;
			std::cout << std::endl;
			int jour;
			std::cout << "Saisir le jour de fin" << std::endl;
			std::cin >> jour;
			std::cout << std::endl;

			Date::Date date_fin(ann�e, mois, jour);

			save.get_reservation(id_reservation).set_date_fin(date_fin);
			start(save);

		}
		else if (choix_4 == 5) {
			//Changement dates

			//On demande la date de d�but
			int ann�e;
			std::cout << "Saisir l'annee de debut" << std::endl;
			std::cin >> ann�e;
			std::cout << std::endl;
			int mois;
			std::cout << "Saisir le mois de debut" << std::endl;
			std::cin >> mois;
			std::cout << std::endl;
			int jour;
			std::cout << "Saisir le jour de debut" << std::endl;
			std::cin >> jour;
			std::cout << std::endl;

			Date::Date date_debut(ann�e, mois, jour);	//Le constructeur de Date appelle la fonction CheckDate()

			//On demande la date de fin
			std::cout << "Saisir l'annee de fin" << std::endl;
			std::cin >> ann�e;
			std::cout << std::endl;
			std::cout << "Saisir le mois de fin" << std::endl;
			std::cin >> mois;
			std::cout << std::endl;
			std::cout << "Saisir le jour de fin" << std::endl;
			std::cin >> jour;
			std::cout << std::endl;

			Date::Date date_fin(ann�e, mois, jour);

			save.get_reservation(id_reservation).set_dates(date_debut, date_fin);
			start(save);

		}
		else if (choix_4 == 6) {
			//Suppression de la reservation

			std::cout << "Etes-vous sur de vouloir supprimer cette reservation ? (oui/non)" << std::endl;
			std::string choix_2_5;
			std::cin >> choix_2_5;
			if (choix_2_5 == "oui") {
				for (int i = 0; i < save.get_liste_reservation().size(); i++) {
					if (save.get_liste_reservation().at(i).get_id() == id_reservation) {
						save.get_liste_reservation().at(i).Annuler();
						save.supprimer_reservation(save.get_liste_reservation().at(i));
					}

				}
				start(save);
			}
			else {
				start(save);
			}
		}
		else if (choix_4 == 7) {
			//Retour au menu
			start(save);
		}
		else {
			start(save);
		}


		
	}
	else if (choix == 5) {
		//Afficher des informations
		afficher_menu_informations();

		int choix_5;
		std::cin >> choix_5;
		std::cout << std::endl;

		int id_hotel = 0;
		if ((choix_5 == 2) || (choix_5 == 3)) {
			system("CLS");
			std::cout << "Rentrer l'id de l'hotel" << std::endl;
			std::cin >> id_hotel;
			std::cout << std::endl;
		}

		
		if (choix_5 == 1) {
			//Liste des hotels
			system("CLS");
			if (save.get_liste_hotel().size() > 0) {
				for (int i = 1; i < save.get_liste_hotel().size() + 1; i++) {	//Les id commencent � 1 (et finissent � taille+1)

					std::cout << " Hotel : " << save.get_hotel(i).get_id() << " Nom : " << save.get_hotel(i).get_nom() << " (" << save.get_hotel(i).get_ville() << ")" << std::endl;

				}
			}
			else {
				std::cout << "Aucun hotel enregistre" << std::endl;
			}
		}
		else if (choix_5 == 2) {
			//Liste des chambres d'un hotel
			system("CLS");
			if ((save.get_liste_hotel().size() >= id_hotel) && save.get_hotel(id_hotel).get_liste_chambres().size() > 0) {	//Si l'hotel existe, la taille du tableau d'hotel est superieur ou egal � l'id de l'hotel (et il doit y avoir des chambres)
				for (int i = 0; i < save.get_hotel(id_hotel).get_liste_chambres().size(); i++) {
					std::cout << save.get_hotel(id_hotel).get_liste_chambres().at(i);
				}
			}
			else {
				start(save);
			}

		}
		else if (choix_5 == 3) {
			//Liste des clients d'un hotel
			if ((save.get_liste_hotel().size() >= id_hotel) && save.get_hotel(id_hotel).get_liste_clients().size() > 0) {	//Si l'hotel existe, la taille du tableau d'hotel est superieur ou egal � l'id de l'hotel (et il doit y avoir des clients)
				for (int i = 0; i < save.get_hotel(id_hotel).get_liste_clients().size(); i++) {
					std::cout << save.get_hotel(id_hotel).get_liste_clients().at(i);
				}
			}
			else {
				start(save);
			}
		}
		else if (choix_5 == 4) {
			//Liste des reservations
			system("CLS");
			afficher_reservations(save.get_liste_reservation());
		}
		else if (choix_5 == 5) {
			//Liste des reservations par id
			system("CLS");
			int id_reservation = 0;
			std::cout << "Rentrer l'id de la reservation a afficher" << std::endl;
			std::cin >> id_reservation;
			std::cout << std::endl;
			
			afficher_reservations_par_numero(save.get_liste_reservation(), id_reservation);
		}
		else if (choix_5 == 6) {
			//Liste des reservations par id de client
			system("CLS");
			int id_client = 0;
			std::cout << "Rentrer l'id du client" << std::endl;
			std::cin >> id_client;
			std::cout << std::endl;

			afficher_reservations_par_client(save.get_liste_reservation(), id_client);

			std::cout << std::endl;
			double total = 0;

			if (save.get_liste_reservation().size() > 0) {
				for (int i = 0; i < save.get_liste_reservation().size(); i++) {
					if (save.get_liste_reservation().at(i).get_id_client() == id_client) {
						total += save.get_liste_reservation().at(i).montant_total(save.get_nbr_reser(), save.get_pourcentage_reduc());
						std::cout << "Prix reservation numero " << i << " = " << save.get_liste_reservation().at(i).montant_total(save.get_nbr_reser(), save.get_pourcentage_reduc()) << " $" << std::endl;
					}
				}
			}
			std::cout << "Prix total : " << total << "$" << std::endl;

		}
		else if (choix_5 == 7) {
			//Liste des reservations par nom de client
			system("CLS");
			std::string nom;
			std::cout << "Rentrer le nom du client" << std::endl;
			std::cin >> nom;
			std::cout << std::endl;
			
			afficher_reservations_par_client(save.get_liste_reservation(), nom);

			std::cout << std::endl;
			double total = 0;

			if (save.get_liste_reservation().size() > 0) {
				for (int i = 0; i < save.get_liste_reservation().size(); i++) {
					if (save.get_liste_reservation().at(i).get_nom_client() == nom) {
						total += save.get_liste_reservation().at(i).montant_total(save.get_nbr_reser(), save.get_pourcentage_reduc());
						std::cout << "Prix reservation numero " << i << " = " << save.get_liste_reservation().at(i).montant_total(save.get_nbr_reser(), save.get_pourcentage_reduc()) << " $" << std::endl;
					}
				}
			}
			std::cout << "Prix total : " << total << "$" << std::endl;

		}
		else if (choix_5 == 8) {
			start(save);
		}
		else {
			start(save);	//Aucune entr�e ne correspond
		}

		//Pour ne pas effacer la liste � afficher
		std::cout << std::endl << std::endl << "Rentrer un caractere pour retourner au menu" << std::endl;
		std::string a;
		std::cin >> a;
		start(save);

	}
	else if (choix == 6) {
		//Fin de programme : on retourne dans le main
	}
	else{
		start(save);	//Aucune entr�e ne correspond
	}
}
