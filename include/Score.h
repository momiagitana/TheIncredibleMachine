#pragma once
#include "globals.h"
#include "ResourceManager.h"
#include "baseImg.h"

class Score
{
public:
	Score(const int);
	void set(int score);
	int get() const;
	void draw(sf::RenderWindow& window) const;
	void setClock();

private:
	int m_score;
	std::vector<BaseImg> m_numbers;
	BaseImg m_background;
	sf::Clock m_clock;
	std::vector<float> m_sources;
};