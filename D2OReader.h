#ifndef D2O_READER_H
#define D2O_READER_H

#include <iostream>
#include <fstream>
#include <map>

#include "Manager/DatacenterManager.h"

#include "IO/MessageReader.h"
#include "IO/MessageWriter.h"

#include "D2OFieldType.h"

using namespace std;

class D2OReader
{
public:
    D2OReader(const char* filePath);

private:
    void initialize();
    void readIndexTable();
    void readClassesTable();

    DatacenterManager datacenter;

    int classCount;
    int headerOffset;
    int indexTableLen;
    //map<int, D2OClassDefinition*> classes;
    map<int, int> indexTable;
    MessageReader* reader;
};

#endif // D2O_READER_H
