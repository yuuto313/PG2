#include "Color.h"

Color::Color()
{
    Init();
}

Color::~Color()
{
}

void Color::Init()
{  red_ = {};
    green_ = {};
    blue_ = {};
    alpha_ = {};
}

unsigned int Color::GetColor(){
	red_ <<= 24;
	green_ <<= 16;
	blue_ <<= 8;
    int color = red_ + green_ + blue_ + alpha_;

	return color;
}

void Color::SetColor(int red, int green, int blue, int alpha)
{
    red_ = red;
    green_ = green;
    blue_ = blue;
    alpha_ = alpha;
}





