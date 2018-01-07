/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:50:52 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/07 15:01:27 by qhonore          ###   ########.fr       */
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
		else if (buffer == "SEARCH")
			this->searchContact();
		else if (buffer == "EXIT")
		{
			std::cout << "Closing PhoneBook..." << std::endl;
			this->_run = false;
		}
	}
}

std::string PhoneBook::getEntry(std::string entryName) const
{
	std::string buffer;

	std::cout << entryName;
	std::getline(std::cin, buffer);
	return (buffer);
}

std::string PhoneBook::truncateString(std::string str) const
{
	if (str.size() > 10)
	{
		str = str.substr(0, 10);
		str[9] = '.';
	}
	return (str);
}

void PhoneBook::addContact(void)
{
	if (this->_nbContacts == 8)
		std::cout << "The PhoneBook is already full !" << std::endl;
	else
	{
		class Contact &contact = this->_contacts[this->_nbContacts];

		contact.setFirstName(this->getEntry("Enter firstname: "));
		contact.setLastName(this->getEntry("Enter lastname: "));
		contact.setNickname(this->getEntry("Enter nickname: "));
		contact.setLogin(this->getEntry("Enter login: "));
		contact.setPostalAddress(this->getEntry("Enter postal address: "));
		contact.setEmailAddress(this->getEntry("Enter email address: "));
		contact.setPhoneNumber(this->getEntry("Enter phone number: "));
		contact.setBirthdayDate(this->getEntry("Enter birthday date: "));
		contact.setFavoriteMeal(this->getEntry("Enter favorite meal: "));
		contact.setUnderwearColor(this->getEntry("Enter underwear color: "));
		contact.setDarkestSecret(this->getEntry("Enter darkest secret: "));
		this->_nbContacts++;
	}
}

void PhoneBook::searchContact(void) const
{
	int index = -1;

	if (this->_nbContacts > 0)
	{
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		for (int i = 0; i < this->_nbContacts; i++)
		{
			class Contact const &contact = this->_contacts[i];

			std::cout << std::left;
			std::cout << "|" << std::setw(10) << i << "|";
			std::cout << std::setw(10) << this->truncateString(contact.getFirstName()) << "|";
			std::cout << std::setw(10) << this->truncateString(contact.getLastName()) << "|";
			std::cout << std::setw(10) << this->truncateString(contact.getNickname()) << "|" << std::endl;
		}
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Enter contact's index: ";
		std::cin >> index;
		if (std::cin.good() && index >= 0 && index < this->_nbContacts)
			this->showContact(index);
		else
		{
			std::cin.clear();
			std::cout << "Bad entry" << std::endl;
		}
	}
	else
		std::cout << "No contact, use ADD command to add contact !" << std::endl;
}

void PhoneBook::showContact(int index) const
{
	class Contact const &contact = this->_contacts[index];

	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Login: " << contact.getLogin() << std::endl;
	std::cout << "Postal Address: " << contact.getPostalAddress() << std::endl;
	std::cout << "Email Address: " << contact.getEmailAddress() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Birthday Date: " << contact.getBirthdayDate() << std::endl;
	std::cout << "Favorite Meal: " << contact.getFavoriteMeal() << std::endl;
	std::cout << "Underwear Color: " << contact.getUnderwearColor() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
