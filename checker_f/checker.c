/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:25:07 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/18 10:25:15 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Check duplicate
*/

void	check_duplicate(t_data *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->a_size)
	{
		j = i + 1;
		while (j < m->a_size)
		{
			if (m->stack_a[i] == m->stack_a[j])
				exit_error();
			j++;
		}
		i++;
	}
}

/*
** atoi
*/

long	long	get_number(char *arg, int i)
{
	long long	digit;

	digit = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			digit = (digit * 10) + arg[i] - '0';
		else
			exit_error();
		i++;
	}
	return (digit);
}

void	is_valid(t_data *m, char *arg)
{
	int			i;
	int			signe;
	long long	digit;

	digit = 0;
	i = 0;
	signe = 1;
	if (len(arg) > 17)
		exit_error();
	if (arg[i] == '-')
	{
		signe = -1;
		if (!(isdigit(arg[++i])))
			exit_error();
	}
	if (arg[i] == '+')
	{
		if (!(isdigit(arg[++i])))
			exit_error();
	}
	digit = get_number(arg, i);
	if (!(check_overflow(digit * signe)))
		exit_error();
	m->stack_a[++m->pos] = (int)digit * signe;
}

int	main(int argc, char *argv[])
{
	t_data	m;
	int		count;

	count = 1;
	if (argc-- < 2)
		exit(EXIT_SUCCESS);
	init_(&m, argc);
	while (argv[count])
	{
		is_valid(&m, argv[count]);
		count++;
	}
	check_duplicate(&m);
	get_instruction(&m);
	if (is_sorted(&m))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (EXIT_SUCCESS);
}
