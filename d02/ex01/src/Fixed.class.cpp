/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 20:48:07 by qhonore          ###   ########.fr       */
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

Fixed::Fixed(int const nb):
_nb(nb << Fixed::_fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(float const nb):
_nb(roundf(nb * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
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

float Fixed::toFloat(void) const
{
	return ((float)this->_nb / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_nb >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &o, class Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
