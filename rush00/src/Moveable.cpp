/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moveable.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/13 20:38:25 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Moveable.hpp"

Moveable::Moveable(void):
_speed(10)
{
	return;
}

Moveable::Moveable(int speed):
_speed(speed)
{
	return;
}

Moveable::Moveable(const Moveable &src)
{
	*this = src;
	return;
}

Moveable::~Moveable(void)
{
	return;
}

Moveable &Moveable::operator=(Moveable const &rhs)
{
	if (this != &rhs)
	{
		this->_speed  = rhs._speed;
	}
	return (*this);
}

void Moveable::move(int dir, float &x, float &y, Map &map)
{
	// int oldX = (int)x;
	// int oldY = (int)y;

	switch (dir)
	{
		case UP:
			y -= this->_speed / UPS;
			if (!map.pos_in_map(y, x))
				y = 0.0f;
			// else
			// 	map.moveEntity(oldY, oldX, y, x);
		break;

		case DOWN:
			y += this->_speed / UPS;
			if (!map.pos_in_map(y, x))
				y = (float)map.getH() - 1.0f;
			// else
			// 	map.moveEntity(oldY, oldX, y, x);
		break;

		case LEFT:
			x -= this->_speed / UPS;
			if (!map.pos_in_map(y, x))
				x = 0.0f;
			// else
			// 	map.moveEntity(oldY, oldX, y, x);
		break;

		case RIGHT:
			x += this->_speed / UPS;
			if (!map.pos_in_map(y, x))
				x = (float)map.getW() - 1.0f;
			// else
			// 	map.moveEntity(oldY, oldX, y, x);
		break;
	}
}
