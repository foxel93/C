#include "push_swap.h"

static void	replace(t_stack *src, t_stack *dst, _Bool *bool)
{
	t_val	tmp;

	if (!src || !dst)
	{
		*bool = FALSE;
		return;
	}
	if (src->size == 0)
		return ;
	pop_back(src, &tmp);
	if (!push_back(dst, tmp))
		*bool = FALSE;
}

static void	rotate(t_stack *stack, _Bool *bool)
{
	t_val	tmp;

	if (!stack)
	{
		*bool = FALSE;
		return ;
	}
	if (stack->size < 2)
		return ;
	pop_back(stack, &tmp);
	if (!push_front(stack, tmp))
		*bool = FALSE;
}

static void	rerotate(t_stack *stack, _Bool *bool)
{
	t_val	tmp;

	if (!stack)
	{
		*bool = FALSE;
		return ;
	}
	if (stack->size == 0)
		return ;
	pop_front(stack, &tmp);
	if (!push_back(stack, tmp))
		*bool = FALSE;
}

static void	swap(t_stack *stack, _Bool *bool)
{
	t_val	tmp;
	t_val 	tmp2;

	if (!stack)
	{
		*bool = FALSE;
		return ;
	}
	if (stack->size < 2)
		return;
	pop_back(stack, &tmp);
	pop_back(stack, &tmp2);
	if (!push_back(stack,tmp) || !push_back(stack, tmp2))
		*bool = FALSE;
}

_Bool	operation(t_info *info, size_t n)
{
	_Bool flag;

	flag = TRUE;
	if (n != RA && n != RB && n != RR && n != PA && n != PB &&
		n != RRA && n != RRB && n != RRR &&
		n != SA && n != SB && n != SS)
		return (TRUE);
	n == RA || n == RR ? rotate(info->a, &flag) : 0;
	n == RB || n == RR ? rotate(info->b, &flag) : 0;
	n == RRA || n == RRR ? rerotate(info->a, &flag) : 0;
	n == RRB || n == RRR ? rerotate(info->b, &flag) : 0;
	n == SA || n == SS ? swap(info->a, &flag) : 0;
	n == SB || n == SS ? swap(info->b, &flag) : 0;
	n == PA ? replace(info->b, info->a, &flag) : 0;
	n == PB ? replace(info->a, info->b, &flag) : 0;
	!push_back(info->cmds, n) ? flag = FALSE : 0;
	if (flag == FALSE)
		del_info(&info, MEM_ERR);
	(info->opt & OPT_V) ? display_stacks(info) : 0;
	return (TRUE);
}