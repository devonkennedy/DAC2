#include "imageQuestion.h"
static void orangeCaptcha(vector <ofImage>& displayImage, int orangeNum)
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , 11, 12 };
	std::random_shuffle(std::begin(a), std::end(a));
	//Pick one of 3 orange images
	if (orangeNum == 1)
	{
		ofImage orange1;
		orange1.load("orange.jpg");
		displayImage.push_back(orange1);
	}
	if (orangeNum == 2)
	{
		ofImage orange2;
		orange2.load("orange2.jpg");
		displayImage.push_back(orange2);
	}
	if (orangeNum == 3)
	{
		ofImage orange3;
		orange3.load("orange3.jpg");
		displayImage.push_back(orange3);
	}
	//Pick 8 of 12 other images
	for (int i = 0; i < 9; i++)
	{
		if (a[i] == 1)
		{
			ofImage notOrange1;
			notOrange1.load("notOrange.jpg");
			displayImage.push_back(notOrange1);
		}
		if (a[i] == 2)
		{
			ofImage notOrange2;
			notOrange2.load("notOrange2.jpg");
			displayImage.push_back(notOrange2);
		}
		if (a[i] == 3)
		{
			ofImage notOrange3;
			notOrange3.load("notOrange3.jpg");
			displayImage.push_back(notOrange3);
		}
		if (a[i] == 4)
		{
			ofImage notOrange4;
			notOrange4.load("notOrange4.jpg");
			displayImage.push_back(notOrange4);
		}
		if (a[i] == 5)
		{
			ofImage notOrange5;
			notOrange5.load("notOrange5.jpg");
			displayImage.push_back(notOrange5);
		}
		if (a[i] == 6)
		{
			ofImage notOrange6;
			notOrange6.load("notOrange6.jpg");
			displayImage.push_back(notOrange6);
		}
		if (a[i] == 7)
		{
			ofImage notOrange7;
			notOrange7.load("notOrange7.jpg");
			displayImage.push_back(notOrange7);
		}
		if (a[i] == 8)
		{
			ofImage notOrange8;
			notOrange8.load("notOrange8.jpg");
			displayImage.push_back(notOrange8);
		}
		if (a[i] == 9)
		{
			ofImage notOrange9;
			notOrange9.load("notOrange9.jpg");
			displayImage.push_back(notOrange9);
		}
		if (a[i] == 10)
		{
			ofImage notOrange10;
			notOrange10.load("notOrange10.jpg");
			displayImage.push_back(notOrange10);
		}
		if (a[i] == 11)
		{
			ofImage notOrange11;
			notOrange11.load("notOrange11.jpg");
			displayImage.push_back(notOrange11);
		}
		if (a[i] == 12)
		{
			ofImage notOrange12;
			notOrange12.load("notOrange12.jpg");
			displayImage.push_back(notOrange12);
		}
		 
	}

}
static void catCaptcha(vector <ofImage>& displayImage, int catNum)
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , 11, 12 };
	std::random_shuffle(std::begin(a), std::end(a));
	//Pick one of 3 cat images
	if (catNum == 1)
	{
		ofImage cat1;
		cat1.load("cat.jpg");
		displayImage.push_back(cat1);
	}
	if (catNum == 2)
	{
		ofImage cat2;
		cat2.load("cat2.jpg");
		displayImage.push_back(cat2);
	}
	if (catNum == 3)
	{
		ofImage cat3;
		cat3.load("cat3.jpg");
		displayImage.push_back(cat3);
	}
	//Pick 8 of 12 other images
	for (int i = 0; i < 9; i++)
	{
		if (a[i] == 1)
		{
			ofImage notCat1;
			notCat1.load("notCat.jpg");
			displayImage.push_back(notCat1);
		}
		if (a[i] == 2)
		{
			ofImage notCat2;
			notCat2.load("notCat2.jpg");
			displayImage.push_back(notCat2);
		}
		if (a[i] == 3)
		{
			ofImage notCat3;
			notCat3.load("notCat3.jpg");
			displayImage.push_back(notCat3);
		}
		if (a[i] == 4)
		{
			ofImage notCat4;
			notCat4.load("notCat4.jpg");
			displayImage.push_back(notCat4);
		}
		if (a[i] == 5)
		{
			ofImage notCat5;
			notCat5.load("notCat5.jpg");
			displayImage.push_back(notCat5);
		}
		if (a[i] == 6)
		{
			ofImage notCat6;
			notCat6.load("notCat6.jpg");
			displayImage.push_back(notCat6);
		}
		if (a[i] == 7)
		{
			ofImage notCat7;
			notCat7.load("notCat7.jpg");
			displayImage.push_back(notCat7);
		}
		if (a[i] == 8)
		{
			ofImage notCat8;
			notCat8.load("notCat8.jpg");
			displayImage.push_back(notCat8);
		}
		if (a[i] == 9)
		{
			ofImage notCat9;
			notCat9.load("notCat9.jpg");
			displayImage.push_back(notCat9);
		}
		if (a[i] == 10)
		{
			ofImage notCat10;
			notCat10.load("notCat10.jpg");
			displayImage.push_back(notCat10);
		}
		if (a[i] == 11)
		{
			ofImage notCat11;
			notCat11.load("notCat11.jpg");
			displayImage.push_back(notCat11);
		}
		if (a[i] == 12)
		{
			ofImage notCat12;
			notCat12.load("notCat12.jpg");
			displayImage.push_back(notCat12);
		}

	}

}
static void carCaptcha(vector <ofImage>& displayImage, int carNum)
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , 11, 12 };
	std::random_shuffle(std::begin(a), std::end(a));
	//Pick one of 3 red car images
	if (carNum == 1)
	{
		ofImage redcar1;
		redcar1.load("redcar.jpg");
		displayImage.push_back(redcar1);
	}
	if (carNum == 2)
	{
		ofImage redcar2;
		redcar2.load("redcar2.jpg");
		displayImage.push_back(redcar2);
	}
	if (carNum == 3)
	{
		ofImage redcar3;
		redcar3.load("redcar3.jpg");
		displayImage.push_back(redcar3);
	}
	//Pick 8 of 12 other images
	for (int i = 0; i < 9; i++)
	{
		if (a[i] == 1)
		{
			ofImage notredcar1;
			notredcar1.load("notredcar.jpg");
			displayImage.push_back(notredcar1);
		}
		if (a[i] == 2)
		{
			ofImage notredcar2;
			notredcar2.load("notredcar2.jpg");
			displayImage.push_back(notredcar2);
		}
		if (a[i] == 3)
		{
			ofImage notredcar3;
			notredcar3.load("notredcar3.jpg");
			displayImage.push_back(notredcar3);
		}
		if (a[i] == 4)
		{
			ofImage notredcar4;
			notredcar4.load("notredcar4.jpg");
			displayImage.push_back(notredcar4);
		}
		if (a[i] == 5)
		{
			ofImage notredcar5;
			notredcar5.load("notredcar5.jpg");
			displayImage.push_back(notredcar5);
		}
		if (a[i] == 6)
		{
			ofImage notredcar6;
			notredcar6.load("notredcar6.jpg");
			displayImage.push_back(notredcar6);
		}
		if (a[i] == 7)
		{
			ofImage notredcar7;
			notredcar7.load("notredcar7.jpg");
			displayImage.push_back(notredcar7);
		}
		if (a[i] == 8)
		{
			ofImage notredcar8;
			notredcar8.load("notredcar8.jpg");
			displayImage.push_back(notredcar8);
		}
		if (a[i] == 9)
		{
			ofImage notredcar9;
			notredcar9.load("notredcar9.jpg");
			displayImage.push_back(notredcar9);
		}
		if (a[i] == 10)
		{
			ofImage notredcar10;
			notredcar10.load("notredcar10.jpg");
			displayImage.push_back(notredcar10);
		}
		if (a[i] == 11)
		{
			ofImage notredcar11;
			notredcar11.load("notredcar11.jpg");
			displayImage.push_back(notredcar11);
		}
		if (a[i] == 12)
		{
			ofImage notredcar12;
			notredcar12.load("notredcar12.jpg");
			displayImage.push_back(notredcar12);
		}

	}

}
imageQuestion::imageQuestion()
{

}
void imageQuestion::setup(int type)
{
	//Asset loading
	bg1.load("background_noise.png");
	textBox.load("textBox.png");
	blockFont.load("font2.ttf", 17);
	blockFont2.load("font2.ttf", 20);
	click.load("clickSound.wav"); //https://freesound.org/people/notyermom/sounds/434833/
	correct.load("rightAnswer.wav"); //https://freesound.org/people/ertfelda/sounds/243701/

	//Variable initialising
	verifyPressed = false;
	startBox = true;
	answerNum = ofRandom(1, 3.5);
	selectedImage = -1;
	failCounter = 0;
	chosenCAPTCHA = (ofRandom(0, 3));

	if (chosenCAPTCHA == 0)
	{
		orangeCaptcha(displayImage, answerNum);
	}
	if (chosenCAPTCHA == 1)
	{
		catCaptcha(displayImage, answerNum);
	}
	if (chosenCAPTCHA == 2)
	{
		carCaptcha(displayImage, answerNum);
	}
	randomSpot = ofRandom(0, 8);
	swap(displayImage[0], displayImage[randomSpot]);
	answerCorrect = false;	
}

