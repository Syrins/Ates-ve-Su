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
#include "Players.h"
#include "LevelGeneration.h"
using namespace std;
using namespace sf;
using namespace sftools;


vector< pair< pair<int,int>,pair<int,int> > > initialPosition =
{   
    {{41.f,599.f},{41.f,599.f}},
    
    {{41.f,599.f},{41.f,599.f}},
    
    {{41.f,599.f},{41.f,599.f}},
    
    {{41.f,599.f},{41.f,599.f}},
    
    {{120.f,500.f},{41.f,599.f}},
    
    {{41.f,599.f},{41.f,359.f}},
    
    {{41.f,80.f},{1140.f,599.f}},
    
   {{200.f,599.f},{200.f,599.f}},
    
    {{41.f,80.f},{1140.f,599.f}},
    
    {{1000.f,41.f},{600.f,41.f}},
};



bool hoverExit = false;
bool hoverSand = false;
bool hoverStart = false;
bool hoverStone = false;
bool hoverGuest = false;
bool hoverArrow = false;
bool hoverRetry = false;
bool hoverTheme = false;
bool hoverLevel1 = false;
bool hoverLevel2 = false;
bool hoverContinue = false;
bool hoverSettings = false;
bool hoverMainMenu = false;
bool hoverMusicMute = false;
bool hoverTextLevels[10] = {};
bool hoverSoundFxMute = false;
bool hoverArrowThemes = false;
bool hoverLeaderboards = false;
bool hoverContinueIntro = false;
bool hoverArrowMainMenu = false;
bool hoverContinueToGame = false;
bool hoverPlayer1InputBox = false;
bool hoverPlayer2InputBox = false;
bool hoverArrowLevelInquire = false;
bool hoverArrowLeaderboards = false;
bool hoverArrowLevelLeaderboard = false;


bool guest = false;
bool paused = false;
bool started = false;
bool mainMenu = false;
bool themeMenu = false;
bool gameStarted = false;
bool levelInquire = false;
bool leaderboards = false;
bool settingsMenu = false;
bool levelLeaderboardPage[10] = {};


bool musicMute = false;
bool soundFxMute = false;
bool pressedMusicMute = false;
bool gateButtonSoundPlayed[13];
bool pressedSoundFxMute = false;
bool bridgeButtonSoundPlayed[13];


bool bothPlayers = false;
bool player1Input = false;
bool player2Input = false;


bool continueFillColorInc = false;
bool enterYourNameFillColorInc = false;
bool player1InputBoxFillColorInc = false;
bool player2InputBoxFillColorInc = false;


bool canType = true;
bool canClick = true;


bool pushedFireBoy = false;
bool pushedWaterGirl = false;


bool gateOpened[13];
bool buttonGatePressed[13];


bool gemsTaken[11];


bool bridgeOpened[13];
bool buttonBridgePressed[13];


bool boxGroundCheck[13];
bool boxWatergirlPushed[13], boxFireboyPushed[13];


bool FBDead = 0;
bool WGDead = 0;
bool oneDead = 0;


float mouse_xAxis, mouse_yAxis;


float safe = 5.f;


bool enemyMoveRight[10] = {};


RenderWindow window(VideoMode(1280, 720), "Ates Ve Su", Style::Titlebar | Style::Close);

void initWindow()
{
    window.setFramerateLimit(60);
}


Event event;

