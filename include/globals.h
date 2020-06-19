#pragma once

enum Menu_t
{
	M_EXIT_BUTTON,
	M_START_BUTTON,
	M_RESET,
	M_VOL_DOWN,
	M_VOL_UP,
	M_SOUND
};

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
	vol_down,
	vol_up,
	sound,
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


const char READ_NEXT [1] = {'-'};

const float RAD_45 = 0.785398f;
