/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 16:03:58 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(void):
Entity(10, 'P', 0, 0),
_score(0)
{
	return;
}

Player::Player(int x, int y):
Entity(10, 'P', x, y),
_score(0)
{
	return;
}

Player::Player(const Player &src)
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
		this->_alive  = rhs._alive;
		this->_life  = rhs._life;
		this->_name  = rhs._name;
		this->_pos  = rhs._pos;
		this->_score  = rhs._score;
	}
	return (*this);
}

void Player::update(int input)
{
	if (input == UP)
		this->_pos.x--;
	else if (input == RIGHT)
		this->_pos.x++;
	else if (input == UP)
		this->_pos.y--;
	else if (input == DOWN)
		this->_pos.y++;
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
