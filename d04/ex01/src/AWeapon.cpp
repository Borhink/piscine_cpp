/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/11 17:38:45 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(void)
{
	return;
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage):
_name(name),
_apcost(apcost),
_damage(damage)
{
	return;
}

AWeapon::AWeapon(AWeapon const &src)
{
	*this = src;
	return;
}

AWeapon::~AWeapon(void)
{
	return;
}

AWeapon &AWeapon::operator=(AWeapon const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_apcost = rhs._apcost;
		this->_damage = rhs._damage;
	}
	return (*this);
}

std::string const &AWeapon::getName(void) const
{
	return (this->_name);
}

void AWeapon::setName(std::string const &name)
{
	this->_name = name;
	return;
}

int AWeapon::getAPCost(void) const
{
	return (this->_apcost);
}

void AWeapon::setAPCost(int const apcost)
{
	this->_apcost = apcost;
	return;
}

int AWeapon::getDamage(void) const
{
	return (this->_damage);
}

void AWeapon::setDamage(int const damage)
{
	this->_damage = damage;
	return;
}
