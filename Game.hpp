#include "SFML/Graphics.hpp"
#include "ResourceHolder.hpp"

class Game{
    public:
                Game();
        void    run();

    private:

        void    processEvents();
        void    update();
        void    render();
        void    handlePlayerInput(sf::Keyboard::Key, bool);
        
    private:

        ResourceHolder<sf::Texture, Textures::ID> mtextures;
        //TextureHolder mtextures;  
        sf::Sprite          playerPlane;

        sf::RenderWindow    mWindow;

        //sf::Texture         mTexture;
        //sf::Sprite          mPlayer;

        bool                mIsMovingUp{false};
        bool                mIsMovingDown{false};
        bool                mIsMovingRight{false};
        bool                mIsMovingLeft{false};
};