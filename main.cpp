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
#include "Visuals.h"
#include "LevelGeneration.h"
#include "Players.h"
#include "GameControl.h"
#include "Render.h"
using namespace std;
using namespace sf;
using namespace sftools;

float gravity = 7;

int main()
{
    
    initVisuals();
    initVisuals();

    
    Player fireBoy(fireBoyTexture, 1), waterGirl(waterGirlTexture, 2);

    
    initWindow();

    
    initializeCurrentRecords();

    
    initButtonSound();

    
    fillGemObjects();

    Clock clock;

    memset(enemyMoveRight, true, sizeof enemyMoveRight);



    
    while (window.isOpen())
    {
        
        leaderboardAndTextFlickering();

        
        checkTheme();

        
        incrementJumpCnts(fireBoy, waterGirl);

        
        Time timePerIteration;
        timePerIteration = clock.restart();

        float speed = 150;
        float iterationsPerSecond = 1.f / timePerIteration.asSeconds();
        float pixelsPerIteration = speed / iterationsPerSecond;



        
        if (fireBoy.isDead || waterGirl.isDead)
        {
            deathCounter++;
        }

        
        if (deathCounter >= (1.5 * iterationsPerSecond))
        {
            paused = 1;
            deathCounter = 0;
        }

        
        for (auto i : platformObjects)
        {
            
            waterGirl.Inquire();

            
            waterGirlPlatformCollision(waterGirl, i, gravity);

            
            fireBoy.Inquire();

            
            fireBoyPlatformCollision(fireBoy, i, gravity);

            

            
            waterGirl.Inquire();

            
            waterGirlPushedRight(waterGirl, i, pixelsPerIteration);

            
            waterGirl.Inquire();

            
            waterGirlPushedLeft(waterGirl, i, pixelsPerIteration);

            
            fireBoy.Inquire();

            
            fireBoyPushedRight(fireBoy, i, pixelsPerIteration);

            
            fireBoy.Inquire();

            
            fireBoyPushedLeft(fireBoy, i, pixelsPerIteration);
        }

        
        for (auto i : gatesObjects)
        {
            

            
            waterGirlBridgeCollision(waterGirl, i, gravity);

            
            fireBoyBridgeCollision(fireBoy, i, gravity);

            

            
            waterGirl.Inquire();

            
            waterGirlPushedRightBridge(waterGirl, i, pixelsPerIteration);

            
            waterGirl.Inquire();

            
            waterGirlPushedLeftBridge(waterGirl, i, pixelsPerIteration);

            
            fireBoy.Inquire();

            
            fireBoyPushedRightBridge(fireBoy, i, pixelsPerIteration);

            
            fireBoy.Inquire();

            
            fireBoyPushedLeftBridge(fireBoy, i, pixelsPerIteration);
        }

        
        for (auto i : gemObjects)
        {
            
            fireBoy.Inquire();

            
            if (i.first.second == 0)
                gemCollision(fireBoy, i);

            
            waterGirl.Inquire();

            
            if (i.first.second == 1)
                gemCollision(waterGirl, i);
        }
        
        boxesFall(gravity);
        
        
        initFireBoyIdle(fireBoy);

        
        initWaterGirlIdle(waterGirl);

        
        fall(fireBoy, gravity);

        
        fall(waterGirl, gravity);
        
        
        waterGirlMovingRight(waterGirl, pixelsPerIteration);

        
        waterGirlMovingLeft(waterGirl, pixelsPerIteration);

        
        fireBoyMovingRight(fireBoy, pixelsPerIteration);

        
        fireBoyMovingLeft(fireBoy, pixelsPerIteration);

        
        waterGirlJumping(waterGirl, iterationsPerSecond);

        
        fireBoyJumping(fireBoy, iterationsPerSecond);

        
        jumpMechanics(fireBoy, gravity);

        
        jumpMechanics(waterGirl, gravity);

        waterGirl.ready++;
        fireBoy.ready++;

        
        enemyMotionAndCollision(fireBoy, waterGirl);

        
        waterGirl.Inquire();
        fireBoy.Inquire();

        
        checkMusic();

        
        gameTimer();

        
        gamePolling();

        
        window.clear();

        
        renderBackground();

        
        if (gameStarted && !levelInquire && !leaderboards && !currentLevelLeaderboardPage)
        {
            
            if (musicMute) musicLevel.stop(), musicFinalLevel.stop();

            
            renderDoor();

            
            checkCurrentLevelOnScreen(fireBoy, waterGirl);

            
            renderGates();

            
            renderGems();

            
            renderLevel();

            
            fireBoy.Inquire();
            waterGirl.Inquire();

            
            boxesMotionAndCollision(fireBoy, waterGirl, pixelsPerIteration, gravity);

            
            renderBoxes();

            
            renderButtons(fireBoy, waterGirl);
            
            
            renderEnemies();


            
            renderBorders();

            
            renderPools(fireBoy, waterGirl);

            
            renderTimer();

            
            renderCharacters(fireBoy, waterGirl);

            
            renderSmoke();

            
            renderLevelEnding(fireBoy, waterGirl);

            
            renderPauseBackground();
        }

        
        if (event.type == Event::KeyReleased)
            canType = true;

        
        if (event.type == Event::MouseButtonReleased)
            canClick = true;

        
        if (fireBoy.isDead)
            FBDead = 1;

        
        if (waterGirl.isDead)
            WGDead = 1;

        
        renderIntro();

        
        renderExit();

        
        renderChangesBetweenNameBoxes();

        
        renderFirstPlayerName();

        
        renderSecondPlayerName();

        
        renderEnterYourName();

        
        renderMainMenu();

        
        renderTheme();

        
        renderSettingsButton();

        
        renderLevelInquire();

        
        renderLeaderboards();

        
        renderCurrentLevelLeaderboard();

        
        renderSettings();

        
        renderPaused(fireBoy, waterGirl);

        
        window.display();
    }
    return 0;
}
