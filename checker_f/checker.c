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

# include "../includes/checker.h"

static int		isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int len(char *arg)
{
	int i;

	i = 0;
	while (arg[i] >= '0' && arg[i] <= '9')
		i++;
	return (i);
}

/*
** Check duplicate
*/

void    check_duplicate(t_data *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->a_size)
	{
		j = i + 1;
		while (j < m->a_size)
		{
			if (m->stack_a[i] == m->stack_a[j])
				error_code(3);
			j++;
		}
		i++;
	}
}

/*
** Check Overflow 
*/

static int  check_overflow(long digit)
{
	if (digit > INT32_MAX || digit < INT32_MIN)
		return (0);
	return (1);
}

/*
** atoi
*/

void    is_valid(t_data *m, char *arg)
{
	long long digit;
	int i;
	int signe;

	i = 0;
	digit = 0;
	signe = 1;
	if (len(arg) > 17)
		error_code (2);
	if (arg[i] == '-')
	{
		signe = -1;
		if (!(isdigit(arg[++i])))
			error_code(1);
	}
	if (arg[i] == '+')
	{
		if (!(isdigit(arg[++i])))
			error_code(1);
	}
	while (arg[i] != '\0')
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			digit = (digit * 10) + arg[i] - '0';
		else
			error_code(1);
		i++;
	}
	if (!(check_overflow(digit * signe)))
		error_code (2);
	m->pos++;
	m->stack_a[m->pos] = (int)digit * signe;
}


int    main(int argc, char **argv)
{
	t_data 	m;
	int		count;

	count = 1;
	if (argc-- < 2)
		return (EXIT_SUCCESS);
	init_struct(&m, argc);
	if (!(m.stack_a = malloc(sizeof(int) * (argc))))
		exit(EXIT_FAILURE);
	if (!(m.stack_b = malloc(sizeof(int) * (argc))))
		exit(EXIT_FAILURE);
	if (!(m.dup = malloc(sizeof(int) * (argc))))
		exit(EXIT_FAILURE);
	init_stacks(&m, argc);
	while (argv[count])
	{
		is_valid(&m, argv[count]);
		count++;
	}
	check_duplicate(&m);
	get_instruction(&m);
	// int i = 0;
	// while (i < m.a_size)
	// {
	// 	printf("%d\n", m.stack_a[i]);
	// 	i++;
	// }
	// printf ("**************\n");
	// i = 0;
	// while (i < m.b_size)
	// {
	// 	printf("%d\n", m.stack_b[i]);
	// 	i++;
	// }
	if (is_sorted(&m))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (EXIT_SUCCESS);
}