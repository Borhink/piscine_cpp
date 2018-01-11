/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:41:12 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/11 20:20:55 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include <iostream>
# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{

public:

	TacticalMarine(void);
	TacticalMarine(const TacticalMarine &src);
	virtual ~TacticalMarine(void);

	TacticalMarine    &operator=(const TacticalMarine &rhs);

	virtual ISpaceMarine *clone(void) const;
	virtual void battleCry(void) const;
	virtual void rangedAttack(void) const;
	virtual void meleeAttack(void) const;
};

#endif
