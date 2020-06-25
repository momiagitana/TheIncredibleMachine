#pragma once


const int MENU_BUTTONS_INT_RECT [4][2]=  {{24, 23}, {22, 34}, {18, 31}, {110,28}};


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const unsigned obj_size = 40;


enum Type_t
{
	balloon,
	basketBall,
	baseBall,
	bowlingBall,
	conveyor,
	brickWall,
	play,
	worker,
	arrows,
	background,
	exitButton,
	startButton,
	reset,
	sound,
	choseLevel,
	none,
	rotateButton,
	resizeButton,

	balloonButton = 100,
	basketButton,
	baseButton,
	bowlingButton,
	conveyorButton,
	brickWallButton
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

const float DEG_TO_RAD = 0.0174533;

const int SCORE_TIME_H = 100;

const int PLAY_BUTTON_H = 50;
const int ARROWS_BUTTON_H = 50;

const int TB_W = 100;
const int TB_H = WINDOW_HEIGHT - SCORE_TIME_H - PLAY_BUTTON_H - ARROWS_BUTTON_H;
const int TB_TOP = PLAY_BUTTON_H + ARROWS_BUTTON_H;

const int TB_X = WINDOW_WIDTH - TB_W;
const int TB_OBJ_X = WINDOW_WIDTH - TB_W/2;

const int PLAY_Y = 0 + PLAY_BUTTON_H/2;
const int ARROWS_Y = PLAY_BUTTON_H + ARROWS_BUTTON_H/2;
const int BAR_Y = PLAY_BUTTON_H + ARROWS_BUTTON_H + TB_H/2;



const int BUTTONS_IN_PAGE = 6;
const int SPACING = 30;
const int BUTTON_OBJ_SIZE = (TB_H-(SPACING*(BUTTONS_IN_PAGE+1)))/BUTTONS_IN_PAGE;



const float PPM = 64.f;
const float MPP = 0.015625f;
