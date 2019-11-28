#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

# define ERROR		1
# define SUCCESS	0


typedef struct	s_map
{
	char		**names;		// array of room names
	char		*rooms_list;	// list of names that was passed at the beginning
	char		*ants_str;		// list of ants that was passed at the beginning
	char		*links_list;			// list of links_list that was passed at the beginning
	int			count_rooms;		// quantity of names
	int			ants;			// quantity of ants
	int			started;		// a part of validation
	int			curr_room;		// an index of current room we're in
	int			p_ind;			// last path index, current size of path
	int			*path;			// path
	int			**tab;			// edge table
	int			start_end[2];		// a part of validation
	int 		pos_start_end[2];
	int			new_line;		// a part of validation
	int			init_2;			// a part of validation
	char 		*line;
}				t_map;

void			checker(t_map *m);

void			add_rooms(t_map *m);
void			create_tab(t_map *m);
_Bool			solution(t_map *m, int i);

char			*ft_strjoin_free_ln(char *s1, const char *s2);
void			free_split(char **array, t_map *m, int error);
int				room_index(t_map *m, char *room_name, int start);

void			result(t_map *m);
void			print_matrix(t_map *m);
void			ft_exit(t_map *m, int error);

#endif
