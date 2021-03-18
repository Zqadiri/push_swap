/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:15:23 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/18 10:53:42 by zqadiri          ###   ########.fr       */
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
typedef struct s_stack_a
{
	int			data;
	int			alive;

}				t_stack_a;

typedef struct s_stack_b
{
	int			data;
	int			alive;
}				t_stack_b;

typedef struct      s_data
{
	t_stack_a		*stack_a;
	t_stack_b		*stack_b;
	int             pos;
	int				a_size;
	int				b_size;
}                   t_data;

void		init(t_data *data);
void        is_valid(t_data *data, char *arg);
void    	check_duplicate(t_data *data);
void        error_code(int  code);
void        init_struct(t_data *data);
int 		get_next_line(char **line);
void    	get_instruction(t_data *m);
void		init_stacks(t_data *data);
void		print(t_data *m); 
#endif