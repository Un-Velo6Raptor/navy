/*
** battleship.h for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin/include
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 15:22:33 2017 
** Last update Mon Jan 30 19:38:21 2017 
*/

#ifndef		BATTLESHIP_H_
# define	BATTLESHIP_H_

typedef struct	s_map
{
  char		**my_map;
  char		**enemy_map;
}		t_map;

/*
**		Prototypes of file's sources.
*/

char		*my_char_to_binary(char);
char		my_binary_to_char(char *);
int		help_me(void);
t_map		*ini_map(void);
void		disp_map(char **);

/*
**		Prototypes of file's basics.
*/

int		my_strlen(char *);
int		my_puterror(char *);
char		*my_strcpy(char *, char *);
char		*my_strdup(char *);
void		my_putstr(char *);
char		**my_path_tab(char *);

/*
**		Prototypes of get_next_line.
*/

char		*get_next_line(int);

#endif		/* !BATTLESHIP_H_ */
