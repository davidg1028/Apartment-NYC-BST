#pragma once
#pragma once
#include "ApartmentNYC.h"
#include "Visitor.h"
#include <vector>
#include <iostream>
#include <algorithm>


class BoroughFinder : public Visitor {

private:
	string locate;
	vector<ApartmentNYC> results;

	string toLower(const string& str) const;

public:
	BoroughFinder(string locate);
	//~RentFinder();

	void visit(ApartmentNYC apt);

	vector<ApartmentNYC> getResults();

};

BoroughFinder::BoroughFinder(string locate) {
	this->locate = toLower(locate);

}

//Chat gbt helped with insensitive search
string BoroughFinder::toLower(const string& str) const {
	string lower = str;
	transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
	return lower;
}

void BoroughFinder::visit(ApartmentNYC apt) {
	string borough = toLower(apt.getBorough());
	if (borough.find(locate) != string::npos)
		results.push_back(apt);

}

vector<ApartmentNYC>BoroughFinder::getResults() {
	return results;
}

