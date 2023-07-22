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
#include "Visuals.h"
#include "GameControl.h"
using namespace std;
using namespace sf;
using namespace sftools;

const int H = 9, W = 16;

void themeSwitch(Texture texture, Sprite sprite)
{
    Sprite temp;
    temp.setTexture(texture);
    temp.setPosition(sprite.getPosition());
    window.draw(temp);
}

void renderBackground()
{
    
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < W; j++) {
            int h = i * 40, w = j * 80;
            spriteBackground.setPosition(w, h);
            window.draw(spriteBackground);
        }
    }
}

void renderLevel()
{
    int offset = 40;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (levelsMap[level][i][j] == ' ') continue;
            int h = i * 80 + offset, w = j * 80 + offset;
            if (i == 8) h -= offset;
            if (j == 15) w -= offset;
            spriteStoneMid.setPosition(w, h);
            spriteStoneRight.setPosition(w, h);
            spriteStoneLeft.setPosition(w, h);
            if (levelsMap[level][i][j] == 'M')
                window.draw(spriteStoneMid);
            else if (levelsMap[level][i][j] == 'R')
                window.draw(spriteStoneRight);
            else if (levelsMap[level][i][j] == 'L')
                window.draw(spriteStoneLeft);
        }
    }
    for(auto j:fillings)
    {
        if(sand)
        {
            themeSwitch(sandFillingText, j.first);
            window.draw(j.first);
        }
        else if(stone)
        {
            themeSwitch(stoneFillingText, j.first);
            window.draw(j.first);
        }
    }
}

void renderPauseBackground()
{
    if (gameStarted && paused)
    {
        window.draw(spritePauseBackground);
    }
}


void renderIntro()
{
    
    getMouseCoordinates();

    
    fillBool();

    if (!started)
    {
        
        bool currentlyHovering = false;

        
        if (mouse_xAxis >= 235 && mouse_xAxis <= 1045 && mouse_yAxis >= 405.5 && mouse_yAxis <= 454.5)
        {
            if (!hoverContinueIntro)
            {
                soundButtonHover.play();
                hoverContinueIntro = true;
            }
            currentlyHovering = true;
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;

                
                started = true;
                player1Input = true;
            }
        }
        else {
            hoverContinueIntro = false;
            textContinueIntro.setFillColor(Color::White);
        }

        if (currentlyHovering)
        {
            Color colorContinue(0, 255, 0, continueFillColor -= ((continueFillColorInc) ? -5 : 5));
            textContinueIntro.setFillColor(colorContinue);
        }
        else
        {
            Color colorContinue(255, 255, 255, continueFillColor -= ((continueFillColorInc) ? -5 : 5));
            textContinueIntro.setFillColor(colorContinue);
        }

        
        window.draw(textIntro);

        
        window.draw(textContinueIntro);
    }
}


void renderMainMenu()
{
    if (mainMenu)
    {
        
        if (mouse_xAxis >= 44 && mouse_xAxis <= 163 && mouse_yAxis >= 51 && mouse_yAxis <= 104)
        {
            if (!hoverArrowMainMenu)
            {
                soundButtonHover.play();
                hoverArrowMainMenu = true;
            }
            arrowMainMenu.setTexture(&textureRedArrow);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;

                
                mainMenu = false;
                player1Input = true;
                player2Input = false;
                bothPlayers = false;
            }
        }
        else {
            hoverArrowMainMenu = false;
            arrowMainMenu.setTexture(&textureWhiteArrow);
        }
        
        window.draw(arrowMainMenu);

        
        window.draw(textTitle);
        Sprite menuBackGround;
        menuBackGround.setTexture(textureMenuBackground);
        window.draw(menuBackGround);

        
        window.draw(textThemesButton);
        if(mouse_xAxis >= 550 && mouse_xAxis <= 740 && mouse_yAxis >= 570 && mouse_yAxis <= 620)
        {
            if(!hoverTheme)
            {
                soundButtonHover.play();
                hoverTheme = true;
                textThemesButton.setFillColor(Color::Green);
            }
            if(Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                system("start https://syrins.byte-breaker.com/");
            }
        }
        else
        {
            textThemesButton.setFillColor(Color::White);
            hoverTheme = false;
        }

        
        if (!gameStarted && mouse_xAxis >= 561 && mouse_xAxis <= 719 && mouse_yAxis >= 279 && mouse_yAxis <= 321)
        {
            if (!hoverStart)
            {
                soundButtonHover.play();
                hoverStart = true;
            }
            textStart.setFillColor(Color::Green);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;

                
                levelInquire = true;

                
                chron.reset();

                
                chron.resume();
            }
        }
        else {
            hoverStart = false;
            textStart.setFillColor(Color::White);
        }

        
        window.draw(textStart);

        
        if (!gameStarted && mouse_xAxis >= 447.5 && mouse_xAxis <= 832.5 && mouse_yAxis >= 479 && mouse_yAxis <= 521)
        {
            if (!hoverLeaderboards)
            {
                soundButtonHover.play();
                hoverLeaderboards = true;
            }
            textLeaderboards.setFillColor(Color::Green);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;

                
                leaderboards = true;
            }
        }
        else {
            hoverLeaderboards = false;
            textLeaderboards.setFillColor(Color::White);
        }

        
        window.draw(textLeaderboards);
    }
}


