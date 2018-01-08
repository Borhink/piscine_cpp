/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 13:33:35 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name):
_name(name)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	return;
}

std::string const &HumanB::getName(void) const
{
	return (this->_name);
}

void HumanB::setName(std::string name)
{
	if (!name.empty())
		this->_name = name;
	return;
}

class Weapon const *HumanB::getWeapon(void) const
{
	return (this->_weapon);
}

void HumanB::setWeapon(class Weapon &weapon)
{
	this->_weapon = &weapon;
	return;
}
