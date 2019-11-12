#include "push_swap.h"

static char *ft_strjoin_free_space(char *s1, char const *s2, _Bool last)
{
	char *tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	if (tmp == NULL)
		del_info(NULL, MEM_ERR);
	if (last == TRUE)
		tmp = ft_strjoin_free_space(tmp, " ", FALSE);
	return (tmp);
}

static int	ft_atoi_len(char *str, t_val *num)
{
	long	res;
	int		sign;
	int		i;

	res = 0L;
	i = 0;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (i == 1 && (!str[i] || str[i] == '0' || !ft_isdigit(str[i])))
		return (-1);
	while (str[i] && ft_isdigit(str[i]) && res <= MAX_VAL)
	{
		res = res * 10L + (str[i] - '0');
		i++;
	}
	res = res * sign;
	if (res > MAX_VAL || res < MIN_VAL)
		return (-1);
	if (num != NULL)
		*num = (int)res;
	return (i);
}

static int parser_opt(char **arr, size_t *i, t_info *info)
{
	size_t j;

	*i = 0;
	while (arr[*i] != NULL)
	{
		j = 0;
		if (ft_strlen(arr[*i]) == ft_atoi_len(arr[*i], NULL))
			return (--(*i));
		if (arr[*i][j++] != '-' || arr[*i][j] == '\0')
			break;
		if (arr[*i][j] == 'c' && !((info->opt) & OPT_C) && ++j)
			info->opt |= OPT_C;
		if (arr[*i][j] == 'v' && !((info->opt) & OPT_V) && ++j)
			info->opt |= OPT_V;
		if (arr[*i][j] != '\0')
			break ;
		free(arr[*i]);
		(*i)++;
	}
	while (arr[*i] != NULL)
		free(arr[(*i)++]);
	free(arr);
	return (-2);
}

static _Bool check_dubl(t_info *info, t_val value)
{
	size_t i;

	i = -1;
	while (++i < info->a->size)
	{
		if (get_val(info->a, i) == value)
			return (FALSE);
	}
	push_front(info->a, value);
	return (TRUE);
}

void parser(int argc, char **argv, t_info *info)
{
	char *str;
	size_t i;
	char **arr;
	t_val num;
	_Bool f;

	(!(str = ft_strdup(""))) ? del_info(&info, MEM_ERR) : 0;
	i = 0;
	while (++i < argc)
		str = ft_strjoin_free_space(str, argv[i], i != argc - 1);
	arr = ft_strsplit(str, ' ');
	free(str);
	(!arr) ? del_info(&info, MEM_ERR) : 0;
	(parser_opt(arr, &i, info) == -2) ? del_info(&info, ERROR) : 0;
	f = TRUE;
	while (arr[++i])
	{
		if (!f || ft_strlen(arr[i]) != ft_atoi_len(arr[i], &num) || !check_dubl(info, num))
			f = FALSE;
		free(arr[i]);
	}
	free(arr);
	!f ? del_info(&info, ERROR) : 0;
}
