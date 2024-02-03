#pragma once
#include "SceneManager.h"
class GameOver:
	public IScene
{
public:
	GameOver(IManager* pManager);
	~GameOver();
	
	void Update();
	void Draw();
};

