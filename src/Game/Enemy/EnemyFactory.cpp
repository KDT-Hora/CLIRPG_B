#include "../Enemy/EnemyFactory.h"
#include "../CharacterState.h"
#include "../Enemy/EnemyData/EnemyDatabase.h"

std::shared_ptr<Character>
EnemyFactory::CreateEnemy(const std::string& enemyId)
{
    const EnemyData& data = EnemyDatabase::Get(enemyId);

    Status st;
    st.MaxHP = data.maxHP;
    st.HP = data.maxHP;
    st.STR = data.str;

    return std::make_shared<Character>(
        data.name,
        Faction::Enemy,
        st
    );
}
