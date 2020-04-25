//
//  GameEngine.cpp
//  PA-9-1
//
//  Created by will on 4/23/20.
//  Copyright © 2020 will. All rights reserved.
//
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "GameEngine.h"
sf::RectangleShape setStandardItem(sf::Vector2f location, sf::Color color)
{
    sf::RectangleShape item(sf::Vector2f (16, 16));
    item.setFillColor(color);
    item.setPosition(location);
    return item;
}
bool checkCollision(const sf::RectangleShape& shape_1, const sf:: RectangleShape& shape_2)
{
    if(shape_1.getPosition() == shape_2.getPosition())
        return true;
    return false;
}

