/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:04:23 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/17 18:23:52 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <sstream>
# include <stdexcept>

template <typename T>
class Array
{

public:

	Array(void): _array(NULL), _size(0) {}
	Array(unsigned int n): _array(new T[n]()), _size(n) { }
	Array(Array const &src) { *this = src; }
	~Array(void) { delete [] this->_array; }

	Array &operator=(Array const &rhs)
	{
		if (this != &rhs)
		{
			this->_size = rhs._size;
			if (this->_array)
				delete [] this->_array;
			this->_array = new T[this->_size];
			for (int i = 0; i < this->_size; i++)
				this->_array[i] = rhs._array[i];
		}
		return (*this);
	}

	T &operator[](size_t i)
	{
		if (this->_array && i < this->_size)
			return (this->_array[i]);
		else
			throw std::out_of_range("Out of range");
	}

	T *array(void)
	{
		return (this->_array);
	}

	size_t size(void) const
	{
		return (this->_size);
	}

private:

	T *_array;
	size_t _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &rhs)
{
	for (size_t i = 0; i < rhs.size(); i++)
		o << const_cast< Array<T> &>(rhs)[i];
	return (o);
}

#endif
