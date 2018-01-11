/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/11 18:37:15 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	return;
}

Character::Character(std::string const &name):
_name(name),
_ap(40),
_weapon(NULL)
{
	return;
}

Character::Character(Character const &src)
{
	*this = src;
	return;
}

Character::~Character(void)
{
	return;
}

Character &Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_ap = rhs._ap;
		this->_weapon = rhs._weapon;
	}
	return (*this);
}

void Character::recoverAP(void)
{
	this->_ap += 10;
	if (this->_ap > 40)
		this->_ap = 40;
	return;
}

void Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
	return;
}

void Character::attack(Enemy *enemy)
{
	if (enemy && this->_weapon && this->_ap >= this->_weapon->getAPCost())
	{
		std::cout << this->_name << " attacks " << enemy->getType() \
			<< " with a " << this->_weapon->getName() << std::endl;
		this->_ap -= this->_weapon->getAPCost();
		this->_weapon->attack();
		enemy->takeDamage(this->_weapon->getDamage());
		if (enemy->getHP() <= 0)
			delete enemy;
	}
	return;
}

std::string const &Character::getName(void) const
{
	return (this->_name);
}

void Character::setName(std::string const &name)
{
	this->_name = name;
	return;
}

int Character::getAP(void) const
{
	return (this->_ap);
}

void Character::setAP(int const ap)
{
	this->_ap = ap;
	return;
}

AWeapon const *Character::getWeapon(void) const
{
	return (this->_weapon);
}

std::ostream &operator<<(std::ostream &o, Character const &rhs)
{
	if (rhs.getWeapon())
		o << rhs.getName() << " has " << rhs.getAP() \
			<< " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
	else
		o << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
	return (o);
}
