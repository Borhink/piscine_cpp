/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:47:21 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 18:49:06 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.class.hpp"

int main()
{
	class PhoneBook phoneBook;

	std::cout << "=========== Welcome to my PhoneBook ===========" << std::endl;
	std::cout << "You can use the following commands :" << std::endl;
	std::cout << "ADD (add a contact)" << std::endl;
	std::cout << "SEARCH (search in contacts)" << std::endl;
	std::cout << "EXIT (exit the PhoneBook)" << std::endl;
	phoneBook.run();
	return (0);
}
