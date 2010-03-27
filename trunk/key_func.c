/*
**
*/
#include	<SDL/SDL.h>
#include	"define.h"
#include	"env.h"
#include	"map.h"

int		press_up(t_player *player, t_map *map)
{
  if (map->map[player->position.y - 1][player->position.x] != 'w' &&
      (map->map[player->position.y + 1][player->position.x] == 'w' ||
       map->map[player->position.y + 1][player->position.x] == 's' ||
       map->map[player->position.y][player->position.x] == 's'))
    {
      if (player->move)
	{
	  player->position.y -= 1;
	  player->move -= 1;
	  return (42);
	}
      return (1);
     }
   return (1);
 }

 int		press_down(t_player *player, t_map *map)
 {
   if (map->map[player->position.y + 1][player->position.x] != 'w')
     {
       if (player->move)
	 {
	   player->position.y += 1;
	   player->move -= 1;
	 }
       return (1);
     }
   return (2);
 }

int		press_left(t_player *player, t_map *map)
{
  if (map->map[player->position.y][player->position.x - 1] != 'w')
    {
      if (player->move)
	{
	  player->position.x -= 1;
	  player->move -= 1;
	}
      return (1);
    }
  return (2);
}

int		press_right(t_player *player, t_map *map)
{
  if (map->map[player->position.y][player->position.x + 1] != 'w')
    {
      if (player->move)
	{
	  player->position.x += 1;
	  player->move -= 1;
	}
      return (1);
    }
  return (2);
}