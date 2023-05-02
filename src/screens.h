#pragma once
#include "ofMain.h"

class screens
{
public:
	screens();
	~screens();
	void draw(float mouseX, float mouseY);
	void setup(int type);
	void mouseInteraction(float mouseX, float mouseY,int &activeQuestion);
	void drawEndScreen(float mouseX, float mouseY);
	void drawGameOver(float mouseX, float mouseY);

private:

	//Assets
	ofImage background1;
	ofImage textBox;
	ofTrueTypeFont blockFont;
	ofSoundPlayer click;
	ofSoundPlayer radioNoise;

	//Strings
	string mySentance1;
	string mySentance2;
	string mySentance3;
	string mySentance4;
	string mySentance5;
	string mySentance6;
	string linkText;
	
	//Variables
	bool startBox;
	bool mouseOver;
	int currentChara;


};

