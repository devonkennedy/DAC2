#include "ofApp.h"
#include <functional>


//--------------------------------------------------------------
void ofApp::setup() {
	//Initialise variables
	ofSetFullscreen(true);
	activeQuestion = 0;
	firstQuestion.setup();
	practice.setup(6);
	startScreen.setup(1);
	imageQ.setup(1);
	verificationRequired = false;

	//Assets
	bg1.load("background_noise.png");
	textBox.load("textBox.png");
	blockFont.load("font2.ttf", 17);
	click.load("clickSound.wav"); //https://freesound.org/people/notyermom/sounds/434833/
	

}

//--------------------------------------------------------------
void ofApp::update() 
{
	
}
static void drawBorders(ofImage bg1)
{
	//Draws black borders around screen
	ofPushStyle();
	ofSetColor(0);
	ofDrawRectangle(-bg1.getWidth() / 2 - 10, -bg1.getHeight() / 2 - 10, bg1.getWidth() + 20, 10);
	ofDrawRectangle(-bg1.getWidth() / 2 - 10, -bg1.getHeight() / 2 - 10, 10, bg1.getHeight() + 10);
	ofDrawRectangle(bg1.getWidth() / 2, -bg1.getHeight() / 2, 10, bg1.getHeight() + 10);
	ofDrawRectangle(-bg1.getWidth() / 2 - 10, bg1.getHeight() / 2, bg1.getWidth() + 20, 10);
	ofPopStyle();

}

//--------------------------------------------------------------
void ofApp::draw() {
	//Time
	time = ofGetElapsedTimef();

	//Background
	ofBackground(255);
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	bg1.draw(-bg1.getWidth()/2, -bg1.getHeight()/2);
	ofPopMatrix();

	//Questions
	if (activeQuestion == 0)
	{
		//Start screen
		startScreen.draw(mouseX,mouseY);
		drawBorders(bg1);
	}
	if (activeQuestion == 1)
	{
		verificationRequired = true;
	}
	if (activeQuestion == 2)
	{
		//Text question
		practice.draw(mouseX, mouseY);
		practice.textOverlay(mouseX, mouseY);
		practice.textBox(ofGetWidth() / 2 - 100, ofGetHeight() * 0.80, 200, 30, 1);
		ofPushMatrix();

		//White borders
		ofSetColor(255);
		ofDrawRectangle(0, 0, ofGetWidth()/2 - bg1.getWidth() / 2 - 10, ofGetHeight());
		ofDrawRectangle(ofGetWidth()/2 + bg1.getWidth()/2, 0, ofGetWidth() / 2 - bg1.getWidth() / 2 - 10, ofGetHeight());
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight() / 2 - bg1.getHeight() / 2);
		ofDrawRectangle(0, ofGetHeight()/2 + bg1.getHeight()/2, ofGetWidth(), ofGetHeight() / 2 - bg1.getHeight() / 2);
		ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
		drawBorders(bg1);
		ofPopMatrix();

	}
	if (activeQuestion == 3)
	{
		verificationRequired = true;
	}
	if (activeQuestion == 4)
	{
		//Button question
		firstQuestion.draw(mouseX, mouseY);
		ofPushMatrix();
		ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
		drawBorders(bg1);
		ofPopMatrix();
	}
	if (activeQuestion == 5)
	{
		verificationRequired = true;
	}
	if (activeQuestion == 6)
	{
		//Image question
		imageQ.draw(mouseX, mouseY);
		drawBorders(bg1);
	}
	if (activeQuestion == 7)
	{
		//End screen
		startScreen.drawEndScreen(mouseX, mouseY);
	}
	if (activeQuestion == 8)
	{
		//Game over
		startScreen.drawGameOver(mouseX, mouseY);
	}

	if (verificationRequired)
	{
		//Verification window
		ofPushMatrix();
		ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
		drawBorders(bg1);
		ofSetColor(255);
		textBox.draw(-(textBox.getWidth() / 2), -(textBox.getHeight() / 2));
		ofSetColor(0);
		if (activeQuestion > 2)
		{
			blockFont.drawString(" Further verification required", -(textBox.getWidth() / 2) + 80, -(textBox.getHeight() / 2) + 85);
		}
		else
		{
			blockFont.drawString("Verification required", -(textBox.getWidth() / 2) + 135, -(textBox.getHeight() / 2) + 85);
		}
		blockFont.drawString("Please complete the following CAPTCHA", -(textBox.getWidth() / 2) + 45, -(textBox.getHeight() / 2) + (85*2));
		if (time % 2)
		{
			blockFont.drawString("< Click to continue... >", -(textBox.getWidth() / 2) + 120, -(textBox.getHeight() / 2) + (85 * 3));
		}
		ofSetColor(255);
		ofPopMatrix();
	}
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	//Mouse interactions
	firstQuestion.mouseInterraction(mouseX, mouseY, activeQuestion);
	
	if (activeQuestion == 0)
	{
		startScreen.mouseInteraction(mouseX, mouseY, activeQuestion);
	}
	if (activeQuestion == 2)
	{
		practice.mouseInteraction(mouseX, mouseY);
	}
	if (activeQuestion == 6)
	{
		imageQ.mouseInteraction(mouseX, mouseY, activeQuestion);
	}
	if (verificationRequired)
	{
		activeQuestion += 1;
		verificationRequired = false;
		click.play();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	//Uncomment below to manually skip through questions, you need to manually click through verify windows.
	/*cout << key << endl;
	if (key == 57358)
	{
		activeQuestion += 1;
	}
	if (key == 57356)
	{
		activeQuestion -= 1;
	}*/
	practice.textBoxTyping(0, 0, key, activeQuestion);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) 
{
	//Second interaction
	firstQuestion.secondInterraction();
	imageQ.secondInteraction();
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}