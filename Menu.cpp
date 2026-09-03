#include "Menu.h"
#include <iostream>
#include <limits>
#include "Visitor.h"
#include "BoroughFinder.h"
#include "RentFinder.h"
#include "SquareFootageFinder.h"
#include "SpecificBoroughFinder.h"
#include "SquareFootRangeFinder.h"

using namespace std;

Menu::Menu(BinarySearchTree<ApartmentNYC>& tree) : apartmentTree(tree) {}

void Menu::displayMainMenu() {

	int choice;

	do {
        cout << "\n******** MAIN MENU ********\n";
        cout << "1. Search\n";
        cout << "2. Generate Reports\n";
        cout << "3. Maximums and Minimums\n";
        cout << "4. Edit Apartment Data\n";
        cout << "5. Perform Traversal\n";
        cout << "6. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: showSearchMenu(); 
            break;
        case 2: showReportMenu(); 
            break;
        case 3: showMaxMinMenu(); 
            break;
        case 4: showEditMenu(); 
            break;
        case 5: showTraversalMenu();
            break;
        case 6: cout << "\nGoodbye and thanks for trying out my menu!\n";
        default: cout << "Invalid choice. Try again.\n"; 
            break;

        }//end switch

    } while (choice != 6);

}//end displayMainMenu


void Menu::showSearchMenu() {
    int choice;
    do {
        cout << "\n-------- Search Menu --------\n";
        cout << "1. Search by Borough\n";
        cout << "2. Search by Rent Range\n";
        cout << "3. Search by Minimum Square Footage\n";
        cout << "4. Return to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            searchByBorough();
        }break;
        case 2:
            searchByRentRange();
            break;
        case 3: 
            searchByMinSqFt();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

}//end show search menu


void Menu::showReportMenu() {
    int choice;
    do {
        cout << "\n----- Reports Menu -----\n";
        cout << "1. List All Apartments\n";
        cout << "2. List by Borough\n";
        cout << "3. List by Square Foot Range\n";
        cout << "4. Post Order Traverse\n";
        cout << "5. Return to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nListing all apartments...\n";
            apartmentTree.inOrderTraverse(); // basic listing
            break;
        case 2: 
            listByBorough();
              break;
        case 3: 
            listBySqFtRange();
            break;
        case 4:
            apartmentTree.postOrderDelete();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);


}//end show report menu


