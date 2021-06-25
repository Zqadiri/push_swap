/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:27:21 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/25 12:14:14 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		exit_error ();
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
		exit_error ();
	m->stack_a[++m->pos] = (int)digit * signe;
	m->dup[m->pos] = (int)digit * signe;
}

void	init_struct(t_data *m, int argc )
{
	m->pos = -1;
	m->a_size = argc - 1;
	m->dup_size = argc - 1;
	m->b_size = 0;
	m->stack_b = NULL;
	m->stack_a = NULL;
	m->inst.index = -1;
	m->inst.pivot = -1;
	m->inst.best_rot = NULL;
}

void	init_stacks(t_data *m, int argc)
{
	m->stack_a = malloc(sizeof(int) * (argc));
	if (m->stack_a == NULL)
		exit(EXIT_FAILURE);
	ft_memset(m->stack_a, 0, argc);
	m->stack_b = malloc(sizeof(int) * (argc));
	if (m->stack_b == NULL)
		exit(EXIT_FAILURE);
	ft_memset(m->stack_b, 0, argc);
	m->dup = malloc(sizeof(int) * (argc));
	if (m->dup == NULL)
		exit(EXIT_FAILURE);
	ft_memset(m->dup, 0, argc);
}

int	is_sorted(t_data *m)
{
	int	i;
	int	len;

	i = 0;
	len = m->a_size;
	if (m->b_size != 0)
		return (0);
	while (i < len - 1)
	{
		if (m->stack_a[i] < m->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
