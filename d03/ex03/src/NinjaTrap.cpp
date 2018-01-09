/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 20:17:26 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void)
{
	this->_name = "NinjaTrap";
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_meleeAttackDamage = 40;
	this->_rangedAttackDamage = 5;
	this->_armorDamageReduction = 0;
	std::cout << "(NinjaTrap Default Constructor): Heeey, I'm alive ! Ninja have no name..." << std::endl;
	return;
}

NinjaTrap::NinjaTrap(std::string name):
ClapTrap(name)
{
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_meleeAttackDamage = 40;
	this->_rangedAttackDamage = 5;
	this->_armorDamageReduction = 0;
	std::cout << "(NinjaTrap String Constructor): Heeey, I'm alive ! Super ninja " << name << " is OP.." << std::endl;
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src):
ClapTrap(src)
{
	*this = src;
	std::cout << "(NinjaTrap Copy Constructor): Hello " << src.getName() << " I'm " << this->_name \
		<< " ... Idiot, you cloned a ninja ?!!" << std::endl;
	return;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "(NinjaTrap Destructor): Nooo, don't kill me, pleaaase. I have shurikens !" << std::endl;
	return;
}

void NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout << "(NinjaTrap rangedAttack): FR4G-TP " << this->_name << " throw his cam on " \
		<< target << ", causing " << this->_rangedAttackDamage \
		<< " damages ! " << this->_name << " is now blind." << std::endl;
	return;
}

void NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << "(NinjaTrap meleeAttack): FR4G-TP " << this->_name << " punch " \
		<< target << " in the face, causing " \
		<< this->_meleeAttackDamage << " damages. It's hurt !" << std::endl;
	return;
}

void NinjaTrap::ninjaShoebox(ClapTrap &target)
{
	std::cout << "(NinjaTrap ninjaShoebox): FR4G-TP " << this->_name << " throw a shuriken in the balls of " \
		<< target.getName() << ", causing " \
		<< this->_rangedAttackDamage << " damages. Take that !" << std::endl;
	target.takeDamage(this->_rangedAttackDamage);
	return;
}

void NinjaTrap::ninjaShoebox(FragTrap &target)
{
	std::cout << "(NinjaTrap ninjaShoebox): FR4G-TP " << this->_name << " cut the brain of " \
		<< target.getName() << " with a katana, causing " \
		<< this->_meleeAttackDamage << " damages. Brain is a good breakfast !" << std::endl;
	target.takeDamage(this->_meleeAttackDamage);
	return;
}

void NinjaTrap::ninjaShoebox(ScavTrap &target)
{
	std::cout << "(NinjaTrap ninjaShoebox): FR4G-TP " << this->_name << " intimidate " \
		<< target.getName() << " with some funky moves. In reaction, " \
		<< target.getName() << " challenge itself !" << std::endl;
	target.challengeNewcomer(target.getName());
	return;
}

void NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	std::cout << "(NinjaTrap ninjaShoebox): FR4G-TP " << this->_name << " use a ninja attack on " \
		<< target.getName() << ". " << target.getName() << " is a ninja and counter attack" << std::endl;
	this->meleeAttack(target.getName());
	target.takeDamage(this->_meleeAttackDamage);
	target.meleeAttack(this->_name);
	this->takeDamage(target.getMeleeAttackDamage());
	return;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs)
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