imageQuestion::~imageQuestion()
{

}

void imageQuestion::draw(float mouseX, float mouseY)
{
	//Draws border
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofPushMatrix();
	ofScale(1.7, 0.3);
	textBox.draw(-bg1.getWidth()/4.1, -bg1.getHeight() * 1.6);
	ofPopMatrix();
	ofPushMatrix();
	ofScale(1.2, 1.95);
	textBox.draw(-textBox.getWidth()/2, -textBox.getHeight()/2.5);
	ofPopMatrix();
	ofSetColor(0);
	if (chosenCAPTCHA == 0)
	{
		blockFont2.drawString("Please select the image of the 'ORANGE ' to continue", -bg1.getWidth() / 2.8, -bg1.getHeight() / 2.5);
	}
	if (chosenCAPTCHA == 1)
	{
		blockFont2.drawString("Please select the image of the 'CAT ' to continue", -bg1.getWidth() / 2.8 + 20, -bg1.getHeight() / 2.5);
	}
	if (chosenCAPTCHA == 2)
	{
		blockFont2.drawString("Please select the image of the 'RED CAR ' to continue", -bg1.getWidth() / 2.8, -bg1.getHeight() / 2.5);
	}
	
	//Black image borders
	for (int i = 0; i < 3; i++)
	{
		ofSetColor(0);
		ofDrawRectangle(-bg1.getWidth()/4.2, -bg1.getHeight()/3.9 + (165 * i), 154, 154);
		ofDrawRectangle(-bg1.getWidth()/4.2 + 165, -bg1.getHeight() / 3.9 + (165 * i), 154, 154);
		ofDrawRectangle(-bg1.getWidth()/4.2 + (165 * 2), -bg1.getHeight() / 3.9 + (165 * i), 154, 154);
	}

	//Red image border when selected
	if (selectedImage == 0)
	{
		ofSetColor(255, 0, 0);
		ofDrawRectangle(-bg1.getWidth() / 4.2 - 2, -bg1.getHeight() / 3.9 - 2, 158, 158);
	}
	if (selectedImage == 1)
	{
		ofSetColor(255, 0, 0);
		ofDrawRectangle(-bg1.getWidth() / 4.2 - 2, -bg1.getHeight() / 3.9 + 165 - 2, 158, 158);
	}
	if (selectedImage == 2)
	{
		ofSetColor(255, 0, 0);
		ofDrawRectangle(-bg1.getWidth() / 4.2 - 2, -bg1.getHeight() / 3.9 + + (165 * 2) - 2, 158, 158);
	}
	if (selectedImage == 3)
	{
		ofSetColor(255, 0, 0);
		ofDrawRectangle(-bg1.getWidth() / 4.2 + 165 - 2, -bg1.getHeight() / 3.9 - 2, 158, 158);
	}
	if (selectedImage == 4)
	{
		ofSetColor(255, 0, 0);
		ofDrawRectangle(-bg1.getWidth() / 4.2 + 165 - 2, -bg1.getHeight() / 3.9 + 165 - 2, 158, 158);
	}
	if (selectedImage == 5)
	{
		ofSetColor(255, 0, 0);
		ofDrawRectangle(-bg1.getWidth() / 4.2 + 165 - 2, -bg1.getHeight() / 3.9 - 2 + (165*2), 158, 158);
	}
	if (selectedImage == 6)
	{
		ofSetColor(255, 0, 0);
		ofDrawRectangle(-bg1.getWidth() / 4.2 + (165 * 2) - 2, -bg1.getHeight() / 3.9 - 2, 158, 158);
	}
	if (selectedImage == 7)
	{
		ofSetColor(255, 0, 0);
		ofDrawRectangle(-bg1.getWidth() / 4.2 + (165 * 2) - 2, -bg1.getHeight() / 3.9 - 2 + 165, 158, 158);
	}
	if (selectedImage == 8)
	{
		ofSetColor(255, 0, 0);
		ofDrawRectangle(-bg1.getWidth() / 4.2 + (165 * 2) - 2, -bg1.getHeight() / 3.9 - 2 + (165*2), 158, 158);
	}

	//Displays images
	for (int i = 0; i < 3; i++)
	{
		ofSetColor(255);
		displayImage[i].draw(-bg1.getWidth() / 4.2 + 2, -bg1.getHeight() / 3.9 + (165 * i) + 2);
		displayImage[i + 3].draw(-bg1.getWidth() / 4.2 + 165 + 2, -bg1.getHeight() / 3.9 + (165 * i) + 2);
		displayImage[i + 6].draw(-bg1.getWidth() / 4.2 + (165 * 2) + 2, -bg1.getHeight() / 3.9 + (165 * i) + 2);
	}
	
	//Verify button, changes colour when pressed.
	ofFill();
	if (verifyPressed)
	{
		ofSetColor(255);
	}
	else {
		ofSetColor(0);
	}
	ofDrawRectangle(-70, bg1.getHeight()/2.6, 130, 60);
	ofNoFill();
	ofSetColor(0);
	ofDrawRectangle(-70, bg1.getHeight()/2.6, 130, 60);
	ofFill();

	//Text
	ofPushStyle();
	if (verifyPressed)
	{
		ofSetColor(0);
	}
	else
	{
		ofSetColor(250, 253, 252);
	}
	blockFont.drawString("verify", -40, bg1.getHeight() / 2.6 + 40);
	ofPopStyle();

	//Checks if image is correct
	ofSetColor(255);
	if (selectedImage == randomSpot)
	{
		answerCorrect = true;
	}
	else
	{
		answerCorrect = false;
	}

	//Start window overlay
	if (startBox)
	{
		//Window bg
		ofFill();
		ofSetColor(249, 249, 249, 200);
		ofDrawRectangle(-ofGetWidth()/2, -ofGetHeight()/2, ofGetWidth(), ofGetHeight());

		//Window image
		ofSetColor(255);
		textBox.draw(-textBox.getWidth() / 2, -textBox.getHeight() / 2);

		//Text
		ofSetColor(0);
		blockFont.drawString("Pick the image which matches the", -textBox.getWidth() / 2 + 75,  -textBox.getHeight() / 2 + 80);
		blockFont.drawString("statement",  -textBox.getWidth() / 2 + 200, -textBox.getHeight() / 2 + 110);
		blockFont.drawString("Click the image and press verify", -textBox.getWidth() / 2 + 75, -textBox.getHeight() / 2 + 140);
		blockFont.drawString("to submit.", -textBox.getWidth() / 2 + 200, -textBox.getHeight() / 2 + 170);
		blockFont.drawString("Careful, you only have 3 chances", -textBox.getWidth() / 2 + 75, -textBox.getHeight() / 2 + 200);

		//Button
		ofSetColor(6, 3, 11);
		ofDrawRectangle(-55, 80, 110, 50);
		ofSetColor(250, 253, 252);
		blockFont.drawString("ok", -10, 115);
	}
	//Uncomment to see solution image
	//cout << selectedImage << " + " << randomSpot << endl;
}
void imageQuestion::mouseInteraction(float mouseX, float mouseY, int& activeQuestion)
{
	//Button interaction
	if (mouseX > (ofGetWidth() / 2 - 55) && mouseX < (ofGetWidth() / 2 + 55) && mouseY >(ofGetHeight() / 2 + 80) && mouseY < (ofGetHeight() / 2 + 130))
	{
		startBox = false;
		click.play();
	}

	//Select images
	int imageX = -bg1.getWidth() / 4.2;
	int imageY = -bg1.getHeight() / 3.9;
	int widthTranslation = ofGetWidth() / 2;
	int heightTranslation = ofGetHeight() / 2;
	if ( mouseX > widthTranslation + imageX && mouseX < widthTranslation + imageX + 150 && mouseY > heightTranslation + imageY && mouseY < heightTranslation + imageY + 150)
	{
		selectedImage = 0;
		click.play();
	}
	if (mouseX > widthTranslation + imageX && mouseX < widthTranslation + imageX + 150 && mouseY >  heightTranslation + imageY + (165) && mouseY < heightTranslation + imageY + (165) + 150)
	{
		selectedImage = 1;
		click.play();
	}
	if (mouseX > widthTranslation + imageX && mouseX < widthTranslation + imageX + 150 && mouseY >  heightTranslation + imageY + (165 * 2) && mouseY < heightTranslation + imageY + (165 * 2) + 150)
	{
		selectedImage = 2;
		click.play();
	}
	if (mouseX > widthTranslation + imageX + 150 && mouseX < widthTranslation + imageX + 300 && mouseY >  heightTranslation + imageY && mouseY < heightTranslation + imageY + 150)
	{
		selectedImage = 3;
		click.play();
	}
	if (mouseX > widthTranslation + imageX + 150 && mouseX < widthTranslation + imageX + 300 && mouseY > heightTranslation + imageY + (165) && mouseY < heightTranslation + imageY + (165) + 150)
	{
		selectedImage = 4;
		click.play();
	}
	if (mouseX > widthTranslation + imageX + 150 && mouseX < widthTranslation + imageX + 300 && mouseY >  heightTranslation + imageY + (165 * 2) && mouseY < heightTranslation + imageY + (165 * 2) + 150)
	{
		selectedImage = 5;
		click.play();
	}
	if (mouseX > widthTranslation + imageX + 300 && mouseX < widthTranslation + imageX + 450 && mouseY > heightTranslation + imageY && mouseY < heightTranslation + imageY + 150)
	{
		selectedImage = 6;
		click.play();
	}
	if (mouseX > widthTranslation + imageX + 300 && mouseX < widthTranslation + imageX + 450 && mouseY > heightTranslation + imageY + (165) && mouseY < heightTranslation + imageY + (165) + 150)
	{
		selectedImage = 7;
		click.play();
	}
	if (mouseX > widthTranslation + imageX + 300 && mouseX < widthTranslation + imageX + 450 && mouseY >  heightTranslation + imageY + (165 * 2) && mouseY < heightTranslation + imageY + (165 * 2) + 150)
	{
		selectedImage = 8;
		click.play();
	}

	if (mouseX > widthTranslation - 70 && mouseX < widthTranslation + 60 && mouseY > heightTranslation + bg1.getHeight() / 2.6 && mouseY < heightTranslation + bg1.getHeight() / 2.6 + 60)
	{
		verifyPressed = true;
		click.play();
	}
	if (verifyPressed && answerCorrect)
	{
		correct.play();
		activeQuestion += 1;
	}
	if(verifyPressed && answerCorrect == false)
	{
		failCounter += 1;
	}
	if (failCounter >= 3)
	{
		activeQuestion = 8;
	}
}
void imageQuestion::secondInteraction()
{
	verifyPressed = false;
}