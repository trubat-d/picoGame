#ifndef SHELLGAME_SHELLGAME_H
# define SHELLGAME_SHELLGAME_H

# include "PicoShell.h"

typedef enum e_colors
{
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	CYAN,
	WHITE,
	RESET,
	ORANGE
}	t_color;

char	*color(t_color color);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int c);
void	fallout(void);
#endif
