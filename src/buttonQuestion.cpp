#include "buttonQuestion.h"

buttonQuestion::buttonQuestion()
{
}

buttonQuestion::~buttonQuestion()
{
}

void buttonQuestion::setup()
{
	//Intitialising variables
	buttonCorrect = false;
	verifyPressed = false;
	programStart = true;
	imgWidth = 1012;
	imgHeight = 755;

	//Asset loading
	textBox.load("textBox.png");
	myFont.load("font2.ttf", 17.5);
	correct.load("rightAnswer.wav"); //https://freesound.org/people/ertfelda/sounds/243701/
	click.load("clickSound.wav"); //https://freesound.org/people/notyermom/sounds/434833/
	hint.load("hint.wav"); //https://freesound.org/people/Mr._Fritz_/sounds/545238/
	hint.setVolume(0.2);

	//Button initialising
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 21; y++)
		{
			myButtons.push_back(button(ofGetWidth()/2 - imgWidth/2 + 15 + (x * 40), ofGetHeight()/2 - imgHeight/2 + 15 + (y * 35.5)));
		}
	}
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			myButtons.push_back(button(ofGetWidth() / 2 - imgWidth / 2 + 415 + (x * 40), ofGetHeight() / 2 - imgHeight / 2 + 15 + (y * 35.5)));
		}
	}
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			myButtons.push_back(button(ofGetWidth() / 2 - imgWidth / 2 + 415 + (x * 40), ofGetHeight() / 2 - imgHeight / 2 + 405.5 + (y * 35.5)));
		}
	}
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 21; y++)
		{
			myButtons.push_back(button(ofGetWidth() / 2 - imgWidth / 2 + 615 + (x * 40), ofGetHeight() / 2 - imgHeight / 2 + 15 + (y * 35.5)));
		}
	}

	for (int i = 0; i < myButtons.size(); i++)
	{
		myButtons[i].numberAssigner(i);
	}

	selectedButton = ofRandom(0, myButtons.size());

	//Uncomment for answer button
	//cout << selectedButton << endl;
}
void buttonQuestion::update(float xPos, float yPos)
{

}


void buttonQuestion::draw(float mouseX, float mouseY)
{
	//Border window
	ofSetLineWidth(1);
	ofSetColor(249, 249, 249);
	ofDrawRectangle(ofGetWidth() / 2 - imgWidth/2 + 5, ofGetHeight() / 2 - imgHeight/2 + 5, imgWidth - 5, imgHeight -5);
	ofNoFill();
	ofSetColor(0);
	ofDrawRectangle(ofGetWidth() / 2 - imgWidth/2 + 5, ofGetHeight() / 2 - imgHeight/2 + 5, imgWidth - 5, imgHeight -5);

	//Button drawing loops
	for (int i = 0; i < myButtons.size(); i++)
	{
		myButtons[i].draw(mouseX, mouseY);
	}

	//Verify button, changes colour when pressed.
	ofFill();
	if (verifyPressed)
	{
		ofSetColor(255);
	}
	else 
	{
		ofSetColor(0);
	}
	
	//Verify button
	ofDrawRectangle(ofGetWidth() / 2 - 65, ofGetHeight() / 2 + 313, 130, 60);
	ofNoFill();
	ofSetColor(0);
	ofDrawRectangle(ofGetWidth() / 2 - 65, ofGetHeight() / 2 + 313, 130, 60);
	ofFill();

	//Text
	ofSetColor(6, 3, 11);
	myFont.drawString("I'm not a robot", ofGetWidth()/2 - 85, ofGetHeight()/2 - 5);
	ofPushStyle();
	if (verifyPressed)
	{
		ofSetColor(0);
	}
	else 
	{
		ofSetColor(250, 253, 252);
	}
	myFont.drawString("verify", ofGetWidth()/2 - 32, ofGetHeight()/2 + 347);
	ofPopStyle();

	ofSetColor(250, 253, 252);
	//Start window
	if (programStart)
	{
		//BG
		ofFill();
		ofSetColor(249, 249, 249, 200);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

		//Window image
		ofSetColor(255);
		textBox.draw(ofGetWidth()/2 - textBox.getWidth()/2, ofGetHeight()/2 - textBox.getHeight()/2);

		//Text
		ofSetColor(0);
		myFont.drawString("Press on the boxes and click verify", ofGetWidth() / 2 - textBox.getWidth() / 2 + 60, ofGetHeight() / 2 - textBox.getHeight() / 2 + 80);
		myFont.drawString("to submit.", ofGetWidth() / 2 - textBox.getWidth() / 2 + 200, ofGetHeight() / 2 - textBox.getHeight() / 2 + 110);
		myFont.drawString("only one will work!", ofGetWidth() / 2 - textBox.getWidth() / 2 + 150, ofGetHeight() / 2 - textBox.getHeight() / 2 + 140);
		myFont.drawString("If you get stuck try listening", ofGetWidth() / 2 - textBox.getWidth() / 2 + 80, ofGetHeight() / 2 - textBox.getHeight() / 2 + 170);
		myFont.drawString("for a hint...", ofGetWidth() / 2 - textBox.getWidth() / 2 + 180, ofGetHeight() / 2 - textBox.getHeight() / 2 + 200);
	
		//Button
		ofSetColor(6, 3, 11);
		ofDrawRectangle(ofGetWidth() / 2 - 55, ofGetHeight() / 2 + 80, 110, 50);
		ofSetColor(250, 253, 252);
		myFont.drawString("ok", ofGetWidth() / 2 - 10, ofGetHeight() / 2 + 115);
	}

	//Distance handling
	float dist = ofDist(mouseX, mouseY, myButtons[selectedButton].actualXPos + 12.5, myButtons[selectedButton].actualYPos + 12.5);
	if (dist < 10)
	{
	    hint.play();
	}
}
void buttonQuestion::mouseInterraction(float mouseX, float mouseY, int& activeQuestion)
{
	//Button interaction
	if (mouseX > (ofGetWidth() / 2 - 55) && mouseX < (ofGetWidth() / 2 + 55) && mouseY >(ofGetHeight() / 2 + 80) && mouseY < (ofGetHeight() / 2 + 130) && activeQuestion == 4)
	{
		programStart = false;
	}

	if (mouseX > (ofGetWidth() / 2 - 65) && mouseX < (ofGetWidth() / 2 + 65) && mouseY > (ofGetHeight() / 2 + 313) && mouseY < (ofGetHeight() / 2 + 373))
	{
		verifyPressed = true;
	}
	for (int i = 0; i < myButtons.size(); i++)
	{
		//Button press code
		myButtons[i].isPressed(mouseX, mouseY);
		if (myButtons[i].isPressed(mouseX, mouseY) == true && verifyPressed == false)
		{
			myButtons[i].isPressed(mouseX, mouseY);
			//Uncomment below for current number button
			//cout << "Button number: " << i << endl;
			if (i == selectedButton)
			{
				buttonCorrect = true;
			}

		}

	}

	//Sound
	if (verifyPressed == true && buttonCorrect == true)
	{
		correct.play();
		activeQuestion += 1;
	}
}
void buttonQuestion::secondInterraction()
{
	verifyPressed = false;
}
