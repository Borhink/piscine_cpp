/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 16:02:30 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HPP
# define INPUT_HPP

enum Entry
{
	UNKNOW = -1, ///< Unhandled key
	RETURN = 10,       ///< The Return key
	ESCAPE = 27,       ///< The Escape key
	SPACE = 32,        ///< The Space key
	NUM0 = 48,         ///< The 0 key
	NUM1,         ///< The 1 key
	NUM2,         ///< The 2 key
	NUM3,         ///< The 3 key
	NUM4,         ///< The 4 key
	NUM5,         ///< The 5 key
	NUM6,         ///< The 6 key
	NUM7,         ///< The 7 key
	NUM8,         ///< The 8 key
	NUM9,         ///< The 9 key
	A = 97,        ///< The A key
	B,            ///< The B key
	C,            ///< The C key
	D,            ///< The D key
	E,            ///< The E key
	F,            ///< The F key
	G,            ///< The G key
	H,            ///< The H key
	I,            ///< The I key
	J,            ///< The J key
	K,            ///< The K key
	L,            ///< The L key
	M,            ///< The M key
	N,            ///< The N key
	O,            ///< The O key
	P,            ///< The P key
	Q,            ///< The Q key
	R,            ///< The R key
	S,            ///< The S key
	T,            ///< The T key
	U,            ///< The U key
	V,            ///< The V key
	W,            ///< The W key
	X,            ///< The X key
	Y,            ///< The Y key
	Z,            ///< The Z key
	BACKSPACE = 127,    ///< The Backspace key
	DOWN = 258,         ///< Down arrow
	UP = 259,           ///< Up arrow
	LEFT = 260,         ///< Left arrow
	RIGHT = 261,        ///< Right arrow

	ENTRYCOUNT      ///< Keep last -- the total number of inputs
};

// class Input
// {
//
// public:
//
// 	Input(void);
// 	Input(Input const &src);
// 	virtual ~Input(void);
//
// 	virtual Input &operator=(Input const &rhs);
//
// 	void clearEntries(void);
//
// 	bool getEntry(int entry) const;
// 	void setEntry(int entry, bool val);
//
// private:
// 	bool _entries[EntryCount];
// };

#endif
