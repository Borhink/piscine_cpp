/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 13:04:41 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void):
_xp(0),
_type("AMateria")
{
	return;
}

AMateria::AMateria(std::string const &type):
_xp(0),
_type(type)
{
	return;
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
	return;
}

AMateria::~AMateria(void)
{
	return;
}

AMateria &AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
	{
		this->_xp = rhs._xp;
		this->_type = rhs._type;
	}
	return (*this);
}

unsigned int AMateria::getXP(void) const
{
	return (this->_xp);
}

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}
