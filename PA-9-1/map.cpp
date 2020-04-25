//
//  map.cpp
//  PA-9-1
//
//  Created by will on 4/23/20.
//  Copyright © 2020 will. All rights reserved.
//
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
#include "map.h"
#include "GameEngine.h"
Map::Map()
{
        // set the border outsider in the left
    for(int y = 0, i = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
        {
            map[x][y].location = sf::Vector2f(75 + 32 * x, 75 + 32 * y);
            map[x][y].item = setStandardItem(sf::Vector2f( 75 + 32 * x, 75 + 32 * y), sf::Color::White);
        }
    }
    // set mouse
    obj.location = map[4][4].location;
    obj.item = setStandardItem(obj.location,  sf::Color::Yellow);
}

void Map::moveObj(int direction)
{
    sf::Vector2f coordinator = obj.item.getPosition();
   if(direction == 1)
   {
        coordinator.y -= 32;
        if (coordinator.y > 299 || coordinator.y < 75)
            coordinator.y += 32;
        obj.location = coordinator;
        obj.item.setPosition(coordinator.x, coordinator.y);
   }
    if(direction == 2)
    {
        coordinator.y += 32;
        if (coordinator.y > 299 || coordinator.y < 75)
            coordinator.y -= 32;
        obj.location = coordinator;
        obj.item.setPosition(coordinator.x, coordinator.y);
    }
    if(direction == 3)
    {
        coordinator.x -= 32;
        if (coordinator.x > 299 || coordinator.x < 75)
            coordinator.x += 32;
        obj.location = coordinator;
        obj.item.setPosition(coordinator.x, coordinator.y);

    }
    if(direction == 4)
    {
        coordinator.x += 32;
        if (coordinator.x > 299 || coordinator.x < 75)
            coordinator.x -= 32;
        obj.location = coordinator;
        obj.item.setPosition(coordinator.x, coordinator.y);
    }
}

