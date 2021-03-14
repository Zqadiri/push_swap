/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:15:23 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/14 19:11:53 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

/*
** Store all the arguments 
*/

typedef struct      s_data
{
	int				*stack_a;
	int				*stack_b;
	int             pos;
	int				size;
}                   t_data;

void		init(t_data *data);
void        is_valid(t_data *data, char *arg);
void    	check_duplicate(t_data *data);
void        error_code(int  code);

void        init_struct(t_data *data);
int 		get_next_line(char **line);
void    get_instruction();
#endif