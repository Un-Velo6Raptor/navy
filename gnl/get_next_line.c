/*
** get_next_line.c for  in /home/januar_m/delivery/CPE/CPE_2016_getnextline
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan  2 13:05:09 2017 
** Last update Tue Jan 31 14:08:26 2017 
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
  if (buffer[*idx] != '\0')
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

char			*get_next_line(const int fd, t_buffer *ns)
{
  char			*result;

  result = NULL;
  if ((*ns).cpt != 0 || fd < 0)
    return (NULL);
  if ((result = put_excedent((*ns).buffer, &(*ns).idx, &(*ns).size)) != NULL)
    if (end((*ns).buffer, 1, (*ns).idx) != end((*ns).buffer, 0, (*ns).idx))
      return (result);
  (*ns).idx = 0;
  while (fd >= 0 && READ_SIZE < 2147483646 && READ_SIZE > 0 &&
	 ((*ns).size = read(fd, (*ns).buffer, READ_SIZE)) > 0)
    {
      (*ns).buffer[(*ns).size] = '\0';
      if (((*ns).idx = end((*ns).buffer, 0, 0)) != (*ns).size)
	{
	  if ((result = my_realloc(result, (*ns).buffer, (*ns).idx)) == NULL)
	    return (NULL);
	  return (result);
	}
      else if ((result = my_realloc(result, (*ns).buffer, -1)) == NULL)
	return (NULL);
    }
  (*ns).cpt = 1;
  return ((((*ns).size != 0 || (*ns).idx != 0) && (*ns).size != -1) ?
	  result : free_or_not(result, (*ns).buffer, (*ns).size, (*ns).idx));
}
