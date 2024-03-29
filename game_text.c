/*
** game_text for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sun Mar 28 23:24:35 2010 francois1 ancel
** Last update Sun Mar 28 23:24:35 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	"define.h"
#include	"t_image.h"
#include	"image_fct.h"
#include	"boss.h"
#include	"map.h"
#include	"npc.h"
#include	"env.h"
#include	"exec_fct.h"
#include	"xio.h"
#include	"game_text.h"

void		display_life(SDL_Surface *screen, t_player *player)
{
  TTF_Font	*font;

  if (TTF_Init() < 0)
    {
      fprintf(stderr, "TTF error : %s", TTF_GetError());
      return ;
    }
  font = TTF_OpenFont(FONT_DIR, MFONT_SIZE);
  if (!font)
    {
      fprintf(stderr, "TTF error : %s", TTF_GetError());
      return ;
    }
  display_text(screen, player, font);
  TTF_CloseFont(font);
  TTF_Quit();
}

void		display_text(SDL_Surface *screen, t_player *player,
			     TTF_Font *font)
{
  char		str[50];
  SDL_Color	color = {0, 0, 0, 0};
  SDL_Rect	pos;
  SDL_Surface	*text;

  sprintf(str, "%i life remaining", player->life);
  text = TTF_RenderText_Blended(font, str, color);
  pos.x = 16;
  pos.y = 16;
  SDL_BlitSurface(text, NULL, screen, &pos);
  sprintf(str, "%d ammo", player->item.weapon);
  text = TTF_RenderText_Blended(font, str, color);
  pos.y = 32;
  SDL_BlitSurface(text, NULL, screen, &pos);
  sprintf(str, "%d move", player->move);
  text = TTF_RenderText_Blended(font, str, color);
  pos.y = 48;
  SDL_BlitSurface(text, NULL, screen, &pos);
  sprintf(str, "%d key", player->item.key);
  text = TTF_RenderText_Blended(font, str, color);
  pos.y = 64;
  SDL_BlitSurface(text, NULL, screen, &pos);
}
