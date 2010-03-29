/*
** header
*/
#include	<SDL/SDL.h>
#include	"define.h"
#include	"map.h"
#include	"t_image.h"
#include	"npc.h"
#include	"env.h"

void	rand_move(t_player *boss, t_map *map)
{
  int	dir;

  dir = boss->direction;
  if (map->map[boss->position.y][boss->position.x + dir] != WALL_CHAR &&
      (map->map[boss->position.y + 1][boss->position.x + dir] == LADDER_CHAR ||
       map->map[boss->position.y + 1][boss->position.x + dir] == WALL_CHAR))
    boss->position.x += boss->direction;
  else
    boss->direction *= -1;
}

void	shoot(t_player *boss, t_player *player)
{
  int	direction;

  direction = player->move - boss->move;
  if (direction > 0)
    boss->direction = 1;
  else
    boss->direction = -1;
  boss->banane.pos.x = boss->position.x + boss->direction;
  boss->banane.pos.y = boss->position.y;
  boss->banane.move = PORTEE;
  boss->banane.dir = boss->direction;
}

void	path_finding(t_player *player, t_player *boss, t_map *map)
{
  int	dir;

  dir = player->move - boss->move;
  if (dir > 0)
    dir = 1;
  else
    dir = -1;
  boss->direction = dir;
  if (map->map[boss->position.y][boss->position.x + dir] != WALL_CHAR &&
      (map->map[boss->position.y + 1][boss->position.x + dir] == LADDER_CHAR ||
       map->map[boss->position.y + 1][boss->position.x + dir] == WALL_CHAR))
    boss->position.x += boss->direction;
      
}

void	ia(t_player *player, t_player *boss, t_map *map)
{
  int	test;

  if (boss->move)
    {
      if (player->position.y == boss->position.y)
	{
	  test = player->position.x - boss->position.x;
	  if (test < 0)
	    test *= -1;
	  if (test <= PORTEE && test > boss->move) 
	    shoot(boss, player);
	  else
	    path_finding(player, boss, map);
	}
      else
	rand_move(boss, map);
      boss->move--;
      if (!boss->move)
	player->move = NB_MOVE;
    }
}