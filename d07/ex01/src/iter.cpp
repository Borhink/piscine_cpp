/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/17 18:10:07 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename T>
void function(T &addr)
{
	addr++;
}

template <typename T>
void iter(T *addr, size_t len, void (*func)(T &))
{
	for (size_t i = 0; i < len; i++)
		func(addr[i]);
}

int main(void)
{
	std::string str("Bonjour, je suis une string");

	std::cout << "str = " << str << std::endl;
	iter(const_cast<char*>(str.c_str()), str.size(), &function);
	std::cout << "str = " << str << std::endl;

	int tab[5] = {1, 23, 3, 6, 15};

	std::cout << "tab =";
	for (int i = 0; i < 5; i++)
		std::cout << " " << tab[i];
	std::cout << std::endl;
	iter(tab, 5, &function);
	std::cout << "tab =";
	for (int i = 0; i < 5; i++)
		std::cout << " " << tab[i];
	std::cout << std::endl;

	return (0);
}
