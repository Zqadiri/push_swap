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

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../includes/helpers.h"

typedef struct s_data
{
	int				*stack_a;
	int				*stack_b;
	char			*inst_tmp;
	int				a_size;
	int				b_size;
	int				pos;
}	t_data;

/*
**  Operations
*/

void				rotate_b(t_data *m);
void				rotate_a(t_data *m);
void				push_b(t_data *m);
void				push_a(t_data *m);
void				swap_b(t_data *m);
void				swap_a(t_data *m);
void				apply_rra(t_data *m);
void				apply_rrb(t_data *m);

/*
** Parsing
*/

void				get_instruction(t_data *m);
void				is_valid(t_data *data, char *arg);
void				check_duplicate(t_data *data);
void				init_struct(t_data *data, int argc);
void				init_stacks(t_data *data, int argc);
int					is_sorted(t_data *m);
void				help(char *inst, t_data *m);

#endif
