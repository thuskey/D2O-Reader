#ifndef DATA_CENTER_MANAGER_H
#define DATA_CENTER_MANAGER_H

#include <map>
#include <string>

#include "../Datacenter/IDataCenter.h"
#include "../Datacenter/list.h"

using namespace std;

class DatacenterManager
{
public:
    void Register();
    IDataCenter* get(string className);
};

class DatacenterFactory
{
public:
    static void registerClass(string className, IDataCenter* obj);
    IDataCenter* getClass(string className);

private:
    static map<string, IDataCenter*> datacenterList;
};

#endif // DATA_CENTER_MANAGER_H
