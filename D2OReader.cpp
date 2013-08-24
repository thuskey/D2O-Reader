#include "D2OReader.h"

D2OReader::D2OReader(const char* filePath)
{
    char* binary;

    ifstream d2oFile(filePath, ios::in | ios::binary | ios::ate);

    if(d2oFile.is_open())
    {
        int size = d2oFile.tellg();
        binary = new char[size];
        d2oFile.seekg(0, ios::beg);
        d2oFile.read(binary, size);
        d2oFile.close();
    }

    reader = new MessageReader(binary);

    datacenter.Register();
    initialize();
}

void D2OReader::initialize()
{
    char* headers = reader->ReadBytes(3);

    if(strcmp(headers, "D2O") != 0)
        throw "Header doesn't equal the string 'D2O' : Corrupted file";

    readIndexTable();
    readClassesTable();
}

void D2OReader::readIndexTable()
{
    headerOffset = reader->ReadUInt();
    reader->setPosition(headerOffset);
    indexTableLen = reader->ReadUInt();

    for(int i = 0; i < indexTableLen; i += 8)
    {
        indexTable.insert(pair<int, int>(reader->ReadUInt(), reader->ReadUInt()));
    }
}

void D2OReader::readClassesTable()
{
    classCount = reader->ReadUInt();

    for(int i = 0; i < classCount; i++)
    {
        int classId = reader->ReadUInt();
        char* classMemberName = reader->ReadUTF();
        char* classPackageName = reader->ReadUTF();

        IDataCenter* currentClass = datacenter.get(classMemberName);

        if(currentClass == 0)
            throw "No data class found";

        //currentClass->getModuleName();

        int fieldsCount = reader->ReadInt();

        for(int j = 0; j < fieldsCount; j++)
        {
            char* fieldName = reader->ReadUTF();
            D2OFieldType fieldType = (D2OFieldType)reader->ReadUInt();
            cout << fieldName << endl;

            if(fieldType == Vector)
            {
                addVectorType:

                char* name = reader->ReadUTF();
                D2OFieldType id = (D2OFieldType)reader->ReadUInt();

                if(id == Vector)
                    goto addVectorType;
            }
        }
    }
}
