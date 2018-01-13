/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 13:07:21 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void):
Entity(1, 'E', 0, 0),
_score(10)
{
	return;
}

Enemy::Enemy(int life, int score, int x, int y):
Entity(life, 'E', x, y),
_score(score)
{
	return;
}

Enemy::Enemy(const Enemy &src)
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
		this->_alive  = rhs._alive;
		this->_life  = rhs._life;
		this->_name  = rhs._name;
		this->_pos  = rhs._pos;
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
