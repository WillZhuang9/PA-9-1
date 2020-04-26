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
void showUIinGame(sf::RenderWindow *w)
{
    sf::Font font;
    font.loadFromFile("sansation.ttf");
    
    sf::Text text_1 ("Player - 1", font);
    text_1.setCharacterSize(15);
    text_1.setFillColor(sf::Color::Red);
    text_1.setPosition(60, 350);
    
    sf::Text text_2 ("Player - 2", font);
    text_2.setCharacterSize(15);
    text_2.setFillColor(sf::Color::Blue);
    text_2.setPosition(160, 350);
    
    sf::Text text_3 ("Mouse", font);
    text_3.setCharacterSize(15);
    text_3.setFillColor(sf::Color::Yellow);
    text_3.setPosition(260, 350);
    
    
    sf::RectangleShape square_r = setStandardItem(sf::Vector2f(40, 350), sf::Color::Red);
    sf::RectangleShape square_b = setStandardItem(sf::Vector2f(140, 350), sf::Color::Blue);
    sf::RectangleShape square_y = setStandardItem(sf::Vector2f(240, 350), sf::Color::Yellow);

    
    w->draw(text_1);
    w->draw(text_2);
    w->draw(text_3);
    
    w->draw(square_r);
    w->draw(square_b);
    w->draw(square_y);
}

