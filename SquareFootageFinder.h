#pragma once
#include "ApartmentNYC.h"
#include "Visitor.h"
#include <vector>
#include <iostream>

class SquareFootageFinder : public Visitor {

private:
	int minSquareFoot;
	vector<ApartmentNYC> results;

public:
	SquareFootageFinder(int minSquareFoot);
	//~RentFinder();

	void visit(ApartmentNYC apt);

	vector<ApartmentNYC> getResults();

};


SquareFootageFinder::SquareFootageFinder(int minSquareFoot) {
	this->minSquareFoot = minSquareFoot;

}


void SquareFootageFinder::visit(ApartmentNYC apt) {
	if (apt.getSquareFoot() >= minSquareFoot)
		results.push_back(apt);

}


vector<ApartmentNYC>SquareFootageFinder::getResults() {
	return results;
}

