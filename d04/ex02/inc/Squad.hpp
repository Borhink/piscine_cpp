/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:33:59 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/11 20:39:36 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <cstdlib>
# include "ISpaceMarine.hpp"
# include "ISquad.hpp"

class Squad : public ISquad
{
	typedef struct s_marineList
	{
		ISpaceMarine *marine;
		struct s_marineList *next;
	} t_marineList;

public:

	Squad(void);
	Squad(Squad const &src);
	virtual ~Squad(void);

	Squad &operator=(Squad const &rhs);

	virtual int getCount(void) const;
	virtual ISpaceMarine *getUnit(int nb) const;
	virtual int push(ISpaceMarine *marine);
	bool alreadyInSquad(ISpaceMarine *marine) const;

private:

	int _units;
	t_marineList *_squad;
};

#endif
