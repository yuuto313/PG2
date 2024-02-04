#pragma once
class Color
	//未完成
{
private:
	unsigned int red_;
	unsigned int green_;
	unsigned int blue_;
	unsigned int alpha_;

public:
	Color();
	~Color();

	void Init();

	unsigned int GetColor();

	void SetColor(int red, int green, int blue, int alpha);

};

