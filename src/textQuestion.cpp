#include "textQuestion.h"

textQuestion::textQuestion()
{
}

textQuestion::~textQuestion()
{
	//destruct
}

void textQuestion::setup(int numOfCharas)
{
	//Variable initialising
	programStart = true;
	input = 0;
	captchaLength = numOfCharas;

	// Asset loading
	correct.load("rightAnswer.wav"); //https://freesound.org/people/ertfelda/sounds/243701/
	click.load("clickSound.wav"); //https://freesound.org/people/notyermom/sounds/434833/
	startWindow.load("textBox.png");
	blockFont.load("textBox_font.ttf", 17);
	infoFont.load("font2.ttf", 17);

	//Generates random answer CAPTCHA, distorts and adds to vector
	for (int i = 0; i < captchaLength; i++)
	{
		charSequence.push_back(ofRandom(1,62));
		randomScaleX.push_back(ofRandom(0.6, 1));
		randomScaleY.push_back(ofRandom(0.8, 1));
		randomRotation.push_back(ofRandom(-20, 20));
	}
	
	//Generates CAPTCHA cloud
	for (int i = 0; i < 800; i++)
	{
		captchaCloud.push_back(ofRandom(1, 61));
		randomRotation.push_back(ofRandom(-20, 20));
		characterX.push_back(ofRandom(ofGetWidth()/2 - 500, ofGetWidth()/2 + 500));
		characterY.push_back(ofRandom(ofGetHeight()/2 - 384, ofGetHeight()/2 + 384));
	}
	
	//Assigns images
	pickLetters(charSequence, captchaImages, true);
	pickLetters(captchaCloud, captchaCloudImages, false);

}
void textQuestion::update(float xPos, float yPos)
{

}

void textQuestion::textOverlay(float mouseX, float mouseY)
{
	//Input handling
	input += 0.01;

	//Letter movement from mouse
	for (int i = 0; i < captchaCloud.size(); i++)
	{
		ofPushMatrix();
		captchaCloudImages[i].setAnchorPercent(0.5, 0.5);
		captchaCloudImages[i].draw(characterX[i] + (sin(input + ofRandom(-0.8, 0.8)) * 10), characterY[i] + (cos(input + ofRandom(-0.8, 0.8)) * 10));
		ofPopMatrix();
		mouseDist = ofDist(mouseX, mouseY, characterX[i], characterY[i] );
		if (mouseDist < 70 && programStart == false)
		{
			if (mouseX > characterX[i])
			{
				characterX[i] -= 8;
			}
			if (mouseX < characterX[i])
			{
				characterX[i] += 8;
			}
			if (mouseY > characterY[i])
			{
				characterY[i] -= 8;
			}
			if (mouseY < characterY[i])
			{
				characterY[i] += 8;
			}
			isMoving2 = true;
		}
		else
		{
			if (mouseDist > 500)
			{
				isMoving2 = false;
			}
		}
		if (isMoving2 == false && programStart == false)
		{
			if (ofGetWidth()/2 > characterX[i])
			{
				characterX[i] += 0.06;
			}
			if (ofGetWidth()/2 < characterX[i])
			{
				characterX[i] -= 0.06;
			}

			if (ofGetHeight()/2 > characterY[i])
			{
				characterY[i] += 0.06;
			}
			if (ofGetHeight()/2 < characterY[i])
			{
				characterY[i] -= 0.06;
			} 
		}
	}

	//Start window overlay
	if (programStart)
	{
		//Window bg
		ofFill();
		ofSetColor(249, 249, 249, 200);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

		//Window image
		ofSetColor(255);
		startWindow.draw(ofGetWidth() / 2 - startWindow.getWidth() / 2, ofGetHeight() / 2 - startWindow.getHeight() / 2);

		//Text
		ofSetColor(0);
		infoFont.drawString("Use the mouse to move the letters", ofGetWidth() / 2 - startWindow.getWidth() / 2 + 70, ofGetHeight() / 2 - startWindow.getHeight() / 2 + 80);
		infoFont.drawString("on screen and reveal", ofGetWidth() / 2 - startWindow.getWidth() / 2 + 150, ofGetHeight() / 2 - startWindow.getHeight() / 2 + 110);
		infoFont.drawString("the 6 character answer CAPTCHA!", ofGetWidth() / 2 - startWindow.getWidth() / 2 + 100, ofGetHeight() / 2 - startWindow.getHeight() / 2 + 140);
		infoFont.drawString("Type the text that doesn't move", ofGetWidth() / 2 - startWindow.getWidth() / 2 + 80, ofGetHeight() / 2 - startWindow.getHeight() / 2 + 170);
		infoFont.drawString("and press the enter key to submit", ofGetWidth() / 2 - startWindow.getWidth() / 2 + 70, ofGetHeight() / 2 - startWindow.getHeight() / 2 + 200);

		//Button
		ofSetColor(6, 3, 11);
		ofDrawRectangle(ofGetWidth() / 2 - 55, ofGetHeight() / 2 + 80, 110, 50);
		ofSetColor(250, 253, 252);
		blockFont.drawString("ok", ofGetWidth() / 2 - 10, ofGetHeight() / 2 + 115);
	}
}

