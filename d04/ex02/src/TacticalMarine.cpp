/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:41:07 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/11 20:44:21 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void)
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
	return;
}

TacticalMarine::TacticalMarine(const TacticalMarine &src)
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
	*this = src;
	return;
}

TacticalMarine::~TacticalMarine(void)
{
	std::cout << "Aaargh ..." << std::endl;
	return;
}

TacticalMarine &TacticalMarine::operator=(TacticalMarine const &rhs)
{
	if (this != &rhs)
	{
		//this->something = rhs.something;
	}
	return (*this);
}

ISpaceMarine *TacticalMarine::clone(void) const
{
	return (new TacticalMarine(*this));
}

void TacticalMarine::battleCry(void) const
{
	std::cout << "For the holy PLOT !" << std::endl;
	return;
}

void TacticalMarine::rangedAttack(void) const
{
	std::cout << "* attacks with bolter *" << std::endl;
	return;
}

void TacticalMarine::meleeAttack(void) const
{
	std::cout << "* attacks with chainsword *" << std::endl;
	return;
}
