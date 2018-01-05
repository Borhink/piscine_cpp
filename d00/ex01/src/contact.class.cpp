/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:50:52 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/05 19:21:29 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.class.hpp"

Contact::Contact(void):
_firstName("First"),
_lastName("Last"),
_nickname("Nick"),
_login("Login")
{
}

Contact::~Contact(void)
{
}

std::string const &Contact::getFirstName(void) const
{
	return (this->_firstName);
}

void Contact::setFirstName(std::string const &firstName)
{
	if (!firstName.empty())
		this->_firstName = firstName;
}

std::string const &Contact::getLastName(void) const
{
	return (this->_lastName);
}

void Contact::setLastName(std::string const &lastName)
{
	if (!lastName.empty())
		this->_lastName = lastName;
}

std::string const &Contact::getNickname(void) const
{
	return (this->_nickname);
}

void Contact::setNickname(std::string const &nickname)
{
	if (!nickname.empty())
		this->_nickname = nickname;
}

std::string const &Contact::getLogin(void) const
{
	return (this->_login);
}

void Contact::setLogin(std::string const &login)
{
	if (!login.empty())
		this->_login = login;
}