void textQuestion::draw(float mouseX, float mouseY)
{
	//Draws chosen images
	for (int i = 0; i < charSequence.size(); i++)
	{
		ofSeedRandom(100);
		ofPushMatrix();
		ofTranslate(ofGetWidth() / 3, ofGetHeight()/2);
		ofRotateDeg(randomRotation[i]);
		ofScale(1, randomScaleY[i]);
		captchaImages[i].setAnchorPercent(0.5, 1);
		captchaImages[i].draw(i * 20 * ofRandom(5,15), 0);
		ofPopMatrix();
	}

}
void textQuestion::textBox(int xPos, int yPos,int width, int height, int keyInput)
{
	//initialising
	textDisplay = "";
	answer = "";

	//Adds text input to the answer vector
	for (int i = 0; i < textBoxInput.size(); i++)
	{
		textDisplay += textBoxInput[i];
	}
	for (int i = 0; i < answerInput.size(); i++)
	{
		answer += answerInput[i];
	}

	//Draw
	ofSetColor(0);
	ofDrawRectangle(xPos, yPos, width, height);
	ofSetColor(255);
	ofDrawRectangle(xPos + 2, yPos + 2, width - 4, height - 4);
	ofPushStyle();
	ofSetColor(0);
	blockFont.drawString(textDisplay, xPos + 3, yPos + 22);
	ofPopStyle();
	if (textDisplay == "")
	{
		int time = ofGetElapsedTimef() * 1.2;
		ofSetColor(0);
		ofSetLineWidth(3);
		if (time % 2)
		{
			ofDrawLine(xPos + 10, yPos + 5, xPos + 10, yPos + 24);
		}
	}

	//Tests if user input is correct
	if (textBoxInput.size() == answerInput.size())
	{
		for (int i = 0; i < textBoxInput.size(); i++)
		{
			if (textBoxInput[i] == answerInput[i])
			{
				answerCorrect = true;
			}
		}
		
	}
}
void textQuestion::mouseInteraction(int mouseX, int mouseY)
{
	//Button interaction
	if (mouseX > (ofGetWidth() / 2 - 55) && mouseX < (ofGetWidth() / 2 + 55) && mouseY >(ofGetHeight() / 2 + 80) && mouseY < (ofGetHeight() / 2 + 130))
	{
		programStart = false;
		click.play();
	}
}
void textQuestion::textBoxTyping(int xPos, int yPos, int keyInput, int& activeQuestion)
{
	//Lamda to designate keys to certain letters.
	auto designateKey = [&](string letter, int key)
	{
		if (keyInput == key)
		{
			textBoxInput.push_back(letter);
		}
	};
	
	//Lower case letters
	designateKey("a", 97);
	designateKey("b", 98);
	designateKey("c", 99);
	designateKey("d", 100);
	designateKey("e", 101);
	designateKey("f", 102);
	designateKey("g", 103);
	designateKey("h", 104);
	designateKey("i", 105);
	designateKey("j", 106);
	designateKey("k", 107);
	designateKey("l", 108);
	designateKey("m", 109);
	designateKey("n", 110);
	designateKey("o", 111);
	designateKey("p", 112);
	designateKey("q", 113);
	designateKey("r", 114);
	designateKey("s", 115);
	designateKey("t", 116);
	designateKey("u", 117);
	designateKey("v", 118);
	designateKey("w", 119);
	designateKey("x", 120);
	designateKey("y", 121);
	designateKey("z", 122);

	//Upper case Letters
	designateKey("A", 65);
	designateKey("B", 66);
	designateKey("C", 67);
	designateKey("D", 68);
	designateKey("E", 69);
	designateKey("F", 70);
	designateKey("G", 71);
	designateKey("H", 72);
	designateKey("I", 73);
	designateKey("J", 74);
	designateKey("K", 75);
	designateKey("L", 76);
	designateKey("M", 77);
	designateKey("N", 78);
	designateKey("O", 79);
	designateKey("P", 80);
	designateKey("Q", 81);
	designateKey("R", 82);
	designateKey("S", 83);
	designateKey("T", 84);
	designateKey("U", 85);
	designateKey("V", 86);
	designateKey("W", 87);
	designateKey("X", 88);
	designateKey("Y", 89);
	designateKey("Z", 90);

	//Numbers
	designateKey("0", 48);
	designateKey("1", 49);
	designateKey("2", 50);
	designateKey("3", 51);
	designateKey("4", 52);
	designateKey("5", 53);
	designateKey("6", 54);
	designateKey("7", 55);
	designateKey("8", 56);
	designateKey("9", 57);
	
	//Backspace
	if (textBoxInput.size() > 0)
	{
		if (keyInput == 8)
		{
			textBoxInput.pop_back();
		}
	}
	
	//Tests if correct
	if (keyInput == 13 && answerCorrect == true)
	{
		correct.play();
		activeQuestion += 1;
    }
	
}

