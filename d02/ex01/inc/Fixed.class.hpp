/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 20:47:02 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{

public:

	Fixed(void);
	Fixed(int const nb);
	Fixed(float const nb);
	Fixed(class Fixed const & src);
	~Fixed(void);

	Fixed &operator=(class Fixed const &rhs);

	int getRawBits(void) const;
	void setRawBits(int const nb);
	float toFloat(void) const;
	int toInt(void) const;

private:

	int _nb;
	static int const _fractionalBits;
};

std::ostream &operator<<(std::ostream &o, class Fixed const &i);

# endif
