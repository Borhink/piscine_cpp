/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:50:52 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/07 19:46:38 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.class.hpp"

Contact::Contact(void):
_firstName("First"),
_lastName("Last"),
_nickname("Nick"),
_login("Login"),
_postalAddress("Postal"),
_emailAddress("Email"),
_phoneNumber("Phone"),
_birthdayDate("Birthday"),
_favoriteMeal("Meal"),
_underwearColor("Color"),
_darkestSecret("Secret")
{
	return;
}

Contact::~Contact(void)
{
	return;
}

std::string const &Contact::getFirstName(void) const
{
	return (this->_firstName);
}

void Contact::setFirstName(std::string const &firstName)
{
	if (!firstName.empty())
		this->_firstName = firstName;
	return;
}

std::string const &Contact::getLastName(void) const
{
	return (this->_lastName);
}

void Contact::setLastName(std::string const &lastName)
{
	if (!lastName.empty())
		this->_lastName = lastName;
	return;
}

std::string const &Contact::getNickname(void) const
{
	return (this->_nickname);
}

void Contact::setNickname(std::string const &nickname)
{
	if (!nickname.empty())
		this->_nickname = nickname;
	return;
}

std::string const &Contact::getLogin(void) const
{
	return (this->_login);
}

void Contact::setLogin(std::string const &login)
{
	if (!login.empty())
		this->_login = login;
	return;
}

std::string const &Contact::getPostalAddress(void) const
{
	return (this->_postalAddress);
}

void Contact::setPostalAddress(std::string const &postalAddress)
{
	if (!postalAddress.empty())
		this->_postalAddress = postalAddress;
	return;
}

std::string const &Contact::getEmailAddress(void) const
{
	return (this->_emailAddress);
}

void Contact::setEmailAddress(std::string const &emailAddress)
{
	if (!emailAddress.empty())
		this->_emailAddress = emailAddress;
	return;
}

std::string const &Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

void Contact::setPhoneNumber(std::string const &phoneNumber)
{
	if (!phoneNumber.empty())
		this->_phoneNumber = phoneNumber;
	return;
}

std::string const &Contact::getBirthdayDate(void) const
{
	return (this->_birthdayDate);
}

void Contact::setBirthdayDate(std::string const &birthdayDate)
{
	if (!birthdayDate.empty())
		this->_birthdayDate = birthdayDate;
	return;
}

std::string const &Contact::getFavoriteMeal(void) const
{
	return (this->_favoriteMeal);
}

void Contact::setFavoriteMeal(std::string const &favoriteMeal)
{
	if (!favoriteMeal.empty())
		this->_favoriteMeal = favoriteMeal;
	return;
}

std::string const &Contact::getUnderwearColor(void) const
{
	return (this->_underwearColor);
}

void Contact::setUnderwearColor(std::string const &underwearColor)
{
	if (!underwearColor.empty())
		this->_underwearColor = underwearColor;
	return;
}

std::string const &Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

void Contact::setDarkestSecret(std::string const &darkestSecret)
{
	if (!darkestSecret.empty())
		this->_darkestSecret = darkestSecret;
	return;
}
