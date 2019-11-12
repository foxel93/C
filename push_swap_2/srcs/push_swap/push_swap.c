#include "push_swap.h"

int main(int argc, char **argv)
{
	t_info *info;
	if (argc == 1)
		del_info(NULL, USG_PS);
	else if (argc > 1)
	{
		info = init(argc, argv);
		(info->opt & OPT_V) ? display_stacks(info) : print_cmds(info);
		sort(info);
		optimizer(info);
		(info->opt & OPT_C) ? ft_printf("Count: %zu\n", info->cmds->size) : 0;
		del_info(&info, SUCCESS);
	}
	return (0);
}