/*
** get_next_line.c for  in /home/januar_m/delivery/CPE/CPE_2016_getnextline
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan  2 13:05:09 2017 
** Last update Tue Jan 31 14:07:51 2017 
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"get_next_line.h"

int			end(char *str, int opt, int start)
{
  int			idx;
  int			check;

  check = 0;
  idx = start;
  if (str == NULL)
    return (0);
  while (str[idx] != '\0' && (opt == 1 || opt == 2 || str[idx] != '\n'))
    {
      if (str[idx] == '\n')
	check++;
      if (check == 2)
	return (idx);
      idx++;
    }
  return (idx);
}

char			*free_or_not(char *result, char *buffer, int size, int idx)
{
  if (idx == 0 && end(result, 1, 0))
    return (result);
  if (size == -1)
    return (NULL);
  if (end(buffer, 2, 0) != 0)
    free(result);
  return (NULL);
}

char			*my_realloc(char *str, char *add_str, int max)
{
  char			*new_str;
  int			idx;
  int			idx2;

  idx = 0;
  idx2 = 0;
  if ((new_str = malloc(end(str, 2, 0) + end(add_str, 0, 0) + 1)) == NULL)
    return (NULL);
  if (str != NULL)
    while (str[idx] != '\0')
      {
	new_str[idx] = str[idx];
	idx++;
      }
  while (add_str[idx2] != '\0' && (idx2 < max || max == -1))
    {
      new_str[idx] = add_str[idx2];
      idx++;
      idx2++;
    }
  new_str[idx] = '\0';
  if (str != NULL)
    free(str);
  return (new_str);
}

char			*put_excedent(char *buffer, int *idx, int *cpt)
{
  char			*new_str;
  int			idx2;
  int			tmp;

  idx2 = 0;
  tmp = (*idx);
  (*idx)++;
  *cpt = 0;
  if ((new_str = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  while (buffer[*idx] != '\0' && (*idx) < end(buffer, 2, tmp))
    {
      new_str[idx2] = buffer[*idx];
      (*idx)++;
      idx2++;
    }
  new_str[idx2] = '\0';
  return (new_str);
}

char			*get_next_line(const int fd)
{
  static t_buffer	news = {{0}, 0, 0, 0};
  char			*result;

  result = NULL;
  if (news.cpt != 0 || fd < 0)
    return (NULL);
  if ((result = put_excedent(news.buffer, &news.idx, &news.size)) != NULL)
    if (end(news.buffer, 1, news.idx) != end(news.buffer, 0, news.idx))
      return (result);
  news.idx = 0;
  while (fd >= 0 && READ_SIZE < 2147483646 && READ_SIZE > 0 &&
	 (news.size = read(fd, news.buffer, READ_SIZE)) > 0)
    {
      news.buffer[news.size] = '\0';
      if ((news.idx = end(news.buffer, 0, 0)) != news.size)
	return (((result = my_realloc(result, news.buffer,
				      news.idx)) == NULL) ? NULL : result);
      else if ((result = my_realloc(result, news.buffer, -1)) == NULL)
	return (NULL);
    }
  news.cpt++;
  return (((news.size != 0 || news.idx != 0) && news.size != -1) ?
	  result : free_or_not(result, news.buffer, news.size, news.idx));
}
