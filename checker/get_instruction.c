/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:08:58 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/14 19:30:25 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker.h"

void    swap_a(t_data *data)
{
    int  tmp;

    if (data->size < 2)
        exit(EXIT_SUCCESS);
    else
    {
        tmp = data->stack_a[0];
        data->stack_a[0] = data->stack_a[1];
        data->stack_a[1] = tmp;
    }
}

void    swap_b(t_data *data)
{
    int  tmp;

    if (data->size < 2)
        exit(EXIT_SUCCESS);
    else
    {
        tmp = data->stack_b[0];
        data->stack_b[0] = data->stack_b[1];
        data->stack_b[1] = tmp;
    }
}

void    push_a(t_data *data)
{
    
}

void    push_b()
{
    printf("push_b");
}

void    rotate_a()
{
    printf("rotate_a");
}

void    rotate_b()
{
    printf("rotate_b");
}

void    get_instruction(t_data *data)
{
    int ret;
    char *line;

    ret = 1;
    while (ret)
    {
        ret = get_next_line(&line);
        if (line[0] == 's' && line[1] == 'a')
            swap_a(data);
        else if (line[0] == 's' && line[1] == 'b')
            swap_b();
        else if (line[0] == 's' && line[1] == 's')
        {
            swap_a(data);
            swap_b(data);
        }
        else if (line[0] == 'p' && line[1] == 'a')
            push_a();
        else if (line[0] == 'p' && line[1] == 'b')
            push_b();
        else if (line[0] == 'r' && line[1] == 'a')
            rotate_a();
        else if (line[0] == 'r' && line[1] == 'b')
            rotate_b();
        else if (line[0] == 'r' && line[1] == 'r')
        {
            rotate_a();
            rotate_b();
        }
        exit(EXIT_SUCCESS);
    }
}
