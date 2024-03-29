/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:38:21 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/12 11:28:22 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_IMAGE_H
# define CUB_IMAGE_H

# include "libft.h"
# include "cub_parse.h"

typedef	struct		s_img
{
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				line_length_i;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef	struct		s_sprite
{
	double			x;
	double			y;
	double			spritedis;
	t_img			**sprite;
	int				nsprite;
	int				xpm;
}					t_sprite;

/*
**					CREATE IMAGE
*/
t_img				**create_tab_xpm(void *mlx, int size, char **xpm);
t_img				*create_xpm_image(void *mlx, char *tex_file);
t_img				*create_image(void *mlx, int x, int y);

/*
**					FREE IMAGE
*/
void				free_image_tab(int n, t_img **tab, void *mlx);
void				free_image(t_img *image, void *mlx);

/*
**					CREATE SPRITE
*/
t_sprite			*create_sprite(void *mlx, t_spritei spritei, double x,
					double y);
t_sprite			**create_sprite_tab(void *mlx, t_spritem *s_map, int size);
/*
**					FREE SPRITE
*/
void				free_sprite(t_sprite *sprite, void *mlx);
void				free_sprite_tab(t_sprite **sprite, void *mlx, int size);

void				write_pixel(t_img *image, int x, int y, int color);
#endif
