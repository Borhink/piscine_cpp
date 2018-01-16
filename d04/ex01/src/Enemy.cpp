/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:31:34 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/15 14:56:47 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void)
{
	return;
}

Enemy::Enemy(int hp, std::string const &type):
_type(type),
_hp(hp)
{
	return;
}

Enemy::Enemy(Enemy const &src)
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
		this->_type = rhs._type;
		this->_hp = rhs._hp;
	}
	return (*this);
}

void Enemy::takeDamage(int amount)
{
	if (amount > 0)
		this->setHP(this->_hp - amount);
	return;
}

std::string const &Enemy::getType(void) const
{
	return (this->_type);
}

void Enemy::setType(std::string const &type)
{
	this->_type = type;
	return;
}

int Enemy::getHP(void) const
{
	return (this->_hp);
}

void Enemy::setHP(int hp)
{
	this->_hp = hp;
	if (this->_hp < 0)
		this->_hp = 0;
	return;
}
