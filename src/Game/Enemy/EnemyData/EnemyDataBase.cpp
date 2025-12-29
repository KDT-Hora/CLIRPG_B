#include "EnemyDatabase.h"

const std::unordered_map<std::string, EnemyData>
EnemyDatabase::data =
{
    { "goblin", { "Goblin", 50, 8 } },
    { "orc",    { "Orc",    80, 12 } },
    { "slime",  { "Slime",  30, 5 } }
};

const EnemyData& EnemyDatabase::Get(const std::string& id)
{
    return data.at(id);
}