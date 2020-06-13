#pragma once
#include <string>

// Enum for each object by his char representation.
enum Char_t
{
	
};

// Enum for each object in the project. 
enum Object_t
{
	
	
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
	
	TIME,
	SCORE,
	LEVEL
};

const unsigned NUM_OF_TEXTURE = 12;
const unsigned NUM_OF_BUTTONS = 2;
const unsigned WINDOW_HEIGHT = 600;
const unsigned WINDOW_WIDTH = 600;
const unsigned DATA_BAR_SPACE = 80;
const unsigned DIGGER_LIVES = 3;
const unsigned TOOLBAR_SPACE = 80;
const int MONSTER_SPEED = 80;
const int DIGGER_SPEED = 200;


const unsigned DIAMOND_X = 344;
const unsigned DIAMOND_Y = 300;
const unsigned DIAMOND_BORDER = 3;
const unsigned NUM_OF_TOOLBAR_INFO = 3;

const std::string FILE_NAME = "Board.txt";

const unsigned DIGGER_SIZE = 40;
const unsigned SPACE_BETWEEN_DIGGER = 8;
const unsigned DIGGER_BORDER = 10;

const unsigned TOOLBAR_OBJ_X = 530;

const unsigned FIRST_TOOLBAR_OBJ_Y = 120;
const unsigned SECOND_TOOLBAR_OBJ_Y = 200;
const unsigned THIRD_TOOLBAR_OBJ_Y = 280;

const unsigned obj_size = 40;

const int NUM_OF_TOOLBAR_OBJ = 7;

enum gameTexture
{
	T_OBJ_Basketball,
	T_OBJ_Bowling,
	T_OBJ_Arrows,
	T_OBJ_Propeties,
	T_OBJ_Worker,
	T_OBJ_Engine,
	T_OBJ_invalid
};


enum class figure
{
	Basketball,
	Bowling,
	Arrows,
	Propeties,
	Worker,
	Engine,
	invalid
};