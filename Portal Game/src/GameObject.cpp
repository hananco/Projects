#include "GameObject.h"
//==============================CONSTRUCTOR====================================
GameObject::GameObject(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world , const bool& dynamic)
    :m_world(&world)
{
    m_sprite.setTexture(texture, true);
    updateSprite(loc, objSize);
    setWorldBody(dynamic);
}

bool GameObject :: checkCollision(sf::FloatRect rec) const
{
    return (m_sprite.getGlobalBounds().intersects(rec));
}

bool GameObject::Press(const bool& enter)
{
    return false;
}

bool GameObject::isDisposed() const {

    return m_isDisposed;
}

void GameObject :: draw(sf::RenderWindow& window)
{
    upElevator();
    m_sprite.setPosition(m_body->GetPosition().x, m_body->GetPosition().y);
    if(!m_isDisposed)
      window.draw(m_sprite);
}

void GameObject::setAble(bool b)
{
    m_body->SetEnabled(b);
}

sf::FloatRect GameObject :: getGlobalBounds() const
{
    return m_sprite.getGlobalBounds();
}

void GameObject::updateSprite(const sf::Vector2f& loc, const sf::Vector2f& objSize)
{
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2, 
        m_sprite.getGlobalBounds().height/2);
    m_sprite.setScale(objSize.x / m_sprite.getGlobalBounds().width,
        objSize.y / m_sprite.getGlobalBounds().height);
    m_sprite.setPosition(sf::Vector2f{loc.x + objSize.x / 2, loc.y + objSize.y / 2});
    m_startLoc = m_sprite.getPosition();
}

void GameObject::setWorldBody(const bool& dynamic)
{
    b2BodyDef bodyDef;
    b2PolygonShape Box;
    b2FixtureDef fixtureDef;

    if (dynamic) {
        bodyDef.type = b2_dynamicBody;
        bodyDef.gravityScale = 0.07f;
        Box.SetAsBox(float(m_sprite.getGlobalBounds().width / 2.5), float(m_sprite.getGlobalBounds().height / 2.5));
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 1.0f;
    }
    else 
        Box.SetAsBox(float(m_sprite.getGlobalBounds().width / 2), float(m_sprite.getGlobalBounds().height / 2));

    m_body = m_world->CreateBody(&bodyDef);
    fixtureDef.shape = &Box;
    m_body->CreateFixture(&fixtureDef); 
    m_body->SetTransform({ m_startLoc.x, m_startLoc.y } , m_body->GetAngle());
    m_body->SetUserData(this);
    if (dynamic){
        b2MassData* MassData = new b2MassData();
        MassData->mass = -10.0f;
        m_body->SetMassData(MassData);
    }
}

b2Vec2 GameObject::getPosition()
{
    return m_body->GetPosition();
}

b2Body* GameObject::getBody() const
{
    return m_body;
}

bool GameObject::collision(const b2Body* body) 
{   

   for (b2ContactEdge* edge = m_body->GetContactList(); edge; edge = edge->next)
   {
       if (!edge->contact->IsEnabled() || !edge->contact->IsTouching())
           continue;
       if (edge->other == body)
           return true;
   }
   return false;

}

void GameObject::ifOutOfRange() {

    if (m_body->GetPosition().x < 0)
        m_body->SetLinearVelocity(b2Vec2(100, 0));

    if (m_body->GetPosition().x > WINDOW_WIDTH)
        m_body->SetLinearVelocity(b2Vec2(-100, 0));

    if (m_body->GetPosition().y < 0)
        m_body->SetLinearVelocity(b2Vec2(0, -100));

    if (m_body->GetPosition().y > WINDOW_HEIGHT)
        m_body->SetLinearVelocity(b2Vec2(0, 100));
}

void GameObject::resetBody()
{
    if (m_isDisposed && !m_body->IsEnabled())
        setAble(true);
    m_isDisposed = false;
    m_body->SetTransform(b2Vec2{ m_startLoc.x, m_startLoc.y }, m_body->GetAngle());
    m_body->SetAwake(true);
}
void GameObject :: upElevator()
{
    if (m_levelEnd) {
        
        if (m_body->GetPosition().y < 0) 
            m_finish = true;

        m_body->SetType(b2_staticBody);
        m_body->SetTransform(b2Vec2{ m_body->GetPosition().x, m_body->GetPosition().y - 5 }, m_body->GetAngle());
    }
}

void GameObject::play(const int& index, const bool& loop) {

    Resources& p2Sin = Resources::getInstance();
    p2Sin.playMusic(index, loop);
}