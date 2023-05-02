#pragma once

#include "ofMain.h"

class button
{
public:
	button(float xPos, float yPos);
	~button();
	void draw(float mouseX, float mouseY);
	bool isPressed(float mouseX, float mouseY);
	bool correctButton(int selectedButton);
	void numberAssigner(int buttonNum);
	float actualXPos;
	float actualYPos;

private:

	//Variable initialising
	bool isActive;
	int buttonNumber;
	float width;
	float height;

	//Asset loading
	ofSoundPlayer click;
};