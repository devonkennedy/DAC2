#include "screens.h"
screens::screens()
{}
void screens::setup(int type)
{
	//Asset loading
	//BG image accessed: kentlive.news/news/nostalgia/abandoned-kent-railway-stations-left-6205581
	background1.load("startScreen.jpg");
	textBox.load("textBox.png");
	blockFont.load("font2.ttf", 17);
	currentChara = 0;
	click.load("clickSound.wav"); //https://freesound.org/people/notyermom/sounds/434833/
	radioNoise.load("static.wav"); //https://freesound.org/people/Raining-0n-Satrn/sounds/615906/
	radioNoise.setVolume(0.3);
	radioNoise.setLoop(true);
	radioNoise.play();

	//Variable initialising
	startBox = true;	
}
screens::~screens()
{}
void screens::draw(float mouseX, float mouseY)
{
	//Start screen
	int imgWidth = background1.getWidth();
	int imgHeight = background1.getHeight();
	ofTranslate(ofGetWidth() / 2, ofGetHeight()/2);
	int time = int(ofGetElapsedTimef());
	ofPushMatrix();
	ofScale(1.09, 1.075);
	background1.draw(-imgWidth/2 , -imgHeight/2);
	ofPopMatrix();

	//Overlay box
	if (startBox)
	{
		ofPushMatrix();
		ofScale(0.5, 0.3);
		textBox.draw( -textBox.getWidth()/2, -textBox.getHeight()/2);
		ofPopMatrix();
		ofPushStyle();
		ofSetColor(0);
		blockFont.drawString("Press to", -textBox.getWidth() * 0.18 , 5);
		if (time % 2 == 0)
		{
			blockFont.drawString("<START>", -textBox.getWidth() * 0.18 + 100, 5);
		}
		ofPopStyle();
	}
	else
	{
		textBox.draw(-(textBox.getWidth() / 2), -(textBox.getHeight() / 2));
		ofPushStyle();
		ofSetColor(0);
		mySentance1 = "The year is 20XX";
		mySentance2 = "AI has advanced to the point where it is";
		mySentance3 = "near indistinguishable from humans";
		mySentance4 = "As such, CAPTCHAs have had to evolve";
		mySentance5 = "alongside it";
		mySentance6 = "Click the link below to find out more";
		linkText = "https://randomwebpage.com";

		blockFont.drawString(mySentance1, -(textBox.getWidth() / 2) + 160,  -(textBox.getHeight() / 2) + 50);
		blockFont.drawString(mySentance2, -(textBox.getWidth() / 2) + 30,  -(textBox.getHeight() / 2) + 85);
		blockFont.drawString(mySentance3, -(textBox.getWidth() / 2) + 60, -(textBox.getHeight() / 2) + 120);
		blockFont.drawString(mySentance4, -(textBox.getWidth() / 2) + 50, -(textBox.getHeight() / 2) + 155);
		blockFont.drawString(mySentance5,  -(textBox.getWidth() / 2) + 190, -(textBox.getHeight() / 2) + 190);
		blockFont.drawString(mySentance6, -(textBox.getWidth() / 2) + 45, -(textBox.getHeight() / 2) + 225);
		if (mouseOver)
		{
			ofSetColor(0,0,255);
		}
		blockFont.drawString(linkText, -(textBox.getWidth() / 2) + 110, -(textBox.getHeight() / 2) + 260);
		ofPopStyle();
	}
	if (mouseX >= ofGetWidth()/2 -(textBox.getWidth() / 2) + 110 
		&& mouseX <= ofGetWidth()/2 -(textBox.getHeight() / 2) + 360 
		&& mouseY <= ofGetHeight()/2 -(textBox.getHeight() / 2) +  265
		&& mouseY >= ofGetHeight()/2 -(textBox.getHeight() / 2) + 245 && startBox == false)
	{
		mouseOver = true;
		ofPushStyle();
		ofSetLineWidth(3);
		ofSetColor(0, 0, 255);
		ofDrawLine(-(textBox.getWidth() / 2) + 110, -(textBox.getHeight() / 2) + 265, -(textBox.getWidth() / 2) + 390, -(textBox.getHeight() / 2) + 265);
		ofPopStyle();
	}
	else
	{
		mouseOver = false;
	}
	
}
void screens::mouseInteraction(float mouseX, float mouseY, int &activeQuestion)
{
	//Handles interaction, plays sound when clicked
	if (startBox)
	{
		click.play();
	}
	startBox = false;
	if (mouseX >= ofGetWidth() / 2 - (textBox.getWidth() / 2) + 110
		&& mouseX <= ofGetWidth() / 2 - (textBox.getHeight() / 2) + 360
		&& mouseY <= ofGetHeight() / 2 - (textBox.getHeight() / 2) + 265
		&& mouseY >= ofGetHeight() / 2 - (textBox.getHeight() / 2) + 245 
		&& startBox == false)
	{
		activeQuestion += 1;
		click.play();
	}
}
void screens::drawEndScreen(float mouseX, float mouseY)
{
	//Draws finishing screen
	int imgWidth = background1.getWidth();
	int imgHeight = background1.getHeight();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	int time = int(ofGetElapsedTimef());
	ofSetColor(255);
	ofPushMatrix();
	ofScale(1.09, 1.075);
	background1.draw(-imgWidth / 2, -imgHeight / 2);
	ofPopMatrix();

	textBox.draw(-(textBox.getWidth() / 2), -(textBox.getHeight() / 2));
	ofSetColor(0);
	blockFont.drawString("Congratulations", -(textBox.getWidth() / 2) + 170, -(textBox.getHeight() / 2) + 80);
	blockFont.drawString("You are officially a human!", -(textBox.getWidth() / 2) + 110, -(textBox.getHeight() / 2) + 115);
	blockFont.drawString("At least according to this CAPTCHA's", -(textBox.getWidth() / 2) + 50, -(textBox.getHeight() / 2) + 150);
	blockFont.drawString("standards", -(textBox.getWidth() / 2) + 200, -(textBox.getHeight() / 2) + 185);
	blockFont.drawString("(Not like it can really decide your", -(textBox.getWidth() / 2) + 70, -(textBox.getHeight() / 2) + 220);
	blockFont.drawString("humanity anyways...)", -(textBox.getWidth() / 2) + 140, -(textBox.getHeight() / 2) + 255);
}
void screens::drawGameOver(float mouseX, float mouseY)
{
	//Draws 'game over' screen
	int imgWidth = background1.getWidth();
	int imgHeight = background1.getHeight();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	int time = int(ofGetElapsedTimef());
	ofSetColor(255);
	ofPushMatrix();
	ofScale(1.09, 1.075);
	background1.draw(-imgWidth / 2, -imgHeight / 2);
	ofPopMatrix();

	textBox.draw(-(textBox.getWidth() / 2), -(textBox.getHeight() / 2));
	ofSetColor(0);
	blockFont.drawString("Verification failed", -(textBox.getWidth() / 2) + 140, -(textBox.getHeight() / 2) + 100);
	blockFont.drawString("Your activities were flagged as", -(textBox.getWidth() / 2) + 80, -(textBox.getHeight() / 2) + 135);
	blockFont.drawString("suspicious and as such you cannot access ", -(textBox.getWidth() / 2) + 30, -(textBox.getHeight() / 2) + 170);
	blockFont.drawString("this site.", -(textBox.getWidth() / 2) + 190, -(textBox.getHeight() / 2) + 205);
	blockFont.drawString("Please try again.", -(textBox.getWidth() / 2) + 150, -(textBox.getHeight() / 2) + 240);
}