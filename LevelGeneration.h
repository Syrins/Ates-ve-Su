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
#include "Visuals.h"
using namespace std;
using namespace sf;
using namespace sftools;



bool sand = false, stone = true;


vector <pair<RectangleShape, pair<float, float>>> enemies;


int level = 0;

String levelsMap[11][9] =
        {
                /*
                      HARÝTA TUÞU

                    G: kapý düðmesi
                    B: köprü düðmesi
                    M: Orta blok
                    L: sol blok
                    R: sað blok
                    W: küçük su
                    F: küçük lav
                    f: sol lav
                    ben: orta lav
                    r: sað lav
                    w:sol su
                    a: orta su
                    t: doðru su

                */
                
                {
                        "                ",
                        "                ",
                        "         LMMMMMM",
                        "                ",
                        "GR       LMMGMMM",
                        "    LMBR        ",
                        "           LBR  ",
                        "    LfirR       ",
                        "                ",
                },
                
                {
                        "                ",
                        "                ",
                        "          LBMMMR",
                        "       M        ",
                        "LBMR        LMMR",
                        "      LMMR      ",
                        " fir        wat ",
                        "      LMMR      ",
                        "                ",
                },
                
                {
                        "                ",
                        "                ",
                        "         LMMMMM ",
                        "MMMMMMR         ",
                        "       M        ",
                        "          LFR   ",
                        "      LMR       ",
                        " LWR            ",
                        "                ",
                },
                
                {
                        "                ",
                        "                ",
                        "MMMMMMMMMMMR    ",
                        "              MM",
                        "   LMMMMMMMMMMMM",
                        "M               ",
                        "MMMMMBMMMMR  M  ",
                        "            MM  ",
                        "              G ",
                },
                
                {
                        "                ",
                        "                ",
                        "LMBR    BMG     ",
                        "                ",
                        "   GMMMMMBMMMmu ",
                        "                ",
                        "                ",
                        " LMMMMMMfiiirMB ",
                        "                ",
                },
                
                {
                        "                ",
                        "                ",
                        "                ",
                        "LG              ",
                        "    L    R      ",
                        "BMMMfiiiirMR    ",
                        "              M ",
                        "   G  B         ",
                        "                ",
                },
                
               {
                       "                ",
                       "                ",
                       "LMR         LMGR",
                       "                ",
                       "LBfirR    BMMMMR",
                       "                ",
                       "LMMMMR     LMMMR",
                       "                ",
                       "                ",
               },
                
                {
                        "                ",
                        "                ",
                        " firR     GWR LR",
                        " M     M   M    ",
                        " M  M      M    ",
                        " M              ",
                        " MMMMMMMR  M    ",
                        " M         Mmud ",
                        "B               ",
                },
                
                {
                    "                ",
                    "                ",
                    "LMGMMR   LMMMWMG",
                    "                ",
                    "                ",
                    "                ",
                    "LMMFBR     LMGMR",
                    "                ",
                    "             B  ",
                },
                
                {
                        "                ",
                        "                ",
                        " LFMMFMMMMMMBR  ",
                        "                ",
                        "                ",
                        " LMMWMMWMMAMMGM ",
                        "                ",
                        "M M M M M M LMR ",
                        "muuuuuuuuuuuuud ",
                },        
        };


