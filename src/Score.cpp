#include "..\include\Score.h"
#include <iostream>
using std::cout;
int speed = 20;



Score::Score(const int)
	:m_score(9999),m_background(sf::Vector2f(SC_X,SC_Y),Type_t::score)
{
	for (int i = 0; i < NUM_OF_NUMBERS_TEX; i++)
	{
		m_numbers.emplace_back(BaseImg(sf::Vector2f(SC_N_INITIAL +(SC_N_W+SC_SEP)*i ,WINDOW_HEIGHT+50),Type_t::numbers));  //alloc baseimg
		m_numbers.at(i).setTextureRect(sf::IntRect(SC_INS_RECT_X, SC_INS_RECT_Y, SC_N_W, SC_N_W*2));     //slice a rectangle
	}
	m_clock.restart();
}

void Score::set(int score)
{
	m_score = score;
}

int Score::get() const
{
	return m_score;
}


void Score::draw(sf::RenderWindow& window) const
{
	m_background.draw(window);
	for (auto & number : m_numbers)
	{
		number.draw(window);
	}
}


void Score::setClock()
{	
	
	int spped = 40;

	for (auto& i : m_numbers)
	{
		i.setTextureRect(sf::IntRect(0,160- m_clock.getElapsedTime().asSeconds()*spped, SC_N_W, SC_N_W * 2));
	}

	if (m_numbers.at(m_numbers.size() - 1).getTextureRect().top == 0)
	{
		m_numbers.at(m_numbers.size() - 1).setTextureRect(sf::IntRect(0,160, SC_N_W, SC_N_W * 2));
		m_clock.restart();

	}

	

}
