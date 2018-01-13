/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 19:56:55 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Map.hpp"

Player::Player(int x, int y, Map &map):
Entity(10, 'P', x, y, map), Moveable(30), _score(0)
{
	return;
}

Player::Player(const Player &src):
Entity(src.getMap())
{
	*this = src;
	return;
}

Player::~Player(void)
{
	return;
}

Player &Player::operator=(Player const &rhs)
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
		//Player
		this->_score  = rhs._score;
	}
	return (*this);
}

void Player::update(Input &input)
{
	if (input.getEntry(UP))
	{
		this->move(UP, this->_pos.x, this->_pos.y, this->_map);
		mvprintw(5, 0, "UP");
	}
	else if (input.getEntry(RIGHT))
	{
		this->move(RIGHT, this->_pos.x, this->_pos.y, this->_map);
		mvprintw(5, 0, "RIGHT");
	}
	else if (input.getEntry(LEFT))
	{
		this->move(LEFT, this->_pos.x, this->_pos.y, this->_map);
		mvprintw(5, 0, "LEFT");
	}
	else if (input.getEntry(DOWN))
	{
		this->move(DOWN, this->_pos.x, this->_pos.y, this->_map);
		mvprintw(5, 0, "DOWN");
	}
	return;
}

int Player::getScore(void) const
{
	return (this->_score);
}

void Player::setScore(int score)
{
	this->_score = score;
	return;
}
