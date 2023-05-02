#pragma once

#include "ofMain.h"
#include "imageQuestion.h"
#include "button.h"
#include "textQuestion.h"
#include "buttonQuestion.h"
#include "screens.h"

using namespace glm;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		//Variables
		int activeButton;
		int selectedButton;
		bool buttonCorrect;
		bool correctAnswer;
		int buttonColour;
		bool verifyPressed;
		bool programStart;
		bool nextQuestion;
		bool verificationRequired;
		int time;
		int activeQuestion;
		
		//Assets
		ofImage startWindow;
		ofImage window2;
		ofImage bg1;
		ofImage textBox;
		ofTrueTypeFont blockFont;
		ofSoundPlayer click;

		//Questions
		textQuestion practice;
		buttonQuestion firstQuestion;
		screens startScreen;
		imageQuestion imageQ;
		
};
