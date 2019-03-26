/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:03:47 by dstepane          #+#    #+#             */
/*   Updated: 2019/03/21 19:03:48 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/includes/libft.h"

typedef struct 				s_adjlist
{
	int						dst;
	char					*dest;
	struct s_room			*link;
	struct s_adjlist		*next;
}							t_adjlist;

typedef struct 				s_room
{
	char					*name;
	int						num;
	int						x;
	int						y;
	enum {no, start, end}	flag;
	char					ant;
	int						fire;
	int						count;
	struct s_room			*from;
	struct s_adjlist		*adj;
	struct s_room			*next;
}							t_room;

typedef struct 				s_lemin
{
	size_t					ants;
	size_t					nrooms;
	t_room					*rooms;
	t_room					*start;
	t_room					*end;
	t_room					**q;
}							t_lemin;

int							validate_room(char *line);
void						addroom(t_lemin *l, char *line, int flag);
int							validate_link(char *line);
void						addlink(t_lemin *l, char *line);

void						count_rooms(t_lemin *l);
void						link_adjlist(t_lemin *l);

void						bfs(t_lemin *l);

void						error(char *str);
void						del_arr(char **arr);
void						clean_rooms(t_lemin *l);
//	DEBUG
void						print_rooms_list(t_room *rooms);
void						print_struct_lemin(t_lemin *l);

#endif