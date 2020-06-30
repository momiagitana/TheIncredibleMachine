#include "Score.h"
#include <iostream>
using std::cout;
int speed = 20;



Score::Score(const int)
	:m_score(9999), m_background(sf::Vector2f(SC_X, SC_Y), Type_t::score)
{
	for (int i = NUM_OF_NUMBERS_TEX - 1; i >= 0; i--)
	{
		BaseImg number(sf::Vector2f(0, 0), Type_t::numbers);
		number.setTextureRect(sf::IntRect(SC_INS_RECT_X, SC_INS_RECT_Y, SC_N_W, INT_RECT_H));
		number.setOrigin(number.getGlobalBounds().width / 2, number.getGlobalBounds().height / 2);
		number.setPosition(sf::Vector2f(SC_N_INITIAL + (SC_N_W + SC_SEP) * i, SC_Y + NUM_DELTA_Y_FROM_SCORE));
		m_numbers.push_back(number);

		m_sources.push_back(float(0));
	}
	m_clock.restart();
}

void Score::set(int score)
{
	m_score = score;

	int temp;

	for (int i = NUM_OF_NUMBERS_TEX - 1; i >= 0; i--)
	{
		temp = score % 10;
		score = score * 0.1;
		m_numbers.at(i).setTextureRect(sf::IntRect(SC_INS_RECT_X, temp * 21, SC_N_W, SC_N_W * 2));     //slice a rectangle
	}
}

int Score::get() const
{
	int numberTop = 0;
	int found = 0;
	int pSum = 0;
	int mod = 0;
	int power = 0;


	for (auto number = NUM_OF_NUMBERS_TEX - 1; number != -1; number--)
	{
		numberTop = m_numbers.at(number).getTextureRect().top;

		for (int top = 0; top < SCORE_PIX_LOC_SIZE - 1; top++)
		{
			if (numberTop >= SCORE_PIX_LOC[0][top] && numberTop < SCORE_PIX_LOC[0][top + 1])
			{
				found = top;
				found++;
				break;
			}
		}

		mod = (pow(10, power));
		power++;
		found *= mod;
		found += pSum;
		pSum = found;
	}

	return pSum;
}

void Score::play()
{
	m_play = true;
}

void Score::stop()
{
	m_play = false;
}

void Score::draw(sf::RenderWindow& window)
{
	m_background.draw(window);

	if (m_play)
		updateClock();

	for (auto& number : m_numbers)
	{
		number.draw(window);
	}
}


void Score::updateClock()
{

	float mult = 0.1f;

	static auto delta = m_clock.getElapsedTime().asSeconds();
	m_clock.restart();



	for (int i = 0; i < m_numbers.size(); i++)
	{
		sf::IntRect newRect(m_numbers[i].getTextureRect());
		m_sources[i] += delta * (mult);
		if (m_sources[i] >= 1)
		{
			newRect.top -= 1;
			m_sources[i] = 0;
		}

		m_numbers[i].setTextureRect(newRect);
		mult = mult / 10.f;

		if (m_numbers[i].getTextureRect().top == 0)
			m_numbers[i].setTextureRect(sf::IntRect(SC_INS_RECT_X, 210, SC_N_W, INT_RECT_H));

	}


}
