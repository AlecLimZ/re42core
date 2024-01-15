/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_options.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:05:16 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/12 12:07:31 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_OPTIONS_H
# define CUB_OPTIONS_H

# include <stdbool.h>

typedef struct		s_options
{
	bool			minimap;
	bool			ceilingandfloor;
	bool			ceilflooron;
	bool			texture;
	bool			fps;
	bool			game;
	bool			data;
	bool			ignore;
	bool			save;
	bool			menu;
	bool			resume;
	bool			settings;
	bool			ui;
	bool			on;
	bool			help;
}					t_optis;

#endif
