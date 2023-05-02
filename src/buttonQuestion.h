#pragma once
#include "ofMain.h"
#include "button.h"
#include <functional>

class buttonQuestion
{
public:
	buttonQuestion();
	~buttonQuestion();
	void draw(float mouseX, float mouseY);
	void setup();
	void update(float xPos, float yPos);
	void mouseInterraction(float mouseX, float mouseY, int& activeQuestion);
	void secondInterraction();

private:
	//Vectors
    vector < ofRectangle > buttons;
	vector < button > myButtons;
	
	//Variabe handling
	int activeButton;
	int selectedButton;
	bool buttonCorrect;
	bool correctAnswer;
	int buttonColour;
	bool verifyPressed;
	bool programStart;
	int imgWidth;
	int imgHeight;

	//Assets
	ofImage startWindow;
	ofImage window2;
	ofImage textBox;
	ofSoundPlayer correct;
	ofSoundPlayer click;
	ofSoundPlayer hint;
	ofTrueTypeFont myFont;

};