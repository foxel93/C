#include "../includes/ft_deque.h"

t_deque *deque_alloc(void)
{
	t_deque	*d;
	t_info	*info;

	if (!(d = malloc(sizeof(t_deque))))
		return (NULL);
	if (!(info = malloc(sizeof(t_info))))
	{
		free(d);
		return (NULL);
	}
	d->prev = NULL;
	d->next = NULL;
	d->val = 0;
	info->head = NULL;
	info->tail = NULL;
	info->len = 1;
	d->info = info;
	return (d);
}

void deque_free(t_deque *d)
{
	int len;
	t_deque	*tmp;
	t_deque	*t;

	t = d;
	len = d->info->len;
	d = d->info->head;
	while (len-- > 1)
	{
		tmp = d;
		free(d->prev);
		d = tmp;
	}
	free(t->info);
	free(t);
}

int deque_is_empty(t_deque *d)
{
	return (d->info->len == 1);
}