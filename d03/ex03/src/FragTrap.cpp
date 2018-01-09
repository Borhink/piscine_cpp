/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 19:37:46 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::funcPtr const FragTrap::_functions[5] = {&FragTrap::meleeAttack, &FragTrap::rangedAttack, &FragTrap::atomicBeam, &FragTrap::fireBall, &FragTrap::killProcess};

FragTrap::FragTrap(void):
_atomicBeamDamage(9999)
{
	this->_name = "FragTrap";
	std::cout << "(FragTrap Default Constructor): Heeey, I'm alive ! You don't named me !" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name):
ClapTrap(name),
_atomicBeamDamage(9999)
{
	std::cout << "(FragTrap String Constructor): Heeey, I'm alive ! My lovely name is " << name << " !" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &src):
ClapTrap(src)
{
	*this = src;
	std::cout << "(FragTrap Copy Constructor): Hello " << src.getName() << " I'm " << this->_name \
		<< " ... You are me or I am you ?" << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "(FragTrap Destructor): Nooo, don't kill me, pleaaase. I can make bubbles for you !" << std::endl;
	return;
}

void FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "(FragTrap rangedAttack): FR4G-TP " << this->_name << " throw his cam on " \
		<< target << ", causing " << this->_rangedAttackDamage \
		<< " damages ! " << this->_name << " is now blind." << std::endl;
	return;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "(FragTrap meleeAttack): FR4G-TP " << this->_name << " punch " \
		<< target << " in the face, causing " \
		<< this->_meleeAttackDamage << " damages. It's hurt !" << std::endl;
	return;
}

void FragTrap::atomicBeam(std::string const &target)
{
	std::cout << "(FragTrap atomicBeam): FR4G-TP " << this->_name << " launch atomic beam on " \
		<< target << ", it's super effective. " << target << " take " \
		<< this->_atomicBeamDamage << " damages, but " << this->_name \
		<< " get hited too..." << std::endl;
	return;
}

void FragTrap::fireBall(std::string const &target)
{
	std::cout << "(FragTrap fireBall): FR4G-TP " << this->_name << " throw a burning paper on " \
		<< target << ". " << target << " didn't care..." << std::endl;
	return;
}

void FragTrap::killProcess(std::string const &target)
{
	std::cout << "(FragTrap killProcess): FR4G-TP " << this->_name << " kill all " \
		<< target << "'s processes. " << target << " is stuned.." << std::endl;
	return;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	std::srand(std::time(nullptr));
	if (this->_energyPoints >= 25)
	{
		(this->*(FragTrap::_functions[std::rand() % 5]))(target);
		this->setEnergyPoints(this->_energyPoints - 25);
	}
	else
		std::cout << "(FragTrap vaulthunter_dot_exe): FR4G-TP " << this->_name << " have not enough energy" << std::endl;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
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
		this->_atomicBeamDamage = rhs.getAtomicBeamDamage();
	}
	return (*this);
}

int FragTrap::getAtomicBeamDamage(void) const
{
	return (this->_atomicBeamDamage);
}

void FragTrap::setAtomicBeamDamage(int const val)
{
	this->_atomicBeamDamage = val;
	return;
}
