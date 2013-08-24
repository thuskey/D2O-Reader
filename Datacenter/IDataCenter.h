#ifndef IDATA_CENTER_H
#define IDATA_CENTER_H

template <class T> class DataPrototype
{
public:
    virtual ~DataPrototype() {}
    virtual T* getInstance() const = 0;
};

class IDataCenter : public DataPrototype<IDataCenter>
{
public:
    virtual const char* getModuleName() = 0;
};

#endif // IDATA_CENTER_H
