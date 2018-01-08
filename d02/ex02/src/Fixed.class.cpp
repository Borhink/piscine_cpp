/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 21:05:51 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

int const Fixed::_fractionalBits = 8;

Fixed::Fixed(void):
_nb(0)
{
	return;
}

Fixed::Fixed(int const nb):
_nb(nb << Fixed::_fractionalBits)
{
	return;
}

Fixed::Fixed(float const nb):
_nb(roundf(nb * (1 << _fractionalBits)))
{
	return;
}

Fixed::Fixed(class Fixed const & src)
{
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	return;
}

Fixed &Fixed::operator=(class Fixed const &rhs)
{
	if (this != &rhs)
	{
		this->_nb = rhs.getRawBits();
	}
	return (*this);
}

Fixed Fixed::operator+(class Fixed const &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

int Fixed::getRawBits(void) const
{
	return (this->_nb);
}

void Fixed::setRawBits(int const nb)
{
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
