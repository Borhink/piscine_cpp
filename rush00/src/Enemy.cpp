/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 19:20:18 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Map.hpp"

Enemy::Enemy(int life, int score, int x, int y, Map &map):
Entity(life, 'E', x, y, map), _score(score)
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
		this->_alive  = rhs._alive;
		this->_life  = rhs._life;
		this->_name  = rhs._name;
		this->_pos  = rhs._pos;
		this->_map  = rhs._map;
		//Moveable
		this->_speed  = rhs._speed;
		//Player
		this->_score  = rhs._score;
	}
	return (*this);
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
