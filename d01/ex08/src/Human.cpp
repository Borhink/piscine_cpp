/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 13:57:52 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::funcPtr const Human::_functions[4] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout, &Human::atomicBeam};
std::string const Human::_functionsName[4] = {"meleeAttack", "rangedAttack", "intimidatingShout", "atomicBeam"};

Human::Human(std::string name):
_name(name)
{
	return;
}

Human::~Human(void)
{
	return;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	for (int i = 0; i < 4; i++)
	{
		if (Human::_functionsName[i] == action_name)
			(this->*(Human::_functions[i]))(target);
	}
	return;
}

std::string const &Human::getName(void) const
{
	return (this->_name);
}

void Human::meleeAttack(std::string const &target)
{
	std::cout << this->_name << " uses melee attack on " << target << std::endl;
	return;
}

void Human::rangedAttack(std::string const &target)
{
	std::cout << this->_name << " uses ranged attack on " << target << std::endl;
	return;
}

void Human::intimidatingShout(std::string const &target)
{
	std::cout << this->_name << " uses intimidating shout on " << target << std::endl;
	return;
}

void Human::atomicBeam(std::string const &target)
{
	std::cout << this->_name << " uses atomic beam on " << target << ". " \
	<< target << " is dead, " << this->_name << " is dead too." << std::endl;
	return;
}
