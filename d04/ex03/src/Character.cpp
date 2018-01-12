/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 13:24:52 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void):
_name("Default")
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	return;
}

Character::Character(std::string const &name):
_name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	return;
}

Character::Character(Character const &src)
{
	*this = src;
	return;
}

Character::~Character(void)
{
	return;
}

Character &Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
			this->_materias[i] = rhs._materias[i];
		this->_name = rhs._name;
	}
	return (*this);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if (!this->_materias[i])
		{
			this->_materias[i] = m;
			break;
		}
	return;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_materias[idx])
		this->_materias[idx] = NULL;
	return;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_materias[idx])
		this->_materias[idx]->use(target);
	return;
}

std::string const &Character::getName(void) const
{
	return (this->_name);
}