void checkTheme()
{
    if(sand)
    {
        
        spriteStoneLeft.setTexture(&textureSandLeft);
        spriteStoneRight.setTexture(&textureSandRight);
        spriteStoneMid.setTexture(&textureSandMid);

        
        spriteBackground.setTexture(&textureBackgroundSand);

        
        borders[2].setTexture(&textureSideBorderSand), borders[3].setTexture(&textureSideBorderSand);
        borders[0].setTexture(&textureTopBorderSand), borders[1].setTexture(&textureBottomBorderSand);

        
        buttonOn.setTexture(&textureButtonOnSand);
        buttonOff.setTexture(&textureButtonOffSand);

        
        spriteLavaLeft.setTexture(lavaLeftSandText);
        spriteLavaMid.setTexture(lavaMidSandText);
        spriteLavaRight.setTexture(lavaRightSandText);
        spriteSmallLava.setTexture(smallLavaSandText);

        spriteWaterLeft.setTexture(waterLeftSandText);
        spriteWaterMid.setTexture(waterMidSandText);
        spriteWaterRight.setTexture(waterRightSandText);
        spriteSmallWater.setTexture(smallWaterSandText);

        spriteAcidLeft.setTexture(acidLeftSandText);
        spriteAcidMid.setTexture(acidMidSandText);
        spriteAcidRight.setTexture(acidRightSandText);
        spriteSmallAcid.setTexture(smallAcidSandText);

    }
    else if(stone)
    {
        
        spriteStoneLeft.setTexture(&textureStoneLeft);
        spriteStoneRight.setTexture(&textureStoneRight);
        spriteStoneMid.setTexture(&textureStoneMid);

        
        spriteBackground.setTexture(&textureBackground);

        
        borders[2].setTexture(&textureSideBorder), borders[3].setTexture(&textureSideBorder);
        borders[0].setTexture(&textureTopBorder), borders[1].setTexture(&textureBottomBorder);

        
        buttonOn.setTexture(&textureButtonOn);
        buttonOff.setTexture(&textureButtonOff);

        
        spriteLavaLeft.setTexture(lavaLeftText);
        spriteLavaMid.setTexture(lavaMidText);
        spriteLavaRight.setTexture(lavaRightText);
        spriteSmallLava.setTexture(smallLavaText);

        spriteWaterLeft.setTexture(waterLeftText);
        spriteWaterMid.setTexture(waterMidText);
        spriteWaterRight.setTexture(waterRightText);
        spriteSmallWater.setTexture(smallWaterText);

        spriteAcidLeft.setTexture(acidLeftText);
        spriteAcidMid.setTexture(acidMidText);
        spriteAcidRight.setTexture(acidRightText);
        spriteSmallAcid.setTexture(smallAcidText);
    }
}

void gamePolling()
{
    while (window.pollEvent(event))
    {
        
        if (event.type == Event::Closed) {
            window.close();
        }

        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape && gameStarted) {
            
            if (paused && !FBDead && !WGDead && !settingsMenu)
                paused = false, chron.resume();
            
            else if (!FBDead && !WGDead)
                paused = true, chron.pause();
        }

        
        if (player1Input && !bothPlayers)
        {
            
            if (event.type == sf::Event::TextEntered && event.text.unicode == 8 && !player1Name.empty() && canType)
            {
                
                player1Name.pop_back();

                
                player1Text.setString(player1Name);

                
                window.draw(player1Text);
            }
                
            else if (player1Name.size() >= 10) {}
                
            else if (event.type == sf::Event::TextEntered && event.text.unicode <= 128 && event.text.unicode != 8 && !Keyboard::isKeyPressed(Keyboard::Key::Return) && canType)
            {
                
                player1Name += tolower(event.text.unicode);

                
                player1Text.setString(player1Name);
            }
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Return && !player1Name.empty())
            {
                
                player1Input = 0;
                player2Input = 1;
            }
        }

        
        if (player2Input && !bothPlayers)
        {
            
            if (event.type == sf::Event::TextEntered && event.text.unicode == 8 && !player2Name.empty() && canType)
            {
                
                player2Name.pop_back();

                
                player2Text.setString(player2Name);

                
                window.draw(player2Text);
            }
                
            else if (player2Name.size() >= 10) {}
                
            else if (event.type == sf::Event::TextEntered && event.text.unicode <= 128 && event.text.unicode != 8 && !Keyboard::isKeyPressed(Keyboard::Key::Return) && canType)
            {
                
                player2Name += tolower(event.text.unicode);

                
                player2Text.setString(player2Name);
            }
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Return && !player2Name.empty() && !player1Name.empty())
            {
                
                player1Input = 0;
                player2Input = 0;
                bothPlayers = 1;
            }
        }
    }
}

