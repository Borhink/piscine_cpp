/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:51:51 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/07 18:33:18 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "contact.class.hpp"

class PhoneBook
{

public:

	PhoneBook(void);
	~PhoneBook(void);

	void run(void);

private:

	std::string getEntry(std::string entryName) const;
	std::string truncateString(std::string str) const;
	void addContact(void);
	void searchContact(void) const;
	void showContact(int index) const;

	bool _run;
	int _nbContacts;
	class Contact _contacts[8];
};

#endif
