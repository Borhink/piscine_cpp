/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/14 19:52:42 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(Entity *parent, int damage, int dir, int x, int y, Map &map):
Entity(PROJECTILE, 1, '*', x, y, map), _parent(parent), _damage(damage), _dir(dir)
{
	switch (dir)
	{
		case UP:
			this->_pos.y--;
		break;
		case DOWN:
			this->_pos.y++;
		break;
		case LEFT:
			this->_pos.x--;
		break;
		case RIGHT:
			this->_pos.x++;
		break;
	}
	return;
}

Projectile::Projectile(Entity *parent, int type, int damage, int dir, int x, int y, Map &map):
Entity(type, 1, '*', x, y, map), _parent(parent), _damage(damage), _dir(dir)
{
	switch (dir)
	{
		case UP:
			this->_pos.y--;
		break;
		case DOWN:
			this->_pos.y++;
		break;
		case LEFT:
			this->_pos.x--;
		break;
		case RIGHT:
			this->_pos.x++;
		break;
	}
	return;
}

Projectile::Projectile(const Projectile &src):
Entity(src.getMap())
{
	*this = src;
	return;
}

Projectile::~Projectile(void)
{
	return;
}

Projectile &Projectile::operator=(Projectile const &rhs)
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
		//Projectile
		this->_parent = rhs._parent;
		this->_damage = rhs._damage;
		this->_dir = rhs._dir;
	}
	return (*this);
}

void Projectile::update(void)
{
	this->move(this, this->_dir, this->_map);
}

int Projectile::getDamage(void) const
{
	return (this->_damage);
}

void Projectile::setDamage(int damage)
{
	this->_damage = damage;
	return;
}

Entity *Projectile::getParent(void)
{
	return (this->_parent);
}