void leaderboardAndTextFlickering()
{
    
    for (int i = 0; i < 10; i++)
    {
        if (levelLeaderboardPage[i])
        {
            currentLevelLeaderboardPage = i + 1;
            leaderboards = false;
            break;
        }
    }

    
    if (!continueFillColor) continueFillColorInc = true;
    else if (continueFillColor == 255) continueFillColorInc = false;

    
    if (!enterYourNameFillColor) enterYourNameFillColorInc = true;
    else if (enterYourNameFillColor == 255) enterYourNameFillColorInc = false;

    
    if (!player1InputBoxFillColor) player1InputBoxFillColorInc = true;
    else if (player1InputBoxFillColor == 255) player1InputBoxFillColorInc = false;

    
    if (!player2InputBoxFillColor) player2InputBoxFillColorInc = true;
    else if (player2InputBoxFillColor == 255) player2InputBoxFillColorInc = false;
}

void checkMusic()
{
    
    if (soundLevelComplete.getStatus() != Music::Status::Playing && musicIntro.getStatus() != Music::Status::Playing && !gameStarted && !musicMute)
        musicIntro.play();
}

Time gameTime;
int secondst, minutes;

void gameTimer()
{
    
    gameTime = chron.getElapsedTime();
    secondst = gameTime.asSeconds(); minutes = secondst / 60;
    secondst %= 60;

    
    if (minutes <= 9)
        ss << 0;
    ss << minutes << ":";
    if (secondst <= 9)
        ss << 0;
    ss << secondst;
    ss >> stringTimer;
    ss.clear();
    textTimer.setString(stringTimer);
}

void getEndingTime()
{
    if (!guest)
    {
        updateData(player1Name, player2Name, level, (secondst + minutes * 60));
        initializeCurrentRecords();
    }
    else
    {
        guestRecords[level] = secondst + minutes * 60;
    }
}

void initButtonSound()
{
    memset(bridgeButtonSoundPlayed, false, 13);
    memset(gateButtonSoundPlayed, false, 13);
}

void restartGems()
{
    memset(gemsTaken, false, sizeof gemsTaken);
}

void getMouseCoordinates()
{
    mouse_xAxis = Mouse::getPosition(window).x, mouse_yAxis = Mouse::getPosition(window).y;
}

void fillBool()
{
    mainMenu = !gameStarted && !paused && !settingsMenu && started && bothPlayers && !levelInquire && !leaderboards && !currentLevelLeaderboardPage && !themeMenu;
    oneDead = FBDead || WGDead;
}

void checkCurrentLevelOnScreen(Player& fireBoy, Player& waterGirl)
{
    if (level != curPlatformObjectLevel)
    {
        
        fireBoy.Restart(initialPosition[level].first.first,initialPosition[level].first.second);
        waterGirl.Restart(initialPosition[level].second.first,initialPosition[level].second.second);

        
        platformObjects.clear();
        gatesObjects.clear();
        gemObjects.clear();
        boxes.clear();
        boxesPositions.clear();
        enemies.clear();
        pools.clear();
        fillings.clear();
        
        platformObjects.push_back({{ground,0},0});
        checkTheme();
        fillPlatformObjects();
        fillGateObjects();
        fillGemObjects();

        boxesRestart();

        
        memset(gateOpened, 0, sizeof(gateOpened));
        memset(buttonGatePressed, 0, sizeof(bridgeOpened));
        memset(buttonGatePressed, 0, sizeof(buttonGatePressed));
        memset(buttonBridgePressed, 0, sizeof(buttonBridgePressed));
        memset(gemsTaken, 0, sizeof(gemsTaken));
        memset(bridgeOpened, 0, sizeof(bridgeOpened));
        memset(boxGroundCheck, 0, sizeof(boxGroundCheck));
        memset(boxWatergirlPushed, 0, sizeof(boxWatergirlPushed));
        memset(boxFireboyPushed, 0, sizeof(boxFireboyPushed));
        memset(bridgeButtonSoundPlayed, 0, sizeof(bridgeButtonSoundPlayed));
        memset(enemyMoveRight, 0, sizeof(enemyMoveRight));

        
        buttonCnt = 10;
        gateCnt = 0;
        bridgeCnt = 0;
        buttonGateCnt = 0;
        buttonBridgeCnt = 0;
        gemCnt = 0;

        
        curPlatformObjectLevel = level;

        deathX = deathY = -100.f;
    }
}


void initFireBoyIdle(Player& fireBoy)
{
    fireBoy.playerSprite.setTexture(fireBoyTexture);
}


