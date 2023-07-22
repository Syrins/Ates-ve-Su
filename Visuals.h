#pragma once
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <cstring>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <sftools/Chronometer.hpp>
#include <fstream>
#include "DataRetrieval.h"
using namespace std;
using namespace sf;
using namespace sftools;



Vector2f vec1(1280, 40), vec2(40, 720);







Texture waterMidText;
Texture waterLeftText;
Texture waterRightText;
Texture lavaMidText;
Texture lavaLeftText;
Texture lavaRightText;
Texture acidMidText;
Texture acidLeftText;
Texture acidRightText;
Texture smallAcidText;
Texture smallLavaText;
Texture smallWaterText;
Texture waterMidSandText;
Texture waterLeftSandText;
Texture waterRightSandText;
Texture lavaMidSandText;
Texture lavaLeftSandText;
Texture lavaRightSandText;
Texture acidMidSandText;
Texture acidLeftSandText;
Texture acidRightSandText;
Texture smallAcidSandText;
Texture smallLavaSandText;
Texture smallWaterSandText;



Texture textureGateTop;
Texture textureGateMiddle;
Texture textureGateBottom;
Texture textureGateBottomMiddle;


Texture textureBridgeLeft;
Texture textureBridgeMiddle;


Texture textureButtonOn;
Texture textureButtonOff;
Texture textureButtonOnSand;
Texture textureButtonOffSand;


Texture fireBoyTexture;
Texture fireBoyTextureLeft;
Texture fireBoyTextureRight;
Texture waterGirlTexture;
Texture waterGirlTextureLeft;
Texture waterGirlTextureRight;


Texture textureBackground;
Texture textureBackgroundSand;
Texture textureMenuBackground;


Texture texturePauseBackground;


Texture textureTopBorder;
Texture textureSideBorder;
Texture textureBottomBorder;
Texture textureTopBorderSand;
Texture textureSideBorderSand;
Texture textureBottomBorderSand;


Texture smoke1Text;
Texture smoke2Text;


Texture textureStoneLeft;
Texture textureStoneMid;
Texture textureStoneRight;
Texture textureSandLeft;
Texture textureSandMid;
Texture textureSandRight;


Texture textureRedArrow;
Texture textureWhiteArrow;


Texture textureDoor;


Texture textureBlueGem;
Texture textureRedGem;


Texture textureBox;


Texture enemyText;
Texture enemyLeftText;
Texture enemyRightText;




Font fontTitle;





FloatRect textRect;







Text textTitle;


Text player1Text;
Text player2Text;


Text textEnterYourName;


Text textIntro;


Text textPaused;


Text textGameOver;


Text textStart;


Text textMainMenu;


Text textRetryLevel;


Text textContinue;


Text textContinueIntro;


Text textExit;


Text textGuest;


Text textContinueToGame;


Text textLeaderboards;


Text textLeaderboard;


Text textLevels[10];


Text textMainLevels[10];


Text textLevelsTitle;


Text textSettingsButton;
Text textSettingsTitle;


Text textOn;


Text textOff;


Text textMusic;


Text textSoundFx;


Text textThemesButton;
Text textThemesTitle;
Text textSand;
Text textStone;



Color color(0, 0, 0, 0);
Color color2(255, 255, 255, 0);







RectangleShape buttonOn({80,60});


RectangleShape buttonOff({80,60});


RectangleShape ground({1280, 1});


RectangleShape spriteBackground(Vector2f(80, 40));



RectangleShape borders[4];


RectangleShape spriteStoneMid(Vector2f(80.f, 40.f));
RectangleShape spriteStoneLeft(Vector2f(80.f, 40.f));
RectangleShape spriteStoneRight(Vector2f(80.f, 40.f));


RectangleShape enterYourNameRectangle;
RectangleShape enterYourNameRectangle2;


RectangleShape enterYourNameRectangleFade;
RectangleShape enterYourNameRectangleFade2;


RectangleShape arrow;
RectangleShape arrowLevelInquire;
RectangleShape arrowLeaderboards;
RectangleShape arrowLevelLeaderboard;
RectangleShape arrowThemes;
RectangleShape arrowMainMenu;






string player1Name;
string player2Name;







Sprite smoke1;
Sprite smoke2;


Sprite spritePauseBackground;


Sprite spriteDoor;


Sprite spriteBox;



Sprite spriteLavaLeft;
Sprite spriteLavaRight;
Sprite spriteLavaMid;
Sprite spriteSmallLava;

