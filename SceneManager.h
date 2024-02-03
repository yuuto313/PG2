﻿#pragma once
#include "Novice.h"


//シーンの基底クラス
class IManager;
class IScene
{
protected:
	IManager* manager_;

public:
	IScene(IManager* pManager) { manager_ = pManager; };
	virtual~IScene() {};

	virtual void Update();
	virtual void Draw();

};

class IManager
{
	char* key;


public:
	IScene* scene;

	IManager(char* pKey) { key = pKey; };
	~IManager() { delete scene; };

	char* GetKey() { return key; };

	void Update() { scene->Update(); };
	void Draw() { scene->Draw(); };
};
