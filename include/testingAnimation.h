#pragma once

#include "globals.h"


class TestingAnimation
{
public:

    TestingAnimation()
    {   
        getTextures();
        setTexture();
        m_direction = 1;
    
    }

    void setTexture()
    {
        m_sprite.setTexture(m_texture[2]);
        //conveyor - gets start point and size of current conveyor
        m_sprite.setTextureRect(sf::IntRect(LARGE_START,LARGE_SIZES));

        //for balloon starts off in the position (0,0) with whole balloon
        // m_sprite.setTextureRect(sf::IntRect(0,0,43,78));

        //for walls- can switch between horizontal and vertical accordingly just need to change the first argument
        //m_sprite.setTextureRect(sf::IntRect(HOR_PIPE_START,WALL_SIZES));

        //for balls
        // m_sprite.setTextureRect(sf::IntRect(BOWLING_START,BALL_SIZE));

    }

    void drawAnimation(sf::RenderWindow& window)
    {
        window.clear();
        updateSprite();
        window.draw(m_sprite);
        window.display();     
    }

    void getTextures()
    {
        std::string m_fileNames[AMOUNT_OF_TEXTURES] = {"/Users/zalmanrabin/Documents/oop/project/TheIncredibleMachine/resources/balloonPopping.png",
                                            "/Users/zalmanrabin/Documents/oop/project/TheIncredibleMachine/resources/balls.png",
                                            "/Users/zalmanrabin/Documents/oop/project/TheIncredibleMachine/resources/conveyor.png",
                                            "/Users/zalmanrabin/Documents/oop/project/TheIncredibleMachine/resources/flooringHorizontal.png",
                                            "/Users/zalmanrabin/Documents/oop/project/TheIncredibleMachine/resources/flooringVertical.png"};

        sf::Texture curr;

        for (auto i = 0; i < AMOUNT_OF_TEXTURES; i++)
        {
            curr.loadFromFile(m_fileNames[i]);

            m_texture.push_back(curr);

        }
    }
    

    void updateSprite()
    {
    	if(m_clock.restart().asSeconds() > 0.04)
			m_source.x += m_direction;

        // if(m_source.x<0)
        //     m_source.x +=7;
		
		if (m_source.x == 7)
			m_source.x = 0;     
 
        //conveyor
        sf::IntRect newRect(m_source.x*(LARGE_SIZES.x+SPACE_BETWEEN), LARGE_START.y, LARGE_SIZES.x , LARGE_SIZES.y); 
	   
        //for balloon
        //sf::IntRect newRect(BALLOON_SIZES[m_source.x][BALLON_X_START] , 0 , BALLOON_SIZES[m_source.x][BALLON_WIDTH] , 78 );
        
        //for walls i know we dont need animation its just to see that we have the right sizes
        //sf::IntRect newRect(m_source.x*(WALL_SIZES.y+2), HOR_PIPE_START.y , WALL_SIZES.x , WALL_SIZES.y);   
        //sf::IntRect newRect(VER_PIPE_START.x, m_source.y*(WALL_SIZES.x) , WALL_SIZES.x , WALL_SIZES.y); 

        //for balls     
        //sf::IntRect newRect(m_source.x*(BALL_SIZE.y) , BOWLING_START.x, BALL_SIZE.x , BALL_SIZE.y); 

        m_sprite.setTextureRect(newRect);

        m_clock.restart();
    }



private:


    sf::Sprite m_sprite;

    sf::Clock m_clock;

    sf::Vector2i m_source;

    int m_direction;

    bool m_attached;

    std::string m_fileNames[AMOUNT_OF_TEXTURES];

    std::vector<sf::Texture> m_texture;
    
};