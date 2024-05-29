#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Chasing the cursor");
    sf::Text displayText;
    sf::Font font_playground;
    if (!font_playground.loadFromFile("assets/fonts/Playground.ttf"))
    {
        std::cout << "failed to load font" << std::endl;
    }
    
    displayText.setFont(font_playground);
    displayText.setFillColor(sf::Color::Yellow);
    displayText.setCharacterSize(20);
    displayText.setString("help me");
    sf::FloatRect textRec = displayText.getLocalBounds();
    displayText.setOrigin(textRec.width / 2, 0);
    displayText.setPosition(window.getSize().x / 2, 0);

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color(0,100,0,240));
    circle.setOrigin(50, 50);

    sf::Vector2f velocity;
    velocity.x = .08;
    velocity.y = .08;
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    sf::Vector2f targetPos;
    sf::Vector2f currentPos = circle.getPosition();
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        localPosition = sf::Mouse::getPosition(window);
        targetPos.x = localPosition.x;
        targetPos.y = localPosition.y;
        currentPos = circle.getPosition();
        if (targetPos.x > currentPos.x)
        {
            velocity.x = 0.08;
        }
        else if (targetPos.x < currentPos.x)
        {
            velocity.x = -0.08;
        }
        if (targetPos.y > currentPos.y)
        {
            velocity.y = 0.08;
        }
        else if (targetPos.y < currentPos.y)
        {
            velocity.y = -0.08;
        }
        
        circle.setPosition(currentPos + velocity);
        window.clear();
        window.draw(circle);
        window.draw(displayText);
        window.display();
    }

    return 0;
}