/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:33:59 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/12 13:12:34 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{

public:

	Cure(void);
	Cure(Cure const &src);
	~Cure(void);

	Cure &operator=(Cure const &rhs);

	virtual Cure *clone(void) const;
	virtual void use(ICharacter &target);
};

#endif