void Menu::showMaxMinMenu() {
    int choice;
    do {
        cout << "\n----- Maximums and Minimums -----\n";
        cout << "1. Maximum Rent\n";
        cout << "2. Maximum Square Footage\n";
        cout << "3. Minimum Rent\n";
        cout << "4. Minimum Square Footage\n";
        cout << "5. Return to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:// Maximum Rent
            cout << "\n--- Maximum Rent ---\n";
            displayMaxRent();
        break;
        case 2:
            cout << "\n--- Maximum Square Foot ---\n";
            displayMaxSquareFoot();
            break;
        case 3:
            cout << "\n--- Minimum Rent ---\n";
            displayMinRent();
            break;
        case 4:
            cout << "\n--- Minimum Square Foot ---\n";
            displayMinSquareFoot();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

}//end show max/min menu


void Menu::showEditMenu() {
    int choice;
    do {
        cout << "\n----- Edit Menu -----\n";
        cout << "1. Edit Apartment Rent\n";
        cout << "2. Edit Bedrooms\n";
        cout << "3. Add New Apartment\n";
        cout << "4. Return to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            editApartmentRent();
            break;
        case 2:
            editApartmentBedroom();
            break;
        case 3:
            addNewApartment();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

}//end show edit menu


void Menu::showTraversalMenu() {
    int choice;
    do {
        cout << "\n----- Edit Menu -----\n";
        cout << "1. Perform inorder traversal\n";
        cout << "2. Perfrom preorder traversal\n";
        cout << "3. Perform postOrder traversal\n";
        cout << "4. Return to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nI only have one inorderTraverse in BTS so this will display with all attributes\n";
            apartmentTree.inOrderTraverse();
            break;
        case 2:
            cout << "\nI created a second getCurrent2 to display only address, borough, and rent\n";
            apartmentTree.preOrderTraverse();
            break;
        case 3:
            cout << "\nDidnt use same format since display is deleting\n";
            apartmentTree.postOrderDelete();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);


}//end show Traversal Menu


void Menu::addNewApartment() {
    ApartmentNYC newApartment;

    cout << "\nPlease enter the following information separated by commas:\n";
    cout << "[StreetAddress],[Borough],[Bedrooms],[Bathrooms],[SquareFoot],[MonthlyRent]\n";
    cout << "Example: 123MainSt,Manhattan,2,1,750,2800\n";
    cout << "Input: ";
    cin.ignore();

    try {
        cin >> newApartment;
        apartmentTree.add(newApartment);
        cout << "\nApartment added successfully:\n";
        cout << newApartment << endl;
    }
    catch (const exception& e) {
        cerr << "\nError: Invalid input format or data type.\n";
        cerr << "Details: " << e.what() << endl;
    }
}//end add new apartment


void Menu::editApartmentBedroom() {
    string targetAddress;
    cout << "\nEnter the street address of the apartment you want to edit bedrooms for: ";
    cin.ignore(); 
    getline(cin, targetAddress);

    bool edited = searchAndEditBedroom(apartmentTree.getRoot(), targetAddress);

    if (!edited) {
        cout << "\nNo apartment found with the address \"" << targetAddress << "\".\n";
    }

}//end edit apartment bedroom


bool Menu::searchAndEditBedroom(Node<ApartmentNYC>* current, const string& address) {
    if (current == nullptr)
        return false;

    ApartmentNYC& apt = current->getData();

    if (apt.getStreetAddress() == address) { 
        cout << "\nApartment found:\n" << apt << endl;

        int newBedrooms;
        cout << "Enter new number of bedrooms: ";
        cin >> newBedrooms;

        apt.setBedrooms(newBedrooms);

        cout << "\nBedroom updated successfully:\n" << apt << endl;
        return true;
    }

    //Search left then right
    return searchAndEditBedroom(current->getLeftChild(), address) ||
        searchAndEditBedroom(current->getRightChild(), address);

}//end search and edit Bedrooms


void Menu::editApartmentRent() {
    string targetAddress;
    cout << "\nEnter the street address of the apartment you want to edit: ";
    cin.ignore();
    getline(cin, targetAddress);

    bool edited = searchAndEditRent(apartmentTree.getRoot(), targetAddress);

    if (!edited) {
        cout << "No apartment found with the address \"" << targetAddress << "\".\n";
    }

}//end editAprtmentRent


bool Menu::searchAndEditRent(Node<ApartmentNYC>* current, const string& address) {
    if (current == nullptr)
        return false;

    ApartmentNYC& apt = current->getData();

    if (apt.getStreetAddress() == address) {
        cout << "\nApartment found:\n" << apt << endl;

        double newRent;
        cout << "Enter new monthly rent: $";
        cin >> newRent;

        apt.setMonthlyRent(newRent);

        cout << "\nRent updated successfully:\n" << apt << endl;
        return true;
    }

    //Search left then right
    return searchAndEditRent(current->getLeftChild(), address) ||
        searchAndEditRent(current->getRightChild(), address);

}//end searchAndEditApartment


void Menu::displayMaxRent() {
    Node<ApartmentNYC>* current = apartmentTree.getRoot();

    while (current->getRightChild() != nullptr) {
        current = current->getRightChild();
    }

    cout << "\nApartment with the highest rent:\n";
    cout << current->getData() << endl;
}//end displayMaxRent


void Menu::displayMinRent() {
    Node<ApartmentNYC>* current = apartmentTree.getRoot();

    while (current->getLeftChild() != nullptr) {
        current = current->getLeftChild();
    }

    cout << "\nApartment with the cheapest rent:\n";
    cout << current->getData() << endl;

}//end displayMinRent


void Menu::displayMaxSquareFoot() {
    ApartmentNYC maxApartment = findMaxSquareFoot(apartmentTree.getRoot(), apartmentTree.getRoot()->getData());

    cout << "\nApartment with the maximum square footage:\n";
    cout << maxApartment << endl;
}//display MaxSquareFoot


ApartmentNYC Menu::findMaxSquareFoot(Node<ApartmentNYC>* current, ApartmentNYC currentMax) {
    if (current == nullptr) {
        return currentMax;
    }

    ApartmentNYC currentApt = current->getData();

    if (currentApt > currentMax) {
        currentMax = currentApt;
    }

    currentMax = findMaxSquareFoot(current->getLeftChild(), currentMax);
    currentMax = findMaxSquareFoot(current->getRightChild(), currentMax);

    return currentMax;

}//end findMaxSquareFoot


void Menu::displayMinSquareFoot() {
    ApartmentNYC minApartment = findMinSquareFoot(apartmentTree.getRoot(), apartmentTree.getRoot()->getData());
    cout << "\nApartment with the minimum square footage:\n";
    cout << minApartment << endl;
}//end displayMinSquareFoot


ApartmentNYC Menu::findMinSquareFoot(Node<ApartmentNYC>* current, ApartmentNYC currentMin) {
    if (current == nullptr) {
        return currentMin;
    }

    ApartmentNYC currentApt = current->getData();

    if (currentApt.smallestSquareFoot(currentMin)) {
        currentMin = currentApt;
    }

    currentMin = findMinSquareFoot(current->getLeftChild(), currentMin);
    currentMin = findMinSquareFoot(current->getRightChild(), currentMin);

    return currentMin;

}//end displayMinSquareFoot


void Menu::searchByBorough() {
    string input;

    cout << "\nEnter part or full borough name to begin search: ";
    cin >> input;

    BoroughFinder finder(input);

    apartmentTree.inorderVisit(finder);

    vector<ApartmentNYC> result = finder.getResults();

    cout << "\nApartments found in search for: " << input << "\n";
    if (!result.empty()) {
        for (ApartmentNYC apt : result)
            cout << apt << endl;
    }
    else
        cout << "no results from search..." << endl;

}//end searchByBorough


void Menu::searchByRentRange() {
    double rentAmount1 = 0,
        rentAmount2 = 0;
    cout << "\nEnter a minimum rent amount $";
    cin >> rentAmount1;
    cout << "Enter a maximum rent amount $";
    cin >> rentAmount2;

    RentFinder finder(rentAmount1, rentAmount2);

    apartmentTree.inorderVisit(finder);

    vector<ApartmentNYC> result = finder.getResults();

    cout << "\nApartments with a rent amount between $" << rentAmount1 << " & $" << rentAmount2 << "\n";
    if (!result.empty()) {
        for (ApartmentNYC apt : result)
            cout << apt << endl;
    }
    else
        cout << "no results from search..." << endl;
    
}//end searchByRentRange


void Menu::searchByMinSqFt() {
    int squareFoot;

    cout << "\nEnter a min square foot: ";
    cin >> squareFoot;

    SquareFootageFinder finder(squareFoot);

    apartmentTree.inorderVisit(finder);

    vector<ApartmentNYC> result = finder.getResults();

    cout << "\nApartments with a square footage above " << squareFoot << " listed below: " << endl;
    if (!result.empty()) {
        for (ApartmentNYC apt : result)
            cout << apt << endl;
    }
    else
        cout << "no results from search..." << endl;

}//end searchByMInSqFt


void Menu::listByBorough() {
    string borough;

    cout << "\nEnter borough to search options are Manhattan, Bronx, Brooklyn, Queens, Staten Island: ";
    cin >> borough;

    SpecificBoroughFinder finder(borough);

    apartmentTree.inorderVisit(finder);

    vector<ApartmentNYC> result = finder.getResults();

    cout << "\nApartments in " << borough << " are listed below: " << endl;
    if (!result.empty()) {
        for (ApartmentNYC apt : result)
            cout << apt << endl;
    }
    else
        cout << "no results from search..." << endl;

}//end listByBorough


void Menu::listBySqFtRange() {
    cout << "\nChoose a square footage range:\n";
    cout << "1. Less than 1600 sq ft\n";
    cout << "2. 1600 - 2000 sq ft\n";
    cout << "3. Greater than 2000 sq ft\n";
    cout << "Enter your choice (1-3): ";

    int choice;
    cin >> choice;

    int minSqFt = 0;
    int maxSqFt = 100000; // big default

    switch (choice) {
    case 1:
        minSqFt = 0;
        maxSqFt = 1599;
        break;
    case 2:
        minSqFt = 1600;
        maxSqFt = 2000;
        break;
    case 3:
        minSqFt = 2001;
        maxSqFt = 100000;
        break;
    default:
        cout << "Invalid choice.\n";
        return;
    }

    SquareFootRangeFinder finder(minSqFt, maxSqFt);

    apartmentTree.inorderVisit(finder);

    vector<ApartmentNYC> result = finder.getResults();

    cout << "\nBelow are the apartments with a min square foot of " << minSqFt << "-" << maxSqFt << "\n";
    if (!result.empty()) {
        for (ApartmentNYC apt : result)
            cout << apt << endl;
    }
    else
        cout << "no results from search..." << endl;
}//end listBYSqFtRange

