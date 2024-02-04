#pragma once
#include "Novice.h"
#include "Color.h"

//シーンの基底クラス
class IManager;
class IScene
{
protected:
	IManager* manager_;
	Color* color_;

	int gh_ = {};
	int gh2_ = Novice::LoadTexture("./Resources/game_Enter.png");

public:
	IScene(IManager* pManager) { manager_ = pManager; };
	virtual~IScene() {};

	virtual void Update();
	virtual void Draw();

};

class IManager
{
	char* key;
	char* preKey;

public:
	IScene* scene;

	IManager(char* pKey,char *pPreKey) { key = pKey,preKey=pPreKey; };
	~IManager() { delete scene; };

	char* GetKey() { return key; };
	char* GetPreKey() { return preKey; };

	void Update() { scene->Update(); };
	void Draw() { scene->Draw(); };
};

