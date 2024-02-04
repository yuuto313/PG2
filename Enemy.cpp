#include "Enemy.h"

Enemy::Enemy()
{
	Init();
}

Enemy::~Enemy()
{
}

void Enemy::Move()
{
	pos_.x += vel_.x;
	if (pos_.x <= radius_ || pos_.x >= 1280 - radius_) {
		vel_.x *= -1;
	}
}

void Enemy::BulletUpdate()
{
	
	if (isAlive_ && coolDown_ == 0) {
		enemyBullets_.push_back(new Bullet(pos_));
		coolDown_ = 15;

	}

	if (coolDown_ >= 1) {
		--coolDown_;
	}

	auto itr = enemyBullets_.begin();
	while (itr != enemyBullets_.end()) {
		(*itr)->SetVel({ 0, -5 });
		(*itr)->Update();

		if (!(*itr)->isShot_) {
			itr = enemyBullets_.erase(itr);
		}
		else {
			++itr;
		}
	}
}

void Enemy::Init()
{
	pos_ = { 600,200 };
	vel_ = { 8,0 };
	radius_ = 25;
	isAlive_ = true;
	//blendColor_ = {};
	
	coolDown_ = 0;

	gh_ = Novice::LoadTexture("./Resources/game_Enemy.png");
}

void Enemy::Update()
{
	BulletUpdate();
	Move();
}

void Enemy::Draw()
{
	for (auto itr = enemyBullets_.begin(); itr != enemyBullets_.end(); ++itr) {
		(*itr)->Draw();
	}
	if (isAlive_) {
		//Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.f, RED, kFillModeSolid);
		Novice::DrawSprite((int)pos_.x - 32, (int)pos_.y - 32, gh_, 1.f, 1.f, 0.f, 0xFFFFFFFF);
	}
}
