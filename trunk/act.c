/*
**
*/
#include	<SDL/SDL.h>
#include	<math.h>
#include	"map.h"
#include	"t_image.h"
#include	"npc.h"
#include	"env.h"
#include	"keydown.h"
#include	"back_to_start.h"

int		something_on_da_way(t_player *player, t_map *map, int fall_len)
{
  int		height;

  height = 0;
  while (height < fall_len)
    {
      if (map->map[player->position.y + height + 1][player->position.x] == 'w' ||
	  map->map[player->position.y + height + 1][player->position.x] == 's')
	{
	  return (height);
	}
      height++;
    }
  return (height);
}

int		falling(t_player *player, t_map *map, int fall_len)
{
  int		temp;

  temp = something_on_da_way(player, map, (int)pow(2, fall_len));
  player->position.y += temp;
  return (temp);
}

void		life_verif(t_player *player, t_map *map, int save)
{
  if (save > 4)
    you_loose(player, map);
  player->wait = 0;
}

void		gravite(t_player *player, t_map *map)
{
  int			tempsActuel;
  static int		tempsPrecedent = 0;
  static int		fall_len = 0;
  static int		save = 0;

  if (map->map[player->position.y + 1][player->position.x] != WALL_CHAR &&
      map->map[player->position.y][player->position.x] != LADDER_CHAR &&
      map->map[player->position.y + 1][player->position.x] != LADDER_CHAR)
    {
      tempsActuel = SDL_GetTicks();
      if (tempsActuel - tempsPrecedent > 30)
	{
	  save += falling(player, map, fall_len);
	  tempsPrecedent = tempsActuel;
	  fall_len++;
	}
      else
	SDL_Delay(30 - (tempsActuel - tempsPrecedent));
    }
  else
    {
      life_verif(player, map, save);
      fall_len = 0;
      save = 0;
    }
}

int		handle_event(t_player *player, t_map *map)
{
  SDL_Event	event;
  int		temp;

  temp = SDL_PollEvent(&event);
  if (temp)
    return (event_loop(&event, player, map));
  return (1);
}

void		env_act(t_map *map, 
			t_player *player, t_npc *monsters)
{
  if (!player->move)
    {
      if (!monsters->move)
	monsters->move = 5;
      monster_time(player, map, monsters);
    }
  are_you_dying(monsters, player, map);
  SDL_Delay(50);
}

void		player_act(int *continuer,
			   t_map *map, t_player *player)
{
  *continuer = handle_event(player, map);
}