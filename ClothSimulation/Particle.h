#pragma once
#include <SFML/Graphics.hpp>

class Particle {
	private:
		// Drag
		float dragCoefficient;

		const float GRAVITY = 100.f;

	public: 
		sf::Vector2f position;
		sf::Vector2f velocity;
		sf::CircleShape shape;

		Particle(sf::Vector2f startPos, float dragCoefficient = 0.1f)
			: position(startPos), velocity(0.f, 0.f), shape(4.f), dragCoefficient(dragCoefficient) {
			shape.setFillColor(sf::Color::White);
			shape.setPosition(position);
		}

		void update(float dt) {

			// Gravity
			velocity.y += GRAVITY * dt;

			// Drag
			sf::Vector2f dragForce = -dragCoefficient * velocity;
			velocity += dragForce * dt;

			// Update position
			position += velocity * dt;
			shape.setPosition(position);
		}

		void draw(sf::RenderWindow& window) {
			window.draw(shape);
		}
};
