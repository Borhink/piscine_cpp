/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:51:51 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/07 18:33:23 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

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
	std::string const &getPostalAddress(void) const;
	void setPostalAddress(std::string const &postalAddress);
	std::string const &getEmailAddress(void) const;
	void setEmailAddress(std::string const &emailAddress);
	std::string const &getPhoneNumber(void) const;
	void setPhoneNumber(std::string const &phoneNumber);
	std::string const &getBirthdayDate(void) const;
	void setBirthdayDate(std::string const &birthdayDate);
	std::string const &getFavoriteMeal(void) const;
	void setFavoriteMeal(std::string const &favoriteMeal);
	std::string const &getUnderwearColor(void) const;
	void setUnderwearColor(std::string const &underwearColor);
	std::string const &getDarkestSecret(void) const;
	void setDarkestSecret(std::string const &darkestSecret);


private:

	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _login;
	std::string _postalAddress;
	std::string _emailAddress;
	std::string _phoneNumber;
	std::string _birthdayDate;
	std::string _favoriteMeal;
	std::string _underwearColor;
	std::string _darkestSecret;
};

#endif
