//
//  map.hpp
//  PA-9-1
//
//  Created by will on 4/23/20.
//  Copyright © 2020 will. All rights reserved.
//

#ifndef map_h
#define map_h

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "GameEngine.h"
using namespace std;
class Map
{
private:
    struct border
    {
        sf::Vector2f location;
        sf::RectangleShape item;
    };
    struct mouse
    {
        sf::Vector2f location;
        sf::RectangleShape item;
    };
    struct border map[8][8];
    struct mouse obj;
public:
    Map();
    void moveObj(int);
    sf::RectangleShape getLocalposition()
    {
        return obj.item;
    } 
    
    sf::RectangleShape getMap(int n, int m)
    {
        return map[n][m].item;
    }
};

#endif /* map_h */
