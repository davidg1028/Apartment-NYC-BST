#pragma once

#include "ApartmentNYC.h"
#include "Visitor.h"
#include <vector>
#include <iostream>

class RentFinder : public Visitor {

private:
	double minRent;
	double maxRent;
	vector<ApartmentNYC> results;

public:
	RentFinder(double minRent, double maxRent);
	//~RentFinder();

	void visit(ApartmentNYC apt);

	vector<ApartmentNYC> getResults();

};

RentFinder::RentFinder(double minRent, double maxRent) {
	this->minRent = minRent;
	this->maxRent = maxRent;

}

void RentFinder::visit(ApartmentNYC apt) {
	if (apt.getMonthlyRent() >= minRent && apt.getMonthlyRent() <= maxRent)
		results.push_back(apt);

}

vector<ApartmentNYC>RentFinder::getResults() {
	return results;
}

