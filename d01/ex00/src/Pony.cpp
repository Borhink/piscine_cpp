/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:30 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/07 19:44:32 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(void)
{
	std::cout << "A new pony was born ! (CREATED)" << std::endl;
	return;
}

Pony::~Pony(void)
{
	std::cout << "My pony died, OH NOOO ! (DELETED)" << std::endl;
	return;
}

void Pony::sayHello(void) const
{
	std::cout << "Are you serious ? Pony can't talk..." << std::endl;
	return;
}
