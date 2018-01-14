/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/14 18:46:18 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"
#include "Map.hpp"

int Entity::nbEntities = 0;

Entity::Entity(int type, int life, char name, float x, float y, Map &map):
_type(type), _alive(true), _life(life), _name(name), _pos(x, y), _map(map)
{
	Entity::nbEntities++;
	return;
}

Entity::Entity(int type, int life, char name, Point pos, Map &map):
_type(type), _alive(true), _life(life), _name(name), _pos(pos), _map(map)
{
	Entity::nbEntities++;
	return;
}

Entity::Entity(Map &map):
_type(ENTITY), _alive(true), _life(1), _name('.'), _pos(0, 0), _map(map)
{
	Entity::nbEntities++;
	return;
}

Entity::Entity(const Entity &src):
_map(src.getMap())
{
	Entity::nbEntities++;
	*this = src;
	return;
}

Entity::~Entity(void)
{
	Entity::nbEntities--;
	return;
}

Entity &Entity::operator=(Entity const &rhs)
{
	if (this != &rhs)
	{
		this->_alive = rhs._alive;
		this->_life = rhs._life;
		this->_name = rhs._name;
		this->_pos = rhs._pos;
		this->_map = rhs._map;
	}
	return (*this);
}

void Entity::update(void)
{
	return;
}

bool Entity::takeDamage(int damage)
{
	if (damage > 0)
		this->setLife(this->_life - damage);
	if (this->isAlive())
		return (false);//EN VIE
	return (true);//MORT
}

int Entity::getType(void) const
{
	return (this->_type);
}

void Entity::setType(int type)
{
	this->_type = type;
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
	if (this->_life <= 0)
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
	return ((int)(this->_pos.x));
}

int Entity::getY(void) const
{
	return ((int)(this->_pos.y));
}

float Entity::getXF(void) const
{
	return (this->_pos.x);
}

float Entity::getYF(void) const
{
	return (this->_pos.y);
}

void Entity::setPos(Point pos)
{
	this->_pos = pos;
	return;
}

void Entity::setPos(float x, float y)
{
	this->_pos.x = x;
	this->_pos.y = y;
	return;
}

void Entity::setX(float x)
{
	this->_pos.x = x;
}

void Entity::setY(float y)
{
	this->_pos.y = y;
}

void Entity::moveX(float x)
{
	this->_pos.x += x;
}

void Entity::moveY(float y)
{
	this->_pos.y += y;
}

Map &Entity::getMap(void) const
{
	return (this->_map);
}

Entity::Point::Point(): x(0), y(0)
{
	return;
}

Entity::Point::Point(float X, float Y): x(X), y(Y)
{
	return;
}
