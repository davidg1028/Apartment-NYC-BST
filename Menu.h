#pragma once
#include "BinarySearchTree.h"
#include "ApartmentNYC.h"
#include "Node.h"


class Menu
{
private:
	BinarySearchTree<ApartmentNYC>& apartmentTree;

	//helper submenu
	void showSearchMenu();
	void showReportMenu();
	void showMaxMinMenu();
	void showEditMenu();
	void showTraversalMenu();


	void searchByBorough();
	void searchByRentRange();
	void searchByMinSqFt();
	void listByBorough();
	void listBySqFtRange();
	void displayMaxRent();
	void displayMinRent();
	void displayMaxSquareFoot();
	void displayMinSquareFoot();
	void editApartmentRent();
	void editApartmentBedroom();
	void addNewApartment();

	//tree is in order by rent so why not look from the root? left being the smallest and right the biggest 
	ApartmentNYC findMaxSquareFoot(Node<ApartmentNYC>* current, ApartmentNYC currentMax);
	ApartmentNYC findMinSquareFoot(Node<ApartmentNYC>* current, ApartmentNYC currentMin);

	//search for apartment
	bool searchAndEditRent(Node<ApartmentNYC>* current, const string& address);
	bool searchAndEditBedroom(Node<ApartmentNYC>* current, const string& address);


public:
	Menu(BinarySearchTree<ApartmentNYC>& tree);
	void displayMainMenu();


};

