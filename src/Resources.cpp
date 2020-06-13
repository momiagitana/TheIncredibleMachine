#include "Resources.h"
#include "Globals.h"


Resources::Resources()
{	
	loadresources(); 
}

Resources::~Resources()
{
}

Resources& Resources::instance()
{
	static Resources inst;
	return inst;
}

const Font& Resources::getfont() const
{
	return m_font;
}

 const std::shared_ptr<Texture>& Resources::getWorkerTexture() const
{
	return m_textures.at(T_OBJ_Worker);
}

 const std::shared_ptr<Texture>& Resources::getEngineTexture() const
 {
	 return m_textures.at(T_OBJ_Engine);
 }

 const std::shared_ptr<Texture>& Resources::getArrowsTexture() const
 {
	 return m_textures.at(T_OBJ_Arrows);

 }

 const std::shared_ptr<Texture>& Resources::getPropertiesTexture() const
 {
	 return m_textures.at(T_OBJ_Propeties);
 }

 const std::shared_ptr<Texture>& Resources::getBowlingballTexture() const
 {
	 return m_textures.at(T_OBJ_Bowling);
 }

 const std::shared_ptr<Texture>& Resources::getBasketballTexture() const
 {
	 return m_textures.at(T_OBJ_Basketball);
 }

 const std::shared_ptr<Texture>& Resources::getRequestedTexture(const figure & f) const
 {
	 return m_textures.at(static_cast<int>(f));
 }

void Resources::loadresources()
{
	loadtextures();
	loadsound();
	loadfont();
}

void Resources::loadsound()
{
}

void Resources::loadtextures()
{
	
	m_textures.emplace_back(std::make_shared<sf::Texture>());
	m_textures.at(T_OBJ_Basketball)->loadFromFile("basketball.png");
	m_textures.emplace_back(std::make_shared<sf::Texture>());
	m_textures.at(T_OBJ_Bowling)->loadFromFile("bowling.png");
	m_textures.emplace_back(std::make_shared<sf::Texture>());
	m_textures.at(T_OBJ_Arrows)->loadFromFile("arrows.png"); 
	m_textures.emplace_back(std::make_shared<sf::Texture>());
	m_textures.at(T_OBJ_Propeties)->loadFromFile("propeties.png"); 
	m_textures.emplace_back(std::make_shared<sf::Texture>());
	m_textures.at(T_OBJ_Worker)->loadFromFile("worker.jpg"); 
	m_textures.emplace_back(std::make_shared<sf::Texture>());
	m_textures.at(T_OBJ_Engine)->loadFromFile("engine.png"); 
 
}

void Resources::loadfont()
{
	if (!m_font.loadFromFile("Amadeus.ttf"))	// if font couldn't be loaded
	{
		perror("cant load font");
		exit(EXIT_FAILURE);
	}
}
