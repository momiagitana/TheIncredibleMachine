#pragma once

enum Menu_t
{
	exitButton,
	startButton,
	resetButton,
	soundButton
};

const int MENU_BUTTONS_INT_RECT [4][2]=  {{24, 23}, {22, 34}, {18, 31}, {110,28}};

enum Toolbardata_t
{
	TIME,
	SCORE,
	LEVEL
};

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
	brickWallH,
	brickWallV,
	play,
	worker,
	arrows,
	background,
	exit_button,
	start_button,
	reset,
	sound,
	none
};


const float TIMESTEP = 1.0f / 60.0f;
const int VELITER = 10;
const int POSITER = 10;

const int NUM_DIFF = 10;


const bool DYNAMIC = true;
const bool STATIC = false;
const bool MOVABLE = true;
const bool UNMOVABLE = false;

const int FLOORING_UNIT = 16; //pixels
const int FLOORING_MARGIN = 1; //pix


const char READ_NEXT [1] = {'-'};

const float RAD_45 = 0.785398f;


