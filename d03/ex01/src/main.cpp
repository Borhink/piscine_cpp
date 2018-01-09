/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 18:26:35 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap clapTrap("ClapTrap");
	ScavTrap *clapTrap2 = new ScavTrap(clapTrap);
	FragTrap bill;

	delete clapTrap2;
	bill.setName("Bill");

	clapTrap.rangedAttack("Bill");
	bill.takeDamage(clapTrap.getRangedAttackDamage());

	bill.meleeAttack("ClapTrap");
	clapTrap.takeDamage(bill.getMeleeAttackDamage());

	clapTrap.fireBall("Bill");
	clapTrap.beRepaired(200);

	bill.killProcess("ClapTrap");
	clapTrap.setEnergyPoints(0);

	clapTrap.challengeNewcomer("Bill");
	bill.vaulthunter_dot_exe("ClapTrap");

	clapTrap.atomicBeam("Bill");
	bill.takeDamage(clapTrap.getAtomicBeamDamage());
	clapTrap.takeDamage(bill.getAtomicBeamDamage());
	return (0);
}
