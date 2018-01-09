/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 12:44:49 by qhonore          ###   ########.fr       */
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

Fixed::Fixed(Fixed const & src)
{
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	return;
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

Fixed const &Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
	return (lhs > rhs ? lhs : rhs);
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs > rhs ? lhs : rhs);
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->_nb = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return (this->_nb > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return (this->_nb < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return (this->_nb >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return (this->_nb <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return (this->_nb == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return (this->_nb != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->_nb++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->_nb--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed fixed(*this);
	this->_nb++;
	return (fixed);
}

Fixed Fixed::operator--(int)
{
	Fixed fixed(*this);
	this->_nb--;
	return (fixed);
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

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
