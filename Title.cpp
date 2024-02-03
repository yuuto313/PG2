#include "Title.h"
#include "Game.h"
#include "Clear.h"
#include "GameOver.h"

Title::Title(IManager* pManager) :IScene(pManager)
{
}

Title::~Title()
{
}

void Title::Update()
{
	if (manager_->GetKey()[DIK_RETURN]) {
		manager_->scene = new Game(manager_);
		delete this;
	}
}

void Title::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.f, GREEN, kFillModeSolid);
}
