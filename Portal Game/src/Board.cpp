#include "Board.h"
//==============================CONSTRUCTOR====================================
Board::Board() : m_file()
{
	Resources& p2Sin = Resources::getInstance();
	m_backGround.setTexture(p2Sin.getTexture(BACK_GROUND_PIC), true);
	m_backGround.setScale(WINDOW_WIDTH / m_backGround.getGlobalBounds().width,
		WINDOW_HEIGHT / m_backGround.getGlobalBounds().height);	
}
//=================================BEGIN=======================================
// REMOVE ALL EXISTING BODYS FROM WORLD AND SET DATA
//=============================================================================
void Board::begin(b2World& world)
{
	clearWorld(m_objects, world);
	clearWorld(m_data, world);
	m_objects.clear();
	m_data.clear();
	createMap(world);
}
//=============================CREAT MAP=======================================
//CREAT THE OBJECTS VECTOR BY THE LEVEL FILE
//=============================================================================
void Board::createMap(b2World& world)
{
	std::pair<std::vector <char>, std::vector <sf::Vector2f>> map = m_file.readLevel(m_currentLevel);
	sf::Vector2f size = sf::Vector2f(m_file.getSize());
	for (int i = 0; i < map.first.size(); i++)
		createObject(map.first[i], map.second[i], size, world);
	for (auto& i : m_objects)
		i->addElement(m_data);
}
//=================================END=========================================
//RETURN IF WE'VE FINISHED ALL LEVELS
//=============================================================================
bool Board::end()
{
	return (m_currentLevel - 1 == LEVELS_AMOUNT);
}
//=================================DRAW========================================
//DRAW THE OBJECTS
//=============================================================================
void Board::draw(sf::RenderWindow& window)
{
	window.draw(m_backGround);

	for (auto& obj : m_objects) 
		obj->draw(window);
	
	if (m_fireClock.getElapsedTime().asSeconds() < 0.5f) {
		m_callback.line.data()->color = sf::Color::Red;
		window.draw(m_callback.line.data(), 2, sf::Lines);
	}
}
//============================CREAT OBJECTS====================================
void Board::createObject(const char& type, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world)
{
	if (type == BUTTON_FLOOR)
		m_data.push_back(std::make_shared<ButtonFloor>(type, loc, objSize,  world));
	else 
	{
		if (type == PLAYER) {
			m_player = std::make_shared<Player>(type, loc, objSize, world);
			m_objects.push_back(m_player);
		}
		else {
			auto p = Creator::create(type, loc, objSize, world);
			if (p)
				m_objects.push_back(p);
		}
	}
}
//=========================HANDLE COLLISION===================================
void Board::handleCollisions()
{
	for (auto& object : m_objects)
	{
		for (auto& other : m_objects)
		{
			if (object->collision(other->getBody()) && m_portal[EXIT_PORT] && m_portal[ENTER_PORT] && other == m_portal[ENTER_PORT]) 
				object->port(m_portal[EXIT_PORT]->getPosition());
			
			else if (object->collision(other->getBody()))
				object->handleCollision(*other);
		}
	}
}
//============================OPERATOR ++======================================
//MOVE TO THE NEXT LEVEL
//=============================================================================
void Board::operator++()
{
	++m_currentLevel;
}
//================================RESTART======================================
//RESET THE EXISTING PORTAL AND CALLING TO OBJECTS RESET FUNCTION
//=============================================================================
void Board::restart(b2World& world)
{
	for (auto &obj : m_objects)
		obj->resetBody();

	for (auto& port : m_portal) {
		if (port)
		{
			port->NotPressed();
			port = nullptr;
		}
	}
}
//=============================HANDLE PRESS====================================
//CHECK IF WE NEED TO OPEN A PORTAL / PICKING UP / DROPING A BOX
//=============================================================================
void Board::handlePress(sf::RenderWindow& window  , const bool& type , b2World& world) {
	
	for (auto& objetc : m_objects)
	{
		sf::Vector2f mousePos(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y));
		if (objetc->getGlobalBounds().contains(mousePos) && (m_player->collision(objetc->getBody())||m_player->getBox())) {
			objetc->handlePress(*m_player);
		}
		if (objetc->getGlobalBounds().contains(mousePos) && path(m_player->getBody() , objetc->getBody(), world) && objetc->Press(type))
		{
			if (m_portal[type]) 
				m_portal[type]->NotPressed();
			
			if (m_portal[type] == objetc) {
				m_portal[type] = nullptr;
				continue;
			}
			m_portal[type] = objetc;
			if (m_portal[type] == m_portal[!type])
				m_portal[!type] = nullptr;
		}	
	}	
}
//================================FIRE=========================================
//ADD BULLET TO THE BAD LAZER
//=============================================================================
void Board::fire()
{
	for (auto& gun : m_objects) 
	{
		if (auto ptr = dynamic_cast<BadLaser*>(gun.get())) 
			if (ptr->doesFire())
				ptr->fire();
	}
}
//=================================GET TIME====================================
//GET THE LEVEL TIME
//=============================================================================
int Board::getTime() const
{
	return m_file.getTime();
}
//===================================PATH======================================
//RETURN IF THERE IS A PATH BETWEEN THIS 2 LOCATIONS WITHOUT COLLISION WITH
//OTHER BODY
//=============================================================================
bool Board::path(b2Body* obj1, b2Body* obj2, b2World& world) {

	m_fireClock.restart();

	if (m_callback.rayCastValid(obj1->GetPosition() , obj2->GetPosition())) {
		m_callback.set(obj1, obj2);
		world.RayCast(&m_callback, obj1->GetPosition(), obj2->GetPosition());
		return m_callback.path();
	}
	return false;
}
void Board::movePlayer(const int& key, sf::Time deltaTime) {
	m_player->move(key, deltaTime);
}
void Board::roratePlayerGun(sf::RenderWindow& window) {
	m_player->rotateToMouse(window);
}
bool Board::getnextLevel() const {
	return m_player->getIfLevelCompleted();
}
bool Board::getTimePresent() const {
	return m_player->isExtraTime();
}
bool Board::getRestart() const {
	return m_player->getRestart();
}

void Board::initCurrentLevel()
{
	m_currentLevel = 1;
}

int Board::getLevel()
{
	return m_currentLevel;
}
