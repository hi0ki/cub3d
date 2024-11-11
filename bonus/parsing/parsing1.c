/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:20:39 by kadam             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/11/10 21:45:50 by kadam            ###   ########.fr       */
=======
/*   Updated: 2024/11/11 11:13:13 by eel-ansa         ###   ########.fr       */
>>>>>>> hiki
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_av_path(char *str, int len, int index)
{
	int	fd;

	if (index == 0)
	{
		if (str[len - 1] == 'b' && str[len - 2] == 'u' && str[len - 3] == 'c'
			&& str[len - 4] == '.')
			return (1);
	}
	else if (index == 1)
	{
		fd = open(str, O_RDONLY);
		if (fd == -1)
			return (ft_putstrn_fd("Error\nInvalid path\n", 2), 1);
		close(fd);
	}
	return (0);
}

int	process_path(char **str, int i, char *name, char **path)
{
	char	**split;

	split = ft_split(str[i], " \t\v\f\r");
	if (ft_lenarray(split) != 2 || (split[0] && ft_strcmp(split[0], name) != 0))
		return (free_2d_array(split),
			ft_putstrn_fd("Error\nYOU HAVE TO SET ALL THE PATHS\n", 2), 1);
	if (check_av_path(split[1], 0, 1) == 1)
		return (free_2d_array(split), 1);
	free(*path);
	*path = ft_strdup(split[1]);
	free_2d_array(split);
	return (0);
}

static int	load_textures(t_data *map, int i)
{
	map->textur[0] = mlx_load_png(map->no);
	map->textur[1] = mlx_load_png(map->so);
	map->textur[2] = mlx_load_png(map->we);
	map->textur[3] = mlx_load_png(map->ea);
<<<<<<< HEAD
	map->textur[4] = mlx_load_png("./texturs/download.png");
	if (!map->textur[0] || !map->textur[1] || !map->textur[2] || !map->textur[3]
		|| !map->textur[4])
=======
	map->textur[4] = mlx_load_png("./texturs/door.png");
	if (!map->textur[0] || !map->textur[1] || !map->textur[2]
		|| !map->textur[3] || !map->textur[4])
	
>>>>>>> hiki
	{
		while (i < 5)
		{
			if (map->textur[i])
			{
				mlx_delete_texture(map->textur[i]);
				map->textur[i] = NULL;
			}
			i++;
		}
		return (ft_putstrn_fd("Error\nFailed to load textures\n", 2), 1);
	}
<<<<<<< HEAD
	return (0);
}

static int	load_img(t_data *map, int i)
{
	if (load_textures(map, i))
		return (1);
	map->gun[0] = mlx_load_png("./gun/shoo0.png");
	map->gun[1] = mlx_load_png("./gun/shoo1.png");
	map->gun[2] = mlx_load_png("./gun/shoo2.png");
	map->gun[3] = mlx_load_png("./gun/shoo3.png");
	map->gun[4] = mlx_load_png("./gun/shoo4.png");
	map->gun[5] = mlx_load_png("./gun/shoo5.png");
	map->gun[6] = mlx_load_png("./gun/shoo6.png");
	if (!map->gun[0] || !map->gun[1] || !map->gun[2] || !map->gun[3]
		|| !map->gun[4] || !map->gun[5] || !map->gun[6])
=======
	map->gun[0] = mlx_load_png("./bonus/gun/shoo0.png");
    map->gun[1] = mlx_load_png("./bonus/gun/shoo1.png");
    map->gun[2] = mlx_load_png("./bonus/gun/shoo2.png");
    map->gun[3] = mlx_load_png("./bonus/gun/shoo3.png");
    map->gun[4] = mlx_load_png("./bonus/gun/shoo4.png");
    map->gun[5] = mlx_load_png("./bonus/gun/shoo5.png");
    map->gun[6] = mlx_load_png("./bonus/gun/shoo6.png");
	if (!map->gun[0] || !map->gun[1] || !map->gun[2] || !map->gun[3] || !map->gun[4] || !map->gun[5] || !map->gun[6])
>>>>>>> hiki
	{
		while (i < 7)
		{
			if (map->gun[i])
			{
				mlx_delete_texture(map->gun[i]);
				map->gun[i] = NULL;
			}
			i++;
		}
		return (ft_putstrn_fd("Error\nFailed to load gun textures\n", 2), 1);
	}
	return (0);
}

int	check_all(int ac, char **av, t_data *map_struct, int fd)
{
	t_helper	helper;

	if (init_struct(map_struct, &helper, fd, av[1]))
		return (1);
	if (read_file(fd, &helper))
		return (1);
	if (read_map(helper.line, fd, map_struct, helper.ptr_line))
		return (free(helper.ptr_line), 1);
	free(helper.ptr_line);
	ac = 0;
	while (ac < 3)
	{
		if (map_struct->f[ac] < 0 || map_struct->f[ac] > 255
			|| map_struct->c[ac] < 0 || map_struct->c[ac] > 255)
			return (ft_putstrn_fd("Error\nInvalid color\n", 2), 1);
		ac++;
	}
	if (map_struct->map == NULL)
		return (ft_putstrn_fd("Error\n: The map is empty", 2), 1);
	if (load_img(map_struct, 0))
		return (1);
	return (0);
}
