/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:07:16 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/18 10:57:57 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker.h"

void	ft_putstr(char const *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

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
	// data->size_a = 0;
	data->b_size = 0;
	data->stack_b = NULL;
	data->stack_a = NULL;
}

void		init_stacks(t_data *m)
{
	int i;

	i = 0;
	while (i <= m->b_size)
	{
		m->stack_b[i].data = 0;
		// printf("_data --> %d\n", m->stack_b[i].data);
		i++;
	}
	i = 0;
	while (i <= m->a_size)
	{
		m->stack_b[i].alive = 0;
		// printf("_alive --> %d\n", m->stack_b[i].alive);
		i++;
	}	
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

void		print(t_data *m)
{
	int i;

	i = 0;
	while (i < m->a_size)
	{
		printf("a_data --> %d\n", m->stack_a[i].data);
		i++;
	}
	i = 0;
	while (i < m->a_size)
	{
		printf("a_alive --> %d\n", m->stack_a[i].alive);
		i++;
	}

		i = 0;
	while (i < m->b_size)
	{
		printf("b_data --> %d\n", m->stack_b[i].data);
		i++;
	}
	i = 0;
	while (i < m->b_size)
	{
		printf("b_alive --> %d\n", m->stack_b[i].alive);
		i++;
	}
}

int		is_sorted(t_data *m)
{
	int i;
	int len;

	i = 0;
	len = m->a_size;
	while (i < len - 1)
	{
		if (m->stack_a[i].data < m->stack_a[i + 1].data)
			i++;
		else
			return (0);
	}
	return (1);
}

