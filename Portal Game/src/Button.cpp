#include "Button.h"
bool Button::m_registerit = Creator::registerit('O', [](const char& a, const sf::Vector2f& b, const sf::Vector2f& c,  b2World& e) ->std::shared_ptr <GameObject> { return std::make_shared <Button>(a, b, c, e); });
//==============================CONSTRUCTOR====================================
Button::Button(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize,b2World& world)
	:FixedObject(index, loc, objSize, Resources::getInstance().getTexture(BUTTON_PIC), world){}
//====================HANDLE COLLISION USING DOUBLE DISPATCH===================
void Button :: handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;
    gameObject.handleCollision(*this);
}

void Button ::draw(sf::RenderWindow& window)
{
    bool is = false;
    for (b2ContactEdge* edge = m_body->GetContactList(); edge; edge = edge->next)
    {
        if (!edge->contact->IsEnabled() || !edge->contact->IsTouching())
            continue;
        if (edge->other->GetType() == b2_dynamicBody) 
            is = true;
    }
     
    for (auto& i : m_elements) 
    {
        if (is)
            i->draw(window);
        i->setAble(is);
    }
  
    window.draw(m_sprite);
}

void Button :: addElement(std::vector<std::shared_ptr<ButtonFloor>> obj)
{
    for (auto i : obj)
        if (i->getPosition().y == m_sprite.getPosition().y)
            m_elements.push_back(i);

}