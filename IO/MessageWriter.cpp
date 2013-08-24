#include "MessageWriter.h"

MessageWriter::MessageWriter(): position(0)
{
    buffer = new char[8126];
}

MessageWriter::MessageWriter(int len): position(0)
{
    buffer = new char[len];
}

MessageWriter::~MessageWriter()
{
    delete[] buffer;
}

void MessageWriter::reset()
{
    delete[] buffer;

    buffer = new char[8126];
    position = 0;
}

int MessageWriter::getPosition()
{
    return position;
}

char* MessageWriter::getBuffer()
{
    return buffer;
}

short MessageWriter::SwapShort(short s)
{
    return (s >> 8) | (s << 8);
}

int MessageWriter::SwapInt(int i)
{
    return (i >> 24) | ((i << 8) & 0x00FF0000) | ((i >> 8) & 0x0000FF00) | (i << 24);
}

long MessageWriter::SwapLong(long l)
{
    return (l >> 56) | ((l << 40) & 0x00FF000000000000) | ((l << 24) & 0x0000FF0000000000) | ((l << 8) & 0x000000FF00000000) | ((l >> 8) & 0x00000000FF000000) | ((l >> 24) & 0x0000000000FF0000) | ((l >> 40) & 0x000000000000FF00) | (l << 56);
}

double MessageWriter::SwapDouble(double d)
{
    int * p = (int*)&d;
    int tmp = p[0];
    p[0] = SwapInt(p[1]);
    p[1] = SwapInt(tmp);

    return d;
}

void MessageWriter::WriteByte(char b)
{
    buffer[position] = b;
    position++;
}

void MessageWriter::WriteBytes(char* bs, int len)
{
    int i;

    for(i = 0; i < len; i++)
        buffer[position + i] = bs[i];

    position += i;
}

void MessageWriter::WriteShort(short s)
{
    s = SwapShort(s);
    memcpy(buffer + position, &s, sizeof(s));
    position += sizeof(s);
}

void MessageWriter::WriteUShort(unsigned short s)
{
    s = SwapShort(s);
    memcpy(buffer + position, &s, sizeof(s));
    position += sizeof(s);
}

void MessageWriter::WriteInt(int i)
{
    i = SwapInt(i);
    memcpy(buffer + position, &i, sizeof(i));
    position += sizeof(i);
}

void MessageWriter::WriteUInt(unsigned int i)
{
    i = SwapInt(i);
    memcpy(buffer + position, &i, sizeof(i));
    position += sizeof(i);
}

void MessageWriter::WriteLong(long l)
{
    l = SwapLong(l);
    memcpy(buffer + position, &l, sizeof(l));
    position += sizeof(l);
}

void MessageWriter::WriteULong(unsigned long l)
{
    l = SwapLong(l);
    memcpy(buffer + position, &l, sizeof(l));
    position += sizeof(l);
}

void MessageWriter::WriteDouble(double d)
{
    d = SwapDouble(d);
    memcpy(buffer + position, &d, sizeof(d));
    position += sizeof(d);
}

void MessageWriter::WriteUTF(char* str)
{
    int i;
    int len = strlen(str);

    WriteShort((unsigned short)len);

    for(i = 0; i < len; i++)
        buffer[position + i] = str[i];

    position += i;
}

void MessageWriter::WriteBool(bool b)
{
    if(b)
        WriteByte(1);
    else
        WriteByte(0);
}
