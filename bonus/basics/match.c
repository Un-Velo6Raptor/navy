/*
** match.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:33:01 2017 
** Last update Wed Feb  1 21:36:44 2017 
*/

#include	"my.h"

int		match(char *s1, char *s2)
{
  if (*s1 == '\0' && (*s2 == '\0' || *s2 == '*'))
    return (1);
  if (*s1 == '\0' || *s2 == '\0')
    return (0);
  if (*s1 != *s2 && *s2 != '*')
    return (0);
  if (*s2 == '*' && *(s2 + 1) == '*')
    return (match(s1, s2 + 1));
  if (*s2 == '*' && *s1 != *(s2 + 1))
    return (match(s1 + 1, s2));
  else if (*s2 == '*' && *s1 == *(s2 + 1))
    return (match(s1 + 1, s2 + 2));
  return (match(s1 + 1, s2 + 1));
}
