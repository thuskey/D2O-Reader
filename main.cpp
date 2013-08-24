#include <iostream>
#include "D2OReader.h"

using namespace std;

int main()
{
    try
    {
        D2OReader("Breeds.d2o");
    }
    catch(const char* e)
    {
        cout << e << endl;
    }
}
