#ifndef			__NPC_H__
# define		__NPC_H__

typedef struct		s_npc
{
  int			x;
  int			y;
  int			vx;
  SDL_Surface		*img;
  struct s_npc		*next;
}			t_npc;

t_npc			*get_npc_monsters(t_map *map, SDL_Surface *img);

#endif			/* __NPC_H__ */
