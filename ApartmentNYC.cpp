#include "ApartmentNYC.h"
#include <iomanip>
#include <sstream>

ApartmentNYC::ApartmentNYC() {
	streetAddress = " ";
	borough = " ";
	bedrooms = 0;
	bathrooms = 0;
	squareFoot = 0;
	monthlyRent = 0.0;

}


ApartmentNYC::ApartmentNYC(const string& line) {
	istringstream ss(line);
	string temp = "";

	getline(ss, streetAddress, ',');
	getline(ss, borough, ',');
	getline(ss, temp, ',');
	bedrooms = stoi(temp);
	getline(ss, temp, ',');
	bathrooms = stoi(temp);
	getline(ss, temp, ',');
	squareFoot = stoi(temp);
	getline(ss, temp, ',');
	monthlyRent = stod(temp);
}


ApartmentNYC::ApartmentNYC(const string& streetAddress, const string& borough, const int& bedrooms,
	const int& bathrooms, const int& squareFoot, const double& monthlyRent) {
	this->streetAddress = streetAddress;
	this->borough = borough;
	this->bedrooms = bedrooms;
	this->bathrooms = bathrooms;
	this->squareFoot = squareFoot;
	this->monthlyRent = monthlyRent;

}


//getters
string ApartmentNYC::getStreetAddress() {
	return streetAddress;
}


string ApartmentNYC::getBorough() {
	return borough;
}


int ApartmentNYC::getBedrooms() {
	return bedrooms;
}


int ApartmentNYC::getBathrooms() {
	return bathrooms;
}


int ApartmentNYC::getSquareFoot() {
	return squareFoot;
}


double ApartmentNYC::getMonthlyRent() {
	return monthlyRent;
}


string ApartmentNYC::getCurrent() const {
	ostringstream oss;
	oss << left;
	oss << "-------------------------------------------------------------------------------------------------\n";
	oss << "| Street Address       | Borough          | Bedrooms | Bathrooms | Square Foot   | Monthly Rent |\n";
	oss << "-------------------------------------------------------------------------------------------------\n";

	oss << "| " << setw(20) << streetAddress
		<< " | " << setw(16) << borough
		<< " | " << setw(8) << bedrooms
		<< " | " << setw(9) << bathrooms
		<< " | " << setw(13) << squareFoot
		<< " | $" << setw(11) << fixed << setprecision(2) << monthlyRent << " |\n";
	oss << "-------------------------------------------------------------------------------------------------\n";

	string object = oss.str();

	return object;
}


//You ask for part 3 to only print out Address, borough, and rent
string ApartmentNYC::getCurrent2() const {
	ostringstream oss;
	oss << left;

	oss << "----------------------------------------------------------\n";
	oss << "| Street Address       | Borough          | Monthly Rent |\n";
	oss << "----------------------------------------------------------\n";

	oss << "| " << setw(20) << streetAddress
		<< " | " << setw(16) << borough
		<< " | $" << setw(11) << fixed << setprecision(2) << monthlyRent << " |\n";

	oss << "----------------------------------------------------------\n";

	string object = oss.str();

	return oss.str();


}//end getCurrent2


//setters
void ApartmentNYC::setStreetAddress(string streetAddress) {
	this->streetAddress = streetAddress;
}


void ApartmentNYC::setBorough(string borough) {
	this->borough = borough;
}


void ApartmentNYC::setBedrooms(int bedrooms) {
	this->bedrooms = bedrooms;
}


void ApartmentNYC::setBathrooms(int bathrooms) {
	this->bathrooms = bathrooms;
}


void ApartmentNYC::setSquareFoot(int squareFoot) {
	this->squareFoot = squareFoot;
}


void ApartmentNYC::setMonthlyRent(double monthlyRent) {
	this->monthlyRent = monthlyRent;
}


//operators
bool ApartmentNYC::operator<(const ApartmentNYC& apt) const {
	return(this->monthlyRent) < (apt.monthlyRent);
}


ostream& operator<<(ostream& os, const ApartmentNYC& apt) {
	os << "Apartment info below: " << "\n" << apt.getCurrent() << endl;

	return os;
}

bool ApartmentNYC::operator<(int amount) const {
	return(this->monthlyRent) < (amount);
}


bool ApartmentNYC::operator>(int amount) const {
	return(this->squareFoot) > (amount);
}


bool ApartmentNYC::operator==(const ApartmentNYC& apt) const {
	return(this->streetAddress, this->borough, this->bedrooms, this->bathrooms, this->squareFoot, this->monthlyRent)
		== (apt.streetAddress, apt.borough, apt.bedrooms, apt.bathrooms, apt.squareFoot, apt.monthlyRent);
}


//no scope resolution needed for friend
istream& operator>>(istream& is, ApartmentNYC& apt) {
	string line;
    getline(is, line);

    istringstream ss(line);
    string temp;

    getline(ss, apt.streetAddress, ',');
    getline(ss, apt.borough, ',');
    
    getline(ss, temp, ',');
    apt.bedrooms = stoi(temp);

    getline(ss, temp, ',');
    apt.bathrooms = stoi(temp);

    getline(ss, temp, ',');
    apt.squareFoot = stoi(temp);

    getline(ss, temp, ',');
    apt.monthlyRent = stod(temp);

	/* didn;t like it being separated by space so lets do commas
	char dot = ' ';

	is >> apt.streetAddress;
	is >> apt.borough;
	is >> apt.bedrooms;
	is >> apt.bathrooms;
	is >> apt.squareFoot;
	is >> apt.monthlyRent;
	*/
	return is;
}


//----------------my operators-------------------------
//for comparing squareFoot for max
bool ApartmentNYC::operator>(const ApartmentNYC& apt) const {
	return this->squareFoot > apt.squareFoot;
}


//for comparing squareFoot for min
//bool ApartmentNYC::operator<(const ApartmentNYC& apt) const {
	//return this->squareFoot < apt.squareFoot;
//}


//for comparing squareFoot for min
bool ApartmentNYC::smallestSquareFoot(const ApartmentNYC& apt) const {
	return this->squareFoot < apt.squareFoot;
}

