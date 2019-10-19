#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_deque.h"

# define SA		1
# define SB		2
# define SS		3
# define RA		4
# define RB		5
# define RR		6
# define RRA	7
# define RRB	8
# define RRR	9
# define PA		10
# define PB		11

void	ft_print_stacks(t_deque *a, t_deque *b, int max);
void	ft_error(int n_error);
int 	max_len_deq(t_deque *a, t_deque *b);
int		ft_printf(const char *format, ...);
void	ft_print_commands(t_deque *a);

int		*all_numbers(int argc, char **argv, int count);
int		count_numbers(int argc, char **argv);

int 	swap_stack(t_deque *d);
int 	re_rotate_stack(t_deque *d);
int 	rotate_stack(t_deque *d);
int 	replace_top(t_deque *src, t_deque *dst);

int		swap_all(t_deque *a, t_deque *b);
int		rotate_all(t_deque *a, t_deque *b);
int		re_rotate_all(t_deque *a, t_deque *b);

#endif