Sprite spriteWaterLeft;
Sprite spriteWaterRight;
Sprite spriteWaterMid;
Sprite spriteSmallWater;

Sprite spriteAcidLeft;
Sprite spriteAcidRight;
Sprite spriteAcidMid;
Sprite spriteSmallAcid;






Music musicIntro;


Music musicLevel;


Music musicFinalLevel;







SoundBuffer bufferFireboyJump;


SoundBuffer bufferWatergirlJump;


SoundBuffer bufferLevelComplete;


SoundBuffer bufferPlayerDeath;


SoundBuffer bufferButtonHover;


SoundBuffer bufferButtonSound;


SoundBuffer bufferGemSound;






Sound soundButtonHover(bufferButtonHover);


Sound soundLevelComplete(bufferLevelComplete);


Sound soundFireboyJump(bufferFireboyJump);


Sound soundWatergirlJump(bufferWatergirlJump);


Sound soundPlayerDeath(bufferPlayerDeath);


Sound buttonSound(bufferButtonSound);


Sound soundGem(bufferGemSound);



Text textTimer;
stringstream ss;
Chronometer chron;
string stringTimer;

int callCounter = 0;
int continueFillColor = 255;
int enterYourNameFillColor = 255;
int player1InputBoxFillColor = 255;
int player2InputBoxFillColor = 255;
int currentLevelLeaderboardPage = 0;


Texture sandFillingText, stoneFillingText;

