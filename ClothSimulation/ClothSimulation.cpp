// STD
#include <iostream>
#include <vector>

// Simulation files
#include "Particle.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "2d Particle Simulation");
    window.setFramerateLimit(144);

    std::vector<Particle> particles;

    // With drag
    particles.emplace_back(sf::Vector2f(100.f, 100.f));

    // Without drag
    particles.emplace_back(sf::Vector2f(200.f, 100.f), 0.f);

    sf::Clock clock;

    while (window.isOpen()) 
    {
        while (const std::optional event = window.pollEvent()) 
        {
            if (event->is<sf::Event::Closed>()) 
            {
                window.close();
            }
        }

        float dt = clock.restart().asSeconds();

        for (auto& p : particles)
            p.update(dt);

        window.clear(sf::Color::Black);

        for (auto& p : particles)
            p.draw(window);
        
        window.display();
    }

    return 0;
}