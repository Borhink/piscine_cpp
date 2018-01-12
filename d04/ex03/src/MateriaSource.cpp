/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 14:04:29 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	return;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	*this = src;
	return;
}

MateriaSource::~MateriaSource(void)
{
	return;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
			this->_materias[i] = rhs._materias[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
		if (!this->_materias[i])
		{
			this->_materias[i] = materia;
			break;
		}
	return;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	return (NULL);
}
