/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/11 14:01:45 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void):
_name("Sorcerer"),
_title("Title")
{
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
	return;
}

Sorcerer::Sorcerer(std::string const &name, std::string const &title):
_name(name),
_title(title)
{
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
	return;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
	*this = src;
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
	return;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title \
		<< ", is dead. Consequences will never be the same !" << std::endl;
	return;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_title = rhs._title;
	}
	return (*this);
}

void Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

std::string const &Sorcerer::getName(void) const
{
	return (this->_name);
}

void Sorcerer::setName(std::string const &name)
{
	this->_name = name;
	return;
}

std::string const &Sorcerer::getTitle(void) const
{
	return (this->_title);
}

void Sorcerer::setTitle(std::string const &title)
{
	this->_title = title;
	return;
}

std::ostream &operator<<(std::ostream &o, Sorcerer const &rhs)
{
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() \
		<< ", and I like ponies !" << std::endl;
	return (o);
}
