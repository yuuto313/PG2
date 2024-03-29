#include "Clear.h"
#include "Title.h"

Clear::Clear(IManager* pManager):IScene(pManager)
{
	gh_ = Novice::LoadTexture("./Resources/game_Clear.png");

	//color_ ->Init();


	
}

Clear::~Clear()
{
}

void Clear::Update()
{
	//color_->SetColor(0xF0, 0xE6, 0x8C, 0x00);
	if (manager_->GetKey()[DIK_RETURN] && !manager_->GetPreKey()[DIK_RETURN]) {
		manager_->scene = new Title(manager_);
		delete this;
	}
}

void Clear::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.f,WHITE, kFillModeSolid);
	Novice::DrawSprite(400, 50,gh_, 1.f, 1.f, 0.f, 0xFFFFFFFF);
	Novice::DrawSprite(500, 450, gh2_, 1.f, 1.f, 0.f, 0xFFFFFFFF);
}