/*

G: kapý düðmesi
B: köprü düðmesi
M: Orta blok
L: sol blok
R: sað blok
W: küçük su
F: küçük lav
f: sol lav
ben: orta lav
r: sað lav
w:sol su
a: orta su
t: doðru su
*/
String objectsMap[11][36] =
        {
                
                {

                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                      T                D        ",
                        "                                      M                         ",
                        "                                      M      g                  ",
                        "                                      M                         ",
                        "                                      M                         ",
                        "                                      M                         ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "    G                                                           ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "LWWWWWWWW                                                       ",
                        "                         g                                      ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                "
                },
                
                {
                        "                                                                ",
                        "                                                                ",
                        "                                                       D        ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                LWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "         g                                           G          ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                "
                },
                
                {
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                      D         ",
                        "                                                                ",
                        "                                                                ",
                        "                                     E                          ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "   G   g  E                                                     ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                             g                  ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "         G                                                      ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                "
                },
                
                {

                        "        T                                                       ",
                        "        M                                                       ",
                        "  D     M                                                       ",
                        "        M                                                       ",
                        "        M                                                       ",
                        "        M      O                                                ",
                        "        M                                                       ",
                        "        M                                                       ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                        Q       ",
                        "                                                                ",
                        "                                                        Q       ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "Q                                                               ",
                        "                                                                ",
                        "Q                                           LWWWWWWWW           ",
                        "                                                                ",
                        "                                                    Q           ",
                        "                                                                ",
                        "                                                    Q           ",
                        "                                                                ",
                        "                                                Q   Q           ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                "
                },
                
                {
                        "                                                                ",
                        "                                                                ",
                        "    D                                                           ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                LWWWWWWWWWWWWWWWW                               ",
                        "                        G                                       ",
                        "                                           T                    ",
                        "                                           M                    ",
                        "                                           M                    ",
                        "                                        O  M                    ",
                        "                E                          M                    ",
                        "  g                                        B                    ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                         g                      ",
                        "LWWWW                                                           ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "              E                                                 ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                },
                
                {

                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "D                                                               ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "      T                                                         ",
                        "      M                                                         ",
                        "      M             LWWWWWWWWWWWWWWW                            ",
                        "      M                                      O                  ",
                        "      M                                                         ",
                        "      B                                                         ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                "
                },
                
                {
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                 O              ",
                        "                                                                ",
                        "                                                                ",
                        "                                                   g            ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                    O                      O                    ",
                        "  g                                                             ",
                        "                                                                ",
                        "                        LWWWWWWWWWWWWWWW                        ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "             O                                                  ",
                        "                                                  E  G          ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                T      D        ",
                        "                                                M               ",
                        "                                                M               ",
                        "                               O                M               ",
                        "                   E                            M      g        ",
                        "                                                B               ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                },
                
                {

                        "                   T                                            ",
                        "        G          M                                            ",
                        "                   M                                            ",
                        "                   M                         g                  ",
                        "          O        M                                            ",
                        "                   M                                            ",
                        "                   M                                            ",
                        "                   M                                            ",
                        " g                                                              ",
                        "                                                                ",
                        "    Q                                       Q           D       ",
                        "                                                                ",
                        "    Q                                       Q                   ",
                        "                                                                ",
                        "    Q                                       Q                   ",
                        "                                                                ",
                        "    Q                                       Q                   ",
                        "                                                                ",
                        "    Q                                                           ",
                        "                                                  G             ",
                        "    Q                                                           ",
                        "        O                                                       ",
                        "    Q       E                                                   ",
                        "                                                                ",
                        "    Q                                           LWWWWWWWWWWWWWW ",
                        "                                                                ",
                        "    Q                                       Q                   ",
                        "                                                                ",
                        "    Q                                       Q                   ",
                        "                                   O                            ",
                        "    Q                                       Q   Q   Q   Q   Q   ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                "
                },
                
                {

                        "                     T                                          ",
                        "                     M                                          ",
                        "                     M                                          ",
                        "                     M                                          ",
                        "       O             M                                          ",
                        "                     M       D             O                    ",
                        "                     M                                          ",
                        "                     B                                      g   ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                            G    g                              ",
                        "                                                                ",
                        "                                                                ",
                        "                        LWWWWWWWWWWWWW                          ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "         O                                    O                 ",
                        "                                                                ",
                        "      G                                            E   g        ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                            T                   ",
                        "                                            M                   ",
                        "                                            M                   ",
                        "                                            M       O           ",
                        "    G              E                        M                   ",
                        "                                            B                   ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                "
                },
                
                {

                        "                                 Q                     T        ",
                        "                                 Q                     M        ",
                        "         G                       Q                     M        ",
                        "                                 Q                     M        ",
                        "                                 Q                     M        ",
                        "                                 Q                     M        ",
                        "                                 Q   E                 M        ",
                        "                                                       M        ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                 g                                              ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "LWWWWWWWW                                                       ",
                        "                                                                ",
                        "                                                       D        ",
                        "                                                                ",
                        "     G       g       G       g       G       g                  ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                ",
                        "                                                                "
                },
        };


vector<pair<pair<RectangleShape, int>, int> > platformObjects;
int buttonCnt = 10;

int gateCnt = 0, bridgeCnt = 0;
vector<pair<pair<RectangleShape, int>, int>> gatesObjects;
vector<pair<pair<RectangleShape, int>, int>> gemObjects;
vector<pair<Sprite, pair<int,int>>>pools;
vector<pair<Sprite, int>>fillings;
int buttonGateCnt = 0, buttonBridgeCnt = 0;
int gemCnt = 0;


vector<Sprite> boxes;
vector<pair<float,float>> boxesPositions;


void fillPlatformObjects()
{
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            
            if (levelsMap[level][i][j] == 'f' || levelsMap[level][i][j] == 'i' || levelsMap[level][i][j] == 'r' || levelsMap[level][i][j] == 'F')
            {
                RectangleShape obj({80,40});
                float posX = 40 + (80 * j), posY = 40 + (80 * i);
                obj.setPosition({posX, posY});

                if (levelsMap[level][i][j] == 'f')
                {
                    spriteLavaLeft.setPosition({posX, posY});
                    pools.push_back({spriteLavaLeft,{1,0}});
                }
                if (levelsMap[level][i][j] == 'i')
                {
                    spriteLavaMid.setPosition({posX, posY});
                    pools.push_back({spriteLavaMid,{1,1}});
                }
                if (levelsMap[level][i][j] == 'r')
                {
                    spriteLavaRight.setPosition({posX, posY});
                    pools.push_back({spriteLavaRight,{1,2}});
                }
                if (levelsMap[level][i][j] == 'F')
                {
                    spriteSmallLava.setPosition({posX, posY});
                   pools.push_back({spriteSmallLava,{1,3}});
                }
                platformObjects.push_back({ {obj, 1},0});
            }
            
            if (levelsMap[level][i][j] == 'w' || levelsMap[level][i][j] == 'a' || levelsMap[level][i][j] == 't' || levelsMap[level][i][j] == 'W')
            {
                RectangleShape obj({80,40});
                float posX = 40 + (80 * j), posY = 40 + (80 * i);
                obj.setPosition({posX, posY});

                if (levelsMap[level][i][j] == 'w')
                {
                    spriteWaterLeft.setPosition({posX, posY});
                    pools.push_back({spriteWaterLeft,{2,0}});
                }
                if (levelsMap[level][i][j] == 'a')
                {
                    spriteWaterMid.setPosition({posX, posY});
                    pools.push_back({spriteWaterMid,{2,1}});
                }
                if (levelsMap[level][i][j] == 't')
                {
                    spriteWaterRight.setPosition({posX, posY});
                    pools.push_back({spriteWaterRight,{2,2}});
                }
                if (levelsMap[level][i][j] == 'W')
                {
                    spriteSmallWater.setPosition({posX, posY});
                    pools.push_back({spriteSmallWater,{2,3}});
                }
                platformObjects.push_back({ {obj,2},0});
            }
            
            if (levelsMap[level][i][j] == 'm' || levelsMap[level][i][j] == 'u' || levelsMap[level][i][j] == 'd' || levelsMap[level][i][j] == 'A')
            {
                RectangleShape obj({80,40});
                float posX = 40 + (80 * j), posY = 40 + (80 * i);
                obj.setPosition({posX, posY});

                if (levelsMap[level][i][j] == 'm')
                {
                    spriteAcidLeft.setPosition({posX, posY});
                    pools.push_back({spriteAcidLeft,{3,0}});
                }
                if (levelsMap[level][i][j] == 'u')
                {
                    spriteAcidMid.setPosition({posX, posY});
                    pools.push_back({spriteAcidMid,{3,1}});
                }
                if (levelsMap[level][i][j] == 'd')
                {
                    spriteAcidRight.setPosition({posX, posY});
                    pools.push_back({spriteAcidRight,{3,2}});
                }
                if (levelsMap[level][i][j] == 'A')
                {
                    spriteSmallAcid.setPosition({posX, posY});
                    pools.push_back({spriteSmallAcid, {3,3}});
                }
                platformObjects.push_back({ {obj, 3},0});
            }
            
            if (levelsMap[level][i][j] == 'G' || levelsMap[level][i][j] == 'B')
            {
                RectangleShape obj;
                obj.setSize({80, 40});
                float posX = 40 + (80 * j), posY = 40 + (80 * i);
                obj.setPosition({posX, posY});
                if (levelsMap[level][i][j] == 'G')
                {
                    platformObjects.push_back({{obj, 4 },++buttonGateCnt});
                }
                else
                {
                    platformObjects.push_back({{obj, 5 },++buttonBridgeCnt});
                }
            }
        }
    }
    
    int streak = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (levelsMap[level][i][j] == 'L' || levelsMap[level][i][j] == 'M' || levelsMap[level][i][j] == 'R')
            {
                streak++;
            }
            else
            {
                if (streak)
                {
                    float start = (j - streak) * 80 + 40, end = start + (80 * streak);
                    RectangleShape obj({end - start - 5, 40});
                    obj.setPosition({start, (float)(40 + 80 * i)});
                    obj.setFillColor(color);
                    platformObjects.push_back({{ obj, 0 },0});
                    streak = 0;
                }
            }
        }
        if (streak)
        {
            float start = (15 - streak) * 80 + 40 + 80, end = start + (80 * streak);
            RectangleShape obj({end - start - 5, 40});
            obj.setPosition({start, (float)(40 + 80 * i)});
            obj.setFillColor(color);
            platformObjects.push_back({{obj, 0 },0});
            streak = 0;
        }
    }
}

