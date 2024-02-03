#pragma once
#include "SceneManager.h"
class Title:
	public IScene
{
public:
	Title(IManager* pManager);
	~Title();

	void Update();
	void Draw();
};

