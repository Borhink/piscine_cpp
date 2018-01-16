/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/16 16:55:12 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

static void *serialize(void)
{
	char const *characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	std::stringstream stream;
	Data *data = new Data;

	for (int i = 0; i < 8; i++)
		stream << static_cast<char>(characters[rand() % strlen(characters)]);
	data->s1 = stream.str();
	data->n = rand();
	stream.str("");
	for (int i = 0; i < 8; i++)
		stream << static_cast<char>(characters[rand() % strlen(characters)]);
	data->s2 = stream.str();
	return (static_cast<void*>(data));
}

static Data *deserialize(void *raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
	void *raw;
	Data *data;

	srand(time(NULL));
	raw = serialize();
	data = deserialize(raw);
	std::cout << "s1: " << data->s1 <<std::endl;
	std::cout << "n: " << data->n <<std::endl;
	std::cout << "s2: " << data->s2 <<std::endl;
	return (0);
}