void renderLevelInquire()
{
    if (levelInquire)
    {
        
        if (mouse_xAxis >= 44 && mouse_xAxis <= 163 && mouse_yAxis >= 51 && mouse_yAxis <= 104)
        {
            if (!hoverArrowLevelInquire)
            {
                soundButtonHover.play();
                hoverArrowLevelInquire = true;
            }
            arrowLevelInquire.setTexture(&textureRedArrow);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;

                
                levelInquire = false;
            }
        }
        else {
            hoverArrowLevelInquire = false;
            arrowLevelInquire.setTexture(&textureWhiteArrow);
        }

        
        window.draw(arrowLevelInquire);

        
        window.draw(textLevelsTitle);

        string currentPlayer1 = min({ player1Name, player2Name });
        string currentPlayer2 = max({ player1Name, player2Name });

        
        for (int i = 0; i < 10; i++) window.draw(textLevels[i]);

        
        for (int i = 0; i < 10; i++)
        {
            
            float textLevelCoordinatesW = textLevels[i].getLocalBounds().width, textLevelCoordinatesH = textLevels[i].getLocalBounds().height;
            if (((currentRecords[{currentPlayer1, currentPlayer2}].size() >= i && (i == 0 || currentRecords[{currentPlayer1, currentPlayer2}][i - 1] != 0)) || (guestRecords.size() >= i && guest && (i == 0 || guestRecords[i - 1] != 0))) && mouse_xAxis >= ((i < 5) ? 440 : 840) - textLevelCoordinatesW / 2 && mouse_xAxis <= ((i < 5) ? 440 : 840) + textLevelCoordinatesW / 2 && mouse_yAxis >= ((i < 5) ? (i + 1) * 100 + 130 : (i - 5 + 1) * 100 + 130) - textLevelCoordinatesH / 2 && mouse_yAxis <= ((i < 5) ? (i + 1) * 100 + 130 : (i - 5 + 1) * 100 + 130) + textLevelCoordinatesH / 2)
            {
                if (!hoverTextLevels[i])
                {
                    soundButtonHover.play();
                    hoverTextLevels[i] = true;
                }
                textLevels[i].setFillColor(Color::Green);
                if (Mouse::isButtonPressed(Mouse::Left) && canClick)
                {
                    
                    level = i;
                    chron.reset();
                    chron.resume();
                    gameStarted = true;
                    levelInquire = false;

                    if (!musicMute)
                    {
                        musicIntro.stop();
                        if (level == 9) musicFinalLevel.play();
                        else musicLevel.play();
                    }

                    
                    canClick = false;

                    break;
                }
            }
            else {
                hoverTextLevels[i] = false;
                textLevels[i].setFillColor(Color::White);
            }
        }
    }
}


void renderEnterYourName()
{
    if (started && !bothPlayers)
    {
        Sprite menuBackGround;
        menuBackGround.setTexture(textureMenuBackground);
        window.draw(menuBackGround);

        
        if (mouse_xAxis >= 412.5 && mouse_xAxis <= 867.5 && mouse_yAxis >= 619 && mouse_yAxis <= 661)
        {
            if (!hoverGuest)
            {
                soundButtonHover.play();
                hoverGuest = true;
            }
            textGuest.setFillColor(Color::Green);
            
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                player1Input = true;
                player2Input = true;
                bothPlayers = true;

                
                player1Name.clear();
                player2Name.clear();
                player1Text.setString(player1Name);
                player2Text.setString(player2Name);

                
                guest = true;

                
                canClick = false;
            }
        }
        else {
            hoverGuest = false;
            textGuest.setFillColor(Color::White);
        }

        

        
        if (player1Name.size() && player2Name.size())
            textContinueToGame.setString("Devam et " + player1Name + " ve " + player2Name);
        else
            textContinueToGame.setString("Devam");

        
        textRect = textContinueToGame.getLocalBounds();
        textContinueToGame.setOrigin(textRect.left +
                                     textRect.width / 2.0f,
                                     textRect.top +
                                     textRect.height / 2.0f);
        textContinueToGame.setPosition(640, 540);

        
        float continueX = textContinueToGame.getLocalBounds().width;
        float continueY = textContinueToGame.getLocalBounds().height;
        float continueXStart = 640 - continueX / 2, continueXEnd = 640 + continueX / 2;
        float continueYStart = 540 - continueY / 2, continueYEnd = 540 + continueY / 2;

        if (mouse_xAxis >= continueXStart && mouse_xAxis <= continueXEnd && mouse_yAxis >= continueYStart && mouse_yAxis <= continueYEnd && player1Name.size() && player2Name.size())
        {
            if (!hoverContinueToGame)
            {
                soundButtonHover.play();
                hoverContinueToGame = true;
            }
            textContinueToGame.setFillColor(Color::Green);
            
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                player1Input = true;
                player2Input = true;
                bothPlayers = true;

                
                canClick = false;
            }
        }
        else {
            hoverContinueToGame = false;
            textContinueToGame.setFillColor(Color::White);
        }

        
        window.draw(textGuest);

        
        window.draw(textContinueToGame);
    }
}


