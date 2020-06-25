#pragma once
#include <SFML/Graphics.hpp>

const int MENU_BUTTONS_INT_RECT [4][2]=  {{24, 23}, {22, 34}, {18, 31}, {110,28}};
const int MENU_BUTTONS_LOC [4][2] = {{260, 250}, {200, 250}, {150,250}, {150, 200}};



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
	arrowRButton,
	arrowLButton,
	menuBackground,
	frame,

	//menu buttons
	exitButton,
	startButton,
	reset,
	sound,
	choseLevel,
	//----
	none,
	rotateButton,
	resizeButton,

	msgRublic,
	msgRepley,
	msgAdvance,

	balloonButton = 100,
	basketButton,
	baseButton,
	bowlingButton,
	conveyorButton,
	brickWallButton,

};

struct ObjInfo
{
	Type_t _typ;
	sf::Vector2f _loc;
	int _angle = -1;
	int _size = -1;
};

const float TIMESTEP = 1.0f / 60.0f;
const int VELITER = 10;
const int POSITER = 10;

const int NUM_DIFF = 10;


const bool DYNAMIC = true;
const bool STATIC = false;
const bool MOVABLE = true;
const bool UNMOVABLE = false;



const char READ_NEXT [1] = {'-'};

const float DEG_TO_RAD = 0.0174533;



//images
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 450;

const int FLOORING_UNIT = 16; //pixels
const int FLOORING_MARGIN = 1; //pix

const int FRAME_SIZE = 8;
const int SCORE_TIME_H = 60;

const int FRAME_X = WINDOW_WIDTH/2;
const int FRAME_Y = (WINDOW_HEIGHT-SCORE_TIME_H)/2;

const int PLAY_BUTTON_H = 50;
const int ARROWS_H = 20;

const int TB_W = 56;
const int TB_H = WINDOW_HEIGHT - SCORE_TIME_H - PLAY_BUTTON_H - ARROWS_H-60;//frames
const int TB_TOP = 100;//PLAYH+ARRH+3FRAMES~

const int TB_X = WINDOW_WIDTH - FRAME_SIZE - TB_W; //topleft
const int TB_OBJ_X = WINDOW_WIDTH - FRAME_SIZE- TB_W/2;

const int PLAY_Y = FRAME_SIZE + PLAY_BUTTON_H/2;
const int ARROWS_Y = PLAY_BUTTON_H + 2*FRAME_SIZE + ARROWS_H/2;
const int ARROWS_W = TB_W/2;
const int L_ARR_X = TB_OBJ_X - ARROWS_W/2;
const int R_ARR_X = TB_OBJ_X + ARROWS_W/2;

const int BAR_Y = PLAY_BUTTON_H + ARROWS_H + TB_H/2;

const float BUTTON_SCALE = .9f;






//fix 
const int puzzleCompleteX = 400;
const int puzzleCompleteY = 300;
const int puzzleCompleteSIZE = 250;
const int replayLevelRexuestX = 350;
const int replayLevelRexuestY = 350;
const int advanceRequestX = 460;
const int advanceRequestY = 350;



const int BUTTONS_IN_PAGE = 5;
const int SPACING = 25;
const int BUTTON_OBJ_SIZE = (TB_H-(SPACING*(BUTTONS_IN_PAGE+1)))/BUTTONS_IN_PAGE;



const float PPM = 64.f;
const float MPP = 0.015625f;
