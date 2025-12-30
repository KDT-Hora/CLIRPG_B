#pragma once
#include <unordered_map>
#include <string>
#include "EnemyData.h"

class EnemyDatabase
{
public:
    static const EnemyData& Get(const std::string& id);

private:
    static const std::unordered_map<std::string, EnemyData> data;
};
