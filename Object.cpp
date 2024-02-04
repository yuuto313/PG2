#include "Object.h"

Object::Object()
{
	pos_ = {};
	vel_ = {};
	radius_ = {};
	isAlive_ = {};
	coolDown_ = {};

	//blendColor_ = {};
	color_ = new Color();
	color_->SetRed(255);
	color_->SetGreen(255);
	color_->SetBlue(255);
	color_->SetAlpha(100);

}

Object::~Object()
{
}

Vector2 Object::GetPos() const
{
	return pos_;
}

float Object::GetRadius() const
{
	return radius_;
}

Vector2 Object::SetVel(Vector2 vel)
{
	return vel_ = vel;
}

bool Object::GetIsAlive() const
{
	return isAlive_;
}

bool Object::ChackHitCircle()
{
	return isAlive_ = false;
}
