/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/15 15:17:24 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>

class FragTrap
{

public:

	typedef void (FragTrap::*funcPtr)(std::string const &);

	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void atomicBeam(std::string const &target);
	void fireBall(std::string const &target);
	void killProcess(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const &target);

	FragTrap &operator=(FragTrap const &rhs);

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
	static funcPtr const _functions[5];
};

# endif
