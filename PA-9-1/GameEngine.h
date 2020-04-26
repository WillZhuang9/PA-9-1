//
//  GameEngine.hpp
//  PA-9-1
//
//  Created by will on 4/23/20.
//  Copyright © 2020 will. All rights reserved.
//

#ifndef GameEngine_h
#define GameEngine_h

#include<SFML/Graphics.hpp>

sf::RectangleShape setStandardItem(sf::Vector2f, sf::Color);
bool checkCollision(const sf::RectangleShape&, const sf:: RectangleShape&);
void showUIinGame(sf::RenderWindow*);

#endif /* GameEngine_hpp */
