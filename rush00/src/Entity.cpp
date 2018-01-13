/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 16:00:47 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

Entity::Entity(void):
_alive(true),
_life(1),
_name('#'),
_pos(0, 0)
{
	return;
}

Entity::Entity(int life, char name, int x, int y):
_alive(true),
_life(life),
_name(name),
_pos(x, y)
{
	return;
}

Entity::Entity(int life, char name, Point pos):
_alive(true),
_life(life),
_name(name),
_pos(pos)
{
	return;
}

Entity::Entity(const Entity &src)
{
	*this = src;
	return;
}

Entity::~Entity(void)
{
	return;
}

Entity &Entity::operator=(Entity const &rhs)
{
	if (this != &rhs)
	{
		this->_alive  = rhs._alive;
		this->_life  = rhs._life;
		this->_name  = rhs._name;
		this->_pos  = rhs._pos;
	}
	return (*this);
}

void Entity::update(int input)
{
	(void)input;
	return;
}

bool Entity::isAlive(void) const
{
	return (this->_alive);
}

int Entity::getLife(void) const
{
	return (this->_life);
}

void Entity::setLife(int life)
{
	this->_life = life;
	if (this->_life < 0)
		this->_alive = false;
	return;
}

char Entity::getName(void) const
{
	return (this->_name);
}

void Entity::setName(char name)
{
	this->_name = name;
	return;
}

Entity::Point Entity::getPos(void) const
{
	return (this->_pos);
}

int Entity::getX(void) const
{
	return (this->_pos.x);
}

int Entity::getY(void) const
{
	return (this->_pos.y);
}

void Entity::setPos(Point pos)
{
	this->_pos = pos;
	return;
}

void Entity::setPos(int x, int y)
{
	this->_pos.x = x;
	this->_pos.y = y;
	return;
}

Entity::Point::Point(): x(0), y(0)
{
	return;
}

Entity::Point::Point(int X, int Y): x(X), y(Y)
{
	return;
}
