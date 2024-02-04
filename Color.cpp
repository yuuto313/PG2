#include "Color.h"

Color::Color()
{
    red_ = 0xFF;
    green_ = 0xFF;
    blue_ = 0xFF;
    alpha_ = 0xFF;
}

Color::~Color()
{
}

unsigned int Color::GetColor() const
{
    return (red_ << 24) + (green_ << 16) + (blue_ << 8) + alpha_;
}


Color* Color::SetColor(int red, int green, int blue, int alpha)
{
    red_ = red;
    green_ = green;
    blue_ = blue;
    alpha_ = alpha;
    return this;
}

Color* Color::SetRed(int red)
{
    red_ = red;
    return this;
}

Color* Color::SetGreen(int green)
{
    green_ = green;
    return this;
}

Color* Color::SetBlue(int blue)
{
    blue_ = blue;
    return this;
}

Color* Color::SetAlpha(int alpha)
{
    alpha_ = alpha;
    return this;
}




