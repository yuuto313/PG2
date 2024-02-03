#pragma once
#include "SceneManager.h"

#include "Player.h"
#include "Enemy.h"

#include "Bullet.h"
class Game :
	public IScene
{
public:
	Game(IManager* pManager);
	~Game();

	Player* player;
	Enemy* enemy;


	//変数名変える
	Vector2 range1_;
	float radius1_;
	float distance1_;

	Vector2 range2_;
	float radius2_;
	float distance2_;

	void Update();
	void Draw();
};

