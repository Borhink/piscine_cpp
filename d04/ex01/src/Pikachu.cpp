/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pikachu.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 15:32:20 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pikachu.hpp"

Pikachu::Pikachu(void):
Enemy(40, "Pikachu")
{
	std::cout << "Pika pikaa !" << std::endl;
	return;
}

Pikachu::Pikachu(Pikachu const &src)
{
	*this = src;
	return;
}

Pikachu::~Pikachu(void)
{
	std::cout << "Pikaaaaa ..." << std::endl;
	return;
}

Pikachu &Pikachu::operator=(Pikachu const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_hp = rhs._hp;
	}
	return (*this);
}

void Pikachu::takeDamage(int amount)
{
	amount -= 15;
	if (amount > 0)
		this->setHP(this->_hp - amount);
	return;
}
