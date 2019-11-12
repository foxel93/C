#include "push_swap.h"

void	del_info(t_info **info, size_t mode)
{
	if (info != NULL && *info != NULL)
	{
		((*info)->a != NULL) ? free((*info)->a) : 0;
		((*info)->b != NULL) ? free((*info)->b) : 0;
		((*info)->cmds != NULL) ? free((*info)->cmds) : 0;
		free(*info);
		*info = NULL;
	}
	if (mode == SUCCESS || mode == USG_CH || mode == USG_PS || mode == OK || mode == KO)
	{
		(mode == USG_CH) ? ft_putstr("Usage: checker\n") : 0;
		(mode == USG_PS) ? ft_putstr("Usage: push swap\n") : 0;
		(mode == OK) ? ft_putstr("OK\n") : 0;
		(mode == KO) ? ft_putstr("KO\n") : 0;
		exit(EXIT_SUCCESS);
	}
	else if (mode == MEM_ERR || mode == ERROR)
	{
		(mode == MEM_ERR) ? ft_putstr_fd("Error: Memory\n", STDERR_FILENO) : 0;
		(mode == ERROR) ? ft_putstr_fd("Error\n", STDERR_FILENO) : 0;
		exit(EXIT_FAILURE);
	}
}

t_info	*init(int argc, char **argv)
{
	t_info *info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		del_info(&info, MEM_ERR);
	info->a = create_dlst();
	info->b = create_dlst();
	info->cmds = create_dlst();
	info->opt = 0;
	if (!info->a || !info->b || !info->cmds)
		del_info(&info, MEM_ERR);
	parser(argc, argv, info);
	return (info);
}