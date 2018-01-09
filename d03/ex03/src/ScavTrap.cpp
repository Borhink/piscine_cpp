/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 19:24:31 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::string const ScavTrap::_challenges[5] = {"cook a pizza cake", "play pokemon go everyday", "go in the jungle and kill a gorilla", "play the game Escape From Tarkov and survive", "do nothing for one year"};

ScavTrap::ScavTrap(void)
{
	this->_name = "ScavTrap";
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;
	std::cout << "(ScavTrap Default Constructor): Heeey, I'm alive ! Do you even know my name ?" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name):
ClapTrap(name)
{
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;
	std::cout << "(ScavTrap String Constructor): Heeey, I'm alive ! Why you named me " << name << " ? It's ugly.." << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src):
ClapTrap(src)
{
	*this = src;
	std::cout << "(ScavTrap Copy Constructor): Hello " << src.getName() << " I'm " << this->_name \
		<< " ... but... it's my name... Holy fuck, you are me !!!" << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "(ScavTrap Destructor): Nooo, don't kill me, pleaaase. I'm a dancing robot !" << std::endl;
	return;
}

void ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "(ScavTrap rangedAttack): FR4G-TP " << this->_name << " throw his cam on " \
		<< target << ", causing " << this->_rangedAttackDamage \
		<< " damages ! " << this->_name << " is now blind." << std::endl;
	return;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "(ScavTrap meleeAttack): FR4G-TP " << this->_name << " punch " \
		<< target << " in the face, causing " \
		<< this->_meleeAttackDamage << " damages. It's hurt !" << std::endl;
	return;
}

void ScavTrap::challengeNewcomer(std::string const &target)
{
	std::string challenge;
	std::srand(std::time(nullptr));
	challenge = ScavTrap::_challenges[std::rand() % 5];
	std::cout << "(ScavTrap challengeNewcomer): " << target << " will try to " \
		<< challenge << " ! I'm so happy !" << std::endl;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
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
