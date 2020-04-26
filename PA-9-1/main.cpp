
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//
#include"GameEngine.h"
#include"map.h"
#include"player.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include<string>
// Here is a small helper for you! Have a look.
int main()
{
    
    sf::RenderWindow window(sf::VideoMode(400, 400), "Checker C++");
    window.setFramerateLimit(15);
    
    sf::Font font;
    font.loadFromFile("sansation.ttf");
    
    sf::Text text ("", font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(20, 20);
    
    sf::Text text_1 ("", font);
    text_1.setCharacterSize(30);
    text_1.setFillColor(sf::Color::Yellow);
    text_1.setPosition(200, 20);
    

    Map gamemap;
    player checker_1(sf::Color::Red, gamemap, 1);
    player checker_2(sf::Color::Blue, gamemap, 2);
    
    sf::Vector2f pos_1;
    sf::Vector2f pos_2;
    
    sf::RectangleShape temp;
    
    int time = 0;
    int a = 0;
    int b = 0;
    
    int player_1 = 0;
    int player_2 = 0;
    
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        
        for (int n = 0; n< 8; n++)
            for(int m = 0; m<8; m++)
                window.draw(gamemap.getMap(n, m));
        
        for (int n = 0; n< 3; n++)
            for(int m = 0; m<4; m++)
            {
                window.draw(checker_1.getChecker(n, m));
                window.draw(checker_2.getChecker(n, m));
            }

        if (player_1 == 0)//confirm
            text.setString("Player - 1");
            
        if (player_1 == 1)
            text.setString("Player - 2");
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            text_1.setString("Loading...");
            while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            {
                window.draw(text_1);
                window.display();
            }
            text_1.setString(" ");
            if(time == 0)
            {
                pos_1 = gamemap.getLocalposition().getPosition();
                //time = 2;
                if (checker_1.Getposition(pos_1) || checker_2.Getposition(pos_1))
                {
                    time++;
                }
                else
                {
                    time = 0;
                }
            }
            
            else
                time++;
            
            
            
            if(time == 2)
            {
                pos_2 = gamemap.getLocalposition().getPosition();
                if(player_1 == 0) // red
                {
                    int x_c =(pos_1.x + pos_2.x) / 2;
                    int y_c =(pos_1.y + pos_2.y) / 2;
                    for (int n = 0; n < 3; n++)
                        for (int m = 0; m < 4; m++)
                            if (sf::Vector2f(x_c,y_c) == checker_2.getChecker(n, m).getPosition())
                            {
                                temp = checker_2.getChecker(n,m);
                            }
                    
                    int status = 0;
                    if (checker_1.Getposition(pos_2)||(checker_2.Getposition(pos_2)))
                        status = 1;
                    if (status == 0)
                    {
                         
                        if (a == 2)
                        {
                            a = checker_1.moveObj(pos_1, pos_2, 1, temp);
                            if (a == 0)
                            {
                                a = checker_1.moveObj(pos_2, pos_1, 1,temp);
                                time = 2, player_1 = 1;
                                a = 2;
                            }
                            
                            else if (a == 1)
                                {
                                    checker_2.moveToTrash(temp.getPosition());
                                    time = 2, player_1 = 0;
                                    a = 2;
                                }
                        }
                        else
                        {
                            a = checker_1.moveObj(pos_1, pos_2, 1, temp);//move the obj
                            player_1 = 1;
                            if(a == 1)
                            {
                                checker_2.moveToTrash(temp.getPosition());
                                time = 2, player_1 = 0;
                                a = 2;
                            }
                            if(a == -1)
                            {
                                time = 2, player_1 = 1, player_2 = 1;
                                a = 0;
                            }
                        }
                    }
                    else
                    {
                        player_1 = 0;
                        time = 2;
                    }
                   // break;
                }
                else if (player_1 == 1) // blue
                {
                    int x_c =(pos_1.x + pos_2.x) / 2;
                    int y_c =(pos_1.y + pos_2.y) / 2;
                    for (int n = 0; n < 3; n++)
                        for (int m = 0; m < 4; m++)
                            if (sf::Vector2f(x_c,y_c) == checker_1.getChecker(n, m).getPosition())
                            {
                                temp = checker_1.getChecker(n,m);
                            }
                    int status = 0;
                    if (checker_1.Getposition(pos_2) || checker_2.Getposition(pos_2))
                        status = 1;
                    if (status == 0)
                    {
                        
                        if(b == 2)
                        {
                            b = checker_2.moveObj(pos_1, pos_2, 2, temp);
                            if(b == 0)
                            {
                                b = checker_2.moveObj(pos_2, pos_1, 2, temp);
                                time = 2, player_2 = 1;
                                b = 2;
                            }
                            else if(b == 1)
                            {
                                checker_1.moveToTrash(temp.getPosition());
                                time = 2, player_2 = 0;
                                b = 2;
                            }
                        }
                        else
                        {
                            b = checker_2.moveObj(pos_1, pos_2, 2, temp);
                            player_2 = 1;
                            if(b == 1)
                            {
                                checker_1.moveToTrash(temp.getPosition());
                                time = 2, player_2 = 0;
                                b = 2;
                            }
                            if (b == -1)
                            {
                                time = 2, player_1 = 2, player_2 = 1;
                                b = 0;
                            }
                        }

                    }
                    else
                    {
                        player_2 = 0;
                        time = 2;
                    }
                }
                time++;
            }
            
            if(time == 3)
            {
                
                if(player_1 == 2 && player_2 == 1)
                {
                    player_1 = 1, player_2 = 0;
                }
                if(player_1 == player_2 == 1)
                {
                    player_1 = 0, player_2 = 0;
                }
                
//                else
//                    if(player_1 == 1 && player_2 == 0)
//                        player_1 = 1, player_2 = 1;
//                    else if (player_2 == 1)
//                        player_2 = 0;
                time = 0;
            }
        }
        else
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                gamemap.moveObj(1);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                gamemap.moveObj(2);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                gamemap.moveObj(3);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                gamemap.moveObj(4);
            window.draw(gamemap.getLocalposition());
            window.draw(text);
            window.draw(text_1);
        }
        window.draw(gamemap.getLocalposition());
        showUIinGame(&window);
                //window.draw(playe);
        //while(player.)
        window.display();
    }
    return 0;
}