void textQuestion::pickLetters(vector <int>& m, vector <ofImage>& imageOut, bool isAnswer)
{
	//Loads images for each character available.
	for (int i = 0; i < m.size(); i++)
	{
		if (m[i] == 1)
		{
			ofImage A;
			A.load("A.png");
			imageOut.push_back(A);
			if(isAnswer)answerInput.push_back("A");
		}
		if (m[i] == 2)
		{
			ofImage B;
			B.load("B.png");
			imageOut.push_back(B);
			if (isAnswer)answerInput.push_back("B");
		}
		if (m[i] == 3)
		{
			ofImage C;
			C.load("C.png");
			imageOut.push_back(C);
			if (isAnswer)answerInput.push_back("C");
		}
		if (m[i] == 4)
		{
			ofImage D;
			D.load("D.png");
			imageOut.push_back(D);
			if (isAnswer)answerInput.push_back("D");
		}
		if (m[i] == 5)
		{
			ofImage E;
			E.load("E.png");
			imageOut.push_back(E);
			if (isAnswer)answerInput.push_back("E");
		}
		if (m[i] == 6)
		{
			ofImage F;
			F.load("F.png");
			imageOut.push_back(F);
			if (isAnswer)answerInput.push_back("F");
		}
		if (m[i] == 7)
		{
			ofImage G;
			G.load("G.png");
			imageOut.push_back(G);
			if (isAnswer)answerInput.push_back("G");
		}
		if (m[i] == 8)
		{
			ofImage H;
			H.load("H.png");
			imageOut.push_back(H);
			if (isAnswer)answerInput.push_back("H");
		}
		if (m[i] == 9)
		{
			ofImage I;
			I.load("I.png");
			imageOut.push_back(I);
			if (isAnswer)answerInput.push_back("I");
		}
		if (m[i] == 10)
		{
			ofImage J;
			J.load("J.png");
			imageOut.push_back(J);
			if (isAnswer)answerInput.push_back("J");
		}
		if (m[i] == 11)
		{
			ofImage K;
			K.load("K.png");
			imageOut.push_back(K);
			if (isAnswer)answerInput.push_back("K");
		}
		if (m[i] == 12)
		{
			ofImage L;
			L.load("L.png");
			imageOut.push_back(L);
			if (isAnswer)answerInput.push_back("L");
		}
		if (m[i] == 13)
		{
			ofImage M;
			M.load("M.png");
			imageOut.push_back(M);
			if (isAnswer)answerInput.push_back("M");
		}
		if (m[i] == 14)
		{
			ofImage N;
			N.load("N.png");
			imageOut.push_back(N);
			if (isAnswer)answerInput.push_back("N");
		}
		if (m[i] == 15)
		{
			ofImage O;
			O.load("O.png");
			imageOut.push_back(O);
			if (isAnswer)answerInput.push_back("O");
		}
		if (m[i] == 16)
		{
			ofImage P;
			P.load("P.png");
			imageOut.push_back(P);
			if (isAnswer)answerInput.push_back("P");
		}
		if (m[i] == 17)
		{
			ofImage Q;
			Q.load("Q.png");
			imageOut.push_back(Q);
			if (isAnswer)answerInput.push_back("Q");
		}
		if (m[i] == 18)
		{
			ofImage R;
			R.load("R.png");
			imageOut.push_back(R);
			if (isAnswer)answerInput.push_back("R");
		}
		if (m[i] == 19)
		{
			ofImage S;
			S.load("S.png");
			imageOut.push_back(S);
			if (isAnswer)answerInput.push_back("S");
		}
		if (m[i] == 20)
		{
			ofImage T;
			T.load("T.png");
			imageOut.push_back(T);
			if (isAnswer)answerInput.push_back("T");
		}
		if (m[i] == 21)
		{
			ofImage U;
			U.load("U.png");
			imageOut.push_back(U);
			if (isAnswer)answerInput.push_back("U");
		}
		if (m[i] == 22)
		{
			ofImage V;
			V.load("V.png");
			imageOut.push_back(V);
			if (isAnswer)answerInput.push_back("V");
		}
		if (m[i] == 23)
		{
			ofImage W;
			W.load("W.png");
			imageOut.push_back(W);
			if (isAnswer)answerInput.push_back("W");
		}
		if (m[i] == 24)
		{
			ofImage X;
			X.load("X.png");
			imageOut.push_back(X);
			if (isAnswer)answerInput.push_back("X");
		}
		if (m[i] == 25)
		{
			ofImage Y;
			Y.load("Y.png");
			imageOut.push_back(Y);
			if (isAnswer)answerInput.push_back("Y");
		}
		if (m[i] == 26)
		{
			ofImage Z;
			Z.load("Z.png");
			imageOut.push_back(Z);
			if (isAnswer)answerInput.push_back("Z");
		}
		if (m[i] == 27)
		{
			ofImage a2;
			a2.load("a2.png");
			imageOut.push_back(a2);
			if (isAnswer)answerInput.push_back("a");
		}
		if (m[i] == 28)
		{
			ofImage b2;
			b2.load("b2.png");
			imageOut.push_back(b2);
			if (isAnswer)answerInput.push_back("b");
		}
		if (m[i] == 29)
		{
			ofImage c2;
			c2.load("c2.png");
			imageOut.push_back(c2);
			if (isAnswer)answerInput.push_back("c");
		}
		if (m[i] == 30)
		{
			ofImage d2;
			d2.load("d2.png");
			imageOut.push_back(d2);
			if (isAnswer)answerInput.push_back("d");
		}
		if (m[i] == 31)
		{
			ofImage e2;
			e2.load("e2.png");
			imageOut.push_back(e2);
			if (isAnswer)answerInput.push_back("e");
		}
		if (m[i] == 32)
		{
			ofImage f2;
			f2.load("f2.png");
			imageOut.push_back(f2);
			if (isAnswer)answerInput.push_back("f");
		}
		if (m[i] == 62)
		{
			ofImage g2;
			g2.load("g2.png");
			imageOut.push_back(g2);
			if (isAnswer)answerInput.push_back("g");
		}
		if (m[i] == 33)
		{
			ofImage h2;
			h2.load("h2.png");
			imageOut.push_back(h2);
			if (isAnswer)answerInput.push_back("h");
		}
	
		if (m[i] == 34)
		{
			ofImage i2;
			i2.load("i2.png");
			imageOut.push_back(i2);
			if (isAnswer)answerInput.push_back("i");
		}
		if (m[i] == 35)
		{
			ofImage j2;
			j2.load("j2.png");
			imageOut.push_back(j2);
			if (isAnswer)answerInput.push_back("j");
		}
		if (m[i] == 36)
		{
			ofImage k2;
			k2.load("k2.png");
			imageOut.push_back(k2);
			if (isAnswer)answerInput.push_back("k");
		}
		if (m[i] == 37)
		{
			ofImage l2;
			l2.load("l2.png");
			imageOut.push_back(l2);
			if (isAnswer)answerInput.push_back("l");
		}
		if (m[i] == 38)
		{
			ofImage m2;
			m2.load("m2.png");
			imageOut.push_back(m2);
			if (isAnswer)answerInput.push_back("m");
		}
		if (m[i] == 39)
		{
			ofImage n2;
			n2.load("n2.png");
			imageOut.push_back(n2);
			if (isAnswer)answerInput.push_back("n");
		}
		if (m[i] == 40)
		{
			ofImage o2;
			o2.load("o2.png");
			imageOut.push_back(o2);
			if (isAnswer)answerInput.push_back("o");

		}
		if (m[i] == 41)
		{
			ofImage p2;
			p2.load("p2.png");
			imageOut.push_back(p2);
			if (isAnswer)answerInput.push_back("p");
		}
		if (m[i] == 42)
		{
			ofImage q2;
			q2.load("q2.png");
			imageOut.push_back(q2);
			if (isAnswer)answerInput.push_back("q");

		}
		if (m[i] == 43)
		{
			ofImage r2;
			r2.load("r2.png");
			imageOut.push_back(r2);
			if (isAnswer)answerInput.push_back("r");
		}
		if (m[i] == 44)
		{
			ofImage s2;
			s2.load("s2.png");
			imageOut.push_back(s2);
			if (isAnswer)answerInput.push_back("s");
		}
		if (m[i] == 45)
		{
			ofImage t2;
			t2.load("t2.png");
			imageOut.push_back(t2);
			if (isAnswer)answerInput.push_back("t");
		}
		if (m[i] == 46)
		{
			ofImage u2;
			u2.load("u2.png");
			imageOut.push_back(u2);
			if (isAnswer)answerInput.push_back("u");
		}
		if (m[i] == 47)
		{
			ofImage v2;
			v2.load("v2.png");
			imageOut.push_back(v2);
			if (isAnswer)answerInput.push_back("v");
		}
		if (m[i] == 48)
		{
			ofImage w2;
			w2.load("w2.png");
			imageOut.push_back(w2);
			if (isAnswer)answerInput.push_back("w");
		}
		if (m[i] == 49)
		{
			ofImage x2;
			x2.load("x2.png");
			imageOut.push_back(x2);
			if (isAnswer)answerInput.push_back("x");
		}
		if (m[i] == 50)
		{
			ofImage y2;
			y2.load("y2.png");
			imageOut.push_back(y2);
			if (isAnswer)answerInput.push_back("y");
		}
		if (m[i] == 51)
		{
			ofImage z2;
			z2.load("z2.png");
			imageOut.push_back(z2);
			if(isAnswer)answerInput.push_back("z");
		}
		if (m[i] == 52)
		{
			ofImage zero;
			zero.load("0.png");
			imageOut.push_back(zero);
			if (isAnswer)answerInput.push_back("0");
		}
		if (m[i] == 53)
		{
			ofImage one;
			one.load("1.png");
			imageOut.push_back(one);
			if (isAnswer)answerInput.push_back("1");

		}
		if (m[i] == 54)
		{
			ofImage two;
			two.load("2.png");
			imageOut.push_back(two);
			if (isAnswer)answerInput.push_back("2");

		}
		if (m[i] == 55)
		{
			ofImage three;
			three.load("3.png");
			imageOut.push_back(three);
			if (isAnswer)answerInput.push_back("3");
		}
		if (m[i] == 56)
		{
			ofImage four;
			four.load("4.png");
			imageOut.push_back(four);
			if (isAnswer)answerInput.push_back("4");
		}
		if (m[i] == 57)
		{
			ofImage five;
			five.load("5.png");
			imageOut.push_back(five);
			if (isAnswer)answerInput.push_back("5");
		}
		if (m[i] == 58)
		{
			ofImage six;
			six.load("6.png");
			imageOut.push_back(six);
			if (isAnswer)answerInput.push_back("6");
		}
		if (m[i] == 59)
		{
			ofImage seven;
			seven.load("7.png");
			imageOut.push_back(seven);
			if (isAnswer)answerInput.push_back("7");
		}
		if (m[i] == 60)
		{
			ofImage eight;
			eight.load("8.png");
			imageOut.push_back(eight);
			if (isAnswer)answerInput.push_back("8");
		}
		if (m[i] == 61)
		{
			ofImage nine;
			nine.load("9.png");
			imageOut.push_back(nine);
			if (isAnswer)answerInput.push_back("9");
		}
	}
}

