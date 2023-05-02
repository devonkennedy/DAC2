#pragma once
#include "ofMain.h"

class imageQuestion
{
public:
	imageQuestion();
	~imageQuestion();
	void draw(float mouseX, float mouseY);
	void setup(int type);
	void mouseInteraction(float mouseX, float mouseY,int &activeQuestion);
	void secondInteraction();

private:
	//Variable initialising
	bool startBox;
	bool verifyPressed;
	int answerNum;
	int selectedImage;
	int randomSpot;
	bool answerCorrect;
	int failCounter;
	int chosenCAPTCHA;

	//Asset loading
	ofImage bg1;
	ofImage background1;
	ofImage textBox;
	ofTrueTypeFont blockFont;
	ofTrueTypeFont blockFont2;
	ofSoundPlayer click;
	ofSoundPlayer correct;

	//Vector
	vector <ofImage> displayImage;
};

