/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:29:37 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/29 16:54:31 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Integer.class.hpp"

int	main() {

	Integer		x( 30 );
	Integer		y( 10 );
	Integer		z( 0 );

	std::cout << "Value of x: " << x << std::endl;
	std::cout << "Value of y: " << y << std::endl;
	
	y = Integer( 12 );
	std::cout << "Value of y: " << y << std::endl;
	
	std::cout << "Value of z: " << z << std::endl;
	z = x + y;
	std::cout << "Value of z: " << z << std::endl;
	
	return 0;
}