void renderFirstPlayerName()
{
    if (player1Input && !bothPlayers && started)
    {
        
        window.draw(enterYourNameRectangle);
        window.draw(enterYourNameRectangle2);

        
        textEnterYourName.setString("1. oyuncu:");

        
        textRect = player1Text.getLocalBounds();
        player1Text.setOrigin(textRect.left +
                              textRect.width / 2.0f,
                              textRect.top +
                              textRect.height / 2.0f);

        
        player1Text.setPosition(640, 350);

        
        window.draw(textTitle);

        
        window.draw(player1Text);

        
        window.draw(player2Text);

        
        Color colorEnterYourName(255, 255, 255, enterYourNameFillColor -= ((enterYourNameFillColorInc) ? -5 : 5));
        textEnterYourName.setFillColor(colorEnterYourName);

        
        window.draw(textEnterYourName);

        
        Color colorPlayer1InputBox(255, 0, 0, player1InputBoxFillColor -= ((player1InputBoxFillColorInc) ? -5 : 5));
        enterYourNameRectangleFade.setOutlineColor(colorPlayer1InputBox);

        
        window.draw(enterYourNameRectangleFade);
    }
}


void renderSecondPlayerName()
{
    if (player2Input && !bothPlayers && started)
    {
        
        window.draw(enterYourNameRectangle);
        window.draw(enterYourNameRectangle2);

        
        window.draw(textTitle);

        
        window.draw(player1Text);

        
        window.draw(player2Text);

        
        Color colorEnterYourName(255, 255, 255, enterYourNameFillColor -= ((enterYourNameFillColorInc) ? -5 : 5));
        textEnterYourName.setFillColor(colorEnterYourName);

        
        textEnterYourName.setString("2. oyuncu:");

        
        textRect = player2Text.getLocalBounds();
        player2Text.setOrigin(textRect.left +
                              textRect.width / 2.0f,
                              textRect.top +
                              textRect.height / 2.0f);

        
        player2Text.setPosition(640, 450);

        
        window.draw(textEnterYourName);

        
        Color colorPlayer2InputBox(255, 0, 0, player2InputBoxFillColor -= ((player2InputBoxFillColorInc) ? -5 : 5));
        enterYourNameRectangleFade2.setOutlineColor(colorPlayer2InputBox);

        
        window.draw(enterYourNameRectangleFade2);
    }
}


void renderChangesBetweenNameBoxes()
{
    if (started && !bothPlayers)
    {
        
        if (mouse_xAxis >= 435 && mouse_xAxis <= 845 && mouse_yAxis >= 322.5 && mouse_yAxis <= 377.5)
        {
            if (!hoverPlayer1InputBox)
            {
                soundButtonHover.play();
                hoverPlayer1InputBox = true;
            }
            enterYourNameRectangle.setOutlineColor(Color::Green);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;

                
                player1Input = 1;
                player2Input = 0;
            }
        }
        else {
            hoverPlayer1InputBox = false;
            enterYourNameRectangle.setOutlineColor(Color::White);
        }

        
        if (mouse_xAxis >= 435 && mouse_xAxis <= 845 && mouse_yAxis >= 422.5 && mouse_yAxis <= 477.5)
        {
            if (!hoverPlayer2InputBox)
            {
                soundButtonHover.play();
                hoverPlayer2InputBox = true;
            }
            enterYourNameRectangle2.setOutlineColor(Color::Green);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;

                
                player1Input = 0;
                player2Input = 1;
            }
        }
        else {
            hoverPlayer2InputBox = false;
            enterYourNameRectangle2.setOutlineColor(Color::White);
        }
    }
}


