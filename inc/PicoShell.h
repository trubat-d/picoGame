#ifndef PICO_SHELL_H
# define PICO_SHELL_H

# define KEY_1 "%yO01*$kla79)(;{FLAGS}"//"%yO01*$kla79)(;{FLAGS}"
# define KEY_2 "c1r13s2"//"c1r13s2"
# define KEY_3 "piscine"//"student_key"
# define KEY_4 "SL@GOON"//"remove_me"
# define PLAY_TIME 60
# include "../printfd/HEADER/ft_printfd.h"
# include "man.h"
# include "get_next_line.h"
# include "shellgame.h"
# include "hints.h"
# include <math.h>
# include <string.h>
# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <termios.h>

typedef struct s_timer
{
	pthread_mutex_t		*timer_lock;
	time_t				start_time;
	time_t				cur_time;
}	t_timer;

typedef struct s_data
{
	t_timer			*time;
	char			**env;
	int				level;
	int				level_hint_stat;
	int				max_used_hints;
	unsigned		hint_score;
	unsigned		time_score;
}					DATA;

char			**ft_split(char *s, char c);
void			*routine(void *time_ds);
void			gen_timer(void);
unsigned long	get_elapse_time(void);
DATA			*get_data(DATA	*data);
int				fr33_th3_duck(void);
void			get_status(void);
unsigned long	get_global_score(void);
void			get_time_score(void);
void			get_hint_score(void);
void			free_tab(char **ss);
void			print_score(void);
void			show_elapse_time(void);

#endif