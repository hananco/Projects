#include "Player.h"
bool Player::m_registerit = Creator::registerit('P', [](const char& a, const sf::Vector2f& b, const sf::Vector2f& c , b2World& e) ->std::shared_ptr <GameObject> { return std::make_shared <Player>(a, b, c, e); });
//==============================CONSTRUCTOR====================================
Player::Player(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize,b2World& world)
	: UnFixedObject(index, loc, objSize, Resources::getInstance().getTexture(PLAYER_PIC), world, true),
	m_animation(objSize , PLATER_LEFT_PIC_NAMES ,PLATER_RIGHT_PIC_NAMES)
{
	updateGunSprite(objSize, loc, Resources::getInstance());
}
//====================HANDLE COLLISION USING DOUBLE DISPATCH===================
void Player::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}
//==========================HANDLE COLLISION WITH ELEVATOR=====================
//PUT THE PLAYER ON THE ELEVATOR CENTER, PLAY MUSIC AND UPDATE THE THIS LEVEL
//HAS COMPLETED
//=============================================================================
void Player::handleCollision(Elevator& gameObject)
{
	m_body->SetTransform(b2Vec2{ gameObject.getPosition().x, gameObject.getPosition().y }, m_body->GetAngle());
	if (!m_levelEnd)
		play(ELEVATOR_SOUND, false);
	m_levelEnd = true;
}
//========================HANDLE COLLISION WITH TIME PRESENT===================
//PLAY MUSIC AND UPDATE THE TIME 
//=============================================================================
void Player::handleCollision(TimePresent& gameObject)
{
	play(TIME_PRESENT_SOUND, false);
	m_extraTime = true;
}
//===========================HANDLE COLLISION WITH ACID========================
//PLAY MUSIC AND UPDATE THE THAT LEVEL NEED TO BE RESTART
//=============================================================================
void Player::handleCollision(Acid& gameObject)
{
	play(ACID_SOUND, false);
	m_restart = true;
};
//===========================HANDLE COLLISION WITH WALL========================
//UPDATE THE THAT THE PLAYER IS ON GROUND (FOR THE JUMPING OPTION)
//=============================================================================
void Player::handleCollision(Wall& gameObject)
{
	if (gameObject.getPosition().y > m_body->GetPosition().y &&
		abs(gameObject.getPosition().x - getPosition().x) < getGlobalBounds().width/2)
		m_onGround = true;
};
//========================HANDLE COLLISION WITH BAD LAZER======================
//PLAY MUSIC AND UPDATE THE THAT LEVEL NEED TO BE RESTART
//=============================================================================
void Player::handleCollision(BadLaser& gameObject) {

	play(ACID_SOUND, false);
	m_restart = true;
}
//=====================================MOVE====================================
void Player::move(const int &key ,sf::Time deltaTime)
{
	b2Vec2 vel = m_body->GetLinearVelocity();
	
	switch (key)
	{
	case sf::Keyboard::Left:
		updateAnimatedMove(m_firstR, m_firstL, LEFT);
		vel.x = updateMove(-WALK_SPEED, deltaTime.asSeconds());
		break;
	case sf::Keyboard::Right:
		updateAnimatedMove(m_firstL, m_firstR, RIGHT);
		vel.x = updateMove(WALK_SPEED, deltaTime.asSeconds());
		break;
	case sf::Keyboard::Up:
		if (m_onGround) 
			vel.y = updateMove(-JUMP_SPEED, deltaTime.asSeconds());
		m_onGround = false;
		break;
	}

	m_body->SetLinearVelocity(vel);
}
//==============================UPDATE MOVE====================================
//FOR THE MOVE FUNCTION USE
//=============================================================================
float Player::updateMove(const int& movement , float time)
{
	return ((time >= 1.0f) ? movement * time : movement);
}
//==========================UPDATE ANIMATED MOVE===============================
//FOR THE MOVE FUNCTION USE
//=============================================================================
void Player::updateAnimatedMove(bool& first, bool& second, const int& direction)
{
	if (!first && second)
		m_gunSprite.setScale({-m_gunSprite.getScale().x , m_gunSprite.getScale().y});
	first = true;
	second = false;
	m_sprite = m_animation.move(direction);
}
//=====================================DRAW====================================
//UPDATE AND DAW THE SPRITE AND THE GUN ACCORDING TO THE BODY 
//=============================================================================
void Player::draw(sf::RenderWindow& window)
{
	ifOutOfRange();
	upElevator();
	m_sprite.setPosition(m_body->GetPosition().x, m_body->GetPosition().y);
	m_gunSprite.setPosition(m_body->GetPosition().x, m_body->GetPosition().y);
	window.draw(m_sprite);
	window.draw(m_gunSprite);
}
//=============================RORATE TO MOUSE=================================
//MAKE THE GUN FOLLOW AND RORATE ACCORDING TO THE MOUSE 
//=============================================================================
void Player::rotateToMouse(sf::RenderWindow& window)
{
	sf::Vector2f curPos = m_gunSprite.getPosition();
	sf::Vector2i position = sf::Mouse::getPosition(window);
	double dx = double(double(position.x) - double(curPos.x));
	double dy = double(double(position.y) - double(curPos.y));
	double rotation = (atan2(dy, dx) * ANGLE) / PI;
	m_firstL == false ? m_gunSprite.setRotation(float(rotation +  ANGLE)) :
						m_gunSprite.setRotation(float(rotation));
}
//================================BOX==========================================
//THIS FUNCTION IS BEEN CALLED WHEN THE PLAYER PICKING UP OR DROPING A BOX,
//M_BOX == NULLPTR -> PICKING UP BOX, CREAT JOINT OF THE BOX AND THE PLAYER, 
//THE BOX WILL FOLLOW THE PLAYER
//M_BOX != NULLPTR -> DROPING THE BOX, REMOVE TO JOINT
//=============================================================================
void Player::box(b2Body& box) {

	if (m_box == nullptr) {
		m_box = &box;
		m_box->SetTransform(m_body->GetPosition(), m_body->GetAngle());
		wj.Initialize(m_box, m_body, m_body->GetWorldCenter());
		joint = (b2Joint*)m_world->CreateJoint(&wj);
	}
	else {
		m_world->DestroyJoint(joint);
		m_box->SetTransform({ m_body->GetPosition().x + m_sprite.getGlobalBounds().width / 2,
			m_body->GetPosition().y} , m_body->GetAngle());
		m_box = nullptr;
	}
	
}
//================================GET BOX======================================
//GET IF THE PLAYER HOLDING A BOX
//=============================================================================
bool Player::getBox()
{
	return (m_box != nullptr);
}

