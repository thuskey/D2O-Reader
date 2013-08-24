#ifndef MESSAGE_WRITER_H
#define MESSAGE_WRITER_H

#include <cstring>

class MessageWriter
{
private:
    int position;
    char* buffer;

public:
    MessageWriter();
    MessageWriter(int);
    ~MessageWriter();

    void reset();
    int getPosition();
    char* getBuffer();

    short SwapShort(short);
    int SwapInt(int);
    long SwapLong(long);
    double SwapDouble(double);

    void WriteByte(char);
    void WriteBytes(char*, int);
    void WriteShort(short);
    void WriteUShort(unsigned short);
    void WriteInt(int);
    void WriteUInt(unsigned int);
    void WriteLong(long);
    void WriteULong(unsigned long);
    void WriteDouble(double);
    void WriteUTF(char*);
    void WriteBool(bool);
};

#endif // MESSAGE_WRITER_H

