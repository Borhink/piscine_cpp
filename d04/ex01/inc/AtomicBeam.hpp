/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AtomicBeam.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 16:40:48 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOMICBEAM_HPP
# define ATOMICBEAM_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"

class AtomicBeam : public AWeapon
{

public:

	AtomicBeam(void);
	AtomicBeam(AtomicBeam const &src);
	virtual ~AtomicBeam(void);

	AtomicBeam &operator=(AtomicBeam const &rhs);

	virtual void attack(void) const;
};

# endif
