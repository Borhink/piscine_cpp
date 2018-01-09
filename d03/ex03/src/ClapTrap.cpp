/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 19:16:35 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
_name("ClapTrap"),
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(100),
_maxEnergyPoints(100),
_level(1),
_meleeAttackDamage(30),
_rangedAttackDamage(20),
_armorDamageReduction(5)
{
	std::cout << "(ClapTrap Default Constructor): Heeey, I'm alive !" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name):
_name(name),
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(100),
_maxEnergyPoints(100),
_level(1),
_meleeAttackDamage(30),
_rangedAttackDamage(20),
_armorDamageReduction(5)
{
	std::cout << "(ClapTrap String Constructor): Heeey, I'm alive !" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
	std::cout << "(ClapTrap Copy Constructor): Hello " << src.getName() \
		<< " I'm " << this->_name << std::endl;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "(ClapTrap Destructor): Nooo, don't kill me, pleaaase." << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)amount - this->_armorDamageReduction < 0)
		amount = 0;
	else
		amount -= this->_armorDamageReduction;
	std::cout << "(ClapTrap takeDamage): FR4G-TP " << this->_name << " take only " << amount \
		<< " damages, it's a badass robot with armor !";
	this->setHitPoints(this->_hitPoints - amount);
	std::cout << " (HP left: " << this->_hitPoints << ")" << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "(ClapTrap beRepaired): FR4G-TP " << this->_name << " use a medikit, healing " << amount \
		<< " HP.";
	this->setHitPoints(this->_hitPoints + amount);
	std::cout << " (HP left: " << this->_hitPoints << ")" << std::endl;
	return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_maxHitPoints = rhs.getMaxHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
		this->_level = rhs.getLevel();
		this->_meleeAttackDamage = rhs.getMeleeAttackDamage();
		this->_rangedAttackDamage = rhs.getRangedAttackDamage();
		this->_armorDamageReduction = rhs.getArmorDamageReduction();
	}
	return (*this);
}

std::string const &ClapTrap::getName(void) const
{
	return (this->_name);
}

void ClapTrap::setName(std::string const &name)
{
	this->_name = name;
	return;
}

int ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

void ClapTrap::setHitPoints(int const val)
{
	if (val > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	else if (val < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints = val;
	return;
}

int ClapTrap::getMaxHitPoints(void) const
{
	return (this->_maxHitPoints);
}

void ClapTrap::setMaxHitPoints(int const val)
{
	this->_maxHitPoints = val;
	return;
}

int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

void ClapTrap::setEnergyPoints(int const val)
{
	if (val > this->_maxEnergyPoints)
		this->_energyPoints = this->_maxEnergyPoints;
	else if (val < 0)
		this->_energyPoints = 0;
	else
		this->_energyPoints = val;
	return;
}

int ClapTrap::getMaxEnergyPoints(void) const
{
	return (this->_maxEnergyPoints);
}

void ClapTrap::setMaxEnergyPoints(int const val)
{
	this->_maxEnergyPoints = val;
	return;
}

int ClapTrap::getLevel(void) const
{
	return (this->_level);
}

void ClapTrap::setLevel(int const val)
{
	this->_level = val;
	return;
}

int ClapTrap::getMeleeAttackDamage(void) const
{
	return (this->_meleeAttackDamage);
}

void ClapTrap::setMeleeAttackDamage(int const val)
{
	this->_meleeAttackDamage = val;
	return;
}

int ClapTrap::getRangedAttackDamage(void) const
{
	return (this->_rangedAttackDamage);
}

void ClapTrap::setRangedAttackDamage(int const val)
{
	this->_rangedAttackDamage = val;
	return;
}

int ClapTrap::getArmorDamageReduction(void) const
{
	return (this->_armorDamageReduction);
}

void ClapTrap::setArmorDamageReduction(int const val)
{
	this->_armorDamageReduction = val;
	return;
}
