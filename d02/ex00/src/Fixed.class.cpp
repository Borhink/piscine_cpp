/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 19:59:05 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

int const Fixed::_fractionalBits = 8;

Fixed::Fixed(void):
_nb(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int nb):
_nb(nb)
{
	return;
}

Fixed::Fixed(class Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed &Fixed::operator=(class Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_nb = rhs.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nb);
}

void Fixed::setRawBits(int const nb)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nb = nb;
	return;
}

std::ostream &operator<<(std::ostream &o, class Fixed const &fixed)
{
	o << fixed.getRawBits();
	return (o);
}