void initWaterGirlIdle(Player& waterGirl)
{
    waterGirl.playerSprite.setTexture(waterGirlTexture);
}


void fall(Player& player, float gravity)
{
    player.move({0, gravity});
}


void boxesFall(float gravity)
{
    for(int i = 0;i < boxes.size();++i)
    {
        boxes[i].move({0,gravity});
        for(auto j : platformObjects)
        {
            if (j.first.first.getPosition().y - boxes[i].getPosition().y <= 59 && j.first.first.getPosition().y - boxes[i].getPosition().y >= 0 )
            {
                if(boxes[i].getGlobalBounds().intersects(j.first.first.getGlobalBounds()))
                {
                    boxes[i].move({0, -gravity});
                }
            }
        }
        for(auto j : gatesObjects)
        {
            if (j.first.first.getPosition().y - boxes[i].getPosition().y <= 59 && j.first.first.getPosition().y - boxes[i].getPosition().y >= 0 && (j.first.second == 3 || j.first.second == 4) && bridgeOpened[j.second])
            {
                if(boxes[i].getGlobalBounds().intersects(j.first.first.getGlobalBounds()))
                {
                    boxes[i].move({0, -gravity});
                }
            }
        }
    }
   
}
    

void jumpMechanics(Player& player, float gravity)
{
    if (player.jumpCnt <= jumpFactor)
    {
        player.move({ 0, ((player.jumpCnt - (jumpFactor / 2)) / 2) });
        player.move({ 0, -gravity });
    }
}


void fireBoyJumping(Player& fireBoy, float iterationsPerSecond)
{
    if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !paused && gameStarted)
    {
        
        if (!pushedFireBoy && fireBoy.jumpCnt > jumpFactor && fireBoy.ready >= iterationsPerSecond / 2 && fireBoy.groundCheck)
        {
            fireBoy.jumpCnt = 0;
            fireBoy.ready = 0;
            fireBoy.groundCheck = 0;
            if (!soundFxMute)
                soundFireboyJump.play();
        }
    }
}


void waterGirlJumping(Player& waterGirl, float iterationsPerSecond)
{
    if (Keyboard::isKeyPressed(Keyboard::Key::W) && !paused && gameStarted)
    {
        
        if (!pushedWaterGirl && waterGirl.jumpCnt > jumpFactor && waterGirl.ready >= iterationsPerSecond / 2 && waterGirl.groundCheck)
        {
            waterGirl.jumpCnt = 0;
            waterGirl.ready = 0;
            waterGirl.groundCheck = 0;
            if (!soundFxMute)
                soundWatergirlJump.play();
        }
    }
}


void fireBoyMovingLeft(Player& fireBoy, float pixelsPerIteration)
{
    if (Keyboard::isKeyPressed(Keyboard::Key::Left) && !paused && gameStarted)
    {
        
        fireBoy.playerSprite.setTexture(fireBoyTextureLeft);

        if (!pushedFireBoy && fireBoy.jumpCnt >= jumpFactor) fireBoy.move({-pixelsPerIteration , 0});
        else if (!pushedFireBoy) fireBoy.move({-1.825 * pixelsPerIteration , 0});
    }
}


void fireBoyMovingRight(Player& fireBoy, float pixelsPerIteration)
{
    if (Keyboard::isKeyPressed(Keyboard::Key::Right) && !paused && gameStarted)
    {
        
        fireBoy.playerSprite.setTexture(fireBoyTextureRight);

        if (!pushedFireBoy && fireBoy.jumpCnt >= jumpFactor) fireBoy.move({pixelsPerIteration , 0});
        else if (!pushedFireBoy)fireBoy.move({1.825 * pixelsPerIteration , 0});
    }
}


void waterGirlMovingLeft(Player& waterGirl, float pixelsPerIteration)
{
    if (Keyboard::isKeyPressed(Keyboard::Key::A) && !paused && gameStarted)
    {
        
        waterGirl.playerSprite.setTexture(waterGirlTextureLeft);

        if (!pushedWaterGirl && waterGirl.jumpCnt >= jumpFactor) waterGirl.move({-pixelsPerIteration , 0});
        else if (!pushedWaterGirl) waterGirl.move({-1.825 * pixelsPerIteration , 0});
    }
}


