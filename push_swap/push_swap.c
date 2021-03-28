# include "checker.h"

int find_big_one(t_data *m)
{
    int i;
	int big;

	i = 0;
	big = 0;
	if (m->a_size == 0)
		return (-1);
	int tmp = m->stack_a[i].data;
	while (i < m->a_size) 
	{
		if (tmp < m->stack_a[i].data)
		{
			tmp = m->stack_a[i].data;
			big = i;
		}
		i++;
	}
	return (big);
}

void sort_stack_3(t_data *m)
{
    int big;

    big = find_big_one(m);
    if (m->a_size == 1)
        return;
    if (m->a_size == 2)
        if (m->stack_a[0].data > m->stack_a[1].data)
            apply_rra(m);
    else if (m->a_size == 3)
    {
        if (big == 0)
            rotate_a(m);
        if (big == 1)
            apply_rra(m);
        if (m->stack_a[0].data > m->stack_a[1].data)
            swap_a(m); 
    }
}

void begin_sort(t_data *m)
{
    if (m->a_size <= 3)
        sort_stack_3(m);
    if (m->)
}

int main(int argc, char *argv[])
{
    t_data m;
    int count;

    count = 1;
    if (argc-- < 2)
        exit (EXIT_FAILURE);
    init_struct(&m);
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
    begin_sort(&m);
    return (EXIT_SUCCESS);
}