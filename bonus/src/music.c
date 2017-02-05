/*
** music.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sat Feb  4 02:40:46 2017 
** Last update Sat Feb  4 03:07:50 2017 
*/

#include	<SFML/System.h>
#include	<SFML/Audio.h>
#include	<unistd.h>
#include	"my.h"

sfMusic		*start_music(char *str)
{
  sfMusic	*music;

  music = sfMusic_createFromFile(str);
  if (!music)
    return (NULL);
  sfMusic_play(music);
  sfMusic_setLoop(music, sfTrue);
  return (music);
}

int		destroy_music(sfMusic *music, int check)
{
  if (!music)
    return (1);
  if (check == 0)
    return (1);
  sfMusic_destroy(music);
  return (1);
}
