#pragma once
#include <SFML/Graphics.hpp>

const int MENU_BUTTONS_INT_RECT[5][2] = { {24,23}, {21, 35}, {18, 31}, {110,28},{30,30} };
const int MENU_BUTTONS_LOC[5][2] = { {210, 200}, {150, 200}, {100,200}, {200, 150}, {100,150} };

const int CHOSE_LEVEL_BUTTONS_INT_RECT[3][2] = { {48, 18}, {21, 15}, {21, 16} };
const int CHOSE_LEVEL_BUTTONS_LOC[3][2] = { {200, 150}, {140, 145}, {141,165} };

const int TOOLBAR_BUTTONS_LOC[2][2] = { {21, 15}, {21,16}};

const unsigned obj_size = 40;//fix check if needed

const int DELTA_ENGINE_CONECT[2][2] = {{13,-3}, {13,0}}; //1 mouse engine, fix change name, 2conveyor

const int NUM_OF_OBJECTS = 8; // update when adding an object 

enum Type_t
{
	//objects
	balloon,
	basketBall,
	baseBall,
	bowlingBall,
	conveyor,
	brickWall,
	mouseEngine,
	trampoline,
	belt,
	//---------

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
	endMenuButtons,
	//-----------

	//chose level menu
	choseLevelMenu,
	playButton,
	upButton,
	downButton,
	endChoseLevelButtons,

	//----------------
	none,
	rotateButton,
	resizeButton,

	puzzleComplete,
	replayButton,
	advanceButton,
	onePixel,

	up,
	down,

	connectButton,

	balloonButton = 100,
	basketButton,
	baseButton,
	bowlingButton,
	conveyorButton,
	brickWallButton,
	mouseEngineButton,
	trampolineButton,
	beltButton


};

struct ObjInfo
{
	Type_t _typ;
	sf::Vector2f _loc;
	int _angle = -1;
	int _size = -1;
	int _fliped = -1; // -1 not intersting, 0 regular , 1 filped
};

const struct ObjInfo wallInitTransforms = {brickWall, sf::Vector2f(0.f,0.f), 0, 1, -1};// fix check if everyone starts like this and then no need


struct PhysicsInfo
{
	bool _shape;
	float _friction;
	float _restitution;
	float _density;
};

 const bool CIRCLE = true;
 const bool RECT = false;


 const PhysicsInfo physicsInfo[NUM_OF_OBJECTS] = {{CIRCLE, 0.1f, 0.4f, 0.7f},    //balloon
                                                  {CIRCLE, 0.5f, 0.775f, 0.2f},  //basketBall
                                                  {CIRCLE, 0.8f, 0.4f, 0.25f},  	 //baseBall
                                                  {CIRCLE, 0.1f, 0.1f, 0.7f},    //bowlingBall
                                                  {RECT,   0.5f, 0.4f, 0.7f},    //conveyor
                                                  {RECT,   0.5f, 0.4f, 0.7f},   //brickWall
												  {RECT,   0.5f, 0.4f, 0.7f},   //mouseEngine
												  {RECT,   0.5f, 0.4f, 0.7f}};   //trampoline

	// m_fixtureDef.friction = 1;
    // m_fixtureDef.restitution = 0.4f;
    // m_fixtureDef.density = 0.7f;


const float TIMESTEP = 1.0f / 60.0f;
const int VELITER = 10;
const int POSITER = 10;

const int NUM_DIFF = 10;


const bool DYNAMIC = true;
const bool STATIC = false;
const bool MOVABLE = true;
const bool UNMOVABLE = false;

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

const int MENU_X = (WINDOW_WIDTH - (TB_W + FRAME_SIZE*2)) /2;
const int MENU_Y = (WINDOW_HEIGHT - SCORE_TIME_H - FRAME_SIZE) / 2;


const float BOARD_W = 560;
const float BOARD_H = 352;
const float TINY_BOARD_W = 263;
const float TINY_BOARD_H = 166;

const float BOARDS_RATIO_X = TINY_BOARD_W / BOARD_W ;
const float BOARDS_RATIO_Y = TINY_BOARD_H / BOARD_H ;


//fix 
const int PUZZLE_COMPLETE_X = 400;
const int PUZZLE_COMPLETE_Y = 300;
const int REPLAY_BUTTON_X = 350;
const int REPLAY_BUTTON_Y = 350;
const int ADVANCE_BUTTON_X = 460;
const int ADVANCE_BUTTON_Y = 350;



const int BUTTONS_IN_PAGE = 5;
const int SPACING = 25;
const int BUTTON_OBJ_SIZE = (TB_H-(SPACING*(BUTTONS_IN_PAGE+1)))/BUTTONS_IN_PAGE;


const float PPM = 64.f;
const float MPP = 0.015625f;

const unsigned CHARATER_SIZE = 13;
const float CHARATER_OUTLINE_THICKNESS = 0.20; 

const sf::Vector2f LEVEL_GOAL_TEXT_LOC{ 70,270 };

const sf::Vector2f LEVEL_NO_TEXT_LOC_MENU{ 95,36 };
const sf::Vector2f LEVEL_NAME_TEXT_LOC_MENU{ 200,36 };

const sf::Vector2f LEVEL_NO_TEXT_LOC_CHOSE_LEVEL{ 125,85.5 };
const sf::Vector2f LEVEL_NAME_TEXT_LOC_CHOSE_LEVEL{ 100,204 };


