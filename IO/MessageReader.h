#ifndef MESSAGE_READER_H
#define MESSAGE_READER_H

#include <fstream>
#include <cstring>

class MessageReader
{
private:
    char* buffer;
    int position;

public:
    MessageReader();
    MessageReader(char * _buffer);

    void    setPosition(int pos);
    int     getPosition();
    int     bytesAvailable();

    signed short    ReadShort();
    unsigned short  ReadUShort();
    char            ReadByte();
    char*           ReadBytes(int len);
    signed int      ReadInt();
    unsigned int    ReadUInt();
    char*           ReadUTF();
    bool            ReadBool();
};

#endif // MESSAGE_READER_H
