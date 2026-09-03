#pragma once

#include <iostream>
#include <string>
using namespace std;

class ApartmentNYC
{
private:
	string streetAddress;
	string borough;
	int bedrooms;
	int bathrooms;
	int squareFoot;
	double monthlyRent;

public:
	ApartmentNYC();
	ApartmentNYC(const string& line);
	ApartmentNYC(const string& streetAddress, const string& borough, const int& bedrooms,
		const int& bathrooms, const int& squareFoot, const double& monthlyRent);


	//getters
	string getStreetAddress();
	string getBorough();
	int getBedrooms();
	int getBathrooms();
	int getSquareFoot();
	double getMonthlyRent();
	string getCurrent() const;
	string getCurrent2() const;

	//setters
	void setStreetAddress(string streetAddress);
	void setBorough(string borough);
	void setBedrooms(int bedrooms);
	void setBathrooms(int bathrooms);
	void setSquareFoot(int squareFoot);
	void setMonthlyRent(double monthlyRent);

	//overloaded operators
	bool operator<(const ApartmentNYC& apt) const;
	friend ostream& operator<<(ostream& os, const ApartmentNYC& apt);
	bool operator<(int amount) const;
	bool operator>(int amount) const;
	bool operator==(const ApartmentNYC& apt) const;
	friend istream& operator>>(istream& is, ApartmentNYC& apt);

	//my added operators
	bool operator>(const ApartmentNYC& apt) const;
	//bool operator<(const ApartmentNYC& apt) const; nvm I can't have two of the same operator

	bool smallestSquareFoot(const ApartmentNYC& apt) const;


};

