/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 16:01:06 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(void):
Entity(1, '*', 0, 0),
_damage(1)
{
	return;
}

Projectile::Projectile(int damage, int x, int y):
Entity(1, '*', x, y),
_damage(damage)
{
	return;
}

Projectile::Projectile(const Projectile &src)
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
		this->_alive  = rhs._alive;
		this->_life  = rhs._life;
		this->_name  = rhs._name;
		this->_pos  = rhs._pos;
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
