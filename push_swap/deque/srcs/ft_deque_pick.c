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

t_val deque_peek_back_n(t_deque *d, int pos)
{
	t_deque	*tmp;

	tmp = d->info->head;
	if (pos <= 0 || pos >= d->info->len)
	{
		deque_free(d);
		ft_error(0);
	}
	while (--pos > 0 && tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		return (tmp->val);
	deque_free(d);
	ft_error(0);
	return (0);
}

t_val deque_peek_front_n(t_deque *d, int pos)
{
	t_deque	*tmp;

	tmp = d->info->tail;
	if (pos <= 0 || pos >= d->info->len)
	{
		deque_free(d);
		ft_error(0);
	}
	while (--pos > 0 && tmp && tmp->prev)
		tmp = tmp->prev;
	if (tmp)
		return (tmp->val);
	deque_free(d);
	ft_error(0);
	return (0);
}

t_val deque_peek_front(t_deque *d)
{
	return ((d->info->head) ? (d->info->head->val) : 0);
}

t_val deque_peek_back(t_deque *d)
{
	return ((d->info->tail) ? (d->info->tail->val) : 0);
}