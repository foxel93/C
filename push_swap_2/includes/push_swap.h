#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../srcs/deque_double_linked_list/double_linked_list.h"
#include "printf.h"
#include "../libft/libft.h"

#define OPT_C	0x1
#define OPT_V	0x2

#define TRUE	1
#define FALSE	0

#define ERROR	1
#define MEM_ERR	2
#define USG_PS	3
#define USG_CH	4
#define SUCCESS	5
#define OK		6
#define KO		7


#define MAX_VAL	INT_MAX
#define MIN_VAL	INT_MIN

#define INC		1
#define DEC		2

#define STACK_A	0
#define STACK_B	1

#define SA	11
#define SB	12
#define SS	23
#define RA	21
#define RB	22
#define RR	43
#define RRA	31
#define RRB	32
#define RRR 63
#define PA	41
#define PB	42

#define F_MIN	0
#define F_MAX	1

typedef t_dlst		t_cmds;
typedef	t_dlst		t_stack;
typedef int			t_val;


# define ABS(x) (x < 0 ? -x : x)
# define MAX(x, y) (x > y ? x : y)
# define MIN(x, y) (x < y ? x : y)

typedef	struct 		s_info
{
	size_t			pos_a;
	size_t			steps_a;
	size_t			steps_b;
	size_t			total_steps;
	size_t			pos_prev_big;
	size_t			op_a;
	size_t			op_b;
	size_t 			opt;
	t_stack			*a;
	t_stack			*b;
	t_cmds			*cmds;
}					t_info;

t_info	*init(int argc, char **argv);
void	del_info(t_info **info, size_t mode);

void	print_cmds(t_info *info);
void	display_stacks(t_info *info);

_Bool	check_sorted(t_stack *stack, int mode);
void	sort(t_info *info);

_Bool	operation(t_info *info, size_t n);
void	optimizer(t_info *info);

size_t	get_steps(t_stack *stack, int value);
void	get_min_steps(t_info *info);

void	parser(int argc, char **argv, t_info *info);

t_val 	find_min_max_elem(t_stack *stack, size_t min_max);
size_t	find_min_max_index(t_stack *stack, size_t min_max);
t_val	get_val(t_stack *stack, size_t pos);
size_t	get_pos(t_stack *stack, int value);
size_t	get_mlen(int length);
#endif
