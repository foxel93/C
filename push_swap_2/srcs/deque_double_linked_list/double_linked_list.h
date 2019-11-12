#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

typedef	int 		t_val;

typedef struct		s_node
{
	t_val			value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_dlst
{
	size_t			size;
	t_node			*head;
	t_node			*tail;
}					t_dlst;

t_dlst* create_dlst(void);
void delete_dlst(t_dlst **dlst);
_Bool push_front(t_dlst *dlst, t_val value);
_Bool push_back(t_dlst *dlst, t_val value);
_Bool pop_back(t_dlst *dlst,t_val *value);
_Bool pop_front(t_dlst *dlst, t_val *value);
t_node* get_nth_elem(t_dlst *dlst, size_t index);
_Bool insert(t_dlst *dlst, size_t index, t_val value);
_Bool delete_nth_elem(t_dlst *dlst, size_t index, t_val *value);
void print_dlst(t_dlst *list, void (*f)(t_val value));
void print_int(t_val value);
_Bool peek_back(t_dlst *dlst, t_val *value);
_Bool peek_front(t_dlst *dlst, t_val *value);
t_node* change_nth_elem(t_dlst *dlst, size_t index, t_val val);
#endif //DOUBLE_LINKED_LIST_H