void renderSettingsButton()
{
    if (paused && !settingsMenu || mainMenu)
    {
        
        if (mouse_xAxis >= 518 && mouse_xAxis <= 760 && mouse_yAxis >= ((oneDead || !gameStarted) ? 383 : 483) && mouse_yAxis <= ((oneDead || !gameStarted) ? 420 : 520))
        {
            if (!hoverSettings)
            {
                soundButtonHover.play();
                hoverSettings = true;
            }
            textSettingsButton.setFillColor(Color::Green);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;

                
                settingsMenu = true;
            }
        }
        else {
            hoverSettings = false;
            textSettingsButton.setFillColor(Color::White);
        }

        
        if (oneDead || !gameStarted) textSettingsButton.setPosition(640, 400);
        else textSettingsButton.setPosition(640, 500);

        
        window.draw(textSettingsButton);
    }
}


void renderExit()
{
    if (!(gameStarted && !paused))
    {
        
        if (mouse_xAxis >= 1145 && mouse_xAxis <= 1250 && mouse_yAxis >= 655 && mouse_yAxis <= 705)
        {
            if (!hoverExit)
            {
                soundButtonHover.play();
                hoverExit = true;
            }
            textExit.setFillColor(Color::Red);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;

                
                window.close();
            }
        }
        else {
            hoverExit = false;
            textExit.setFillColor(Color::White);
        }

        
        window.draw(textExit);
    }
}


void renderLeaderboards()
{
    if (leaderboards)
    {
        
        window.draw(textLeaderboard);

        
        if (mouse_xAxis >= 44 && mouse_xAxis <= 163 && mouse_yAxis >= 51 && mouse_yAxis <= 104)
        {
            if (!hoverArrowLeaderboards)
            {
                soundButtonHover.play();
                hoverArrowLeaderboards = true;
            }
            arrowLeaderboards.setTexture(&textureRedArrow);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                leaderboards = false;

                
                canClick = false;
            }
        }
        else {
            hoverArrowLeaderboards = false;
            arrowLeaderboards.setTexture(&textureWhiteArrow);
        }

        
        window.draw(arrowLeaderboards);

        
        for (int i = 0; i < 10; i++) window.draw(textLevels[i]);

        
        for (int i = 0; i < 10; i++)
        {
            
            float textLevelCoordinatesW = textLevels[i].getLocalBounds().width, textLevelCoordinatesH = textLevels[i].getLocalBounds().height;
            if (mouse_xAxis >= ((i < 5) ? 440 : 840) - textLevelCoordinatesW / 2 && mouse_xAxis <= ((i < 5) ? 440 : 840) + textLevelCoordinatesW / 2 && mouse_yAxis >= ((i < 5) ? (i + 1) * 100 + 130 : (i - 5 + 1) * 100 + 130) - textLevelCoordinatesH / 2 && mouse_yAxis <= ((i < 5) ? (i + 1) * 100 + 130 : (i - 5 + 1) * 100 + 130) + textLevelCoordinatesH / 2)
            {
                if (!hoverTextLevels[i])
                {
                    soundButtonHover.play();
                    hoverTextLevels[i] = true;
                }
                textLevels[i].setFillColor(Color::Green);
                if (Mouse::isButtonPressed(Mouse::Left) && canClick)
                {
                    
                    levelLeaderboardPage[i] = true;

                    
                    canClick = false;

                    break;
                }
            }
            else {
                hoverTextLevels[i] = false;
                textLevels[i].setFillColor(Color::White);
            }
        }
    }
}


void renderCurrentLevelLeaderboard()
{
    if (currentLevelLeaderboardPage)
    {
        
        window.draw(textMainLevels[currentLevelLeaderboardPage - 1]);

        
        getTopTenOfLevel(currentLevelLeaderboardPage);

        
        Text currentLevelRecord;
        currentLevelRecord.setFont(fontTitle);
        currentLevelRecord.setCharacterSize(40);
        currentLevelRecord.setFillColor(Color::White);

        
        for (int i = 0; i < min((int)topTen.size(), 5); i++)
        {
            
            string levelRecordMinutes = to_string(topTen[i].first / 60), levelRecordSeconds = to_string(topTen[i].first % 60);

            
            if (levelRecordMinutes.size() == 1) levelRecordMinutes = "0" + levelRecordMinutes;
            if (levelRecordSeconds.size() == 1) levelRecordSeconds = "0" + levelRecordSeconds;

            
            currentLevelRecord.setString("#" + to_string(i + 1) + " " + topTen[i].second.first + " & " + topTen[i].second.second + " (Skor: " + levelRecordMinutes + ":" + levelRecordSeconds + ")");

            
            currentLevelRecord.setPosition(100, (i + 1) * 100 + 100);

            
            window.draw(currentLevelRecord);
        }

        
        if (mouse_xAxis >= 44 && mouse_xAxis <= 163 && mouse_yAxis >= 51 && mouse_yAxis <= 104)
        {
            if (!hoverArrowLevelLeaderboard)
            {
                soundButtonHover.play();
                hoverArrowLevelLeaderboard = true;
            }
            arrowLevelLeaderboard.setTexture(&textureRedArrow);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;

                
                levelLeaderboardPage[currentLevelLeaderboardPage - 1] = false;
                currentLevelLeaderboardPage = 0;
                leaderboards = true;
            }
        }
        else {
            hoverArrowLevelLeaderboard = false;
            arrowLevelLeaderboard.setTexture(&textureWhiteArrow);
        }

        
        window.draw(arrowLevelLeaderboard);
    }
}


