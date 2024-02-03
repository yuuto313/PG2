#include "Clear.h"
#include "Title.h"

Clear::Clear(IManager* pManager):IScene(pManager)
{
}

Clear::~Clear()
{
}

void Clear::Update()
{
	if (manager_->GetKey()[DIK_RETURN]) {
		manager_->scene = new Title(manager_);
		delete this;
	}
}

void Clear::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.f, WHITE, kFillModeSolid);
}
