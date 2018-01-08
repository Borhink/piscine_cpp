/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 18:52:53 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main()
{
	class Human bob("Bob");
	class Human steve("Steve");

	bob.action("0", steve.getName());
	bob.action("1", steve.getName());
	steve.action("2", bob.getName());
	bob.action("2", steve.getName());
	steve.action("gwgwg", bob.getName());
	bob.action("-1", steve.getName());
	steve.action("84654", bob.getName());
	return (0);
}