void waterGirlMovingRight(Player& waterGirl, float pixelsPerIteration)
{
    if (Keyboard::isKeyPressed(Keyboard::Key::D) && !paused && gameStarted)
    {
        
        waterGirl.playerSprite.setTexture(waterGirlTextureRight);

        if (!pushedWaterGirl && waterGirl.jumpCnt >= jumpFactor) waterGirl.move({pixelsPerIteration , 0});
        else if (!pushedWaterGirl) waterGirl.move({1.825 * pixelsPerIteration , 0});
    }
}


void incrementJumpCnts(Player& fireBoy, Player& waterGirl)
{
    if (fireBoy.jumpCnt < 100)
    {
        fireBoy.jumpCnt++;
    }
    if (waterGirl.jumpCnt < 100)
    {
        waterGirl.jumpCnt++;
    }
}


void waterGirlPlatformCollision(Player& waterGirl, pair<pair<RectangleShape, int>, int> i, float gravity)
{
    if (waterGirl.bounds.intersects(i.first.first.getGlobalBounds()) || (int)i.first.first.getPosition().y / 80 == 8 && levelsMap[level][8][(int)i.first.first.getPosition().x / 80] == 'u' && waterGirl.dy + 80 + 10 > i.first.first.getPosition().y)
    {
        waterGirl.jumpCnt = jumpFactor + 1;
        if (waterGirl.dy < i.first.first.getPosition().y)
        {
            pushedWaterGirl = false;
            waterGirl.move({0, -gravity});
            waterGirl.groundCheck = 1;

            
            if ((i.first.second == 1 || i.first.second == 3) && !waterGirl.isDead)
            {
                waterGirl.die();
                if (!soundFxMute) soundPlayerDeath.play();
                deathX = i.first.first.getPosition().x; deathY = i.first.first.getPosition().y - 40;
                if (i.first.second == 1)
                {
                    smoke1.setPosition({deathX, deathY});
                    smoke2.setPosition({deathX, deathY});
                }
            }

            
            if (i.first.second == 4)
            {
                buttonGatePressed[i.second] = true;
            }

            
            if (i.first.second == 5)
            {
                buttonBridgePressed[i.second] = true;
            }
        }
    }
}


void fireBoyPlatformCollision(Player& fireBoy, pair<pair<RectangleShape, int>, int> i, float gravity)
{
    if (fireBoy.bounds.intersects(i.first.first.getGlobalBounds()) || (int)i.first.first.getPosition().y / 80 == 8 && levelsMap[level][8][(int)i.first.first.getPosition().x / 80] == 'u' && fireBoy.dy + 80 + 10 > i.first.first.getPosition().y)
    {
        fireBoy.jumpCnt = jumpFactor + 1;
        if (fireBoy.dy < i.first.first.getPosition().y)
        {
            pushedFireBoy = false;
            fireBoy.move({0, -gravity});
            fireBoy.groundCheck = 1;

            
            if ((i.first.second == 2 || i.first.second == 3) && !fireBoy.isDead)
            {
                fireBoy.die();
                if (!soundFxMute)soundPlayerDeath.play();
                deathX = i.first.first.getPosition().x; deathY = i.first.first.getPosition().y - 40;
                if (i.first.second == 2)
                {
                    smoke1.setPosition({deathX, deathY});
                    smoke2.setPosition({deathX, deathY});
                }
            }
            
            if (i.first.second == 4)
            {
                buttonGatePressed[i.second] = true;
            }

            
            if (i.first.second == 5)
            {
                buttonBridgePressed[i.second] = true;
            }

        }
    }
}


void waterGirlPushedRight(Player& waterGirl, pair<pair<RectangleShape, int>, int> i, float pixelsPerIteration)
{
    if (waterGirl.bounds.intersects(i.first.first.getGlobalBounds()) && waterGirl.dy + 80 - safe >= i.first.first.getPosition().y && waterGirl.dx + 80 - safe >= i.first.first.getPosition().x)
    {
        pushedWaterGirl = true;
        waterGirl.move({pixelsPerIteration, 0});
    }
}


