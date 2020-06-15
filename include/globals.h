#pragma once
#include <string>

enum Menu_t
{
	M_BACKGROUND,
	M_EXIT_BUTTON,
	M_START_BUTTON
};


enum Toolbardata_t
{
	TIME,
	SCORE,
	LEVEL
};

const std::string FILE_NAME = "Board.txt";

const unsigned TOOLBAR_OBJ_X = 530;

const unsigned FIRST_TOOLBAR_OBJ_Y = 120;
const unsigned SECOND_TOOLBAR_OBJ_Y = 200;
const unsigned THIRD_TOOLBAR_OBJ_Y = 280;


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const unsigned obj_size = 40;


enum GameObject_t
{
	balloon,
	basketBall,
	baseBall,
	bowlingBall,
	conveyor,
	flooringHorizontal,
	flooringVertical,
	play,
	none

};

const float TIMESTEP = 1.0f / 60.0f;
const int VELITER = 10;
const int POSITER = 10;


const bool DYNAMIC = true;
const bool STATIC = false;
const bool MOVABLE = true;
const bool UNMOVABLE = false;

const int FLOORING_UNIT = 16; //pixels
const int FLOORING_MARGIN = 1; //pix