void renderSettings()
{
    if (settingsMenu)
    {
        
        Text state1, state2;

        if (musicMute)
            state1 = textOff;
        else
            state1 = textOn;

        if (soundFxMute)
            state2 = textOff;
        else
            state2 = textOn;


        
        if (mouse_xAxis >= 700 && mouse_xAxis <= 780 && mouse_yAxis >= 280 && mouse_yAxis <= 321)
        {
            if (!hoverMusicMute)
            {
                soundButtonHover.play();
                hoverMusicMute = true;
            }
            if (musicMute)
            {
                state1 = textOff;
                state1.setFillColor(Color::Green);
            }
            else
            {
                state1 = textOn;
                state1.setFillColor(Color::Red);
            }
            
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                if (musicMute)
                {
                    if (gameStarted)
                    {
                        if (level == 9) musicFinalLevel.play();
                        else musicLevel.play();
                    }
                    else musicIntro.play();
                    musicMute = false;
                }
                else
                {
                    if (gameStarted)
                    {
                        if (level == 9) musicFinalLevel.stop();
                        else musicLevel.stop();
                    }
                    else musicIntro.stop();
                    musicMute = true;
                }

                
                canClick = false;

                pressedMusicMute = true;
            }
        }
        else {
            hoverMusicMute = false;
            state1.setFillColor(Color::White);
        }

        
        if (mouse_xAxis >= 750 && mouse_xAxis <= 810 && mouse_yAxis >= 376 && mouse_yAxis <= 425)
        {
            if (!hoverSoundFxMute && !hoverContinue && !hoverStart)
            {
                soundButtonHover.play();
                hoverSoundFxMute = true;
                hoverContinue = true;
                hoverStart = true;
            }
            if (soundFxMute)
            {
                state2 = textOff;
                state2.setFillColor(Color::Green);
            }
            else
            {
                state2 = textOn;
                state2.setFillColor(Color::Red);
            }
            
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                if (soundFxMute)
                    soundFxMute = false;
                else
                    soundFxMute = true;

                
                canClick = false;

                pressedSoundFxMute = true;
            }
        }
        else {
            hoverStart = false;
            hoverContinue = false;
            hoverSoundFxMute = false;
            state2.setFillColor(Color::White);
        }

        
        if (mouse_xAxis >= 44 && mouse_xAxis <= 163 && mouse_yAxis >= 51 && mouse_yAxis <= 104)
        {
            if (!hoverArrow)
            {
                soundButtonHover.play();
                hoverArrow = true;
            }
            arrow.setTexture(&textureRedArrow);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;

                
                settingsMenu = false;
            }
        }
        else {
            hoverSoundFxMute = false;
            arrow.setTexture(&textureWhiteArrow);
        }

        
        state1.setPosition(740, 300);

        
        state2.setPosition(785, 400);

        
        window.draw(textMusic);

        
        window.draw(textSoundFx);

        
        window.draw(state1);

        
        window.draw(state2);

        
        window.draw(arrow);

        
        window.draw(textSettingsTitle);
    }
}


void renderTheme()
{
    if(themeMenu)
    {
        
        window.draw(textThemesTitle);

        if(stone)
            textStone.setFillColor(Color::Green);
        else
            textStone.setFillColor(Color::White);

        if(sand)
            textSand.setFillColor(Color::Green);
        else
            textSand.setFillColor(Color::White);

        if(mouse_xAxis >= 573 && mouse_xAxis <= 707 && mouse_yAxis >= 276.5 && mouse_yAxis <= 323.5) 
        {
            if(!hoverSand)
            {
                hoverSand = true;
                soundButtonHover.play();
            }
            if(Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                sand = true;
                stone = false;
                canClick = false;
            }
        }
        else
            hoverSand = false;

        if(mouse_xAxis >= 552.5 && mouse_xAxis <= 727.5 && mouse_yAxis >= 378 && mouse_yAxis <= 422) 
        {
            if(!hoverStone)
            {
                hoverStone = true;
                soundButtonHover.play();
            }
            if(Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                sand = false;
                stone = true;
                canClick = false;
            }
        }
        else
            hoverStone = false;

        window.draw(textSand);
        window.draw(textStone);
        
        if (mouse_xAxis >= 44 && mouse_xAxis <= 163 && mouse_yAxis >= 51 && mouse_yAxis <= 104)
        {
            if (!hoverArrowThemes)
            {
                soundButtonHover.play();
                hoverArrowThemes = true;
            }
            arrowThemes.setTexture(&textureRedArrow);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;
                
                themeMenu = false;
            }
        }
        else {
            hoverArrowThemes = false;
            arrowThemes.setTexture(&textureWhiteArrow);
        }
        window.draw(arrowThemes);
    }
}


