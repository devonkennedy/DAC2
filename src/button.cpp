#include "button.h"
using namespace glm;
button::button(float xPos, float yPos)
{
	//Asset loading
	click.load("clickSound.wav"); //https://freesound.org/people/notyermom/sounds/434833/

	//Variable initialising
	actualXPos = xPos;
	actualYPos = yPos;
	width = 25;
	height = 25;
	isActive = false;
}

button::~button()
{
	//destruct
}

void button::numberAssigner(int buttonNum)
{
	//Assigns number which allows for checking if button is the answer button.
	buttonNumber == buttonNum;
}

void button::draw(float mouseX, float mouseY)
{
	//Draws button
	ofFill();
	ofSetColor(250, 253, 252);
	ofDrawRectangle(actualXPos, actualYPos, width, height);
	ofSetColor(0);
	ofNoFill();
	ofDrawRectangle(actualXPos, actualYPos, width, height);

	//X inside
	if (isActive)
	{
		ofSetColor(0);
		ofSetLineWidth(3);
		ofLine(actualXPos + 4, actualYPos + 5, actualXPos + width - 4, actualYPos + height - 5);
		ofLine(actualXPos + width - 4, actualYPos + 5, actualXPos + 4, actualYPos + height - 5);
		ofSetLineWidth(1);
	}

}
bool button::isPressed(float mouseX, float mouseY)
{
	//Press handling
	if (mouseX > actualXPos && mouseX < (actualXPos + width) && mouseY > actualYPos && mouseY < (actualYPos + width))
	{
		isActive = true;
		click.play();
		return true;
	}
	else 
	{
		isActive = false;
		return false;
	}
}
bool button::correctButton(int selectedButton)
{
	//Checks if button is correct
	if (buttonNumber == selectedButton)
	{
		return true;
	}
	else
	{
		return false;
	}
}