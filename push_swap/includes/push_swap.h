#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_deque.h"
# include "../ft_printf/includes/printf.h"

void	ft_print_stacks(t_deque *a, t_deque *b, int max);
int		ft_error(int n_error);
int 	max_len_deq(t_deque *a, t_deque *b);
void 	swap_stack(t_deque *d);

#endif
