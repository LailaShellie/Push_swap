//
// Created by Ivan on 17/02/2020.
//

#include "stack.h"

void		copy_mas(int *mas, t_stack *stack)
{
	t_stack		*cur;
	int 		i;

	i = 0;
	cur = stack;
	while (cur)
	{
		mas[i++] = cur->num;
		cur = cur->next;
	}
}

void		bubble_sort(int *mas, int len)
{
	int 	i;
	int 	j;
	int 	tmp;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len - i - 1)
		{
			if (mas[j] > mas[j + 1])
			{
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
}