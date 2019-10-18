#include "../includes/ft_ls.h"


void listdir(const char *name, int indent, t_ldir **ldir)
{
	DIR *dir;
	struct dirent *entry;
	char *path;

	if (*ldir == NULL)
	{
		if (!(dir = opendir(name)))
			return;
		entry = readdir(dir);
		path = ft_strjoin(name, "/");
		path = ft_strjoin(path, entry->d_name);
		*ldir = ft_ldirnew(1, entry->d_name, path);
	}
	else if (!(dir = opendir(name)))
		return;
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_DIR)
		{
			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
				continue;
			path = ft_strjoin(name, "/");
			path = ft_strjoin(path, entry->d_name);
			ft_ldiradd(ldir, ft_ldirnew((*ldir)->id + 1, entry->d_name, path));
			listdir(path, indent, ldir);
		}
	}
	closedir(dir);
}