void waterGirlPushedLeft(Player& waterGirl, pair<pair<RectangleShape, int>, int> i, float pixelsPerIteration)
{
    if (waterGirl.bounds.intersects(i.first.first.getGlobalBounds()) && waterGirl.dy + 80 - safe >= i.first.first.getPosition().y && waterGirl.dx + safe <= i.first.first.getPosition().x + i.first.first.getGlobalBounds().width)
    {
        pushedWaterGirl = true;
        waterGirl.move({-pixelsPerIteration, 0});
    }

}


void fireBoyPushedRight(Player& fireBoy, pair<pair<RectangleShape, int>, int> i, float pixelsPerIteration)
{
    if (fireBoy.bounds.intersects(i.first.first.getGlobalBounds()) && fireBoy.dy + 80 - safe >= i.first.first.getPosition().y && fireBoy.dx + 80 - safe >= i.first.first.getPosition().x)
    {
        pushedFireBoy = true;
        fireBoy.move({pixelsPerIteration, 0});
    }

}


void fireBoyPushedLeft(Player& fireBoy, pair<pair<RectangleShape, int>, int> i, float pixelsPerIteration)
{
    if (fireBoy.bounds.intersects(i.first.first.getGlobalBounds()) && fireBoy.dy + 80 - safe >= i.first.first.getPosition().y && fireBoy.dx + safe <= i.first.first.getPosition().x + i.first.first.getGlobalBounds().width)
    {
        pushedFireBoy = true;
        fireBoy.move({-pixelsPerIteration, 0});
    }
}


void waterGirlBridgeCollision(Player& waterGirl, pair<pair<RectangleShape, int>, int> i, float gravity)
{
    if ((i.first.second == 3 || i.first.second == 4) && waterGirl.bounds.intersects(i.first.first.getGlobalBounds()))
    {
        if (abs(waterGirl.dy - i.first.first.getPosition().y) < 70 && bridgeOpened[i.second])
        {
            waterGirl.jumpCnt = jumpFactor + 1;
        }
        if (waterGirl.dy < i.first.first.getPosition().y && bridgeOpened[i.second])
        {
            pushedWaterGirl = false;
            waterGirl.move({0, -gravity});
            waterGirl.groundCheck = 1;
        }
    }
}


void fireBoyBridgeCollision(Player& fireBoy, pair<pair<RectangleShape, int>, int> i, float gravity)
{
    if ((i.first.second == 3 || i.first.second == 4) && fireBoy.bounds.intersects(i.first.first.getGlobalBounds()))
    {
        if (abs(fireBoy.dy - i.first.first.getPosition().y) < 70 && bridgeOpened[i.second])
        {
            fireBoy.jumpCnt = jumpFactor + 1;
        }
        if (fireBoy.dy < i.first.first.getPosition().y && bridgeOpened[i.second])
        {
            pushedFireBoy = false;
            fireBoy.move({0, -gravity});
            fireBoy.groundCheck = 1;
        }
    }
}


void waterGirlPushedRightBridge(Player& waterGirl, pair<pair<RectangleShape, int>, int> i, float pixelsPerIteration)
{
    if (waterGirl.bounds.intersects(i.first.first.getGlobalBounds()) && waterGirl.dy + 80 - safe >= i.first.first.getPosition().y && waterGirl.dx + 20 - safe >= i.first.first.getPosition().x && !gateOpened[i.second] && i.first.second != 3 && i.first.second != 4)
    {
        pushedWaterGirl = true;
        waterGirl.move({pixelsPerIteration, 0});
    }
}


void waterGirlPushedLeftBridge(Player& waterGirl, pair<pair<RectangleShape, int>, int> i, float pixelsPerIteration)
{
    if (waterGirl.bounds.intersects(i.first.first.getGlobalBounds()) && waterGirl.dy + 80 - safe >= i.first.first.getPosition().y && waterGirl.dx + safe <= i.first.first.getPosition().x + i.first.first.getGlobalBounds().width && !gateOpened[i.second] && i.first.second != 3 && i.first.second != 4)
    {
        pushedWaterGirl = true;
        waterGirl.move({-pixelsPerIteration, 0});
    }
}


void fireBoyPushedRightBridge(Player& fireBoy, pair<pair<RectangleShape, int>, int> i, float pixelsPerIteration)
{
    if (fireBoy.bounds.intersects(i.first.first.getGlobalBounds()) && fireBoy.dy + 80 - safe >= i.first.first.getPosition().y && fireBoy.dx + 20 - safe >= i.first.first.getPosition().x && !gateOpened[i.second] && i.first.second != 3 && i.first.second != 4)
    {
        pushedFireBoy = true;
        fireBoy.move({pixelsPerIteration, 0});
    }
}


