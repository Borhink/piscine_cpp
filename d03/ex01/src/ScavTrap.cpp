/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 18:28:59 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::string const ScavTrap::_challenges[5] = {"cook a pizza cake", "play pokemon go everyday", "go in the jungle and kill a gorilla", "play the game Escape From Tarkov and survive", "do nothing for one year"};

ScavTrap::ScavTrap(void):
_name("ScavTrap"),
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(50),
_maxEnergyPoints(50),
_level(1),
_meleeAttackDamage(20),
_rangedAttackDamage(15),
_armorDamageReduction(3),
_atomicBeamDamage(9999)
{
	std::cout << "(ScavTrap Default Constructor): Heeey, I'm alive ! Do you even know my name ?" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name):
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
	std::cout << "(ScavTrap String Constructor): Heeey, I'm alive ! Why you named me " << name << " ? It's ugly.." << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src)
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

void ScavTrap::atomicBeam(std::string const &target)
{
	std::cout << "(ScavTrap atomicBeam): FR4G-TP " << this->_name << " launch atomic beam on " \
		<< target << ", it's super effective. " << target << " take " \
		<< this->_atomicBeamDamage << " damages, but " << this->_name \
		<< " get hited too..." << std::endl;
	return;
}

void ScavTrap::fireBall(std::string const &target)
{
	std::cout << "(ScavTrap fireBall): FR4G-TP " << this->_name << " throw a burning paper on " \
		<< target << ". " << target << " didn't care..." << std::endl;
	return;
}

void ScavTrap::killProcess(std::string const &target)
{
	std::cout << "(ScavTrap killProcess): FR4G-TP " << this->_name << " kill all " \
		<< target << "'s processes. " << target << " is stuned.." << std::endl;
	return;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if ((int)amount - this->_armorDamageReduction < 0)
		amount = 0;
	else
		amount -= this->_armorDamageReduction;
	std::cout << "(ScavTrap takeDamage): FR4G-TP " << this->_name << " take only " << amount \
		<< " damages, it's a badass robot with armor !";
	this->setHitPoints(this->_hitPoints - amount);
	std::cout << " (HP left: " << this->_hitPoints << ")" << std::endl;
	return;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "(ScavTrap beRepaired): FR4G-TP " << this->_name << " use a medikit, healing " << amount \
		<< " HP.";
	this->setHitPoints(this->_hitPoints + amount);
	std::cout << " (HP left: " << this->_hitPoints << ")" << std::endl;
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
		this->_atomicBeamDamage = rhs.getAtomicBeamDamage();
	}
	return (*this);
}

std::string const &ScavTrap::getName(void) const
{
	return (this->_name);
}

void ScavTrap::setName(std::string const &name)
{
	this->_name = name;
	return;
}

int ScavTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

void ScavTrap::setHitPoints(int const val)
{
	if (val > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	else if (val < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints = val;
	return;
}

int ScavTrap::getMaxHitPoints(void) const
{
	return (this->_maxHitPoints);
}

void ScavTrap::setMaxHitPoints(int const val)
{
	this->_maxHitPoints = val;
	return;
}

int ScavTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

void ScavTrap::setEnergyPoints(int const val)
{
	if (val > this->_maxEnergyPoints)
		this->_energyPoints = this->_maxEnergyPoints;
	else if (val < 0)
		this->_energyPoints = 0;
	else
		this->_energyPoints = val;
	return;
}

int ScavTrap::getMaxEnergyPoints(void) const
{
	return (this->_maxEnergyPoints);
}

void ScavTrap::setMaxEnergyPoints(int const val)
{
	this->_maxEnergyPoints = val;
	return;
}

int ScavTrap::getLevel(void) const
{
	return (this->_level);
}

void ScavTrap::setLevel(int const val)
{
	this->_level = val;
	return;
}

int ScavTrap::getMeleeAttackDamage(void) const
{
	return (this->_meleeAttackDamage);
}

void ScavTrap::setMeleeAttackDamage(int const val)
{
	this->_meleeAttackDamage = val;
	return;
}

int ScavTrap::getRangedAttackDamage(void) const
{
	return (this->_rangedAttackDamage);
}

void ScavTrap::setRangedAttackDamage(int const val)
{
	this->_rangedAttackDamage = val;
	return;
}

int ScavTrap::getArmorDamageReduction(void) const
{
	return (this->_armorDamageReduction);
}

void ScavTrap::setArmorDamageReduction(int const val)
{
	this->_armorDamageReduction = val;
	return;
}

int ScavTrap::getAtomicBeamDamage(void) const
{
	return (this->_atomicBeamDamage);
}

void ScavTrap::setAtomicBeamDamage(int const val)
{
	this->_atomicBeamDamage = val;
	return;
}
