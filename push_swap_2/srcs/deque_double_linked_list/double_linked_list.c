#include "double_linked_list.h"

t_dlst* create_dlst(void)
{
	t_dlst *tmp;

	tmp = malloc(sizeof(tmp));
	if (tmp == NULL)
		return (NULL);
	tmp->size = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	return (tmp);
}

void delete_dlst(t_dlst **dlst) {
	t_node *tmp;
	t_node *next;

	if (dlst == NULL || *dlst == NULL)
		return ;
	tmp = (*dlst)->head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*dlst);
	(*dlst) = NULL;
}

_Bool push_front(t_dlst *dlst, t_val value)
{
	t_node *tmp;

	tmp = malloc(sizeof(tmp));
	if (tmp == NULL)
		return (0);
	tmp->value = value;
	tmp->next = dlst->head;
	tmp->prev = NULL;
	if (dlst->head) {
		dlst->head->prev = tmp;
	}
	dlst->head = tmp;
	if (dlst->tail == NULL) {
		dlst->tail = tmp;
	}
	dlst->size++;
	return (1);
}

_Bool push_back(t_dlst *dlst, t_val value)
{
	t_node *tmp;

	tmp = malloc(sizeof(tmp));
	if (tmp == NULL)
		return (0);
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = dlst->tail;
	if (dlst->tail)
		dlst->tail->next = tmp;
	dlst->tail = tmp;
	if (dlst->head == NULL)
		dlst->head = tmp;
	dlst->size++;
	return (1);
}

_Bool pop_back(t_dlst *dlst, t_val *value)
{
	t_node *next;

	if (dlst == NULL || dlst->tail == NULL)
		return (0);
	next = dlst->tail;
	dlst->tail = dlst->tail->prev;
	if (dlst->tail)
		dlst->tail->next = NULL;
	if (next == dlst->head)
		dlst->head = NULL;
	*value = next->value;
	free(next);
	dlst->size--;
	return (1);
}

_Bool peek_back(t_dlst *dlst, t_val *value)
{
	if (dlst == NULL || dlst->tail == NULL)
		return (0);
	*value = dlst->tail->value;
	return (1);
}

_Bool peek_front(t_dlst *dlst, t_val *value)
{
	if (dlst == NULL || dlst->head == NULL)
		return (0);
	*value = dlst->head->value;
	return (1);
}

_Bool pop_front(t_dlst *dlst, t_val *value)
{
	t_node *prev;

	if (dlst->head == NULL)
		return (0);
	prev = dlst->head;
	dlst->head = dlst->head->next;
	if (dlst->head)
		dlst->head->prev = NULL;
	if (prev == dlst->tail)
		dlst->tail = NULL;
	*value = prev->value;
	free(prev);
	dlst->size--;
	return (1);
}

t_node* change_nth_elem(t_dlst *dlst, size_t index, t_val val)
{
	t_node *tmp;
	size_t	i;

	if (dlst == NULL)
		return (NULL);
	if (index < dlst->size/2)
	{
		i = 0;
		tmp = dlst->head;
		while (tmp && i < index)
		{
			tmp = tmp->next;
			i++;
		}
	}
	else
	{
		i = dlst->size - 1;
		tmp = dlst->tail;
		while (tmp && i > index)
		{
			tmp = tmp->prev;
			i--;
		}
	}
	if (tmp != NULL)
		tmp->value = val;
	return (tmp);
}

t_node* get_nth_elem(t_dlst *dlst, size_t index)
{
	t_node *tmp;
	size_t	i;

	if (dlst == NULL)
		return (NULL);
	if (index < dlst->size/2)
	{
		i = 0;
		tmp = dlst->head;
		while (tmp && i < index)
		{
			tmp = tmp->next;
			i++;
		}
	}
	else
	{
		i = dlst->size - 1;
		tmp = dlst->tail;
		while (tmp && i > index)
		{
			tmp = tmp->prev;
			i--;
		}
	}
	return (tmp);
}

_Bool insert(t_dlst *dlst, size_t index, t_val value)
{
	t_node *elm;
	t_node *ins;

	elm = get_nth_elem(dlst, index);
	if (elm == NULL)
		return (0);
	ins = malloc(sizeof(ins));
	if (ins == NULL)
		return (0);
	ins->value = value;
	ins->prev = elm;
	ins->next = elm->next;
	if (elm->next)
		elm->next->prev = ins;
	elm->next = ins;
	if (!elm->prev)
		dlst->head = elm;
	if (!elm->next)
		dlst->tail = elm;
	dlst->size++;
	return (1);
}

_Bool delete_nth_elem(t_dlst *dlst, size_t index, t_val *value) {
	t_node *elm;

	elm = get_nth_elem(dlst, index);
	if (elm == NULL)
		return (0);
	if (elm->prev)
		elm->prev->next = elm->next;
	if (elm->next)
		elm->next->prev = elm->prev;
	if (value != NULL)
		*value = elm->value;
	if (!elm->prev)
		dlst->head = elm->next;
	if (!elm->next)
		dlst->tail = elm->prev;
	free(elm);
	dlst->size--;
	return (1);
}

void print_dlst(t_dlst *list, void (*f)(t_val value)) {
	t_node *tmp;

	tmp = list->head;
	while (tmp)
	{
		f(tmp->value);
		tmp = tmp->next;
	}
	ft_putstr("\n");
}