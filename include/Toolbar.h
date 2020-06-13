#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include "BaseObject.h"
#include "Globals.h"
#include <string>
#include <sstream>
using std::ostringstream;

class Toolbar
{
public:
	Toolbar(double windowsizeX, double windowsizeY);
	void setButton(figure button, int num,std::shared_ptr<BaseObject> obj);
	figure toolbarclick(sf::Vector2f loc);
	void draw(sf::RenderWindow& window);
	void setbuttonfillcolor(figure figure,sf::Color color);
	void setbuttonorigin(figure figure, sf::Vector2f origin);
	void setbuttonIntRect(figure figure,sf::IntRect value);
	void light(sf::Vector2f location);
	void unlight(sf::Vector2f location);
	void setLevelObjects(figure first, int firstNumofapp,
						 figure second, int secondNumofapp);
	void setLevelObjects(figure first, int firstNumofapp,
						 figure second, int secondNumofapp,
						 figure third, int  thirdNumofapp);

	void setStringbar();

	
private:
	void setDefalutToolbar(double x, double y);
	void setstrings();
	std::map<figure,std::pair<int,std::shared_ptr<BaseObject>>> m_toolbarMap;
	std::shared_ptr<BaseObject> m_net;
	sf::RectangleShape m_rec;
	std::ostringstream m_stringBar;


	sf::Text m_TextBar1;
	sf::Text m_TextBar2;
	sf::Text m_TextBar3;

	int m_firstObjCurrApp;
	int m_secondObjCurrApp;
	int m_thirdObjCurrApp;
};