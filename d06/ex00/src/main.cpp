/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/16 16:56:12 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Converter.hpp"

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		Converter convert(av[1]);

		std::cout << "char: " << convert.getChar() << std::endl;
		std::cout << "int: " << convert.getInt() << std::endl;
		std::cout << "float: " << convert.getFloat() << std::endl;
		std::cout << "double: " << convert.getDouble() << std::endl;
	}
	return (0);
}
