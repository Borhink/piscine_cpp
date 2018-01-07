/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/07 18:39:51 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheHeap(void)
{
	class Pony *pony = new Pony();

	pony->sayHello();
	delete pony;
}

void ponyOnTheStack(void)
{
	class Pony pony;

	pony.sayHello();
}

int main()
{
	std::cout << "Stack pony :" << std::endl;
	ponyOnTheStack();
	std::cout << std::endl << "Heap pony :" << std::endl;
	ponyOnTheHeap();
	return (0);
}
