/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 16:49:04 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int ac, char **av)
{
	if (ac == 4 && av[1][0] && av[2][0] && av[3][0])
	{
		std::ifstream readFile;
		std::ofstream writeFile;
		std::string buffer;
		std::ostringstream file;
		std::string str;
		std::string s1 = av[2];
		std::string s2 = av[3];
		size_t find = 0;

		readFile.open(av[1]);
		if (readFile.fail())
		{
			std::cout << "Open file \"" << av[1] << "\" : " << strerror(errno) << std::endl;
			return (-1);
		}
		while(std::getline(readFile, buffer))
			file << buffer << std::endl;
		str = file.str();
		while (str.find(s1, find) != std::string::npos)
		{
			str.replace(str.find(s1, find), s1.length(), s2);
			find = str.find(s2, find) + s2.length();
		}
		file.str(std::string());
		file << av[1] << ".replace";
		writeFile.open(file.str());
		if (writeFile.fail())
		{
			std::cout << "Open file \"" << file.str() << "\" : " << strerror(errno) << std::endl;
			return (-1);
		}
		writeFile << str;
		writeFile.close();
		readFile.close();
		std::cout << "File \"" << file.str() << "\" created with success" << std::endl;
	}
	else
		std::cout << "Usage: ./replace [FILENAME] [S1] [S2]" << std::endl;
	return (0);
}
