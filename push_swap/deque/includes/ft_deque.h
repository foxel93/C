//
// Created by Impulse Alleen on 18/10/2019.
//

#ifndef FT_DEQUE_H
#define FT_DEQUE_H

#include "../../libft/libft.h"

typedef int			t_val;

typedef struct		s_deque t_deque;

typedef struct 		s_info
{
	t_deque			*tail;
	t_deque			*head;
	size_t 			len;
}					t_info;


struct s_deque
{
	t_deque			*next;
	t_deque			*prev;
	t_info			*info;
	t_val			val;
};





t_deque				*deque_alloc();
void				deque_free(t_deque *d);
int					deque_is_empty(t_deque *d);
int					deque_push_front(t_deque *d, t_val v);
int					deque_push_back(t_deque *d, t_val v);

t_val				deque_pop_front(t_deque *d);
t_val				deque_pop_back(t_deque *d);

t_val				deque_peek_front(t_deque *d);
t_val				deque_peek_back(t_deque *d);
t_val				deque_peek_front_n(t_deque *d, int pos);
t_val				deque_peek_back_n(t_deque *d, int pos);
#endif
