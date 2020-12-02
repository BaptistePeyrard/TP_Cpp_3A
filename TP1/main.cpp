#include <iostream>
#include <vector>
#include "Date.h"
#include "Client.h"
#include "Chambre.h"
#include "Hotel.h"
#include "Reservation.h"


Reservation::Reservation ajouter_reservation(int id, Hotel::Hotel& hotel);
int nbr_nuits(Date::Date date_debut, Date::Date date_fin);
Chambre::Chambre choisir_chambre(Date::Date date_debut, Date::Date date_fin, Hotel::Hotel& hotel);
Client::Client choisir_client(Hotel::Hotel& hotel);
void afficher_reservations(std::vector<Reservation::Reservation> liste);
void afficher_reservations_par_numero(std::vector<Reservation::Reservation> liste, int numero);
void afficher_reservations_par_client(std::vector<Reservation::Reservation> liste, int id_client);
void afficher_reservations_par_client(std::vector<Reservation::Reservation> liste, std::string nom_client);
void modifier_reservation(Reservation::Reservation& reservation);
//Interface pour tester toutes les fonctions
void afficher_menu();
void start();

int main() {

	//initialisation des 10 chambres de l'hotel
	std::vector<Chambre::Chambre> liste;
	Chambre::Chambre chambre1(1, Type::Simple, 100);
	liste.push_back(chambre1);
	Chambre::Chambre chambre2(2, Type::Simple, 100);
	liste.push_back(chambre2);
	Chambre::Chambre chambre3(3, Type::Simple, 100);
	liste.push_back(chambre3);
	Chambre::Chambre chambre4(4, Type::Double, 125);
	liste.push_back(chambre4);
	Chambre::Chambre chambre5(5, Type::Double, 125);
	liste.push_back(chambre5);
	Chambre::Chambre chambre6(6, Type::Double, 125);
	liste.push_back(chambre6);
	Chambre::Chambre chambre7(7, Type::Double, 125);
	liste.push_back(chambre7);
	Chambre::Chambre chambre8(8, Type::Double, 125);
	liste.push_back(chambre8);
	Chambre::Chambre chambre9(9, Type::Suite, 210);
	liste.push_back(chambre9);
	Chambre::Chambre chambre10(10, Type::Suite, 210);
	liste.push_back(chambre10);

	//initialisation des 10 clients
	std::vector<Client::Client> liste_clients;
	Client::Client client1(1, "Nom1", "Prenom1");
	liste_clients.push_back(client1);
	Client::Client client2(2, "Nom2", "Prenom2");
	liste_clients.push_back(client2);
	Client::Client client3(3, "Nom3", "Prenom3");
	liste_clients.push_back(client3);
	Client::Client client4(4, "Nom4", "Prenom4");
	liste_clients.push_back(client4);
	Client::Client client5(5, "Nom5", "Prenom5");
	liste_clients.push_back(client5);
	Client::Client client6(6, "Nom6", "Prenom6");
	liste_clients.push_back(client6);
	Client::Client client7(7, "Nom7", "Prenom7");
	liste_clients.push_back(client7);
	Client::Client client8(8, "Nom8", "Prenom8");
	liste_clients.push_back(client8);
	Client::Client client9(9, "Nom9", "Prenom9");
	liste_clients.push_back(client9);
	Client::Client client100(10, "Nom10", "Prenom10");
	liste_clients.push_back(client100);
	
	//Creation de l'hotel
	Hotel::Hotel hotel1("h1", "L'hotel", "Dijon", liste, liste_clients);
	
	std::vector<Reservation::Reservation> liste_reservations;

	start();












	/*
	liste_reservations.push_back(ajouter_reservation(1, hotel1));
	liste_reservations.push_back(ajouter_reservation(2, hotel1));
	liste_reservations.push_back(ajouter_reservation(3, hotel1));
	*/

	/*	Test avec les résérvations
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

	/* Test annulation résérvation
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
	//On demande la date de début
	int année;
	std::cout << "Saisir l'annee de debut" << std::endl;
	std::cin >> année;
	std::cout << std::endl;
	int mois;
	std::cout << "Saisir le mois de debut" << std::endl;
	std::cin >> mois;
	std::cout << std::endl;
	int jour;
	std::cout << "Saisir le jour de debut" << std::endl;
	std::cin >> jour;
	std::cout << std::endl;

	Date::Date date_debut(année, mois, jour);	//Le constructeur de Date appelle la fonction CheckDate()

	//On demande la date de fin
	std::cout << "Saisir l'annee de fin" << std::endl;
	std::cin >> année;
	std::cout << std::endl;
	std::cout << "Saisir le mois de fin" << std::endl;
	std::cin >> mois;
	std::cout << std::endl;
	std::cout << "Saisir le jour de fin" << std::endl;
	std::cin >> jour;
	std::cout << std::endl;

	Date::Date date_fin(année, mois, jour);

	//Si la date de fin est bien après la date de début, on return la Reservation sinon on recommence
	if ((date_debut <= date_fin) == true) {

		std::cout << "Nombre de nuits reserves : " << nbr_nuits(date_debut, date_fin) << std::endl;	//On affiche le nombre de nuits

		Chambre::Chambre chambre_choisi = choisir_chambre(date_debut, date_fin, hotel);
		Client::Client client_choisi = choisir_client(hotel);
		std::cout << "Client :" << client_choisi.get_nom() << " " << client_choisi.get_prenom() << "( id = " << client_choisi.get_id() << " )" << std::endl;
		Reservation::Reservation reser(id, date_debut, date_fin, hotel, chambre_choisi, client_choisi);
		std::cout << "Le montant sans reduction de fidelite est de " << reser.get_montant() << " $";
		return reser;
	}
	else {
		Reservation::Reservation reser = ajouter_reservation(id, hotel);
		return reser;
	}

	
}

int nbr_nuits(Date::Date date_debut, Date::Date date_fin)
{
	int nbr = date_fin - date_debut;	//Surcharge d'opérateur - dans la classe Date
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
			std::cout << "Reservation numero " << liste.at(i).get_id() << " , Client : id = " << liste.at(i).get_id_client() << " du " << liste.at(i).get_date_debut().toString() << " au " << liste.at(i).get_date_fin().toString() << " chambre numero " << liste.at(i).get_id_chambre() << " dans l'hotel numero " << liste.at(i).get_id_hotel() << std::endl;
		}
	}
}

void afficher_reservations_par_numero(std::vector<Reservation::Reservation> liste, int numero)
{
	if (liste.size() > 0) {
		for (int i = 0; i < liste.size(); i++) {
			if (liste.at(i).get_id() == numero) {
				std::cout << "Reservation numero " << liste.at(i).get_id() << " , Client : id = " << liste.at(i).get_id_client() << " du " << liste.at(i).get_date_debut().toString() << " au " << liste.at(i).get_date_fin().toString() << " chambre numero " << liste.at(i).get_id_chambre() << " dans l'hotel numero " << liste.at(i).get_id_hotel() << std::endl;
			}
		}
	}
}

void afficher_reservations_par_client(std::vector<Reservation::Reservation> liste, int id_client)
{
	if (liste.size() > 0) {
		for (int i = 0; i < liste.size(); i++) {
			if (liste.at(i).get_id_client() == id_client) {
				std::cout << "Reservation numero " << liste.at(i).get_id() << " , Client : id = " << liste.at(i).get_id_client() << " du " << liste.at(i).get_date_debut().toString() << " au " << liste.at(i).get_date_fin().toString() << " chambre numero " << liste.at(i).get_id_chambre() << " dans l'hotel numero " << liste.at(i).get_id_hotel() << std::endl;
			}
		}
	}
}

void afficher_reservations_par_client(std::vector<Reservation::Reservation> liste, std::string nom_client)
{
	if (liste.size() > 0) {
		for (int i = 0; i < liste.size(); i++) {
			if (liste.at(i).get_nom_client() == nom_client) {
				std::cout << "Reservation numero " << liste.at(i).get_id() << " , Client : id = " << liste.at(i).get_id_client() << " du " << liste.at(i).get_date_debut().toString() << " au " << liste.at(i).get_date_fin().toString() << " chambre numero " << liste.at(i).get_id_chambre() << " dans l'hotel numero " << liste.at(i).get_id_hotel() << std::endl;
			}
		}
	}
}

void modifier_reservation(Reservation::Reservation& reservation)
{
	std::cout << "Que voulez vous modifier ?" << std::endl;
	std::cout << "Saisir 1 pour changer la date de début" << std::endl;
	std::cout << "Saisir 2 pour changer la date de fin" << std::endl;
	std::cout << "Saisir 3 pour changer la chambre" << std::endl;
	std::cout << "Saisir 4 pour changer le client" << std::endl;

	int choix;
	std::cin >> choix;

	if ((choix == 1) || (choix == 2)) {	//Changement de date de début ou de date de fin
		std::cout << std::endl << "Saisir la nouvelle année" << std::endl;
		int année;
		std::cin >> année;
		std::cout << std::endl << "Saisir le nouveau mois" << std::endl;
		int mois;
		std::cin >> mois;
		std::cout << std::endl << "Saisir le nouveau jour" << std::endl;
		int jour;
		std::cin >> jour;
		Date::Date new_date(année, mois, jour);
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
	std::cout << "     MENU     " << std::endl << std::endl;
	




}

void start()
{
	afficher_menu();

}
