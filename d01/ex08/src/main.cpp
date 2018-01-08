/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 17:51:32 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
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
