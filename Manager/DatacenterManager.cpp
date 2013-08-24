#include "DatacenterManager.h"

map<string, IDataCenter*> DatacenterFactory::datacenterList = map<string, IDataCenter*>();

void DatacenterManager::Register()
{
    DatacenterFactory::registerClass("Breed", new Breed);
}

IDataCenter* DatacenterManager::get(string className)
{
    DatacenterFactory dcf;

    IDataCenter* data = dcf.getClass(className);
    return data;
}

void DatacenterFactory::registerClass(string className, IDataCenter* obj)
{
    if(datacenterList.find(className) == datacenterList.end())
    {
        datacenterList[className] = obj;
    }
}

IDataCenter* DatacenterFactory::getClass(string className)
{
    IDataCenter* tmp = 0;
    map<string, IDataCenter*>::const_iterator it = datacenterList.find(className);

    if(it != datacenterList.end())
    {
        tmp = ((*it).second)->getInstance();
    }

    return tmp;
}