void renderPaused(Player& fireBoy, Player& waterGirl)
{
    if (paused && !settingsMenu)
    {
        
        if (!FBDead && !WGDead) window.draw(textPaused);

        
        if (FBDead || WGDead) window.draw(textGameOver);

        
        
        if (!FBDead && !WGDead)
        {
            if (mouse_xAxis >= 278.5 && mouse_xAxis <= 1001.5 && mouse_yAxis >= 278.5 && mouse_yAxis <= 321.5)
            {
                if (!hoverContinue)
                {
                    soundButtonHover.play();
                    hoverContinue = true;
                }
                textContinue.setFillColor(Color::Green);
                if (Mouse::isButtonPressed(Mouse::Left) && canClick)
                {
                    
                    canClick = false;

                    
                    paused = false;

                    
                    chron.resume();
                }
            }
            else {
                hoverContinue = false;
                textContinue.setFillColor(Color::White);
            }

            
            window.draw(textContinue);
        }

        
        if (mouse_xAxis >= 476.5 && mouse_xAxis <= 803.5 && mouse_yAxis >= ((oneDead) ? 279 : 379) && mouse_yAxis <= ((oneDead) ? 321 : 421))
        {
            if (!hoverRetry)
            {
                soundButtonHover.play();
                hoverRetry = true;
            }

            textRetryLevel.setFillColor(Color::Green);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;

                
                fireBoy.Restart(initialPosition[level].first.first,initialPosition[level].first.second);
                waterGirl.Restart(initialPosition[level].second.first,initialPosition[level].second.second);
                FBDead = 0, WGDead = 0;

                
                restartEnemies();

                
                chron.reset();

                
                chron.resume();

                
                paused = false;

                
                if (level == 9)
                {
                    musicFinalLevel.stop();
                    musicFinalLevel.play();
                }
                else
                {
                    musicLevel.stop();
                    musicLevel.play();
                }

                
                boxesRestart();

                
                deathX = deathY = -100.f;
                deathCounter = 0;

                
                restartGems();
            }
        }
        else {
            hoverRetry = false;
            textRetryLevel.setFillColor(Color::White);
        }

        
        if (oneDead) textRetryLevel.setPosition(640, 300);
        else textRetryLevel.setPosition(640, 400);

        
        window.draw(textRetryLevel);

        
        if (mouse_xAxis >= 516.5 && mouse_xAxis <= 763.5 && mouse_yAxis >= ((oneDead) ? 478.5 : 578.5) && mouse_yAxis <= ((oneDead) ? 521.5 : 621.5))
        {
            if (!hoverMainMenu)
            {
                soundButtonHover.play();
                hoverMainMenu = true;
            }
            textMainMenu.setFillColor(Color::Green);
            if (Mouse::isButtonPressed(Mouse::Left) && canClick)
            {
                
                canClick = false;

                
                gameStarted = false;
                paused = false;

                
                fireBoy.Restart(initialPosition[level].first.first,initialPosition[level].first.second);
                waterGirl.Restart(initialPosition[level].second.first,initialPosition[level].second.second);
                FBDead = 0, WGDead = 0;
                
                
                curPlatformObjectLevel = 100;
                
                
                restartEnemies();

                
                musicLevel.stop();
                musicFinalLevel.stop();

                
                deathX = deathY = -100.f;
                deathCounter = 0;
            }
        }
        else {
            hoverMainMenu = false;
            textMainMenu.setFillColor(Color::White);
        }

        
        if (oneDead) textMainMenu.setPosition(640, 500);
        else textMainMenu.setPosition(640, 600);

        
        window.draw(textMainMenu);
    }
}


