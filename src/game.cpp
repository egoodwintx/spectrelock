//---------------------------------------------------------
// file: game.cpp
// project: SpectreLock
// author: Ed Goodwin
// date: 08.10.2024
// description:
//  Game Class
//---------------------------------------------------------
#include <iostream>
#include "game.h"

void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {
    this->vm = sf::VideoMode(800, 600, 64);
    this->window = new sf::RenderWindow(this->vm, 
        this->title, sf::Style::Default);
    this->window->setFramerateLimit(144);
}

void Game::initEnemies() {
    this->enemy.setPosition(sf::Vector2f(0.f,0.f));
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
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

void Game::updateMousePositions(){
    /*
    @ return void
    updates mouse positions
    */
   this->mousepositions = sf::Mouse::getPosition(*this->window);
}

void Game::update() {
    this->pollEvents();
    // relative to the screen
    //std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " "
    //    << sf::Mouse::getPosition().y << "\n";

    // relative to the window
    std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " "
        << sf::Mouse::getPosition(*this->window).y << "\n";
}

void Game::render() {
    this->window->clear(sf::Color::Black);

    //Draw game objects
    this->window->draw(this->enemy);

    // Display objects
    this->window->display();

}

void Game::display() {

}

Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}

Game::~Game() {
    delete this->window;
}

