#include "push_swap.h"

static _Bool	get_instruction(t_info *info, char *instr)
{
	if (ft_strequ(instr, "sa"))
		operation(info, SA);
	else if (ft_strequ(instr, "sb"))
		operation(info, SB);
	else if (ft_strequ(instr, "ss"))
		operation(info, SS);
	else if (ft_strequ(instr, "pa"))
		operation(info, PA);
	else if (ft_strequ(instr, "pb"))
		operation(info, PB);
	else if (ft_strequ(instr, "ra"))
		operation(info, RA);
	else if (ft_strequ(instr, "rb"))
		operation(info, RB);
	else if (ft_strequ(instr, "rr"))
		operation(info, RR);
	else if (ft_strequ(instr, "rra"))
		operation(info, RRA);
	else if (ft_strequ(instr, "rrb"))
		operation(info, RRB);
	else if (ft_strequ(instr, "rrr"))
		operation(info, RRR);
	else
		return (FALSE);
	return (TRUE);
}

int main(int argc, char **argv)
{
	t_info *info;
	char *line;

	if (argc == 1)
		del_info(NULL, USG_CH);
	else if (argc > 1)
	{
		info = init(argc, argv);
		(info->opt & OPT_V) ? display_stacks(info) : print_cmds(info);
		if (check_sorted(info->a, INC) && info->b->size == 0)
			del_info(&info, OK);
		while (get_next_line(STDIN_FILENO, &line) > 0)
		{
			if (!get_instruction(info, line))
			{
				free(line);
				del_info(&info, ERROR);
			}
			free(line);
		}
		(info->opt & OPT_C) ? ft_printf("Count: %zu\n", info->cmds->size) : 0;
		if (check_sorted(info->a, INC) && info->b->size == 0)
			del_info(&info, OK);
		else
			del_info(&info, KO);
	}
	return (0);
}