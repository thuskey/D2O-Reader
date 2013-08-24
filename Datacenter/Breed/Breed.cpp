#include "Breed.h"

IDataCenter* Breed::getInstance() const
{
    return new Breed(*this);
}

const char* Breed::getModuleName()
{
    return MODULE;
}
