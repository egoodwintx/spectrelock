//---------------------------------------------------------
// file: game.h
// project:  SpectreLock
// author: Ed Goodwin
// date: 08.10.2024
// description:
//  Game Class definition
//---------------------------------------------------------
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// wrapper class for Game Engine
class Game {
    private:
        //Variables
        //  Window
        sf::RenderWindow* window;
        sf::VideoMode vm;
        sf::Event ev;
        sf::String title = "Spectre Lock";

        // Game objects
        sf::RectangleShape enemy;
        
        void initVariables();
        void initWindow();
        void initEnemies();

    public:
        Game();
        virtual ~Game();

        //Accessors
        const bool running() const;      
        void update();
        void render();
        void display();
        void pollEvents();
};