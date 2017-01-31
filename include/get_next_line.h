/*
** get_next_line.h for  in /home/januar_m/delivery/CPE/CPE_2016_getnextline
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan  2 13:01:16 2017 
** Last update Tue Jan 31 21:00:47 2017 
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (42)
# endif /* !READ_SIZE */

typedef struct	s_buffer
{
  char		buffer[READ_SIZE + 1];
  int		idx;
  int		size;
  int		cpt;
}		t_buffer;

#endif /* !GET_NEXT_LINE_H_ */
