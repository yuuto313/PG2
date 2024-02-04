#include "GameOver.h"
#include "Title.h"
#include "Game.h"
GameOver::GameOver(IManager* pManager):IScene(pManager)
{
	gh_ = Novice::LoadTexture("./Resources/game_Failed.png");

	
	//color_->Init();

	
}

GameOver::~GameOver()
{
}

void GameOver::Update()
{
	if (manager_->GetKey()[DIK_RETURN] && !manager_->GetPreKey()[DIK_RETURN]) {
		manager_->scene = new Game(manager_);
		delete this;
	}
	//color_->SetColor(0xDC, 0x14, 0x3C, 0x00);
}

void GameOver::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.f, RED, kFillModeSolid);
	Novice::DrawSprite(400, 50, gh_, 1.f, 1.f, 0.f, 0xFFFFFFFF);
	Novice::DrawSprite(500, 450, gh2_, 1.f, 1.f, 0.f, 0xFFFFFFFF);
}
