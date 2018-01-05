/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:51:51 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/05 18:53:31 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <string>
#include "contact.class.hpp"

class PhoneBook
{

public:
	PhoneBook(void);
	~PhoneBook(void);

	void run(void);

private:

	void checkEntry(void);
	void addContact(void);

	bool _run;
	int _nbContacts;
	class Contact _contacts[8];
};

#endif