//==================================IS EXTRA TIME==============================
//GET IF THE PLAYER PICKED UP TIME PRESENT AND RETURN THE TIME PRESENT BOOL 
//MEMBER TO BE FALSE
//=============================================================================
bool Player::isExtraTime()
{
	auto temp = m_extraTime;
	m_extraTime = false;
	return temp;
}
//===================================GET RESTART===============================
//GET IF THIS LEVEL NEED TO BE RESTART - COLLISION WITH BAD LAZER/ACID
//=============================================================================
bool Player::getRestart() const
{
	return m_restart;
}
//=============================UPDATE GUN SPRITE===============================
void Player::updateGunSprite(const sf::Vector2f& objSize , const sf::Vector2f& loc, Resources& p2Sin)
{
	m_gunSprite.setOrigin(m_sprite.getOrigin());
	m_gunSprite.setPosition(sf::Vector2f(loc.x + objSize.x, loc.y + objSize.y));
	m_gunSprite.setTexture(p2Sin.getTexture(PLAYER_GUN_PIC), true);
	m_gunSprite.setScale(objSize.x / 5 / m_gunSprite.getLocalBounds().width * 2,
		objSize.y / 5 / m_gunSprite.getLocalBounds().height * 2);
	m_gunSprite.setOrigin(m_sprite.getOrigin());
	m_gunSprite.setPosition(sf::Vector2f(loc.x + objSize.x, loc.y + objSize.y));
}
//================================RESET BODY===================================
void Player :: resetBody() {

	if (m_box != nullptr) {
		m_world->DestroyJoint(joint);		
		m_box = nullptr;
	}

	GameObject::resetBody();
	m_restart = false;
}
//===========================GET IF LEVEL COMPLETED============================
bool Player::getIfLevelCompleted() const
{
	return m_finish;
}

