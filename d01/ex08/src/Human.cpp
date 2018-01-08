/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 17:42:32 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::funcPtr const Human::_functions[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

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
	int i = action_name[0] - '0';

	if (i >= 0 && i <= 2)
		(this->*_functions[i])(target);
	return;
}

std::string const &Human::getName(void) const
{
	return (this->_name);
}

void Human::meleeAttack(std::string const &target)
{
	std::cout << this->_name << " use melee attack on " << target << std::endl;
	return;
}

void Human::rangedAttack(std::string const &target)
{
	std::cout << this->_name << " use ranged attack on " << target << std::endl;
	return;
}

void Human::intimidatingShout(std::string const &target)
{
	std::cout << this->_name << " use intimidating shout on " << target << std::endl;
	return;
}
