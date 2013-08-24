#include "MessageReader.h"

MessageReader::MessageReader()
{
}

MessageReader::MessageReader(char *_buffer): buffer(_buffer), position(0)
{
}

void MessageReader::setPosition(int pos)
{
    position = pos;
}

int MessageReader::getPosition()
{
    return position;
}

int MessageReader::bytesAvailable()
{
    return strlen(buffer) - position;
}

signed short MessageReader::ReadShort()
{
    signed short s =
        buffer[position] * 256 +
        buffer[position + 1];

    position += 2;

    return s;
}

unsigned short MessageReader::ReadUShort()
{
    unsigned short s =
        (unsigned char)buffer[position] * 256 +
        (unsigned char)buffer[position + 1];

    position += 2;

    return s;
}

char MessageReader::ReadByte()
{
    char s = buffer[position];

    position++;

    return s;
}

char* MessageReader::ReadBytes(int len)
{
    char *s = new char[len + 1];
    int i;

    for(i = 0; i < len; i++)
    {
        s[i] = buffer[position + i];
    }

    s[i] = '\0';

    position += len;

    return s;
}

signed int MessageReader::ReadInt()
{
    signed int i =
        buffer[position] * 16777216 +
        buffer[position + 1] * 65536 +
        buffer[position + 2] * 256 +
        buffer[position + 3];

    position += 4;

    return i;
}

unsigned int MessageReader::ReadUInt()
{
    unsigned int i =
        (unsigned char)buffer[position] * 16777216 +
        (unsigned char)buffer[position + 1] * 65536 +
        (unsigned char)buffer[position + 2] * 256 +
        (unsigned char)buffer[position + 3];

    position += 4;
    return i;
}

char* MessageReader::ReadUTF()
{
    unsigned short len = ReadUShort();

    char *s = new char[len + 1];

    int i;

    for(i = 0; i < len; i++)
    {
        s[i] = buffer[position + i];
    }

    s[i] = '\0';

    position += len;

    return s;
}

bool MessageReader::ReadBool()
{
    return ReadByte() == 1 ? true : false;
}
