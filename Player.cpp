#include "Player.h"

Player::Player()
{
	Init();
}

Player::~Player()
{
}

void Player::Move(char* keys)
{
	if (keys[DIK_W]) {
		vel_.y -= 4;
	}
	if (keys[DIK_A]) {
		vel_.x -= 4;
	}
	if (keys[DIK_S]) {
		vel_.y += 4;
	}
	if (keys[DIK_D]) {
		vel_.x += 4;
	}

	if (pos_.y <= 300 + radius_) {
		vel_.y += 4;
	}
	if (pos_.x <= radius_) {
		vel_.x += 4;
	}
	if (pos_.y >= 720 - radius_) {
		vel_.y -= 4;
	}
	if (pos_.x >= 1280 - radius_) {
		vel_.x -= 4;
	}

	pos_.x += vel_.x;
	pos_.y += vel_.y;
	vel_.x = 0;
	vel_.y = 0;

}

void Player::BulletUpdate(char* keys)
{
	if (keys[DIK_SPACE] && coolDown_ == 0 && isAlive_) {
		playerBullets_.push_back(new Bullet(pos_));
		coolDown_ = 18;
		
	}

	if (coolDown_ >= 1) {
		--coolDown_;
	}

	auto itr = playerBullets_.begin();
	while (itr != playerBullets_.end()) {
		(*itr)->SetVel({ 0,7 });
		(*itr)->Update();

		if (!(*itr)->isShot_) {
			itr = playerBullets_.erase(itr);
		}
		else {
			++itr;
		}
	}
}

void Player::Init()
{
	pos_ = { 640,500 };
	vel_ = { 0,0 };
	radius_ = 10;
	isAlive_ = true;
	//blendColor_ = {};

	coolDown_ = 0;

	gh_ = Novice::LoadTexture("./Resources/game_Player.png");
	
}

void Player::Update(char *keys)
{
	Move(keys);
	BulletUpdate(keys);
}

void Player::Update()
{
}

void Player::Draw()
{
	for (auto itr = playerBullets_.begin(); itr != playerBullets_.end(); ++itr) {
		(*itr)->Draw();
	}
	if (isAlive_) {
		//Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.f, WHITE, kFillModeSolid);
		Novice::DrawSprite((int)pos_.x - 32, (int)pos_.y - 32, gh_, 1.f, 1.f, 0.f, 0xFFFFFFFF);
	}
}
