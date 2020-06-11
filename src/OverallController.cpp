#include "OverallController.h"


OverallController::OverallController() :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IncredibleMachine")
{
	loadTextures();
	//m_menu.settexturs(m_menuTextures,m_font, m_window);
	//m_levelManager.readLevels();
	//m_levelManager.setTexts(m_font);
}

void OverallController::run()
{
	while (m_window.isOpen()) {
		//m_menu.runstart(m_window);

		m_levelController.start(m_window, m_gameTextures);


	}
}

void OverallController::loadTextures()
{
	/*m_gameTextures.resize(NUM_OF_TEXTURE);
	m_gameTextures[O_DIGGER].loadFromFile("digger.png");
	m_gameTextures[O_DUMB_MONSTER].loadFromFile("dumbMonster.png");
	m_gameTextures[O_SMART_MONSTER].loadFromFile("smartMonster.png");
	m_gameTextures[O_DIAMOND].loadFromFile("diamond.png");
	m_gameTextures[O_STONE].loadFromFile("stone.png");
	m_gameTextures[O_WALL].loadFromFile("wall.png");
	m_gameTextures[O_EXTRA_TIME_GIFT].loadFromFile("extraTime.png");
	m_gameTextures[O_EXTRA_SCORE_GIFT].loadFromFile("extraScore.png");
	m_gameTextures[O_EXTRA_STONES_GIFT].loadFromFile("extraStones.png");
	m_gameTextures[O_LEVEL_BACKROUND].loadFromFile("levelBackground.png");
	m_gameTextures[O_GAME_OVER].loadFromFile("gameOver.png");
	m_gameTextures[O_WIN].loadFromFile("win.png");

	m_menuTextures.resize(NUM_OF_BUTTONS + 1);
	m_menuTextures[M_BACKGROUND].loadFromFile("menu.png");
	m_menuTextures[M_EXIT_BUTTON].loadFromFile("exitButton.png");
	m_menuTextures[M_START_BUTTON].loadFromFile("startButton.png");*/

	m_font.loadFromFile("C:/Windows/Fonts/cambriab.ttf");
}