void renderPools(Player& fireBoy, Player& waterGirl)
{
    for(int i = 0; i < pools.size(); i++)
    {
        if(stone)
        {
            if(pools[i].second.first == 1)
            {
                if(pools[i].second.second == 3)
                {
                    themeSwitch(smallLavaText, pools[i].first);
                }
                if(pools[i].second.second == 0)
                {
                    themeSwitch(lavaLeftText, pools[i].first);
                }
                if(pools[i].second.second == 1)
                {
                    themeSwitch(lavaMidText, pools[i].first);
                }
                if(pools[i].second.second == 2)
                {
                    themeSwitch(lavaRightText, pools[i].first);
                }
            }
            else if(pools[i].second.first == 2)
            {
                if(pools[i].second.second == 3)
                {
                    themeSwitch(smallWaterText, pools[i].first);
                }
                if(pools[i].second.second == 0)
                {
                    themeSwitch(waterLeftText, pools[i].first);
                }
                if(pools[i].second.second == 1)
                {
                    themeSwitch(waterMidText, pools[i].first);
                }
                if(pools[i].second.second == 2)
                {
                    themeSwitch(waterRightText, pools[i].first);
                }
            }
            else if(pools[i].second.first == 3)
            {
                if(pools[i].second.second == 3)
                {
                    themeSwitch(smallAcidText, pools[i].first);
                }
                if(pools[i].second.second == 0)
                {
                    themeSwitch(acidLeftText, pools[i].first);
                }
                if(pools[i].second.second == 1)
                {
                    themeSwitch(acidMidText, pools[i].first);
                }
                if(pools[i].second.second == 2)
                {
                    themeSwitch(acidRightText, pools[i].first);
                }
            }
        }
        else if(sand)
        {
            if(pools[i].second.first == 1)
            {
                if(pools[i].second.second == 3)
                {
                    themeSwitch(smallLavaSandText, pools[i].first);
                }
                if(pools[i].second.second == 0)
                {
                    themeSwitch(lavaLeftSandText, pools[i].first);
                }
                if(pools[i].second.second == 1)
                {
                    themeSwitch(lavaMidSandText, pools[i].first);
                }
                if(pools[i].second.second == 2)
                {
                    themeSwitch(lavaRightSandText, pools[i].first);
                }
            }
            else if(pools[i].second.first == 2)
            {
                if(pools[i].second.second == 3)
                {
                    themeSwitch(smallWaterSandText, pools[i].first);
                }
                if(pools[i].second.second == 0)
                {
                    themeSwitch(waterLeftSandText, pools[i].first);
                }
                if(pools[i].second.second == 1)
                {
                    themeSwitch(waterMidSandText, pools[i].first);
                }
                if(pools[i].second.second == 2)
                {
                    themeSwitch(waterRightSandText, pools[i].first);
                }
            }
            else if(pools[i].second.first == 3)
            {
                if(pools[i].second.second == 3)
                {
                    themeSwitch(smallAcidSandText, pools[i].first);
                }
                if(pools[i].second.second == 0)
                {
                    themeSwitch(acidLeftSandText, pools[i].first);
                }
                if(pools[i].second.second == 1)
                {
                    themeSwitch(acidMidSandText, pools[i].first);
                }
                if(pools[i].second.second == 2)
                {
                    themeSwitch(acidRightSandText, pools[i].first);
                }
            }
        }
    }
}


void renderButtons(Player& fireBoy, Player& waterGirl)
{
    for (auto i : platformObjects)
    {
        if (!i.second)
            continue;
        else 
        {
            
            
            bool boxButtonGatePressed = false;
            if (!waterGirl.bounds.intersects(i.first.first.getGlobalBounds()) && !fireBoy.bounds.intersects(i.first.first.getGlobalBounds()) && i.first.second == 4)
            {

                for(int j = 0;j < boxes.size();++j)
                {
                    if (abs(i.first.first.getPosition().y - boxes[j].getPosition().y) <= 82 && abs(boxes[j].getPosition().x - i.first.first.getPosition().x) <= 42)
                    {
                        boxButtonGatePressed = true;
                        buttonGatePressed[i.second] = true;
                        break;
                    }
                }
                if(!boxButtonGatePressed)
                {
                    buttonGatePressed[i.second] = false;
                    
                    if (i.second % 2 == 1 && !buttonGatePressed[i.second + 1])
                    {
                        gateOpened[((i.second - 1) / 2) + 1] = false;
                    }
                    if (i.second % 2 == 0 && !buttonGatePressed[i.second - 1])
                    {
                        gateOpened[((i.second - 1) / 2) + 1] = false;
                    }
                }

            }

            
            if (i.first.second == 4 && buttonGatePressed[i.second])
            {
                if (!gateButtonSoundPlayed[i.second] && !soundFxMute)
                {
                    buttonSound.play();
                    gateButtonSoundPlayed[i.second] = true;
                }
                buttonOn.setPosition(i.first.first.getPosition().x, i.first.first.getPosition().y - 20);
                gateOpened[((i.second - 1) / 2) + 1] = true;
                window.draw(buttonOn);
            }

            if (i.first.second == 4 && !buttonGatePressed[i.second])
            {
                gateButtonSoundPlayed[i.second] = false;
                buttonOff.setPosition(i.first.first.getPosition().x, i.first.first.getPosition().y - 20);
                window.draw(buttonOff);
            }
            
            if (!waterGirl.bounds.intersects(i.first.first.getGlobalBounds()) && !fireBoy.bounds.intersects(i.first.first.getGlobalBounds()) && i.first.second == 5)
            {
                bool boxButtonBridgePressed = false;
                for(int j = 0;j < boxes.size();++j)
                {
                    if (abs(i.first.first.getPosition().y - boxes[j].getPosition().y) <= 82 && abs(boxes[j].getPosition().x - i.first.first.getPosition().x) <= 42)
                    {
                        boxButtonBridgePressed = true;
                        buttonBridgePressed[i.second] = true;
                        break;
                    }
                }
                if(!boxButtonBridgePressed)
                {
                    buttonBridgePressed[i.second] = false;
                    if (i.second % 2 == 1 && !buttonBridgePressed[i.second + 1])
                    {
                        bridgeOpened[((i.second - 1) / 2) + 1] = false;
                    }
                    else if (i.second % 2 == 0 && !buttonBridgePressed[i.second - 1])
                    {
                        bridgeOpened[((i.second - 1) / 2) + 1] = false;
                    }
                }

            }

            if (i.first.second == 5 && buttonBridgePressed[i.second])
            {
                if (!bridgeButtonSoundPlayed[i.second] && !soundFxMute)
                {
                    buttonSound.play();
                    bridgeButtonSoundPlayed[i.second] = true;
                }
                buttonOn.setPosition(i.first.first.getPosition().x, i.first.first.getPosition().y - 20);
                bridgeOpened[((i.second - 1) / 2) + 1] = true;
                window.draw(buttonOn);
            }

            if (i.first.second == 5 && !buttonBridgePressed[i.second])
            {
                bridgeButtonSoundPlayed[i.second] = false;
                buttonOff.setPosition(i.first.first.getPosition().x, i.first.first.getPosition().y - 20);
                window.draw(buttonOff);
            }
        }
    }
}