void initVisuals()
{
    callCounter++;

    
    textureGateBottom.loadFromFile(m + "assets/graphics/gateBottom.png");
    textureGateMiddle.loadFromFile(m + "assets/graphics/gateMiddle.png");
    textureGateTop.loadFromFile(m + "assets/graphics/gateTop.png");

    
    textureBridgeLeft.loadFromFile(m + "assets/graphics/bridgeLeft.png");
    textureBridgeMiddle.loadFromFile(m + "assets/graphics/bridgeMiddle.png");

    
    textureRedArrow.loadFromFile(m + "assets/graphics/redArrow.png");
    textureWhiteArrow.loadFromFile(m + "assets/graphics/whiteArrow.png");

    arrow.setSize(Vector2f(150, 80));
    arrow.setPosition(30, 40);
    arrow.setTexture(&textureWhiteArrow);

    arrowLevelInquire = arrow;
    arrowLeaderboards = arrow;
    arrowLevelLeaderboard = arrow;
    arrowThemes = arrow;
    arrowMainMenu = arrow;

    
    textureDoor.loadFromFile(m + "assets/graphics/door.png");

    spriteDoor.setTexture(textureDoor);

    
    textureBlueGem.loadFromFile(m + "assets/graphics/blueGem.png");
    textureRedGem.loadFromFile(m + "assets/graphics/redGem.png");

    
    bufferFireboyJump.loadFromFile(m + "assets/audio/fireboyJump.ogg");
    bufferButtonHover.loadFromFile(m + "assets/audio/buttonHover.ogg");
    bufferWatergirlJump.loadFromFile(m + "assets/audio/watergirlJump.ogg");
    bufferLevelComplete.loadFromFile(m + "assets/audio/levelComplete.ogg");
    bufferPlayerDeath.loadFromFile(m + "assets/audio/death.ogg");
    bufferButtonSound.loadFromFile(m + "assets/audio/buttonSound.wav");
    bufferGemSound.loadFromFile(m + "assets/audio/coinCollect.ogg");

    
    soundGem.setVolume(30);

    
    musicIntro.openFromFile(m + "assets/audio/intro.ogg");
    musicLevel.openFromFile(m + "assets/audio/level.ogg");
    musicFinalLevel.openFromFile(m + "assets/audio/finalLevel.ogg");
    musicIntro.setLoop(true);
    musicLevel.setLoop(true);
    musicFinalLevel.setLoop(true);

    musicIntro.setVolume(50);
    musicLevel.setVolume(40);
    musicLevel.setVolume(40);
    soundButtonHover.setVolume(1000);

    
    textTimer.setFont(fontTitle);
    textTimer.setPosition(590, 0);
    textTimer.setCharacterSize(35);
    textTimer.setFillColor(Color::White);

    
    for (int i = 0; i < 10; i++)
    {
        textLevels[i].setFont(fontTitle);
        textLevels[i].setCharacterSize(50);
        textLevels[i].setFillColor(Color::White);
        textLevels[i].setString("Level " + to_string(i + 1));

        textRect = textLevels[i].getLocalBounds();
        textLevels[i].setOrigin(textRect.left +
            textRect.width / 2.0f,
            textRect.top +
            textRect.height / 2.0f);
        textLevels[i].setPosition(((i < 5) ? 440 : 840), (i < 5) ? (i + 1) * 100 + 130 : (i - 5 + 1) * 100 + 130);
    }

    for (int i = 0; i < 10; i++)
    {
        textMainLevels[i].setFont(fontTitle);
        textMainLevels[i].setCharacterSize(70);
        textMainLevels[i].setFillColor(Color::White);
        textMainLevels[i].setString("" + to_string(i + 1) + " Level Tablo");

        textRect = textMainLevels[i].getLocalBounds();
        textMainLevels[i].setOrigin(textRect.left +
            textRect.width / 2.0f,
            textRect.top +
            textRect.height / 2.0f);
        textMainLevels[i].setPosition(640, 100);
    }

    
    textLevelsTitle.setFont(fontTitle);
    textLevelsTitle.setCharacterSize(70);
    textLevelsTitle.setFillColor(Color::White);
    textLevelsTitle.setString("Leveller");

    textRect = textLevelsTitle.getLocalBounds();
    textLevelsTitle.setOrigin(textRect.left +
                         textRect.width / 2.0f,
                         textRect.top +
                         textRect.height / 2.0f);
    textLevelsTitle.setPosition(640, 100);

    
    textSettingsButton.setFont(fontTitle);
    textSettingsButton.setString("Ayarlar");
    textSettingsButton.setCharacterSize(50);
    textSettingsButton.setFillColor(Color::White);

    textRect = textSettingsButton.getLocalBounds();
    textSettingsButton.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textSettingsButton.setPosition(640, 500);

    textSettingsTitle.setFont(fontTitle);
    textSettingsTitle.setString("Ayarlar");
    textSettingsTitle.setCharacterSize(70);
    textSettingsTitle.setFillColor(Color::White);

    textRect = textSettingsTitle.getLocalBounds();
    textSettingsTitle.setOrigin(textRect.left +
                                 textRect.width / 2.0f,
                                 textRect.top +
                                 textRect.height / 2.0f);
    textSettingsTitle.setPosition(640, 100);

    
    textThemesButton.setFont(fontTitle);
    textThemesButton.setString("Gelistiren");
    textThemesButton.setCharacterSize(50);
    textThemesButton.setFillColor(Color::White);

    textRect = textThemesButton.getLocalBounds();
    textThemesButton.setOrigin(textRect.left +
                           textRect.width / 2.0f,
                           textRect.top +
                           textRect.height / 2.0f);
    textThemesButton.setPosition(640, 600);

    textSand.setFont(fontTitle);
    textSand.setString("Syrins");
    textSand.setCharacterSize(55);
    textSand.setFillColor(Color::White);

    textRect = textSand.getLocalBounds();
    textSand.setOrigin(textRect.left +
                               textRect.width / 2.0f,
                               textRect.top +
                               textRect.height / 2.0f);
    textSand.setPosition(640, 300);

    textStone.setFont(fontTitle);
    textStone.setString("Tas");
    textStone.setCharacterSize(55);
    textStone.setFillColor(Color::White);

    textRect = textStone.getLocalBounds();
    textStone.setOrigin(textRect.left +
                               textRect.width / 2.0f,
                               textRect.top +
                               textRect.height / 2.0f);
    textStone.setPosition(640, 400);

    textThemesTitle.setFont(fontTitle);
    textThemesTitle.setString("Gelistiren");
    textThemesTitle.setCharacterSize(70);
    textThemesTitle.setFillColor(Color::White);

    textRect = textThemesTitle.getLocalBounds();
    textThemesTitle.setOrigin(textRect.left +
                               textRect.width / 2.0f,
                               textRect.top +
                               textRect.height / 2.0f);
    textThemesTitle.setPosition(640, 100);

    
    textOn.setFont(fontTitle);
    textOn.setString("Acik");
    textOn.setCharacterSize(50);
    textOn.setFillColor(Color::White);
    textRect = textOn.getLocalBounds();
    textOn.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textOn.setPosition(640, 300);

    
    textOff.setFont(fontTitle);
    textOff.setString("Kapali");
    textOff.setCharacterSize(50);
    textOff.setFillColor(Color::White);
    textRect = textOff.getLocalBounds();
    textOff.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textOff.setPosition(640, 500);

    
    textMusic.setFont(fontTitle);
    textMusic.setString("Muzik: ");
    textMusic.setCharacterSize(50);
    textMusic.setFillColor(Color::White);
    textRect = textMusic.getLocalBounds();
    textMusic.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textMusic.setPosition(620, 300);

    
    textSoundFx.setFont(fontTitle);
    textSoundFx.setString("Oyun Ses: ");
    textSoundFx.setCharacterSize(50);
    textSoundFx.setFillColor(Color::White);
    textRect = textSoundFx.getLocalBounds();
    textSoundFx.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textSoundFx.setPosition(620, 400);

    
    if (callCounter < 2)
    {
        loadText();
    }
    textIntro.setFont(fontTitle);
    textIntro.setCharacterSize(30);
    textIntro.setFillColor(Color::White);
    textIntro.setString(introText);

    textRect = textIntro.getLocalBounds();
    textIntro.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textIntro.setPosition(640, 200);

    
    texturePauseBackground.loadFromFile(m + "assets/graphics/pauseBackground.png");
    spritePauseBackground.setTexture(texturePauseBackground);
    spritePauseBackground.setPosition(0, 0);

    
    textPaused.setFont(fontTitle);
    textPaused.setCharacterSize(70);
    textPaused.setFillColor(Color::White);
    textPaused.setString("Durdur");

    textRect = textPaused.getLocalBounds();
    textPaused.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textPaused.setPosition(640, 100);

    
    textGameOver = textPaused;
    textGameOver.setString("Oyun Bitti");
    textRect = textGameOver.getLocalBounds();
    textGameOver.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textGameOver.setPosition(640, 100);

    
    textStart.setFont(fontTitle);
    textStart.setCharacterSize(50);
    textStart.setFillColor(Color::White);
    textStart.setString("Basla");

    textRect = textStart.getLocalBounds();
    textStart.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textStart.setPosition(640, 300);

    
    textMainMenu.setFont(fontTitle);
    textMainMenu.setCharacterSize(50);
    textMainMenu.setFillColor(Color::White);
    textMainMenu.setString("Ana Menu");

    textRect = textMainMenu.getLocalBounds();
    textMainMenu.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textMainMenu.setPosition(640, 600);

    
    textRetryLevel.setFont(fontTitle);
    textRetryLevel.setCharacterSize(50);
    textRetryLevel.setFillColor(Color::White);
    textRetryLevel.setString("Tekrar Oyna");

    textRect = textRetryLevel.getLocalBounds();
    textRetryLevel.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textRetryLevel.setPosition(640, 400);

    
    textContinue.setFont(fontTitle);
    textContinue.setCharacterSize(50);
    textContinue.setFillColor(Color::White);
    textContinue.setString("Devam");

    textRect = textContinue.getLocalBounds();
    textContinue.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textContinue.setPosition(640, 300);

    
    textContinueIntro.setFont(fontTitle);
    textContinueIntro.setCharacterSize(60);
    textContinueIntro.setFillColor(Color::White);
    textContinueIntro.setString("Devam");

    textRect = textContinueIntro.getLocalBounds();
    textContinueIntro.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textContinueIntro.setPosition(640, 430);

    
    textExit.setFont(fontTitle);
    textExit.setString("Cikis");
    textExit.setCharacterSize(50);
    textExit.setFillColor(Color::White);

    textRect = textExit.getLocalBounds();
    textExit.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textExit.setPosition(1200, 680);

    
    textGuest.setFont(fontTitle);
    textGuest.setString("Ziyaretci Oyna");
    textGuest.setCharacterSize(50);
    textGuest.setFillColor(Color::White);

    textRect = textGuest.getLocalBounds();
    textGuest.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textGuest.setPosition(640, 640);

    
    textContinueToGame.setFont(fontTitle);
    textContinueToGame.setString("Devam");
    textContinueToGame.setCharacterSize(50);
    textContinueToGame.setFillColor(Color::White);

    textRect = textContinueToGame.getLocalBounds();
    textContinueToGame.setOrigin(textRect.left +
                        textRect.width / 2.0f,
                        textRect.top +
                        textRect.height / 2.0f);
    textContinueToGame.setPosition(640, 540);

    
    textLeaderboards.setFont(fontTitle);
    textLeaderboards.setCharacterSize(50);
    textLeaderboards.setFillColor(Color::White);
    textLeaderboards.setString("Tablo");

    textRect = textLeaderboards.getLocalBounds();
    textLeaderboards.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textLeaderboards.setPosition(640, 500);

    textLeaderboard.setFont(fontTitle);
    textLeaderboard.setCharacterSize(70);
    textLeaderboard.setFillColor(Color::White);
    textLeaderboard.setString("Tablo");

    textRect = textLeaderboard.getLocalBounds();
    textLeaderboard.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textLeaderboard.setPosition(640, 100);

	
	textEnterYourName.setFont(fontTitle);
	textEnterYourName.setFillColor(Color::White);

	textEnterYourName.setCharacterSize(50);
	textEnterYourName.setString("1. oyuncu:");
	textRect = textEnterYourName.getLocalBounds();
	textEnterYourName.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);
	textEnterYourName.setPosition(640, 230);

	
	player1Text.setFont(fontTitle);

	player1Text.setFillColor(Color::White);
	textRect = player1Text.getLocalBounds();
	player1Text.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);

	player1Text.setPosition(640, 350);
	player1Text.setCharacterSize(40);

	
	player2Text.setFont(fontTitle);
	player2Text.setFillColor(Color::White);
	textRect = player2Text.getLocalBounds();
	player2Text.setPosition(640, 450);
	player2Text.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);

	player2Text.setCharacterSize(40);

	
	enterYourNameRectangle.setSize(Vector2f(400, 45));

	enterYourNameRectangle.setFillColor(color2);
	enterYourNameRectangle.setOutlineThickness(5);
	enterYourNameRectangle.setOutlineColor(Color::White);
	textRect = enterYourNameRectangle.getLocalBounds();
	enterYourNameRectangle.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);
	enterYourNameRectangle.setPosition(640, 350);

	enterYourNameRectangle2 = enterYourNameRectangle;
	enterYourNameRectangle2.setPosition(640, 450);

    
    enterYourNameRectangleFade.setSize(Vector2f(400, 45));

    enterYourNameRectangleFade.setFillColor(color2);
    enterYourNameRectangleFade.setOutlineThickness(5);
    enterYourNameRectangleFade.setOutlineColor(Color::White);
    textRect = enterYourNameRectangleFade.getLocalBounds();
    enterYourNameRectangleFade.setOrigin(textRect.left +
                                     textRect.width / 2.0f,
                                     textRect.top +
                                     textRect.height / 2.0f);
    enterYourNameRectangleFade.setPosition(640, 350);

    enterYourNameRectangleFade2 = enterYourNameRectangle;
    enterYourNameRectangleFade2.setPosition(640, 450);


	
	textureStoneMid.loadFromFile(m + "assets/graphics/stoneMid.png");
	textureSandMid.loadFromFile(m + "assets/graphics/sandMid.png");
	spriteStoneMid.setTexture(&textureStoneMid);

	textureStoneLeft.loadFromFile(m + "assets/graphics/stoneLeft.png");
    textureSandLeft.loadFromFile(m + "assets/graphics/sandLeft.png");
	spriteStoneLeft.setTexture(&textureStoneLeft);

	textureStoneRight.loadFromFile(m + "assets/graphics/stoneRight.png");
    textureSandRight.loadFromFile(m + "assets/graphics/sandRight.png");
	spriteStoneRight.setTexture(&textureStoneRight);

	
	smoke1Text.loadFromFile(m + "assets/graphics/smoke1.png");
	smoke2Text.loadFromFile(m + "assets/graphics/smoke2.png");
	smoke1.setTexture(smoke1Text);
	smoke2.setTexture(smoke2Text);

	
	fontTitle.loadFromFile(m + "assets/fonts/KOMIKAP_.ttf");

	textTitle.setFont(fontTitle);
	textTitle.setCharacterSize(70);
	textTitle.setFillColor(Color::White);
	textTitle.setString("Ates ve Su");
	textRect = textTitle.getLocalBounds();

	textTitle.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);
	textTitle.setPosition(640, 100);


	
	textureBackground.loadFromFile(m + "assets/graphics/backGroundBrick.png");
	textureBackgroundSand.loadFromFile(m + "assets/graphics/backgroundSand.png");
	textureMenuBackground.loadFromFile(m + "assets/graphics/newBackground.png");

	spriteBackground.setTexture(&textureBackground);

	
	textureTopBorder.loadFromFile(m + "assets/graphics/topBorder.png");
	textureSideBorder.loadFromFile(m + "assets/graphics/sideBorder.png");
	textureBottomBorder.loadFromFile(m + "assets/graphics/bottomBorder.png");

    textureTopBorderSand.loadFromFile(m + "assets/graphics/topBorderSand.png");
    textureSideBorderSand.loadFromFile(m + "assets/graphics/sideBorderSand.png");
    textureBottomBorderSand.loadFromFile(m + "assets/graphics/bottomBorderSand.png");

	borders[2].setSize(vec2), borders[3].setSize(vec2);
	borders[0].setSize(vec1), borders[1].setSize(vec1);

	borders[2].setPosition(0, 0), borders[3].setPosition(1240, 0);
	borders[0].setPosition(0, 0), borders[1].setPosition(0, 680);

	borders[2].setTexture(&textureSideBorder), borders[3].setTexture(&textureSideBorder);
	borders[0].setTexture(&textureTopBorder), borders[1].setTexture(&textureBottomBorder);

	
	ground.setFillColor(color);
	ground.setPosition({ 0, 680 });

	
	fireBoyTexture.loadFromFile(m + "assets/graphics/fireBoy.png");
	fireBoyTextureLeft.loadFromFile(m + "assets/graphics/fireBoyLeft.png");
	fireBoyTextureRight.loadFromFile(m + "assets/graphics/fireBoyRight.png");
	waterGirlTexture.loadFromFile(m + "assets/graphics/waterGirl.png");
	waterGirlTextureLeft.loadFromFile(m + "assets/graphics/waterGirlLeft.png");
	waterGirlTextureRight.loadFromFile(m + "assets/graphics/waterGirlRight.png");
    
	
	waterLeftText.loadFromFile(m + "assets/graphics/waterLeft.png");
	waterMidText.loadFromFile(m + "assets/graphics/waterMid.png");
	waterRightText.loadFromFile(m + "assets/graphics/waterRight.png");
	lavaLeftText.loadFromFile(m + "assets/graphics/lavaLeft.png");
	lavaMidText.loadFromFile(m + "assets/graphics/lavaMid.png");
	lavaRightText.loadFromFile(m + "assets/graphics/lavaRight.png");
	acidLeftText.loadFromFile(m + "assets/graphics/acidLeft.png");
	acidMidText.loadFromFile(m + "assets/graphics/acidMid.png");
	acidRightText.loadFromFile(m + "assets/graphics/acidRight.png");
	smallWaterText.loadFromFile(m + "assets/graphics/smallWater.png");
	smallAcidText.loadFromFile(m + "assets/graphics/smallAcid.png");
	smallLavaText.loadFromFile(m + "assets/graphics/smallLava.png");

    waterLeftSandText.loadFromFile(m + "assets/graphics/waterLeftSand.png");
    waterMidSandText.loadFromFile(m + "assets/graphics/waterMidSand.png");
    waterRightSandText.loadFromFile(m + "assets/graphics/waterRightSand.png");
    lavaLeftSandText.loadFromFile(m + "assets/graphics/lavaLeftSand.png");
    lavaMidSandText.loadFromFile(m + "assets/graphics/lavaMidSand.png");
    lavaRightSandText.loadFromFile(m + "assets/graphics/lavaRightSand.png");
    acidLeftSandText.loadFromFile(m + "assets/graphics/acidLeftSand.png");
    acidMidSandText.loadFromFile(m + "assets/graphics/acidMidSand.png");
    acidRightSandText.loadFromFile(m + "assets/graphics/acidRightSand.png");
    smallWaterSandText.loadFromFile(m + "assets/graphics/smallWaterSand.png");
    smallAcidSandText.loadFromFile(m + "assets/graphics/smallAcidSand.png");
    smallLavaSandText.loadFromFile(m + "assets/graphics/smallLavaSand.png");

	
	textureButtonOff.loadFromFile(m + "assets/graphics/btnoff.png");
	textureButtonOn.loadFromFile(m + "assets/graphics/btnon.png");

    textureButtonOffSand.loadFromFile(m + "assets/graphics/btnoffSand.png");
    textureButtonOnSand.loadFromFile(m + "assets/graphics/btnonSand.png");

	buttonOn.setTexture(&textureButtonOn);
	buttonOff.setTexture(&textureButtonOff);

    
    textureBox.loadFromFile(m + "assets/graphics/box.png");
    spriteBox.setTexture(textureBox);

    
    enemyText.loadFromFile(m + "assets/graphics/enemy.png");
    enemyRightText.loadFromFile(m + "assets/graphics/enemyRight.png");
    enemyLeftText.loadFromFile(m + "assets/graphics/enemyLeft.png");
    
    
    sandFillingText.loadFromFile(m + "assets/graphics/sandFilling.png");
    stoneFillingText.loadFromFile(m + "assets/graphics/stoneFilling.png");
}
