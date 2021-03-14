/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:07:16 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/14 18:51:33 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker.h"

void        error_code(int  code)
{
    write (2, "Error\n", 6);
    if (code == 1)
        write (2, "Checker gets as an argument a list of integers ...\n", 51);
    if (code == 2)
        write (2, "Overflow error !\n", 17);
    if (code == 3)
        write (2, "The list can not contain duplicates\n", 36);
    exit (EXIT_FAILURE);
}

void        init_struct(t_data *data)
{
	data->pos = 0;
	data->size = 0;
}

int get_next_line(char **line)
{
	static char *rest;
	char temp [1001];
	char *p;
	char *pfree;
	int ret;


	if (!line)
		return (-1);
	*line = ft_strdup("");
	if (rest)
	{
		if ((p = ft_strchr(rest, '\n')))
		{
			*p = 0;
			pfree = *line;
			*line = ft_strdup(rest);
			free(pfree);
			pfree = rest;
			rest = ft_strdup(p + 1);
			free(pfree);
			return (1);
		}
		pfree = *line;
		*line = ft_strdup(rest);
		free(pfree);
		free(rest);
		rest = NULL;
	}


	while ((ret = read(0,&temp, 1000)))
	{
		temp[ret] = 0;
		if ((p = ft_strchr(temp, '\n')))
		{
			*p = 0;
			pfree = *line;
			*line = ft_strjoin(*line, temp);
			free(pfree);
			rest = ft_strdup(p + 1);
			return (1);
		}
		pfree = *line;
		*line = ft_strjoin(*line, temp);
		free(pfree);
	}
	return (0);
}