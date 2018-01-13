/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zaz.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 15:24:21 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAZ_HPP
# define ZAZ_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class Zaz : public Victim
{

public:

	Zaz(std::string const &name);
	Zaz(Zaz const &src);
	virtual ~Zaz(void);

	Zaz &operator=(Zaz const &rhs);

	virtual void getPolymorphed(void) const;

private:
	Zaz(void);
};

# endif
