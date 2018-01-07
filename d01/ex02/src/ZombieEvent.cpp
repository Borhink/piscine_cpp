/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/07 19:51:44 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

std::string const ZombieEvent::_randomNames[8] = {"30_1", "Zaz", "Thor", "NS", "Nours", "Benny", "XN", "Kwame"};

ZombieEvent::ZombieEvent(void):
_type("Basic")
{
	 std::srand(std::time(nullptr));
	 return;
}

ZombieEvent::~ZombieEvent(void)
{
	return;
}

void ZombieEvent::setZombieType(std::string type)
{
	if (!type.empty())
		this->_type = type;
	return;
}

Zombie* ZombieEvent::newZombie(std::string name) const
{
	class Zombie *zombie = new class Zombie(this->_type);

	zombie->setName(name);
	return (zombie);
}

Zombie* ZombieEvent::randomChump(void) const
{
	class Zombie *zombie = new class Zombie(this->_type);

	zombie->setName(ZombieEvent::_randomNames[std::rand() % 8]);
	zombie->announce();
	return (zombie);
}
