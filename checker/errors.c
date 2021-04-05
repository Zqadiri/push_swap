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

void	ft_putchar(char c) {
	write(1, &c, 1);
}

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

void        init_struct(t_data *m, int argc )
{
	m->pos = -1;
	m->a_size = argc;
	m->b_size = 0;
	m->stack_b = NULL;
	m->stack_a = NULL;
	m->inst.index = -1;
	m->inst.pivot = -1;
	m->inst.best_rot = NULL;
	m->inst.big = 0;
}

void		init_stacks(t_data *m, int argc)
{
	int i;
	
	i = 0;
	while (i < argc)
	{
		m->stack_a[i] = 0;
		i++;
	}
	i = 0;
	while (i < argc)
	{
		m->stack_b[i] = 0;
		i++;
	}
	i = 0;
	while (i < argc)
	{
		m->dup[i] = 0;
		i++;
	}
}


void		print(t_data *m)
{
	printf ("a_size : %d\n", m->a_size);
	printf ("b_size : %d\n", m->b_size);
	printf ("pivot : %d\n", m->inst.pivot);
	printf ("start_value:%d\n", m->inst.start_value);
	int i;

	i = 0;
	while (i < m->a_size)
	{
		printf("a_data --> %d\n", m->stack_a[i]);
		i++;
	}
	printf ("*********************************************\n");

	i = 0;
	while (i < m->b_size)
	{
		printf("b_data --> %d\n", m->stack_b[i]);
		i++;
	}
	// i = 0;
	// while (i < m->a_size)
	// {
	// 	printf("dup_data --> %d\n", m->dup[i]);
	// 	i++;
	// }
}

int		is_sorted(t_data *m)
{
	int i;
	int len;

	i = 0;
	len = m->a_size;
	while (i < len - 1)
	{
		if (m->stack_a[i] < m->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

static char	*ft_join(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	if (!(str = (char *)malloc(i + 2)))
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int			get_next_line(char **line)
{
	char	*buffer;
	int		flag;

	buffer = (char *)malloc(2);
	if (!line || !(*line = (char *)malloc(1)) || !buffer)
		return (-1);
	*line[0] = '\0';
	while ((flag = read(0, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
			break ;
		*line = ft_join(*line, buffer[0]);
	}
	free(buffer);
	return (flag);
}