void renderBorders()
{
    for (int i = 0; i < 4; i++) window.draw(borders[i]);
}


void renderSmoke()
{
    if (smoke1.getPosition().x != deathX || smoke2.getPosition().y != deathY) return;
    if (deathCounter && deathX > 0)
    {
        if (deathCounter < 30)
        {
            window.draw(smoke1);
        }
        else if (deathCounter < 60)
        {
            window.draw(smoke2);
        }
        else if (deathCounter < 90)
        {
            window.draw(smoke1);
        }
    }
}


void renderTimer()
{
    window.draw(textTimer);
}


void renderLevelEnding(Player& fireBoy, Player& waterGirl)
{
    
    fireBoy.Inquire();
    waterGirl.Inquire();

    
    float spriteDoorX = spriteDoor.getPosition().x - 20, spriteDoorY = spriteDoor.getPosition().y;
    if (fireBoy.dx >= spriteDoorX && fireBoy.dx + 80 <= spriteDoorX + 100 && fireBoy.dy <= spriteDoorY + 120 && fireBoy.dy >= spriteDoorY)
    {
        if (waterGirl.dx >= spriteDoorX && waterGirl.dx + 80 <= spriteDoorX + 100 && waterGirl.dy <= spriteDoorY + 120 && waterGirl.dy >= spriteDoorY)
        {
            
            gameStarted = false;

            
            levelInquire = true;

            
            musicLevel.stop();
            musicFinalLevel.stop();

            
            if (!soundFxMute) soundLevelComplete.play();

            
            fireBoy.Restart(initialPosition[level].first.first,initialPosition[level].first.second);
            waterGirl.Restart(initialPosition[level].second.first,initialPosition[level].second.second);

            
            restartEnemies();

            
            curPlatformObjectLevel = 100;

            
            deathX = deathY = -100.f;
            deathCounter = 0;

            
            getEndingTime();
            chron.reset();
        }
    }
}


void renderCharacters(Player& fireBoy, Player& waterGirl)
{
    window.draw(fireBoy.playerSprite);
    window.draw(waterGirl.playerSprite);
}


void renderGates()
{
    for (auto i : gatesObjects)
    {
        if (i.first.second == 0 || i.first.second == 1 || i.first.second == 2)
        {
            if (gateOpened[i.second] && i.first.second == 0)
                window.draw(i.first.first);
            else if (!gateOpened[i.second])
                window.draw(i.first.first);
        }
        else if (i.first.second == 3 || i.first.second == 4)
        {
            if (!bridgeOpened[i.second] && i.first.second == 3)
                window.draw(i.first.first);
            else if (bridgeOpened[i.second])
                window.draw(i.first.first);
        }
    }
}


void renderGems()
{
    for (auto i : gemObjects)
    {
        if (!gemsTaken[i.second])
            window.draw(i.first.first);
    }
}


void renderDoor()
{
    window.draw(spriteDoor);
}


void renderEnemies()
{
    for (auto i : enemies)
    {
        window.draw(i.first);
    }
}


void renderBoxes()
{
    for (int i = 0; i < boxes.size(); ++i)
    {
        window.draw(boxes[i]);
    }
}
