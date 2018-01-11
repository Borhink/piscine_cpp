/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:33:59 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/11 20:29:28 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad
{

public:

	virtual ~ISquad(void) {}

	virtual int getCount(void) const = 0;
	virtual ISpaceMarine *getUnit(int nb) const = 0;
	virtual int push(ISpaceMarine *marine) = 0;

};

#endif
