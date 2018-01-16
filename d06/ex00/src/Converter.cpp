/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:03:58 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/16 14:38:42 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(void):
_value("0")
{
}

Converter::Converter(std::string value):
_value(value)
{
}

Converter::Converter(Converter const &src)
{
	*this = src;
}

Converter::~Converter(void)
{
}

Converter &Converter::operator=(Converter const &rhs)
{
	if (this != &rhs)
	{
		this->_value = rhs._value;
	}
	return (*this);
}

std::string Converter::getInt(void) const
{
	if (this->_value == "nan" || this->_value == "-inf" || this->_value == "+inf"
	|| this->_value == "nanf" || this->_value == "-inff" || this->_value == "+inff"
	|| this->_value == "inf")
		return ("impossible");
	else if (this->convertDouble() > std::numeric_limits<int>::max()
	|| this->convertDouble() < std::numeric_limits<int>::min())
		return ("overflow");
	else
	{
		std::stringstream sstream;

		sstream << this->convertInt();
		return (sstream.str());
	}
}

std::string Converter::getChar(void) const
{
	if (this->_value == "nan" || this->_value == "-inf" || this->_value == "+inf"
	|| this->_value == "nanf" || this->_value == "-inff" || this->_value == "+inff"
	|| this->_value == "inf")
		return ("impossible");
	else if (!isprint(this->convertInt()))
		return ("Non displayable");
	else
	{
		std::stringstream sstream;

		sstream << "'" << static_cast<char>(this->convertInt()) << "'";
		return (sstream.str());
	}
}

std::string Converter::getFloat(void) const
{
	std::stringstream sstream;

	if (this->_value == "nan" || this->_value == "-inf" || this->_value == "+inf"
	|| this->_value == "nanf" || this->_value == "-inff" || this->_value == "+inff"
	|| this->_value == "inf")
		sstream << this->convertFloat() << "f";
	else if (this->convertFloat() - static_cast<int>(this->convertFloat()) == 0.0f)
		sstream << this->convertFloat() << ".0f";
	else
		sstream << this->convertFloat() << "f";
	return (sstream.str());
}

std::string Converter::getDouble(void) const
{
	std::stringstream sstream;

	if (this->convertDouble() - static_cast<int>(this->convertDouble()) == 0.0)
		sstream << this->convertDouble() << ".0";
	else
		sstream << this->convertDouble();
	return (sstream.str());
}

int Converter::convertInt(void) const
{
	return (static_cast<int>(atoi(this->_value.c_str())));
}

long Converter::convertLong(void) const
{
	return (static_cast<long>(atol(this->_value.c_str())));
}

double Converter::convertDouble(void) const
{
	return (static_cast<double>(atof(this->_value.c_str())));
}

float Converter::convertFloat(void) const
{
	return (static_cast<float>(atof(this->_value.c_str())));
}

std::string const &Converter::getValue(void) const
{
	return (this->_value);
}
