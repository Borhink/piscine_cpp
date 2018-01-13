/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zaz.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 15:26:40 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zaz.hpp"

Zaz::Zaz(void):
Victim("Zaz")
{
	std::cout << "I love ponies, I'm a ponyyy !" << std::endl;
	return;
}

Zaz::Zaz(std::string const &name):
Victim(name)
{
	std::cout << "I love ponies, I'm a ponyyy !" << std::endl;
	return;
}

Zaz::Zaz(Zaz const &src)
{
	*this = src;
	std::cout << "I love ponies, I'm a ponyyy !" << std::endl;
	return;
}

Zaz::~Zaz(void)
{
	std::cout << "I want to live more, noooo..." << std::endl;
	return;
}

Zaz &Zaz::operator=(Zaz const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
	}
	return (*this);
}

void Zaz::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a otter !" << std::endl;
}