void fireBoyPushedLeftBridge(Player& fireBoy, pair<pair<RectangleShape, int>, int> i, float pixelsPerIteration)
{
    if (fireBoy.bounds.intersects(i.first.first.getGlobalBounds()) && fireBoy.dy + 80 - safe >= i.first.first.getPosition().y && fireBoy.dx + safe <= i.first.first.getPosition().x + i.first.first.getGlobalBounds().width && !gateOpened[i.second] && i.first.second != 3 && i.first.second != 4)
    {
        pushedFireBoy = true;
        fireBoy.move({-pixelsPerIteration, 0});
    }
}


void gemCollision(Player& player, pair<pair<RectangleShape, int>, int> i)
{
    if (player.bounds.intersects(i.first.first.getGlobalBounds()))
    {
        if (!gemsTaken[i.second] && !soundFxMute)
        {
            Time fadeTime;
            fadeTime = seconds(-2);
            chron.add(fadeTime);
            soundGem.play();
        }
        gemsTaken[i.second] = true;
    }
}


void restartEnemies() {
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i].first.setPosition({ enemies[i].second.first,enemies[i].second.second });
        enemies[i].first.setTexture(&enemyRightText);
    }
}


void enemyMotionAndCollision(Player& fireBoy, Player& waterGirl)
{
    
    for (int i = 0; i < enemies.size(); i++) {
        float startPos = enemies[i].second.first;
        float endPos = startPos + 320;
        if(!gameStarted || paused)
            continue;
        if (fireBoy.dx >= enemies[i].second.first && fireBoy.dx <= enemies[i].second.first + 320 && fireBoy.dy < enemies[i].second.second && fireBoy.dy+170 > enemies[i].second.second) {
            if (fireBoy.dx < enemies[i].first.getPosition().x) {
                enemies[i].first.setTexture(&enemyLeftText);
                enemies[i].first.move({ -0.8,0 });
            }
            else {
                enemies[i].first.setTexture(&enemyRightText);
                enemies[i].first.move({ 0.8,0 });
            }
        }
            
        else if (waterGirl.dx >= enemies[i].second.first && waterGirl.dx <= enemies[i].second.first + 320 && waterGirl.dy < enemies[i].second.second && waterGirl.dy + 170 > enemies[i].second.second) {
            if (waterGirl.dx < enemies[i].first.getPosition().x) {
                enemies[i].first.setTexture(&enemyLeftText);
                enemies[i].first.move({ -0.8,0 });
            }
            else {
                enemies[i].first.setTexture(&enemyRightText);
                enemies[i].first.move({ 0.8,0 });
            }
        }
        else {
            if (!enemyMoveRight[i] && !paused) {
                enemies[i].first.setTexture(&enemyLeftText);
                enemies[i].first.move({ -0.8,0 });
            }
            else if (enemyMoveRight[i] && !paused) {
                enemies[i].first.setTexture(&enemyRightText);
                enemies[i].first.move({ 0.8,0 });
            }
        }
        if (enemies[i].first.getPosition().x <= startPos) {
            enemyMoveRight[i] = 1;
        }
        if (enemies[i].first.getPosition().x >= endPos) {
            enemyMoveRight[i] = 0;
        }
        if (fireBoy.bounds.intersects(enemies[i].first.getGlobalBounds())) {
            fireBoy.die();
            if (!soundFxMute)
                soundPlayerDeath.play();
        }

        if (waterGirl.bounds.intersects(enemies[i].first.getGlobalBounds())) {
            waterGirl.die();
            if (!soundFxMute)
                soundPlayerDeath.play();
        }
    }
}


