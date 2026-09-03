#pragma once
#include "ApartmentNYC.h"


#pragma once
#include "ApartmentNYC.h"

class Visitor {
public:
    virtual ~Visitor() = default;  
    virtual void visit(ApartmentNYC apartment) = 0;
};

