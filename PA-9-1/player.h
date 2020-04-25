//
//  player.hpp
//  PA-9-1
//
//  Created by will on 4/23/20.
//  Copyright © 2020 will. All rights reserved.
//

#ifndef player_h
#define player_h

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
using namespace std;
#include "GameEngine.h"
#include "map.h"

class player
{
private:
    struct chess
    {
        sf::Color color;
        sf::Vector2f location;
        sf::RectangleShape item;
    };
    int num = 12;
    chess checker[3][4];
public:
    player(sf::Color, Map, int);
    sf::RectangleShape getChecker(int n, int m)
    {
        return checker[n][m].item;
    }
    //sf::Vector2f getLocalposition(Map gamemap);
    int moveObj(sf::Vector2f, sf::Vector2f, int, sf::RectangleShape);
    bool Getposition(sf::Vector2f);
    void moveToTrash(sf::Vector2f);
    int returnnum()
    {
        return num;
    }
};

#endif /* player_hpp */
