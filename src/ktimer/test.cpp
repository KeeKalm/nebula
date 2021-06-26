#include "ktimer/ktimer.hpp"
#include <iostream>
#include <chrono>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 12.设计一个人物类和怪物类，人物类有玩家ID、玩家姓名、当前血量，
                               怪物类有怪物ID、怪物类型、当前血量。
                               并实现一个简单攻击函数和加血减血函数。(8)
*/


class  Role{
public:
    /*
        角色生物进行攻击
        return  [out]   返回当前角色的攻击里
     */
    virtual unsigned long long Attack() {
        return 0;
    }

protected:
    std::string m_sId;                   //角色类型
    unsigned long long m_iHealth;        //角色生命值
};

class Player : public Role {
public:
    virtual unsigned long long Attack() {
        return 1;
    }

private:
    std::string m_sName;                //玩家名称
};


enum MonsterKind {
    GeBuLin = 1,  //哥布林
};
class Monster : public Role {
public:
    virtual unsigned long long Attack() {
        return 2;
    }

private:
    MonsterKind m_eType;  //怪物类型
}




int main() {
    vector<int> vec{ 3, 2, 2,2 ,5, 1 };
    std::map<int, int> mapVal;
    mapVal[2] = 2;
    mapVal[1] = 3;

    func(mapVal, 2);

    return 0;
}
