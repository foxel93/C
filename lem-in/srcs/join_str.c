#include "lem_in.h"

char	*ft_strjoin_free_ln(char *s1, const char *s2)
{
	if (!(s1 = ft_strjoin_free(s1, "\n")))
		return (NULL);
	return (ft_strjoin_free(s1, s2));

}
