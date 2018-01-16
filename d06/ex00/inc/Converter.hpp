/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:04:23 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/16 15:28:25 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <cstdlib>
# include <string>
# include <sstream>
# include <limits>

class Converter
{

public:

	Converter(void);
	Converter(std::string value);
	Converter(Converter const &src);
	~Converter(void);

	Converter &operator=(Converter const &rhs);

	std::string getInt(void) const;
	std::string getChar(void) const;
	std::string getFloat(void) const;
	std::string getDouble(void) const;

	int convertInt(void) const;
	long convertLong(void) const;
	double convertDouble(void) const;
	float convertFloat(void) const;

	std::string const &getValue(void) const;

private:

	std::string _value;
};

#endif
