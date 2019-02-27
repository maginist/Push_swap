#include "../includes/push_swap.h"

int	pos_best(t_stock **a, t_stock *cur)
{
	int		pos;
	t_stock *beg;

	beg = *a;
	pos = 0;
	while (beg && beg->data != cur->data)
	{
		pos++;
		beg = beg->next;
	}
	return (pos);
}

int		find_max(t_stock **b)
{
	t_stock *beg;
	t_stock	*max;
	int		posm;
	int		pos;

	pos = 0;
	posm = 0;
	max = *b;
	beg = (*b)->next;
	while (beg)
	{
		pos++;
		if (max->data < beg->data)
		{
			posm = pos;
			max = beg;
		}
		beg = beg->next;
	}
	return (posm);
}

void	make_it_sort(t_stock **a, t_stock **b)
{
	int		i;
	int		size;

	size = size_list(b);
	i = find_max(b);
	if (i == 0)
		return ;
	if (i >= size / 2)
		i = -i;
	if (i < 0)
	{
		i = size + i;
		while (i != 0)
		{
			use_rrb(a, b, 1);
			i--;
		}
	}
	else
		while (i != 0)
		{
			use_rb(a, b, 1);
			i--;
		}
	return ;
}

int     pos_goodb2(t_stock *pb, t_stock *c, int inf, t_stock **b)
{
    while (pb && pb->data < c->data)
  	{
		inf++;
		pb = pb->next;
	}
	if (pb && pb->data > c->data)
	{
        while (pb && pb->data > c->data)
		{
			inf++;
			pb = pb->next;
		}
    }
    if (!(pb))
		inf = find_max(b);
    return (inf); 
}

int		pos_goodb(t_stock **b, t_stock *c)
{
	int		inf;
	t_stock	*pb;
	t_stock *end;

	end = *b;
	pb = *b;
	while (end->next)
		end = end->next;
	if (end->data > c->data && pb->data < c->data)
		return (0);
	inf = 0;
	if (pb && pb->data < c->data)
        inf = pos_goodb2(pb, c, inf, b);
	else if (pb && pb->data > c->data)
		while (pb && pb->data > c->data)
		{
			inf++;
			pb = pb->next;
		}
	if (!(pb))
		inf = find_max(b);
	return (inf);
}
