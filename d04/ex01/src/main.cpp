/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 16:44:00 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "AtomicBeam.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "Pikachu.hpp"

int main(void)
{
	Character* zaz = new Character("zaz");

	std::cout << *zaz;

	Enemy* b = new RadScorpion();
	Enemy* a = new RadScorpion();
	Enemy* c = new Pikachu();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	AWeapon* ab = new AtomicBeam();

	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);

	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	b = NULL;

	zaz->attack(b);
	zaz->equip(pf);
	zaz->attack(c);
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;
	c = NULL;

	zaz->attack(a);
	std::cout << *zaz;

	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->equip(ab);
	std::cout << *zaz;

	zaz->attack(a);
	std::cout << *zaz;

	return 0;
}
