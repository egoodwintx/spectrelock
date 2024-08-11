//---------------------------------------------------------
// file: game.cpp
// project: SpectreLock
// author: Ed Goodwin
// date: 08.10.2024
// description:
//  Game Class
//---------------------------------------------------------
#include "game.h"

void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {
    this->vm = sf::VideoMode(800, 600, 64);
    this->window = new sf::RenderWindow(this->vm, 
        this->title, sf::Style::Default);
}

const bool Game::running() const {
    return this->window->isOpen();
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type){
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                break;
        }
    }   
}

void Game::update() {
    this->pollEvents();
}

void Game::render() {
    this->window->clear(sf::Color::Black);

    //Draw game objects
    this->window->display();
}

void Game::display() {

}

Game::Game() {
    this->initVariables();
    this->initWindow();
}

Game::~Game() {
    delete this->window;
}

