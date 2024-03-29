/*
** define for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 26 22:16:19 2010 francois1 ancel
** Last update Fri Mar 26 22:16:19 2010 francois1 ancel
*/

#include	<SDL/SDL.h>
#include	"define.h"
#include	"t_image.h"
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"init_player.h"


int		pass(t_player *player)
{
  player->move = 0;
  return (1);
}

int		fire(t_player *player, t_map *map)
{
  if (player->item.weapon)
    {
      printf("FIRE!!!\n");
      player->item.weapon--;
      pass(player);
    }
  else
    printf("NO MORE AMMO!!!\n");
  return (1);
}

int		take_it(t_player *player, t_map *map)
{
  if (map->map[player->position.y][player->position.x] == LIFE_CHAR)
    {
      printf("You get an extra life.\n");
      map->map[player->position.y][player->position.x] = EMPTY_CHAR;
      player->life += 1;
      return (1);
    }
  if (map->map[player->position.y][player->position.x] == KEY_CHAR)
    {
      printf("You got a key.\n");
      map->map[player->position.y][player->position.x] = EMPTY_CHAR;
      player->item.key = 1;
      return (1);
    }
  if (map->map[player->position.y][player->position.x] == EXIT_CHAR &&
      player->item.key)
    {
      printf("\033[36mLevel complete!\033[00m\n");
      return (0);
    }
  if (map->map[player->position.y][player->position.x] == GUN_CHAR)
     {
       player->item.weapon++;
       map->map[player->position.y][player->position.x] = EMPTY_CHAR;
     }
  return (1);
}

int		jump_in_front(t_player *player, t_map *map)
{
  int		move;

  if ((map->map[player->position.y + 1][player->position.x] == WALL_CHAR ||
       map->map[player->position.y + 1][player->position.x] == LADDER_CHAR ||
       map->map[player->position.y][player->position.x] == LADDER_CHAR) &&
      map->map[player->position.y - 1][player->position.x] != WALL_CHAR)
    {
      if (player->move && !player->wait)
	{
	  player->position.y--;
	  player->wait = 1;
	  player->move--;
	  move = player->direction;
	  if (map->map[player->position.y][player->position.x + move] != WALL_CHAR)
	    {
	      player->position.x += player->direction;
	      if (map->map[player->position.y][player->position.x] != LADDER_CHAR &&
		  map->map[player->position.y][player->position.x + move] != WALL_CHAR)
		{
		  player->position.x += player->direction;
		}
	    }
	}
    }
  return (1);
}

int		press_up(t_player *player, t_map *map)
{
  if (map->map[player->position.y -1][player->position.x] != WALL_CHAR &&
      (map->map[player->position.y + 1][player->position.x] == WALL_CHAR ||
       map->map[player->position.y + 1][player->position.x] == LADDER_CHAR ||
       map->map[player->position.y][player->position.x] == LADDER_CHAR))
    {
      if (player->move && !player->wait)
	{
	  player->position.y--;
	  player->wait = 1;
	  if (map->map[player->position.y - 1][player->position.x] != WALL_CHAR &&
	      map->map[player->position.y][player->position.x] != LADDER_CHAR)
	    {
	      SDL_Delay(30);
	      player->position.y--;
	    }
	  player->move--;
	}
    }
  return (1);
}

int		press_down(t_player *player, t_map *map)
{
  if (map->map[player->position.y + 1][player->position.x] != WALL_CHAR)
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
  player->direction = -1;
  if (map->map[player->position.y][player->position.x - 1] != WALL_CHAR)
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
  player->direction = 1;
  if (map->map[player->position.y][player->position.x + 1] != WALL_CHAR)
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
