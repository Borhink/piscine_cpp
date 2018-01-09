/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 20:13:50 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main()
{
	std::cout << "=============== CREATE TRAPS ===============" << std::endl;
	ScavTrap clapTrap("ClapTrap");
	ScavTrap *clapTrap2 = new ScavTrap(clapTrap);
	FragTrap bill;
	ClapTrap claptrap3("Steve");
	NinjaTrap leeSin("Lee Sin");
	NinjaTrap shen("Shen");

	std::cout << std::endl << "=============== DELETE TRAP2 ===============" << std::endl;
	delete clapTrap2;
	bill.setName("Bill");

	std::cout << std::endl << "=============== START FIGHT ===============" << std::endl;
	clapTrap.rangedAttack("Bill");
	bill.takeDamage(clapTrap.getRangedAttackDamage());
	bill.meleeAttack("ClapTrap");
	clapTrap.takeDamage(bill.getMeleeAttackDamage());
	bill.fireBall("ClapTrap");
	clapTrap.beRepaired(200);
	bill.killProcess("ClapTrap");
	clapTrap.setEnergyPoints(0);

	std::cout << std::endl << "=============== CHALLENGE ===============" << std::endl;
	clapTrap.challengeNewcomer("Bill");

	std::cout << std::endl << "=============== VAULTHUNTER ===============" << std::endl;
	bill.vaulthunter_dot_exe("ClapTrap");

	std::cout << std::endl << "=============== NINJA STUFF ===============" << std::endl;
	leeSin.ninjaShoebox(claptrap3);
	leeSin.ninjaShoebox(clapTrap);
	leeSin.ninjaShoebox(bill);
	leeSin.ninjaShoebox(shen);

	std::cout << std::endl << "=============== FINISH HIM ===============" << std::endl;
	bill.atomicBeam("ClapTrap");
	bill.takeDamage(bill.getAtomicBeamDamage());
	clapTrap.takeDamage(bill.getAtomicBeamDamage());
	return (0);
}
