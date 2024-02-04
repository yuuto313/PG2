#pragma once
class Color
{
private:
	unsigned int red_;
	unsigned int green_;
	unsigned int blue_;
	unsigned int alpha_;

public:
	Color();
	~Color();

	unsigned int GetColor()const;

	Color* SetColor(int red, int green, int blue, int alpha);
	Color* SetRed(int red);
	Color* SetGreen(int green);
	Color* SetBlue(int blue);
	Color* SetAlpha(int alpha);
};

