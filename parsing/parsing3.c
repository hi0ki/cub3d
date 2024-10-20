/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:23:08 by kadam             #+#    #+#             */
/*   Updated: 2024/10/19 17:10:04 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*process_split(char *str, char *name)
{
	char	**split;
	char	*tmp;
	char	*ptr;
	int		i;

	split = ft_split(str, "  \t\v\f\r");
	if (ft_lenarray(split) < 2 || (split[0] && ft_strcmp(split[0], name) != 0))
		return (free_2d_array(split), ft_putstrn_fd("Error\nColor is invalid",
				2), NULL);
	tmp = NULL;
	ptr = NULL;
	i = 1;
	while (split[i])
	{
		tmp = ft_strjoin(ptr, split[i]);
		free(ptr);
		ptr = tmp;
		i++;
	}
	free_2d_array(split);
	return (ptr);
}

static int	validate_commas(char *ptr)
{
	int	i;
	int	commas;

	if (!ptr)
		return (1);
	i = 0;
	commas = 0;
	while (ptr[i])
	{
		if (ptr[i] == ',' && ptr[i + 1] != ',' && ptr[i + 1] != '\0' && ptr[i
				- 1] && ptr[i - 1] != ',')
			commas++;
		else if (ptr[i] == ',' && (ptr[i + 1] == ',' || ptr[i + 1] == '\0'
				|| (ptr[i - 1] && ptr[i - 1] == ',')))
			return (free(ptr), ft_putstrn_fd("Error\nToo many commas", 2), 1);
		i++;
	}
	if (commas != 2)
		return (free(ptr), ft_putstrn_fd("Error\nToo many commas", 2), 1);
	return (0);
}

int	process_color(int *map_color, char *str, char *name)
{
	char	*ptr;
	int		i;
	char	**split;

	ptr = process_split(str, name);
	if (validate_commas(ptr))
		return (1);
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] != ',' && (ptr[i] < '0' || ptr[i] > '9'))
			return (free(ptr), ft_putstrn_fd("Error\nColor is invalid", 2), 1);
		i++;
	}
	split = ft_split(ptr, ",");
	free(ptr);
	i = 0;
	while (i < 3)
	{
		map_color[i] = ft_atoi(split[i]);
		i++;
	}
	return (free_2d_array(split), 0);
}
