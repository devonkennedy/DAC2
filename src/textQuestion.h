#pragma once
#include "ofMain.h"
using namespace glm;
class textQuestion
{
	public:
		textQuestion();
		~textQuestion();
		void draw(float mouseX, float mouseY);
		void setup(int numOfCharas);
		void update(float xPos, float yPos);
		void pickLetters(vector <int>& m, vector < ofImage >& imageOut, bool isAnswer);
		void textOverlay(float mouseX, float mouseY);
		void textBox(int xPos, int yPos,int width, int height, int keyInput);
		void textBoxTyping(int xPos, int yPos, int keyInput, int& activeQuestion);
		void mouseInteraction(int mouseX, int mouseY);

	private:

		//Variable initialising
		bool isActive;
		float width;
		float height;
		float input;
		float randOffset;
		bool isMoving2;
		bool answerCorrect;
		bool textWritten;
		int captchaLength;
		int mouseDist;
		bool programStart;
		string textDisplay;
		string answer;

		//Assets
		ofTrueTypeFont blockFont;
		ofTrueTypeFont infoFont;
		ofSoundPlayer correct;
		ofSoundPlayer click;
		ofImage startWindow;

		//Vectors
		vector < int > charSequence;
		vector < ofImage > captchaImages;
		vector < ofImage > captchaCloudImages;
		vector <bool> isMoving;
		vector <float> randomScaleX;
		vector <float> randomScaleY;
		vector <float> randomRotation;
		vector <int> captchaCloud;
		vector <float> characterX;
		vector <float> characterY;
		vector <string> textBoxInput;
		vector <string> answerInput;
};

