#include "includes/ft_ls.h"

int main(void) {
	t_ldir *list;

	list = NULL;
	listdir(".", 0, &list);


	while (list)
	{
		printf("%s\n",list->fullpath);
		list = list->next;
	}
	return 0;
}