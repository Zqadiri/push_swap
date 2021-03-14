/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:25:07 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/14 19:29:31 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker.h"

/*
** Check duplicate
*/

void    check_duplicate(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->stack_a[i] && i < data->pos)
	{
		j = 0;
		while (data->stack_a[j] && j < data->pos)
		{
			
			if (i != j)
			{
				if (data->stack_a[i] == data->stack_a[j])
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

static int  check_overflow(unsigned long digit)
{
	if ((int)digit > INT32_MAX && (int)digit < INT32_MIN)
		return (0);
	return (1);
}

/*
** atoi
*/

void    is_valid(t_data *data, char *arg)
{
	unsigned long digit;
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
	data->stack_a[data->pos] = (int)digit * signe;
	printf("data->stack_a --> %d\n", data->stack_a[data->pos]);
	data->pos++;
}

int    main(int argc, char **argv)
{
	t_data 	data;
	int		count;

	count = 1;
	if (argc < 2)
		return (EXIT_FAILURE);
	init_struct(&data);
    data.stack_a = malloc((argc) * sizeof(int));
    data.stack_b = malloc((argc) * sizeof(int));
	data.stack_a[argc] = '\0';
	data.stack_b[argc] = '\0';
	data.size = argc - 1;
	while (argv[data.size])
	{
		is_valid(&data, argv[data.size]);
		check_duplicate(&data);
		data.size++;
	}
	get_instruction(data);
	return (EXIT_SUCCESS);
}