/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moveable.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/14 19:26:27 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Moveable.hpp"
#include "Projectile.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

Moveable::Moveable(void):
_speed(20)
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
		this->_speed = rhs._speed;
	}
	return (*this);
}

bool Moveable::collide(Entity *cur, int x, int y, Map &map)
{
	int newX = cur->getX();
	int newY = cur->getY();
	Entity *next;

	if (newX == x && newY == y)
	{
		return (false);
	}
	if (!map.pos_in_map(newY, newX))
	{
		if (cur->getType() != PLAYER)
			map.deleteEntity(y, x);
		cur->setPos(x, y);
		return (true);
	}
	else if (map.getElem(newY, newX))
	{
		next = map.getMap()[newY][newX];
		if ((cur->getType() == PLAYER && next->getType() == E_PROJECTILE)
			|| (cur->getType() == PLAYER && next->getType() == ENEMY))
		{
			map.deleteEntity(newY, newX);
			cur->takeDamage(1);
		}
		else if (cur->getType() == PLAYER && next->getType() == P_PROJECTILE)
			map.deleteEntity(newY, newX);
		else if ((cur->getType() == E_PROJECTILE && next->getType() == PLAYER)
			|| (cur->getType() == ENEMY && next->getType() == PLAYER))
		{
			map.deleteEntity(y, x);
			next->takeDamage(1);
		}
		else if ((cur->getType() == E_PROJECTILE && next->getType() == ENEMY)
			|| (cur->getType() == P_PROJECTILE && next->getType() == PLAYER))
			map.deleteEntity(y, x);
		else if ((cur->getType() == E_PROJECTILE && next->getType() == P_PROJECTILE)
			|| (cur->getType() == P_PROJECTILE && next->getType() == E_PROJECTILE))
		{
			map.deleteEntity(newY, newX);
			map.deleteEntity(y, x);
		}
		else if (cur->getType() == P_PROJECTILE && next->getType() == ENEMY)
		{
			Projectile *proj = (Projectile*)cur;
			Player *player = (Player*)proj->getParent();
			Enemy *enemy = (Enemy*)next;
			player->addScore(enemy->getScore());
			map.deleteEntity(newY, newX);
			map.deleteEntity(y, x);
		}
		else if (cur->getType() == ENEMY && next->getType() == P_PROJECTILE)
		{
			Projectile *proj = (Projectile*)next;
			Player *player = (Player*)proj->getParent();
			Enemy *enemy = (Enemy*)cur;
			player->addScore(enemy->getScore());
			map.deleteEntity(newY, newX);
			map.deleteEntity(y, x);
		}
		cur->setPos(x, y);
		return (true);
	}
	return (false);
}

void Moveable::move(Entity *e, int dir, Map &map)
{
	int oldX = e->getX();
	int oldY = e->getY();

	switch (dir)
	{
		case UP:
			e->moveY(-(this->_speed / UPS));
			if (!this->collide(e, oldX, oldY, map))
				map.moveEntity(oldY, oldX, e->getY(), e->getX());
		break;

		case DOWN:
			e->moveY(this->_speed / UPS);
			if (!this->collide(e, oldX, oldY, map))
				map.moveEntity(oldY, oldX, e->getY(), e->getX());
		break;

		case LEFT:
			e->moveX(-(2 * this->_speed / UPS));
			if (!this->collide(e, oldX, oldY, map))
				map.moveEntity(oldY, oldX, e->getY(), e->getX());
		break;

		case RIGHT:
			e->moveX(2 * this->_speed / UPS);
			if (!this->collide(e, oldX, oldY, map))
				map.moveEntity(oldY, oldX, e->getY(), e->getX());
		break;
	}
}
