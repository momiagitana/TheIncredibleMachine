#pragma once

#include "Globals.h"
#include <fstream>
#include <sstream>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


using std::cout;
using std::endl;
using sf::Font;
using sf::Texture;
using std::ifstream;
using std::vector;
using std::ostringstream;
using sf::SoundBuffer;

class Resources
{
public:
	//----------d-tor-------------------------
	~Resources();
	static Resources& instance();

	//----------get functions-----------------

	//----------get font----------------------
	const Font& getfont() const;


	const std::shared_ptr<Texture>& getWorkerTexture() const;
	const std::shared_ptr<Texture>& getEngineTexture() const;
	const std::shared_ptr<Texture>& getArrowsTexture() const;
	const std::shared_ptr<Texture>& getPropertiesTexture() const;
	const std::shared_ptr<Texture>& getBowlingballTexture() const;
	const std::shared_ptr<Texture>& getBasketballTexture() const;

	const std::shared_ptr<Texture>& getRequestedTexture(const figure& t) const;
	//soundbufferExample
	//const SoundBuffer& getEATDIMONDtune()const;
	


	void loadresources();
	void loadsound();
	void loadtextures();
	void loadfont();

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator= (const Resources&) = default;

	vector<std::shared_ptr<sf::Texture>> m_textures;		               //game figures textures
	sf::Font m_font;                                  //font for the text messeges
	ostringstream m_scoreToolbar;                    //string for toolbar text massages
	std::vector<std::shared_ptr<sf::SoundBuffer>> m_soundefects;
};








