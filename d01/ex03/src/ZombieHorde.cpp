/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/07 20:16:30 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

std::string const ZombieHorde::_randomNames[8] = {"30_1", "Zaz", "Thor", "NS", "Nours", "Benny", "XN", "Kwame"};
std::string const ZombieHorde::_randomTypes[8] = {"Runner", "Explosive", "Creepy", "Bigboy", "Toxic", "Ranger", "Rolling Head", "Ninja"};

ZombieHorde::ZombieHorde(int n):
_nbZombies(n),
_horde(new class Zombie[n])
{
	std::srand(std::time(nullptr));
	for (int i = 0; i < this->_nbZombies; i++)
	{
		class Zombie &zombie = _horde[i];
		zombie.setName(ZombieHorde::_randomNames[std::rand() % 8]);
		zombie.setType(ZombieHorde::_randomTypes[std::rand() % 8]);
	}
	return;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] _horde;
	return;
}

void ZombieHorde::announce(void) const
{
	for (int i = 0; i < this->_nbZombies; i++)
	{
		class Zombie &zombie = _horde[i];
		zombie.announce();
	}
	return;
}
