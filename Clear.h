#pragma once
#include "SceneManager.h"
class Clear:
	public IScene
{
public:
	Clear(IManager *pManager);
	~Clear();

	void Update();
	void Draw();
};

