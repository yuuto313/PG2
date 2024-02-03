#pragma once
#include "Object.h"
#include "Bullet.h"
class Enemy :
    public Object
{
public:
    Enemy();
    ~Enemy();

    void Move();
    void BulletUpdate();

    void Init()override;
    void Update()override;
    void Draw()override;

    std::vector<Bullet*>GetBullet() { return enemyBullets_; };

private:
    std::vector<Bullet*>enemyBullets_;
};

