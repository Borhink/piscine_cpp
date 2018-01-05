/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:51:51 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/05 19:21:40 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>

class Contact
{

public:
	Contact(void);
	~Contact(void);

	std::string const &getFirstName(void) const;
	void setFirstName(std::string const &firstName);
	std::string const &getLastName(void) const;
	void setLastName(std::string const &lastName);
	std::string const &getNickname(void) const;
	void setNickname(std::string const &nickname);
	std::string const &getLogin(void) const;
	void setLogin(std::string const &login);


private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _login;
	// std::string _postalAddress;
	// std::string _emailAdress;
	// std::string _phoneNumber;
	// std::string _birthdayDate;
	// std::string _favoriteMeal;
	// std::string _underwearColor;
	// std::string _darkestSecret;
};

#endif
