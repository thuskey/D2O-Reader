#ifndef BREED_DATA_H
#define BREED_DATA_H

#include <vector>
#include <string>
#include "../IDataCenter.h"

using namespace std;

class Breed : public IDataCenter
{
public:
    IDataCenter* getInstance() const;
    const char* getModuleName();

private:
    const char* MODULE = "Breed";
    int id;
    unsigned int shortNameId;
    unsigned int lonNameId;
    unsigned int descriptionId;
    unsigned int gameplayDescriptionId;
    string maleLook;
    string femaleLook;
    unsigned int creatureBonesId;
    int maleArtwork;
    int femaleArtwork;
    vector<vector<unsigned int>> statsPointsForStrength;
    vector<vector<unsigned int>> statsPointsForIntelligence;
    vector<vector<unsigned int>> statsPointsForChance;
    vector<vector<unsigned int>> statsPointsForAgility;
    vector<vector<unsigned int>> statsPointsForVitality;
    vector<vector<unsigned int>> statsPointsForWisdom;
    vector<unsigned int> breedSpellsId;
    vector<unsigned int> maleColors;
    vector<unsigned int> femaleColors;
};

#endif // BREED_DATA_H
