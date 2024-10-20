/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:24:38 by kadam             #+#    #+#             */
/*   Updated: 2024/10/19 18:10:43 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	read_file(int fd, t_helper *helper)
{
	while (helper->line != NULL)
	{
		helper->trim_line = ft_strtrim(helper->line, " \t\v\f\r");
		if (!ft_strcmp(helper->trim_line, "\n"))
		{
			free(helper->trim_line);
			free(helper->line);
			helper->line = get_next_line(fd);
			continue ;
		}
		else
		{
			helper->res = process_line(helper->trim_line, &helper->ptr_line,
					helper->find);
			free(helper->trim_line);
			if (helper->res == 0)
				break ;
			else if (helper->res == 1)
				return (free(helper->line), free(helper->ptr_line), 1);
		}
		free(helper->line);
		helper->line = get_next_line(fd);
	}
	return (0);
}