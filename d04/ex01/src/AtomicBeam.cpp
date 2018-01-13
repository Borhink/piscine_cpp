/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AtomicBeam.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 16:42:39 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AtomicBeam.hpp"

AtomicBeam::AtomicBeam(void):
AWeapon("Atomic Beam", 25, 999)
{
	return;
}

AtomicBeam::AtomicBeam(AtomicBeam const &src)
{
	*this = src;
	return;
}

AtomicBeam::~AtomicBeam(void)
{
	return;
}

AtomicBeam &AtomicBeam::operator=(AtomicBeam const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_apcost = rhs._apcost;
		this->_damage = rhs._damage;
	}
	return (*this);
}

void AtomicBeam::attack(void) const
{
	std::cout << "* bzzzZZZZ BZZZZIUUUUUUUU *" << std::endl;
	return;
}
