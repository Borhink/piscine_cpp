/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 17:26:56 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int main()
{
	FragTrap clapTrap("ClapTrap");
	FragTrap *clapTrap2 = new FragTrap(clapTrap);
	FragTrap bill;

	delete clapTrap2;
	bill.setName("Bill");

	clapTrap.rangedAttack("Bill");
	bill.takeDamage(clapTrap.getRangedAttackDamage());

	bill.meleeAttack("ClapTrap");
	clapTrap.takeDamage(bill.getMeleeAttackDamage());

	clapTrap.fireBall("Bill");

	bill.killProcess("ClapTrap");
	clapTrap.setEnergyPoints(0);

	clapTrap.vaulthunter_dot_exe("Bill");
	bill.vaulthunter_dot_exe("ClapTrap");

	clapTrap.atomicBeam("Bill");
	bill.takeDamage(clapTrap.getAtomicBeamDamage());
	clapTrap.takeDamage(bill.getAtomicBeamDamage());
	return (0);
}
