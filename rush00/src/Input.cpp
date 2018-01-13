/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 20:01:05 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"

Input::Input(void)
{
	for (int i(0); i < ENTRYCOUNT; i++)
		this->_entries[i] = false;
	return;
}

Input::Input(const Input &src)
{
	for (int i(0); i < ENTRYCOUNT; i++)
		this->_entries[i] = false;
	*this = src;
	return;
}

Input::~Input(void)
{
	return;
}

Input &Input::operator=(Input const &rhs)
{
	if (this != &rhs)
	{
		for (int i(0); i < ENTRYCOUNT; i++)
			this->_entries[i] = false;
	}
	return (*this);
}

void Input::clearEntries(void)
{
	for (int i(0); i < ENTRYCOUNT; i++)
		this->_entries[i] = false;
}

bool Input::getEntry(int entry) const
{
	if (entry >= 0 && entry < ENTRYCOUNT)
		return (this->_entries[entry]);
	return (false);
}

void Input::setEntry(int entry, bool val)
{
	if (entry >= 0 && entry < ENTRYCOUNT)
		this->_entries[entry] = val;
}
