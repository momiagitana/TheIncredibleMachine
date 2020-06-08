#pragma once
#include <string>

// Enum for each object by his char representation.
enum Char_t
{
	C_SPACE = ' ',
	C_DIGGER = '/',
	C_MONSTER = '!',
	C_DIAMOND = 'D',
	C_STONE = '@',
	C_WALL = '#',
	C_GIFT = '+'
};

// Enum for each object in the project. 
enum Object_t
{
	O_DIGGER,
	O_SMART_MONSTER,
	O_DUMB_MONSTER,
	O_DIAMOND,
	O_STONE,
	O_WALL,
	O_EXTRA_TIME_GIFT,
	O_EXTRA_SCORE_GIFT,
	O_EXTRA_STONES_GIFT,
	O_LEVEL_BACKROUND,
	O_GAME_OVER,
	O_WIN,
	O_EMPTY
};

enum Menu_t
{
	M_BACKGROUND,
	M_EXIT_BUTTON,
	M_START_BUTTON
};

enum Direction_t
{
	RIGHT,
	LEFT,
	UP,
	DOWN,
	NONE
};
enum Toolbardata_t
{
	LIVES,
	TIME,
	SCORE,
	STONES_TO_EAT,
	LEVEL
};

const unsigned NUM_OF_TEXTURE = 12;
const unsigned NUM_OF_BUTTONS = 2;
const unsigned WINDOW_HEIGHT = 700;
const unsigned WINDOW_WIDTH = 1000;
const unsigned DATA_BAR_SPACE = 80;
const unsigned DIGGER_LIVES = 3;
const unsigned TOOLBAR_SPACE = 80;
const int MONSTER_SPEED = 80;
const int DIGGER_SPEED = 200;


const unsigned DIAMOND_X = 344;
const unsigned DIAMOND_Y = 300;
const unsigned DIAMOND_BORDER = 3;
const unsigned NUM_OF_TOOLBAR_INFO = 5;

const std::string FILE_NAME = "Board.txt";

const unsigned DIGGER_SIZE = 40;
const unsigned SPACE_BETWEEN_DIGGER = 8;
const unsigned DIGGER_BORDER = 10;
