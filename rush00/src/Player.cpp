/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/14 20:02:52 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Map.hpp"
#include "Projectile.hpp"

Player::Player(int x, int y, Map &map):
Entity(PLAYER, 3, '#', x, y, map), Moveable(30), _score(0), _fireRate(4.0f),
_shootDelay(1.0f), _shooting(false)
{
	return;
}

Player::Player(const Player &src):
Entity(src.getMap())
{
	*this = src;
	return;
}

Player::~Player(void)
{
	return;
}

Player &Player::operator=(Player const &rhs)
{
	if (this != &rhs)
	{
		//Entity
		this->_type = rhs._type;
		this->_alive = rhs._alive;
		this->_life = rhs._life;
		this->_name = rhs._name;
		this->_pos = rhs._pos;
		this->_map = rhs._map;
		//Moveable
		this->_speed = rhs._speed;
		//Player
		this->_score = rhs._score;
		this->_fireRate = rhs._fireRate;
		this->_shootDelay = rhs._shootDelay;
		this->_shooting = rhs._shooting;
	}
	return (*this);
}

void Player::update(Input &input)
{
	if (this->_shootDelay < 1.0f)
		this->_shootDelay += this->_fireRate / UPS;
	if (input.getEntry(UP))
		this->move(this, UP, this->_map);
	if (input.getEntry(RIGHT))
		this->move(this, RIGHT, this->_map);
	if (input.getEntry(LEFT))
		this->move(this, LEFT, this->_map);
	if (input.getEntry(DOWN))
		this->move(this, DOWN, this->_map);
	if (input.getEntry(SPACE))
		this->_shooting = !this->_shooting;
	this->shoot();
	return;
}

void Player::update(void)
{
	return;
}

void Player::shoot(void)
{
	int y = this->getY();
	int x = this->getX();
	Entity ***map = this->_map.getMap();

	if (this->_shootDelay >= 1.0f && this->_shooting)
	{
		this->_shootDelay -= 1.0f;
		if (this->_map.pos_in_map(y, x + 1))
		{
			if (map[y][x + 1] && map[y][x + 1]->takeDamage(1))
				this->_map.deleteEntity(y, x + 1);
			else
				this->_map.addEntity(new Projectile(this, P_PROJECTILE, 1, RIGHT, x, y, this->_map), y, x + 1);
		}
	}
}

int Player::getScore(void) const
{
	return (this->_score);
}

void Player::setScore(int score)
{
	this->_score = score;
	return;
}

void Player::addScore(int score)
{
	this->_score += score;
	return;
}
