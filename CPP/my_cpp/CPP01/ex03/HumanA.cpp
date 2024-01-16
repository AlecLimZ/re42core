/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:10:31 by leng-chu          #+#    #+#             */
/*   Updated: 2022/06/27 15:32:14 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon & club):name(n), weapon(club.getType()) // Learn that reference initialize work here, do not work inside the block
{
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon << std::endl;
}
