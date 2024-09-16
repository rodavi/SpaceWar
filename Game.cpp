#include "Game.hpp"
#include <iostream>

Game::Game():mWindow{sf::VideoMode(640, 480), "SFML Application"}
{
    mWindow.setFramerateLimit(60);
    mtextures.load(Textures::Airplane, "textures/spaceship-3.png");
    mtextures.load(Textures::Landscape, "textures/space-tile-black.jpg");
    mtextures.load(Textures::Enemy, "textures/ufo-1.png");
    //mtextures.load(Textures::Enemy, "textures/ufo-2.png");
    //if(!mTexture.loadFromFile("textures/spaceship-3.png")){std::cout<<"Texture failed to load!";}
    //mPlayer.setTextureRect(sf::IntRect(0, 0, 192.f/2, 384.f/4));
    playerPlane.scale(0.4, 0.4);
    playerPlane.setTexture(mtextures.get(Textures::Airplane));
    playerPlane.setPosition(100.f, 100.f);


}

void Game::run()
{
    while(mWindow.isOpen()){
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event)){
        switch(event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;

            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;
        } 
    }
}

void Game::update()
{
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp)
        movement.y -= 2.f;
    if (mIsMovingDown)
        movement.y += 2.f;
    if (mIsMovingLeft)
        movement.x -= 2.f;
    if (mIsMovingRight)
        movement.x += 2.f;

    playerPlane.move(movement);
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(playerPlane);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if(key == sf::Keyboard::W)
    {
        mIsMovingUp = isPressed;
    }
    else if(key == sf::Keyboard::S)
    {
        mIsMovingDown = isPressed;
    }
    else if(key == sf::Keyboard::A)
    {
        mIsMovingLeft = isPressed;
    }
    else if(key == sf::Keyboard::D)
    {
        mIsMovingRight = isPressed;
    }
}