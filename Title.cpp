#include "Title.h"
#include "Game.h"
#include "Clear.h"
#include "GameOver.h"

Title::Title(IManager* pManager) :IScene(pManager)
{
	color_ = new Color();
	//color_->SetColor(0x20, 0xB2, 0xAA, 0xFF);
	gh_ = Novice::LoadTexture("./Resources/game_Title.png");

}

Title::~Title()
{
}

void Title::Update()
{
	color_->SetColor(0x20, 0xB2, 0xAA, 0xFF);

	if (manager_->GetKey()[DIK_RETURN] && !manager_->GetPreKey()[DIK_RETURN]) {
		manager_->scene = new Game(manager_);
		delete this;
	}
}

void Title::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.f, color_->GetColor(), kFillModeSolid);
	Novice::DrawSprite(400, 50, gh_, 1.f, 1.f, 0.f, 0xFFFFFFFF);
	Novice::DrawSprite(500, 450, gh2_, 1.f, 1.f, 0.f, 0xFFFFFFFF);
}
