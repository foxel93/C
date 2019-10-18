#include "../includes/ft_deque.h"

void deque_push_back(t_deque *d, t_val v)
{
	t_deque *n;

	if (!(n = malloc(sizeof(t_deque))))
		return ;
	n->val = v;
	n->prev = d->info->tail;
	n->next = NULL;
	if (!(d->info->tail))
		d->info->head = n;
	else
		d->info->tail->next = n;
	d->info->tail = n;
	d->info->len++;
}

void deque_push_front(t_deque *d, t_val v)
{
	t_deque *n;

	if (!(n = malloc(sizeof(t_deque))))
		return ;
	n->val = v;
	n->prev = NULL;
	n->next = d->info->head;
	if (!(d->info->head))
		d->info->tail = n;
	else
		d->info->head->prev = n;
	d->info->head = n;
	d->info->len++;
}