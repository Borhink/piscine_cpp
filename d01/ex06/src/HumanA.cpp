/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 13:27:43 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, class Weapon &weapon):
_name(name),
_weapon(weapon)
{
	return;
}

HumanA::~HumanA(void)
{
	return;
}

void HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
	return;
}

std::string const &HumanA::getName(void) const
{
	return (this->_name);
}

void HumanA::setName(std::string name)
{
	if (!name.empty())
		this->_name = name;
	return;
}

class Weapon const &HumanA::getWeapon(void) const
{
	return (this->_weapon);
}
