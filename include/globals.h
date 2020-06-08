#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Vector2i SMALL_SIZES(32,16);
const sf::Vector2i SMALL_START(0,0);

const sf::Vector2i MEDIUM_SIZES(48,18);
const sf::Vector2i MEDIUM_START(0,18);

const sf::Vector2i LARGE_SIZES(64,19);
const sf::Vector2i LARGE_START(0,35);

const sf::Vector2i X_LARGE_SIZES(80,19);
const sf::Vector2i X_LARGE_START(0,53);

const sf::Vector2i XX_LARGE_SIZES(96,19);
const sf::Vector2i XX_LARGE_START(0,72);

const int BALLOON_SIZES[7][2] = {{0,50},{50,90},{133,95},{237,107},{344,107},{451,104},{555,95}}; 
const int BALLON_X_START = 0;
const int BALLON_WIDTH   = 1;

const int SPACE_BETWEEN = 2;

const sf::Vector2i WALL_SIZES(18,17);//index 0 for height index 1 for width

const sf::Vector2i VER_GOLD_START(19,0);
const sf::Vector2i VER_RED_START(0,0);
const sf::Vector2i VER_SAND_START(38,0);
const sf::Vector2i VER_PIPE_START(61,0);

const sf::Vector2i HOR_GOLD_START(0,21);
const sf::Vector2i HOR_RED_START(0,0);
const sf::Vector2i HOR_WORM_START(0,40);
const sf::Vector2i HOR_PIPE_START(0,60);

const sf::Vector2i BALL_SIZE(42,50);
const sf::Vector2i BOWLING_START(0,0);
const sf::Vector2i BASKETBALL_START(50,0);
const sf::Vector2i BASEBALL_START(100,0);

const int AMOUNT_OF_TEXTURES = 5;


