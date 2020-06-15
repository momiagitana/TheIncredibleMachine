#pragma once
#include <string>

enum Menu_t
{
	M_BACKGROUND,
	M_EXIT_BUTTON,
	M_START_BUTTON
};

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

const float TIMESTEP = 1.0f / 60.0f;
const int VELITER = 10;
const int POSITER = 10;

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