/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/14 20:02:58 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Map.hpp"
#include "Projectile.hpp"

Enemy::Enemy(int life, int score, int x, int y, Map &map):
Entity(ENEMY, life, '#', x, y, map), Moveable(15), _score(score), _fireRate(1.0f),
_shootDelay(1.0f)
{
	return;
}

Enemy::Enemy(const Enemy &src):
Entity(src.getMap())
{
	*this = src;
	return;
}

Enemy::~Enemy(void)
{
	return;
}

Enemy &Enemy::operator=(Enemy const &rhs)
{
	if (this != &rhs)
	{
		//Entity
		this->_type = rhs._type;
		this->_alive  = rhs._alive;
		this->_life  = rhs._life;
		this->_name  = rhs._name;
		this->_pos  = rhs._pos;
		this->_map  = rhs._map;
		//Moveable
		this->_speed  = rhs._speed;
		//Player
		this->_score  = rhs._score;
		this->_fireRate = rhs._fireRate;
		this->_shootDelay = rhs._shootDelay;
	}
	return (*this);
}

void  	Enemy::update(void)
{
	this->_shootDelay += this->_fireRate / UPS;
	this->move(this, LEFT, this->_map);
	this->shoot();
}

void Enemy::shoot(void)
{
	int y = this->getY();
	int x = this->getX();
	Entity ***map = this->_map.getMap();

	if (this->_shootDelay >= 1.0f)
	{
		this->_shootDelay -= 1.0f;
		if (this->_map.pos_in_map(y, x - 1))
		{
			if (map[y][x - 1] && map[y][x - 1]->takeDamage(1))
				this->_map.deleteEntity(y, x - 1);
			else
				this->_map.addEntity(new Projectile(this, E_PROJECTILE, 1, LEFT, x, y, this->_map), y, x - 1);
		}
	}
}

int Enemy::getScore(void) const
{
	return (this->_score);
}

void Enemy::setScore(int score)
{
	this->_score = score;
	return;
}