void boxesMotionAndCollision(Player& fireBoy, Player& waterGirl, float pixelsPerIteration, float gravity)
{
    bool gateBoxCollision[13] = { false };
    bool BridgeBoxCollision[13] = { false };
    bool platformBoxCollision[13] = {};
    for (int i = 0; i < boxes.size(); ++i)
    {

        
        for(auto j:gatesObjects)
        {
            if(boxes[i].getGlobalBounds().intersects(j.first.first.getGlobalBounds()) && !gateOpened[j.second] && j.first.second <= 2)
            {
                gateBoxCollision[i] = true;
            }
        }
        
        for(auto j:platformObjects)
        {
            if(boxes[i].getGlobalBounds().intersects(j.first.first.getGlobalBounds()) && j.first.second == 0)
            {
                platformBoxCollision[i] = true;
            }
            if(boxes[i].getPosition().x <= 41.f || boxes[i].getPosition().x >= 1180.f)
            {
                platformBoxCollision[i] = true;
            }
        }
        
        fireBoy.Inquire();
        waterGirl.Inquire();
        if ((waterGirl.bounds.intersects(boxes[i].getGlobalBounds()) && waterGirl.dy + 60 - safe >= boxes[i].getPosition().y && waterGirl.dx + 75 <= boxes[i].getPosition().x))
        {

            pushedWaterGirl = true;
            boxWatergirlPushed[i] = true;
            if(!boxFireboyPushed[i] && !gateBoxCollision[i] && !platformBoxCollision[i])
            {
                waterGirl.move({- pixelsPerIteration/20, 0 });
                boxes[i].move({ pixelsPerIteration, 0 });
            }
            else
            {
                waterGirl.move({- pixelsPerIteration, 0 });
            }
        }
        else if ((waterGirl.bounds.intersects(boxes[i].getGlobalBounds()) && waterGirl.dy + 60 - safe >= boxes[i].getPosition().y && waterGirl.dx + safe >= boxes[i].getPosition().x + boxes[i].getGlobalBounds().width))
        {
            pushedWaterGirl = true;
            boxWatergirlPushed[i] = true;
            if(!boxFireboyPushed[i] && !gateBoxCollision[i] && !platformBoxCollision[i])
            {
                waterGirl.move({ pixelsPerIteration/20, 0 });
                boxes[i].move({ -pixelsPerIteration, 0 });
            }
            else
            {
                waterGirl.move({pixelsPerIteration, 0 });
            }
        }
        else
        {
            boxWatergirlPushed[i] = false;
        }
        if ((fireBoy.bounds.intersects(boxes[i].getGlobalBounds()) && fireBoy.dy + 60 - safe >= boxes[i].getPosition().y && fireBoy.dx + 75 <= boxes[i].getPosition().x) )
        {
            pushedFireBoy = true;
            boxFireboyPushed[i] = true;
            if(!boxWatergirlPushed[i] && !gateBoxCollision[i] && !platformBoxCollision[i])
            {
                fireBoy.move({-pixelsPerIteration/20, 0 });
                boxes[i].move({pixelsPerIteration, 0 });
            }
            else{
                fireBoy.move({-pixelsPerIteration, 0 });
            }
        }
        else if ((fireBoy.bounds.intersects(boxes[i].getGlobalBounds()) && fireBoy.dy + 60 - safe >= boxes[i].getPosition().y && fireBoy.dx + safe >= boxes[i].getPosition().x + boxes[i].getGlobalBounds().width))
        {
            pushedFireBoy = true;
            boxFireboyPushed[i] = true;
            if(!boxWatergirlPushed[i] && !gateBoxCollision[i] && !platformBoxCollision[i])
            {
                fireBoy.move({ pixelsPerIteration/20, 0 });
                boxes[i].move({ -pixelsPerIteration, 0 });
            }
            else
            {
                fireBoy.move({ pixelsPerIteration, 0 });
            }
        }
        else
        {
            boxFireboyPushed[i] = false;
        }
        

        if ( waterGirl.bounds.intersects(boxes[i].getGlobalBounds()))
        {
            if (waterGirl.dy < boxes[i].getPosition().y )
            {
                pushedWaterGirl = false;
                waterGirl.move({ 0, -gravity });
                waterGirl.groundCheck = 1;
            }
        }
        if ( fireBoy.bounds.intersects(boxes[i].getGlobalBounds()))
        {
            if (fireBoy.dy < boxes[i].getPosition().y )
            {
                pushedFireBoy = false;
                fireBoy.move({ 0, -gravity });
                fireBoy.groundCheck = 1;
            }
        }

    }
}
