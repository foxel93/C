#include "libft.h"

void	ft_strsplitdel(char **str)
{
	size_t i;

	if (!str || !*str)
		return;
	i = -1;
	while (str[++i])
		(str[i]) ? free(str[i]) : 0;
	free(str);
	str = NULL;
}