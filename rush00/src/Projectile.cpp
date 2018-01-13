/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 19:20:22 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(int damage, int x, int y, Map &map):
Entity(1, '*', x, y, map), _damage(damage)
{
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
		this->_alive  = rhs._alive;
		this->_life  = rhs._life;
		this->_name  = rhs._name;
		this->_pos  = rhs._pos;
		this->_map  = rhs._map;
		//Moveable
		this->_speed  = rhs._speed;
		//Projectile
		this->_damage  = rhs._damage;
	}
	return (*this);
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
