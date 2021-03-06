/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 13:53:45 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main()
{
	class Human bob("Bob");
	class Human steve("Steve");

	bob.action("meleeAttack", steve.getName());
	bob.action("rangedAttack", steve.getName());
	steve.action("intimidatingShout", bob.getName());
	bob.action("intimidatingShout", steve.getName());
	steve.action("atomicBeam", bob.getName());
	steve.action("gwgwg", bob.getName());
	bob.action("-1", steve.getName());
	steve.action("84654", bob.getName());
	return (0);
}
