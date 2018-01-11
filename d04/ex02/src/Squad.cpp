/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/11 20:44:55 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad(void):
_units(0),
_squad(NULL)
{
	return;
}

Squad::Squad(Squad const &src)
{
	*this = src;
	return;
}

Squad::~Squad(void)
{
	t_marineList *tmp = this->_squad;
	t_marineList *next;

	while (tmp)
	{
		next = tmp->next;
		delete tmp->marine;
		delete tmp;
		tmp = next;
	}
	return;
}

Squad &Squad::operator=(Squad const &rhs)
{
	t_marineList *tmp = this->_squad;
	t_marineList *next;

	if (this != &rhs)
	{
		while (tmp)
		{
			next = tmp->next;
			delete tmp->marine;
			delete tmp;
			tmp = next;
		}
		this->_squad = NULL;
		tmp = rhs._squad;
		while (tmp)
		{
			this->push(tmp->marine->clone());
			tmp = next;
		}
		this->_units = rhs._units;
	}
	return (*this);
}

int Squad::getCount(void) const
{
	return (this->_units);
}

ISpaceMarine *Squad::getUnit(int nb) const
{
	t_marineList *tmp = this->_squad;

	if (tmp && nb >= 0 && nb < this->_units)
	{
		for (int i = 0; i < nb; i++)
			tmp = tmp->next;
		return (tmp->marine);
	}
	return (NULL);
}

int Squad::push(ISpaceMarine *marine)
{
	t_marineList *tmp = this->_squad;

	if (!marine)
		return (this->_units);
	if (!tmp)
	{
		this->_squad = new t_marineList;
		this->_squad->marine = marine;
		this->_squad->next = NULL;
		this->_units++;
	}
	else if (!this->alreadyInSquad(marine))
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new t_marineList;
		tmp->next->marine = marine;
		tmp->next->next = NULL;
		this->_units++;
	}
	return (this->_units);
}

bool Squad::alreadyInSquad(ISpaceMarine *marine) const
{
	t_marineList *tmp = this->_squad;

	while (tmp)
	{
		if (tmp->marine == marine)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}
