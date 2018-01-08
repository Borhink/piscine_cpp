/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 13:33:34 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type):
_type(type)
{
	return;
}

Weapon::~Weapon(void)
{
	return;
}

std::string const &Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	if (!type.empty())
		this->_type = type;
	return;
}
