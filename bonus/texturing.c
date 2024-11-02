/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:34:32 by kadam             #+#    #+#             */
/*   Updated: 2024/10/31 14:08:07 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

static int	color_pixel(void *arr, int is_uint8)
{
	uint8_t	*i;
	int		*j;

	if (is_uint8)
	{
		i = (uint8_t *)arr;
		return ((i[0] << 24) | (i[1] << 16) | (i[2] << 8) | 0xFF);
	}
	else
	{
		j = (int *)arr;
		return ((j[0] << 24) | (j[1] << 16) | (j[2] << 8) | 0xFF);
	}
}

void	draw_f_c(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			mlx_put_pixel(data->image, x++, y, color_pixel(data->c, 0));
		y++;
	}
	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			mlx_put_pixel(data->image, x++, y, color_pixel(data->f, 0));
		y++;
	}
}

int	tex_index(t_dis_H dis_H, t_dis_V dis_V, double rayangle)
{
	if(dis_V.is_door || dis_H.is_door)
		return 4;
	else if (dis_V.inter_type_v == 'V')
	{
		if (rayangle > M_PI_2 && rayangle < 3 * M_PI_2)
			return (2);
		else
			return (3);
	}
	else if (dis_H.inter_type_h == 'H')
	{
		if (rayangle > M_PI && rayangle < 2 * M_PI)
			return (1);
		else
			return (0);
	}
	return (-1);
}

int	get_color(t_data *data, t_rays rays, int tex_y,
		int texture_index)
{
	int	tex_x;
	int	index;

	tex_x = 0;
	if (rays.dis_H.inter_type_h == 'H')
		tex_x = ((rays.dis_H.x_h / SIZE) - floor(rays.dis_H.x_h / SIZE))
			* data->textur[texture_index]->width;
	else if (rays.dis_V.inter_type_v == 'V')
		tex_x = ((rays.dis_V.y_v / SIZE) - floor(rays.dis_V.y_v / SIZE))
			* data->textur[texture_index]->width;
	if (tex_x < 0 || tex_y < 0
		|| (uint32_t)tex_x >= data->textur[texture_index]->width
		|| (uint32_t)tex_y >= data->textur[texture_index]->height)
		return (0);
	index = (tex_y * data->textur[texture_index]->width
			* data->textur[texture_index]->bytes_per_pixel) + (tex_x
			* data->textur[texture_index]->bytes_per_pixel);
	return (color_pixel(&data->textur[texture_index]->pixels[index], 1));
}
