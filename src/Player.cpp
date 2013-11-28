#include "player.h"

Player::Player(std::string texture)
{

	speed = 0.7;
	health = 100;
	active = true;
	
	playerTex.loadFromFile(texture);
	playerTex.setSmooth(false);
	playerSprite.setTexture(playerTex);
	playerSprite.setOrigin(23, 17);
	playerSprite.setPosition(400, 300);
}

void Player::Update(sf::RenderWindow &window, float elapsedTime)
{
	float x = playerSprite.getPosition().x;
	float y = playerSprite.getPosition().y;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(x <= - 7)
		{
			x = window.getSize().x;
		}else
			{
				x -= speed*elapsedTime;
				playerSprite.setRotation(-25);
			}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if(x >= window.getSize().x + 7)
		{
			x = 0;
		}else
			{
				x += speed*elapsedTime;
				playerSprite.setRotation(25);
			}
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (y <= 67)
		{
			y = 67;
		}else
			{
				y -= speed*elapsedTime;
				playerSprite.setRotation(0);
			}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if(y >= window.getSize().y - 17)
		{
			y = window.getSize().y;
		}else
			{
				y += speed*elapsedTime;
				playerSprite.setRotation(0);
			}
	}

	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			playerSprite.setRotation(0);
		}

	playerSprite.setPosition(x, y);
}

void Player::Render(sf::RenderWindow &window)
{
	if(active)
	{
		window.draw(playerSprite);
	}
}

sf::Vector2f Player::getPosition()
{
	return playerSprite.getPosition();
}

int Player::getHealth()
{
	return health;
}

void Player::reduceHealth(int pDamage)
{
	int newhealth = health-pDamage;
	health = newhealth;
}

void Player::increaseHealth (int heal)
{
	int newHealth = health + heal;
	health = newHealth;
	if (health >= 100)
	{
		health = 100;
	}
}