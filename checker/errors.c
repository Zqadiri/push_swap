/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:07:16 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/14 15:23:22 by zqadiri          ###   ########.fr       */
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
}