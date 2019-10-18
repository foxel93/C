#include "../includes/ft_deque.h"

static int ft_error(int n_error)
{
	if (n_error == 0)
	{
		ft_putstr_fd("Error", 2);
		exit(0);
	}
	return (1);
}

t_val deque_pop_front(t_deque *d)
{
	t_deque *n;
	t_val v;

	if (!d->info->head)
		ft_error(0);
	v = d->info->head->val;
	n = d->info->head;
	if (d->info->head == d->info->tail)
	{
		d->info->head = NULL;
		d->info->tail = NULL;
	}
	else
		d->info->head = n->next;
	d->info->len--;
	free(n);
	return (v);
}

t_val deque_pop_back(t_deque *d)
{
	t_val	v;
	t_deque *n;

	if (!d->info->tail)
		ft_error(0);
	v = d->info->tail->val;
	n = d->info->tail;
	if (d->info->head == d->info->tail)
	{
		d->info->head = NULL;
		d->info->tail = NULL;
	}
	else
		d->info->tail = n->prev;
	d->info->len--;
	free(n);
	return (v);
}