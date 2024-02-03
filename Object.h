#pragma once
#include "Novice.h"
#include "Vector2.h"
#include <vector>

class Object
{
protected:
	Vector2 pos_;
	Vector2 vel_;
	float radius_;
	int coolDown_;
	bool isAlive_;

public:
	Object();
	~Object();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	Vector2 GetPos()const;
	float GetRadius()const;

	Vector2 SetVel(Vector2 vel);

	bool GetIsAlive()const;
	bool ChackHitCircle();
};

