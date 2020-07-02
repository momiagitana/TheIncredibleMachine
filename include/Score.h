#pragma once
#include "globals.h"
#include "baseImg.h"

class Score
{
public:
	Score(const int);
	void set(int);
	int get() const;
	void play();
	void stop();
	void draw(sf::RenderWindow&);
	void updateClock();

private:
	int m_score;
	std::vector<BaseImg> m_numbers;
	BaseImg m_background;
	sf::Clock m_clock;
	std::vector<float> m_sources;
	bool m_play = false;
};