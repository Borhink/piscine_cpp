/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 19:51:45 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{

public:

	Fixed(void);
	Fixed(int nb);
	Fixed(class Fixed const & src);
	~Fixed(void);

	Fixed &operator=(class Fixed const &rhs);

	int getRawBits(void) const;
	void setRawBits(int const nb);

private:

	int _nb;
	static int const _fractionalBits;
};

std::ostream &operator<<(std::ostream &o, class Fixed const &i);

# endif
