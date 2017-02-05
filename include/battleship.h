/*
** battleship.h for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin/include
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 15:22:33 2017 
** Last update Sun Feb  5 20:05:44 2017 
*/

#ifndef BATTLESHIP_H_
# define BATTLESHIP_H_

# include	<signal.h>

typedef struct	s_map
{
  char		**my_map;
  char		**enemy_map;
}		t_map;

typedef struct  s_glob
{
  char		**av;
  char		byte;
  int		pid;
  int		last_pid;
}		t_glob;

/*
**		Prototypes of file's sources.
*/

char		*my_char_to_binary(char);
char		my_binary_to_char(char *);
int		help_me(void);
t_map		*ini_map(void);
void		disp_map(char **);
int		check_coo(int, char *, char *);
char		*receive(int);
void		send(int, char *);
int		turn_part1(char **, char **, int, int);
int		turn_part2(char **, char **, int, int);
int		prepare_map(t_map *, int, char **);
void		disp_my_and_enemy_map(char **, char **);
void		connect(int, siginfo_t *, void *);
void		connect2(int);
int		win_loose(char **, char **);
void		start(int);
void		get_enemy_id(int, siginfo_t *, void *);
char		*cg_str(char *);

/*
**		Prototypes of file's basics.
*/

int		my_strlen(char *);
int		my_puterror(char *);
char		*my_strcpy(char *, char *);
char		*my_strdup(char *);
void		my_putstr(char *);
char		**my_path_tab(char *);
int		my_char_isnum(char);
int		count_tab(char **);
int		my_getnbr(char *);
int		free_tab(char **, int);
int		my_strcmp(char *, char *);
void		my_put_nbr(int);
void		my_putchar(char);
char		*my_good_str(char *);
void		my_swap(char **);

#endif /* !BATTLESHIP_H_ */
