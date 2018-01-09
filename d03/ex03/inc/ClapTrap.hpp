/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 19:16:34 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

public:

	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap(void);

	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap &operator=(ClapTrap const &rhs);

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

protected:

	std::string _name;
	int _hitPoints;
	int _maxHitPoints;
	int _energyPoints;
	int _maxEnergyPoints;
	int _level;
	int _meleeAttackDamage;
	int _rangedAttackDamage;
	int _armorDamageReduction;
};

# endif
