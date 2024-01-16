/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:04:17 by leng-chu          #+#    #+#             */
/*   Updated: 2022/08/01 16:12:44 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Animal::Animal(void) : type("Unknown")
{
	std::cout << YELLOW"===Animal Constructor(Default)==="DEF << std::endl;
	std::cout << "Animal type: " << getType() << std::endl;
	std::cout << YELLOW"=================================\n"DEF << std::endl;
}

Animal::~Animal(void)
{
	std::cout << BRED"===Animal Destructor==="DEF << std::endl;
	std::cout << "Animal type: " << getType() << std::endl;
	std::cout << BRED"========================\n"DEF << std::endl;
}

Animal::Animal(Animal const & src): type(src.getType())
{
	std::cout << YELLOW"Animal Class's Copy Construstor called\n"DEF << std::endl;
}

Animal & Animal::operator=(Animal const & rhs)
{
	std::cout << YELLOW"Animal Class's Copy Assignment Called\n"DEF << std::endl;
	if (this != &rhs)
	{
		this->Animal::~Animal();
		new (this) Animal(rhs);
	}
	return (*this);
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void	Animal::setType(std::string n)
{
	this->type = n;
}

void	Animal::makeSound() const
{
	std::cout << MAG << getType() << ": ...............[from Animal class]\n"DEF << std::endl;
}
