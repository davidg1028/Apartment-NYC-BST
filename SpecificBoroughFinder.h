#pragma once

#include "ApartmentNYC.h"
#include "Visitor.h"
#include <vector>
#include <iostream>

class SpecificBoroughFinder : public Visitor {

private:
	string targetBorough;
	vector<ApartmentNYC> results;

public:
	SpecificBoroughFinder(string targetBorough);
	//~RentFinder();

	void visit(ApartmentNYC apt);

	vector<ApartmentNYC> getResults();

};

SpecificBoroughFinder::SpecificBoroughFinder(string targetBorough) {
	this->targetBorough = targetBorough;

}


void SpecificBoroughFinder::visit(ApartmentNYC apt) {
	if (apt.getBorough() == targetBorough)
		results.push_back(apt);

}


vector<ApartmentNYC>SpecificBoroughFinder::getResults() {
	return results;
}


