/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 13:07:41 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void):
AMateria("ice")
{
	return;
}

Ice::Ice(Ice const &src)
{
	*this = src;
	return;
}

Ice::~Ice(void)
{
	return;
}

Ice &Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
	{
		this->_xp = rhs._xp;
		this->_type = rhs._type;
	}
	return (*this);
}

Ice *Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	this->_xp += 10;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return;
}
