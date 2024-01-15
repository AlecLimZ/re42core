/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bmp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:11:23 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/12 12:16:53 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BMP_H
# define CUB_BMP_H

# include <stdint.h>
# include "cub_game.h"

# pragma pack(push, 1)

typedef struct		s_bmpfileheader
{
	unsigned char	signature[2];
	int				bmp_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset;
}					t_bmpfileheader;

typedef struct		s_bmpinfoheader
{
	unsigned int	header_size;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_pxl;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	res_x;
	unsigned int	res_y;
	unsigned int	color_img;
	unsigned int	color_important;
	unsigned int	red_mask;
	unsigned int	green_mask;
	unsigned int	blue_mask;
	unsigned int	alpha_mask;
}					t_bmpinfoheader;

# pragma pack(pop)

int					*int_to_bmp(t_parse *data, t_img *img);
void				fill_header(t_bmpfileheader *bfh,
					t_bmpinfoheader *bih, t_parse *data);

#endif