void fillGateObjects()
{
    for (int i = 0; i < 36; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            RectangleShape obj({20,20});
            float posX = 40 + (20 * j), posY = 40 + (20 * i);
            obj.setPosition({posX, posY});

            if (objectsMap[level][i][j] == 'T')
            {
                ++gateCnt;
                obj.setTexture(&textureGateTop);
                gatesObjects.push_back({{obj, 0 },gateCnt});
            }
            else if (objectsMap[level][i][j] == 'M')
            {
                obj.setTexture(&textureGateMiddle);
                gatesObjects.push_back({{obj, 1},gateCnt});
            }
            else if (objectsMap[level][i][j] == 'B')
            {
                obj.setTexture(&textureGateBottom);
                gatesObjects.push_back({{obj, 2},gateCnt});
            }
            else if (objectsMap[level][i][j] == 'L')
            {
                ++bridgeCnt;
                obj.setTexture(&textureBridgeLeft);
                gatesObjects.push_back({{obj, 3},bridgeCnt});
            }
            else if (objectsMap[level][i][j] == 'W')
            {
                obj.setTexture(&textureBridgeMiddle);
                gatesObjects.push_back({{obj, 4 },bridgeCnt});
            }
            
            else if(objectsMap[level][i][j] == 'O')
            {
                posX = 40 + (20 * j), posY = 40 + (20 * i);
                spriteBox.setPosition(posX, posY);
                
                boxes.push_back(spriteBox);
                boxesPositions.push_back({posX,posY});
            }
            
            else if (objectsMap[level][i][j] == 'D')
            {
                spriteDoor.setPosition({posX, posY});
            }
            
            
            if (objectsMap[level][i][j] == 'E')
            {
                RectangleShape enemyObj({ 40,40 });
                enemyObj.setTexture(&enemyText);
                enemyObj.setPosition({ posX,posY });
                enemies.push_back({ enemyObj,{posX,posY} });
            }
            if (objectsMap[level][i][j] == 'Q')
            {
                RectangleShape obj5({ 80, 40 });
                posX = 40 + (20 * j), posY = 40 + (20 * i);
                obj5.setPosition({ posX, posY });
                if (sand)
                {
                    Sprite temp;
                    temp.setPosition({posX, posY});
                    fillings.push_back({temp,1});
                    obj5.setTexture(&sandFillingText);
                }
                else if(stone)
                {
                    Sprite temp;
                    temp.setPosition({posX, posY});
                    fillings.push_back({temp,0});
                    obj5.setTexture(&stoneFillingText);
                }
                gatesObjects.push_back({ {obj5, 6},-1 });
            }
        }
    }
}

void boxesRestart()
{
    for(int i = 0;i < boxes.size();++i)
    {
        boxes[i].setPosition(boxesPositions[i].first, boxesPositions[i].second);
    }
}

void fillGemObjects()
{
    for (int i = 0; i < 36; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            RectangleShape obj({40,40});
            float posX = 40 + (20 * j), posY = 40 + (20 * i);
            obj.setPosition({posX, posY});

            if (objectsMap[level][i][j] == 'G')
            {
                obj.setTexture(&textureBlueGem);
                gemObjects.push_back({{obj, 1}, ++gemCnt});
            }
            else if (objectsMap[level][i][j] == 'g')
            {
                obj.setTexture(&textureRedGem);
                gemObjects.push_back({{obj, 0}, ++gemCnt});
            }
        }
    }
}


int curPlatformObjectLevel = 100;

