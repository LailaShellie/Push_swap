#include "stack.h"

int main()
{
	t_stack		*a;
	t_stack		*f_a;
	t_stack		*b;
	t_stack		*f_b;

	int i = 1;
	a = new_node(-1);
	f_a = a;
	while (i < 2)
	{
		a->next = new_node(i);
		a = a->next;
		++i;
	}
	int j = 4;
	b = new_node(9);
	f_b = b;
	while (j < 5)
	{
		b->next = new_node(j);
		b = b->next;
		++j;
	}
	show_stack(f_a);
	printf("---------\n");
//	show_stack(f_b);
	reverse_rotate_a(&f_a);
	printf("after\n");
	show_stack(f_a);
	printf("---------\n");
//	show_stack(f_b);
	free_stack(&f_a);
	free_stack(&f_b);
	return (0);
}