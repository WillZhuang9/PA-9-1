//
//  player.cpp
//  PA-9-1
//
//  Created by will on 4/23/20.
//  Copyright © 2020 will. All rights reserved.
//

#include "player.h"
player::player(sf::Color color, Map map, int pos)
{
    if(pos == 1)
    {
        // for line 1
        for (int i = 0; i <4; i++)
        {
            checker[0][i].color = color;
            checker[0][i].item = map.getMap(0 + 2*i + 1, 0);
            checker[0][i].item.setFillColor(color);
        }
        // for line 2
        for (int i = 0; i <4; i++)
        {
            checker[1][i].color = color;
            checker[1][i].item = map.getMap(0 + 2*i, 1);
            checker[1][i].item.setFillColor(color);
        }
        // for line 3
        for (int i = 0; i <4; i++)
        {
            checker[2][i].color = color;
            checker[2][i].item = map.getMap(0 + 2*i + 1, 2);
            checker[2][i].item.setFillColor(color);
        }
    }
    if(pos == 2)
    {
        for (int i = 0; i <4; i++)
               {
                   checker[0][i].color = color;
                   checker[0][i].item = map.getMap(0 + 2*i, 5);
                   checker[0][i].item.setFillColor(color);
               }
               // for line 2
               for (int i = 0; i <4; i++)
               {
                   checker[1][i].color = color;
                   checker[1][i].item = map.getMap(0 + 2*i + 1, 6);
                   checker[1][i].item.setFillColor(color);
               }
               // for line 3
               for (int i = 0; i <4; i++)
               {
                   checker[2][i].color = color;
                   checker[2][i].item = map.getMap(0 + 2*i, 7);
                   checker[2][i].item.setFillColor(color);
               }
    }
}

void player::moveToTrash(sf::Vector2f pos)
{
    for (int n = 0; n< 3; n++)
    for(int m = 0; m<4; m++)
    {
        if(checker[n][m].item.getPosition()== pos)
        {
            checker[n][m].item.setPosition(400, 400);
            num -= 1;
        }
    }
}

bool player::Getposition(sf::Vector2f choosePosition)
{
    bool exist = false;
    for (int n = 0; n< 3; n++)
        for(int m = 0; m<4; m++)
        {
            if(checker[n][m].item.getPosition()== choosePosition)
                exist = true;
        }
    return exist;
}

int player::moveObj(sf::Vector2f pos, sf::Vector2f loc, int player, sf::RectangleShape other)
{
    for(int n = 0;n < 3; n++)
    {
        for (int m = 0; m < 4; m++)
        {
            if(checker[n][m].item.getPosition() == pos)
            {
                
                    
                if (fabs(loc.x - checker[n][m].item.getPosition().x) == 32 && fabs(loc.y - checker[n][m].item.getPosition().y) == 32)
                {
                    checker[n][m].location = loc;
                    checker[n][m].item.setPosition(checker[n][m].location);
                    return 0;
                }
                
                else if (fabs(loc.x - checker[n][m].item.getPosition().x) == 64 && fabs(loc.y - checker[n][m].item.getPosition().y) == 64 )
                {
                    if (other.getFillColor() != checker[n][m].color )
                    {
                        if (player == 1)
                        {
                            //if (bool operator != () )
                            sf::Color color = other.getFillColor();
                            if( color == sf::Color::Blue)
                            {
                                checker[n][m].location = loc;
                                checker[n][m].item.setPosition(checker[n][m].location);
                                return 1;
                            }
                        }
                    }
                    if (other.getFillColor() != checker[n][m].color && other.getFillColor() == sf::Color::Red && player == 2)
                    {
                        checker[n][m].location = loc;
                        checker[n][m].item.setPosition(checker[n][m].location);
                        return 1;
                    }
                }
            }
        }
    }
    return -1;
}
