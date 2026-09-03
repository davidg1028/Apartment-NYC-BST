#include "ApartmentNYC.h"
#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include <vector>
#include "Menu.h"



using namespace std;

vector<ApartmentNYC> buildVector();
int main()
{
    vector<ApartmentNYC> apt;
    BinarySearchTree<ApartmentNYC> apartmentTree;

    apt = buildVector();

    for (ApartmentNYC a : apt)
        //cout << a << "\n";
        apartmentTree.add(a);

    Menu menu(apartmentTree);
    menu.displayMainMenu();
    


    return 0;
}


vector<ApartmentNYC> buildVector() {
    vector<ApartmentNYC> apartments;
    ifstream file("apartment_inventory_nyc-1.csv");

    string line;
    getline(file, line);

    while (getline(file, line)) {
        if (!line.empty()) {
            ApartmentNYC apt(line);
            apartments.push_back(apt);
        }//end if
    }//end while

    file.close();

    return apartments;
}//end build vetcor





/*------------------------------------------This is my testing code that i used to make sure my visitors worked properly--------------------------------
void displayRentRange(BinarySearchTree<ApartmentNYC>& apartmentTree);
void displayMinSquareFoot(BinarySearchTree<ApartmentNYC>& apartmentTree);
void displayBoroughSearch(BinarySearchTree<ApartmentNYC>& apartmentTree);
void searchBySqFt(BinarySearchTree<ApartmentNYC>& apartmentTree);
void searchByBorough(BinarySearchTree<ApartmentNYC>& apartmentTree);


apt = buildVector();

    

    apartmentTree.inOrderTraverse();

    cout << "-----------------------------------------" << endl;

    //displayRentRange(apartmentTree);

    cout << "-----------------------------------------" << endl;

    //displayMinSquareFoot(apartmentTree);

    cout << "-----------------------------------------" << endl;

    //displayBoroughSearch(apartmentTree);

    searchBySqFt(apartmentTree);

    searchByBorough(apartmentTree);

    return 0;
}


void searchByBorough(BinarySearchTree<ApartmentNYC>& apartmentTree) {
    string input;

    cout << "Enter part or full borough name to begin search: ";
    cin >> input;

    BoroughFinder finder(input);

    apartmentTree.inorderVisit(finder);

    vector<ApartmentNYC> result = finder.getResults();

    cout << "\nApartments found in search: " << "\n";
    if (!result.empty()) {
        for (ApartmentNYC apt : result)
            cout << apt << endl;
    }
    else
        cout << "no results from search..." << endl;

}


void searchBySqFt(BinarySearchTree<ApartmentNYC>& apartmentTree) {
    cout << "\nChoose a square footage range:\n";
    cout << "1. Less than 1600 sq ft\n";
    cout << "2. 1600 - 2000 sq ft\n";
    cout << "3. Greater than 2000 sq ft\n";
    cout << "Enter your choice (1-3): ";

    int choice;
    cin >> choice;

    int minSqFt = 0;
    int maxSqFt = 100000; // big default upper bound

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

}


void displayBoroughSearch(BinarySearchTree<ApartmentNYC>& apartmentTree) {
    string borough;

    cout << "\nEnter borough to search(e.g., Manhattan, Bronx, Brooklyn, Queens, Staten Island) : ";
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


}//endBorughSearch


void displayMinSquareFoot(BinarySearchTree<ApartmentNYC>& apartmentTree) {
    int squareFoot;

    cout << "Enter a min square foot: ";
    cin >> squareFoot;

    SquareFootageFinder finder(squareFoot);

    apartmentTree.inorderVisit(finder);

    vector<ApartmentNYC> result = finder.getResults();

    cout << "\nApartments with a square foot above " << squareFoot << " below: " << endl;
    if (!result.empty()) {
        for (ApartmentNYC apt : result)
            cout << apt << endl;
    }
    else
        cout << "no results from search..." << endl;

}//end minSquareFoot



void displayRentRange(BinarySearchTree<ApartmentNYC>& apartmentTree) {

    double rentAmount1 = 0,
        rentAmount2 = 0;

    cout << "Enter a min rent amount $";
    cin >> rentAmount1;
    cout << "Enter a max rent amount $";
    cin >> rentAmount2;

    RentFinder finder(rentAmount1, rentAmount2);

    apartmentTree.inorderVisit(finder);

    vector<ApartmentNYC> result = finder.getResults();

    cout << "\nApartments between $" << rentAmount1 << " & $" << rentAmount2 << "\n";
    if (!result.empty()) {
        for (ApartmentNYC apt : result)
            cout << apt << endl;
    }
    else
        cout << "no results from search..." << endl;

}//endDispalyRentRange


vector<ApartmentNYC> buildVector() {
    vector<ApartmentNYC> apt = {
          ApartmentNYC("1403 5th Ave","Queens",3,3,916,3913.84),
          ApartmentNYC("3786 Broadway","The Bronx",4,3,2923,3123.4),
          ApartmentNYC("7956 5th Ave","Manhattan",1,3,1346,2969.02),
          ApartmentNYC("3115 Broadway","The Bronx",3,2,1426,4205.87)
    };

    return apt;
}


*/