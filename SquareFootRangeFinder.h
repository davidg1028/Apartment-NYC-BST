#pragma once
#include "ApartmentNYC.h"
#include "Visitor.h"
#include <vector>
#include <iostream>

class SquareFootRangeFinder : public Visitor {

private:
	int minSqFt;
	int maxSqFt;
	vector<ApartmentNYC> results;

public:
	SquareFootRangeFinder(int minSqFt, int maxSqFt);
	//~RentFinder();

	void visit(ApartmentNYC apt);

	vector<ApartmentNYC> getResults();

};

SquareFootRangeFinder::SquareFootRangeFinder(int minSqFt, int maxSqFt) {
	this->minSqFt = minSqFt;
	this->maxSqFt = maxSqFt;

}

void SquareFootRangeFinder::visit(ApartmentNYC apt) {
	if (apt.getSquareFoot() >= minSqFt && apt.getSquareFoot() <= maxSqFt)
		results.push_back(apt);

}

vector<ApartmentNYC>SquareFootRangeFinder::getResults() {
	return results;
}

