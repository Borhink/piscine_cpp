/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 17:29:35 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::funcPtr const FragTrap::_functions[5] = {&FragTrap::meleeAttack, &FragTrap::rangedAttack, &FragTrap::atomicBeam, &FragTrap::fireBall, &FragTrap::killProcess};

FragTrap::FragTrap(void):
_name("Default"),
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(100),
_maxEnergyPoints(100),
_level(1),
_meleeAttackDamage(30),
_rangedAttackDamage(20),
_armorDamageReduction(5),
_atomicBeamDamage(9999)
{
	std::cout << "(Default Constructor): Heeey, I'm alive ! Do you even know my name ?" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name):
_name(name),
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(100),
_maxEnergyPoints(100),
_level(1),
_meleeAttackDamage(30),
_rangedAttackDamage(20),
_armorDamageReduction(5),
_atomicBeamDamage(9999)
{
	std::cout << "(String Constructor): Heeey, I'm alive ! Why you named me " << name << " ? It's ugly.." << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &src)
{
	*this = src;
	std::cout << "(Copy Constructor): Hello " << src.getName() << " I'm " << this->_name \
		<< " ... but... it's my name... Holy fuck, you are me !!!" << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "(Destructor): Nooo, don't kill me, pleaaase. I'm a dancing robot !" << std::endl;
	return;
}

void FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "(rangedAttack): FR4G-TP " << this->_name << " throw his cam on " \
		<< target << ", causing " << this->_rangedAttackDamage \
		<< " damages ! " << this->_name << " is now blind." << std::endl;
	return;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "(meleeAttack): FR4G-TP " << this->_name << " punch " \
		<< target << " in the face, causing " \
		<< this->_meleeAttackDamage << " damages. It's hurt !" << std::endl;
	return;
}

void FragTrap::atomicBeam(std::string const &target)
{
	std::cout << "(atomicBeam): FR4G-TP " << this->_name << " launch atomic beam on " \
		<< target << ", it's super effective. " << target << " take " \
		<< this->_atomicBeamDamage << " damages, but " << this->_name \
		<< " get hited too..." << std::endl;
	return;
}

void FragTrap::fireBall(std::string const &target)
{
	std::cout << "(fireBall): FR4G-TP " << this->_name << " throw a burning paper on " \
		<< target << ". " << target << " didn't care..." << std::endl;
	return;
}

void FragTrap::killProcess(std::string const &target)
{
	std::cout << "(killProcess): FR4G-TP " << this->_name << " kill all " \
		<< target << "'s processes. " << target << " is stuned.." << std::endl;
	return;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if ((int)amount - this->_armorDamageReduction < 0)
		amount = 0;
	else
		amount -= this->_armorDamageReduction;
	std::cout << "(takeDamage): FR4G-TP " << this->_name << " take only " << amount \
	<< " damages, it's a badass robot with armor !";
	this->setHitPoints(this->_hitPoints - amount);
	std::cout << " (HP left: " << this->_hitPoints << ")" << std::endl;
	return;
}

void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "(beRepaired): FR4G-TP " << this->_name << " use a medikit, healing " << amount \
	<< " HP.";
	this->setHitPoints(this->_hitPoints + amount);
	std::cout << " (HP left: " << this->_hitPoints << ")" << std::endl;
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
		std::cout << "(vaulthunter_dot_exe): FR4G-TP " << this->_name << " have not enough energy" << std::endl;
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

std::string const &FragTrap::getName(void) const
{
	return (this->_name);
}

void FragTrap::setName(std::string const &name)
{
	this->_name = name;
	return;
}

int FragTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

void FragTrap::setHitPoints(int const val)
{
	if (val > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	else if (val < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints = val;
	return;
}

int FragTrap::getMaxHitPoints(void) const
{
	return (this->_maxHitPoints);
}

void FragTrap::setMaxHitPoints(int const val)
{
	this->_maxHitPoints = val;
	return;
}

int FragTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

void FragTrap::setEnergyPoints(int const val)
{
	if (val > this->_maxEnergyPoints)
		this->_energyPoints = this->_maxEnergyPoints;
	else if (val < 0)
		this->_energyPoints = 0;
	else
		this->_energyPoints = val;
	return;
}

int FragTrap::getMaxEnergyPoints(void) const
{
	return (this->_maxEnergyPoints);
}

void FragTrap::setMaxEnergyPoints(int const val)
{
	this->_maxEnergyPoints = val;
	return;
}

int FragTrap::getLevel(void) const
{
	return (this->_level);
}

void FragTrap::setLevel(int const val)
{
	this->_level = val;
	return;
}

int FragTrap::getMeleeAttackDamage(void) const
{
	return (this->_meleeAttackDamage);
}

void FragTrap::setMeleeAttackDamage(int const val)
{
	this->_meleeAttackDamage = val;
	return;
}

int FragTrap::getRangedAttackDamage(void) const
{
	return (this->_rangedAttackDamage);
}

void FragTrap::setRangedAttackDamage(int const val)
{
	this->_rangedAttackDamage = val;
	return;
}

int FragTrap::getArmorDamageReduction(void) const
{
	return (this->_armorDamageReduction);
}

void FragTrap::setArmorDamageReduction(int const val)
{
	this->_armorDamageReduction = val;
	return;
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
