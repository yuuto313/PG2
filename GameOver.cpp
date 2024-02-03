#include "GameOver.h"
#include "Title.h"
GameOver::GameOver(IManager* pManager):IScene(pManager)
{
}

GameOver::~GameOver()
{
}

void GameOver::Update()
{
	if (manager_->GetKey()[DIK_RETURN]) {
		manager_->scene = new Title(manager_);
		delete this;
	}
}

void GameOver::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.f, RED, kFillModeSolid);
}
