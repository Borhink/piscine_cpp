/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:50:52 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/05 19:18:41 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"

PhoneBook::PhoneBook(void):
_run(true),
_nbContacts(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::run(void)
{
	std::string buffer;

	while (this->_run)
	{
		std::getline(std::cin, buffer);
		if (buffer == "ADD")
			this->addContact();
		else if (buffer == "EXIT")
		{
			std::cout << "Closing PhoneBook..." << std::endl;
			this->_run = false;
		}
	}
}

void PhoneBook::addContact(void)
{
	std::string buffer;

	if (this->_nbContacts == 8)
		std::cout << "The PhoneBook is already full !" << std::endl;
	else
	{
		class Contact &contact = this->_contacts[this->_nbContacts];

		std::cout << "Enter firstname: ";
		std::getline(std::cin, buffer);
		contact.setFirstName(buffer);
		std::cout << "Enter lastname: ";
		std::getline(std::cin, buffer);
		contact.setLastName(buffer);
		std::cout << "Enter nickname: ";
		std::getline(std::cin, buffer);
		contact.setNickname(buffer);
		std::cout << "Enter login: ";
		std::getline(std::cin, buffer);
		contact.setLogin(buffer);

		std::cout << "firstname: " << contact.getFirstName() << std::endl;
		std::cout << "lastname: " << contact.getLastName() << std::endl;
		std::cout << "nickname: " << contact.getNickname() << std::endl;
		std::cout << "login: " << contact.getLogin() << std::endl;
		this->_nbContacts++;
	}
}
