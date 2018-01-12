/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 13:07:38 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void):
AMateria("cure")
{
	return;
}

Cure::Cure(Cure const &src)
{
	*this = src;
	return;
}

Cure::~Cure(void)
{
	return;
}

Cure &Cure::operator=(Cure const &rhs)
{
	if (this != &rhs)
	{
		this->_xp = rhs._xp;
		this->_type = rhs._type;
	}
	return (*this);
}

Cure *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	this->_xp += 10;
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return;
}
