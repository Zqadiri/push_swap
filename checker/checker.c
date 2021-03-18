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

# include "checker.h"

/*
** Check duplicate
*/

void    check_duplicate(t_data *m)
{
	int i;
	int j;

	i = 0;
	while (m->stack_a[i].data && i < m->pos)
	{
		j = 0;
		while (m->stack_a[j].data && j < m->pos)
		{
			
			if (i != j)
			{
				if (m->stack_a[i].data == m->stack_a[j].data)
				{	
					error_code(3);
				}		
			}
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
	long digit;
	int i;
	int signe;

	i = 0;
	digit = 0;
	signe = 1;
	if (arg[i] == '-')
	{
		signe = -1;
		i++;
	}	
	while (arg[i] != '\0')
	{
		if (arg[i] >= '0' && arg[i] <= '9')
		{
			digit = (digit * 10) + arg[i] - '0';
		}	
		else
			error_code(1);
		i++;
	}
	if (!(check_overflow(digit * signe)))
		error_code (2);
	m->stack_a[m->pos].data = (int)digit * signe;
	m->stack_a[m->pos].alive = 1;
	printf("m->stack_a_data --> %d\n", m->stack_a[m->pos].data);
	// printf("m->stack_a_alive --> %d\n", m->stack_a[m->pos].alive);
	m->pos++;
}

int    main(int argc, char **argv)
{
	t_data 	m;
	int		count;

	count = 1;
	if (argc < 2)
		return (EXIT_FAILURE);
	init_struct(&m);
	m.a_size = argc - 1;
	if (!(m.stack_a = (t_stack_a*)malloc(sizeof(t_stack_a) * (argc - 1))))
		exit(EXIT_FAILURE);
	if (!(m.stack_b = (t_stack_b*)malloc(sizeof(t_stack_b) * (argc - 1))))
		exit(EXIT_FAILURE);
	init_stacks(&m);
	while (argv[count])
	{
		is_valid(&m, argv[count]);
		check_duplicate(&m);
		count++;
	}
	get_instruction(&m);
	return (EXIT_SUCCESS);
}