/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/07 19:50:53 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int main()
{
	class ZombieEvent event;
	class Zombie *zombie1, *zombie2, *zombie3;

	event.setZombieType("Runner");
	zombie1 = event.newZombie("Goliath");
	zombie1->announce();
	delete zombie1;

	event.setZombieType("Creepy");
	zombie2 = event.randomChump();
	delete zombie2;

	event.setZombieType("Explosive");
	zombie3 = event.randomChump();
	delete zombie3;
	return (0);
}
