/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 18:20:48 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

class ScavTrap
{

public:

	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);

	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void atomicBeam(std::string const &target);
	void fireBall(std::string const &target);
	void killProcess(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(std::string const &target);

	ScavTrap &operator=(ScavTrap const &rhs);

	std::string const &getName(void) const;
	void setName(std::string const &name);
	int getHitPoints(void) const;
	void setHitPoints(int const val);
	int getMaxHitPoints(void) const;
	void setMaxHitPoints(int const val);
	int getEnergyPoints(void) const;
	void setEnergyPoints(int const val);
	int getMaxEnergyPoints(void) const;
	void setMaxEnergyPoints(int const val);
	int getLevel(void) const;
	void setLevel(int const val);
	int getMeleeAttackDamage(void) const;
	void setMeleeAttackDamage(int const val);
	int getRangedAttackDamage(void) const;
	void setRangedAttackDamage(int const val);
	int getArmorDamageReduction(void) const;
	void setArmorDamageReduction(int const val);
	int getAtomicBeamDamage(void) const;
	void setAtomicBeamDamage(int const val);

private:

	std::string _name;
	int _hitPoints;
	int _maxHitPoints;
	int _energyPoints;
	int _maxEnergyPoints;
	int _level;
	int _meleeAttackDamage;
	int _rangedAttackDamage;
	int _armorDamageReduction;
	int _atomicBeamDamage;
	static std::string const _challenges[5];
};

# endif
