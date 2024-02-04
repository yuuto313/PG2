#include "Game.h"
#include "Clear.h"
#include "GameOver.h"

Game::Game(IManager* pManager) :IScene(pManager)
{
	player = new Player();
	enemy = new Enemy();
	//color_ ->Init();


	range1_ = {};
	distance1_ = {};
	radius1_ = {};

	range2_ = {};
	distance2_ = {};
	radius2_ = {};

	

	
}

Game::~Game()
{
}

void Game::Update()
{
	//color_->SetColor(0x4B, 0x00, 0x8B, 0x00);
	player->Update(manager_->GetKey());
	enemy->Update();

	//自機の弾と敵との判定->ok
	if (player->GetBullet().size() > 0) {
		for (int i = 0; i < player->GetBullet().size(); i++) {
			range1_ = (player->GetBullet()[i]->GetPos()) - (enemy->GetPos());
			distance1_ = (range1_.x * range1_.x) + (range1_.y * range1_.y);
			radius1_ = (player->GetBullet()[i]->GetRadius()) + (enemy->GetRadius());

			if (distance1_ <= radius1_ * radius1_) {
				enemy->ChackHitCircle();
			}
		}
	}
	
	//自機と敵の弾との当たり判定->ok
	if (enemy->GetBullet().size() > 0) {
		for (int i = 0; i < enemy->GetBullet().size(); i++) {
			range2_ = (player->GetPos()) - (enemy->GetBullet()[i]->GetPos());
			distance2_ = (range2_.x * range2_.x) + (range2_.y * range2_.y);
			radius2_ = (player->GetRadius()) + (enemy->GetBullet()[i]->GetRadius());
			if (distance2_ <= radius2_ * radius2_) {
				player->ChackHitCircle();
			}
		}
	}

	if (!enemy->GetIsAlive()) {
		manager_->scene = new Clear(manager_);
	}

	if (!player->GetIsAlive()) {
		manager_->scene = new GameOver(manager_);
		delete this;
	}
	
	
}

void Game::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.f, BLUE, kFillModeSolid);
	player->Draw();
	enemy->Draw();

}
