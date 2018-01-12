/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:31:34 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/12 13:33:36 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void)
{
	return;
}

Enemy::Enemy(int hp, std::string const &type)
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

void Enemy::takeDamage(int damage)
{
	if (damage > 0)
		this->setHP(this->_hp - damage);
	return;
}

std::string const &Enemy::getType(void) const
{
	return (this->_type);
}

void Enemy::setType(std::string const &type) const
{
	this->_type = type;
	return;
}

int Enemy::getHP(void) const
{
	return (this->_hp);
}

int Enemy::setHP(int hp) const
{
	this->_hp = hp;
	return;
}
