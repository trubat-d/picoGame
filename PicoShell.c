/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PicoShell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:38:02 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/21 18:35:11 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/PicoShell.h"

void ft_print_tab(char **ss)
{
	if (!ss)
		return ;
	while (*ss)
		printf("%s\n", *(ss++));
}

void	free_tab(char **ss)
{
	unsigned i = 0;
	while (ss[i])
		free(ss[i++]);
	free(ss);
}

unsigned int	ft_sstrlen(char **ss)
{
	unsigned int i = 0;
	
	while (ss[i])
		i++;
	return (i);
}

void	man_exec(char **ss)
{
	unsigned int ssize = ft_sstrlen(ss);
	if (ssize == 2)
	{
		if (!strcmp(ss[1], "key"))
			ft_printfd(1, KEY);
		else if (!strcmp(ss[1], "status"))
			ft_printfd(1, STATUS);
		else if (!strcmp(ss[1], "indice"))
			ft_printfd( 1, INDICE);
		else if (!strcmp(ss[1], "fr33_th3_duck"))
			ft_printfd(1, "Bienvenue dans fr33_th3_duck\n");
		else
			ft_printfd(1, "Pas de commande de ce nom\n");
	}
	else if (ssize == 1)
	{
		if (!strcmp(ss[0], "man"))
			ft_printfd(1, MANUEL);
	}
	else
		ft_printfd(1, "Mauvais nombre d'argument\n");
	
}

int	level_up(int key)
{
	DATA *data = get_data(NULL);
	if (data->level == key - 1)
	{
		data->level++;
		data->level_hint_stat = 0;
		get_hint_score();
		data->max_used_hints = 0;
	}
	if (data->level >= key - 1)
	{
		return (1);
	}
	return (0);
}

int	key_value(char **av)
{
	if (!strcmp(av[1], KEY_1))
		return (1);
	else if (!strcmp(av[1], KEY_2))
		return (2);
	else if (!strcmp(av[1], KEY_3))
		return (3);
	else if (!strcmp(av[1], KEY_4))
		return (4);
	return (0);
}

void	key(char **av)
{
	int			pid;
	int			key_val;
	unsigned	ac = ft_sstrlen(av);
	
	if (ac < 2)
		ft_printfd(1, "key: error: pas assez d'arguments\n");
	else if (ac == 2)
	{
		key_val = key_value(av);
		if (key_val == 1)
		{
			if(level_up(key_val))
			{
				pid = fork();
				if (pid == -1)
					return ;
				else if (!pid)
				{
					execve("/Users/hrolle/Desktop/PicoShell/activity_script", NULL, get_data(NULL)->env);
					exit (1);
				}
				else
					wait(NULL);
				ft_printfd(1, "\nQuel-est le mac le plus actif de 42Lausanne ?\nConsulte le bocal, si tu sais voir au travers des apparence,\ntu pourras accéder a la prochaine clé !\n\n");
			}
		}
		else if (key_val == 2)
		{
			if(level_up(key_val))
			{
				level_up(key_val);
				ft_printfd(1, "\nQuand tu est bloqué, il y a toujours un étudiant de 42 pour t'aider !\nPose la question : \"Crois tu en la sainte moulinette\", si il te répond :\n\"Oui, je suis les préceptes de la norminette\", la clé qu'il te donnera te sera surement utile !\nMais prend garde au mécréant !\n\n");
			}
		}
		else if (key_val == 3)
		{
			if (level_up(key_val))
			{
				pid = fork();
				if (pid == -1)
					return ;
				else if (!pid)
				{
					execve("/Users/hrolle/Desktop/PicoShell/remove_me_script", NULL, get_data(NULL)->env);
					exit (1);
				}
				else
					wait(NULL);
				ft_printfd(1, "\nSouvent, faire le ménage permet de clarifier les idée !\n\n");
			}
		}
		else if (key_val == 4)
		{
			if (level_up(key_val))
			{
				ft_printfd(1, "\nSauve le cannard de 42 ! Entre fr33_th3_duck dans PicoShell !!!\n\n");
			}
		}
		else
			ft_printfd(1, "key: error: clé incorrect\n");
	}
	else
		ft_printfd(1, "key: error: pas assez d'arguments\n");
}

void	print_gameover(void)
{	
	ft_printfd(1, "\n\n#r    ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███  \n");   
	ft_printfd(1, "   ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒\n");   
	ft_printfd(1, "  ▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒\n");   
	ft_printfd(1, "  ░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  \n");   
	ft_printfd(1, "  ░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒\n");   
	ft_printfd(1, "   ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░\n");   
	ft_printfd(1, "    ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░\n");   
	ft_printfd(1, "  ░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░ \n");   
	ft_printfd(1, "        ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░     \n");   
	ft_printfd(1, "                                                       ░ #0                  \n");   
}

void	print_loose(char **ss)
{
	char *s = NULL;
	free_tab(ss);
	ft_printfd(1, "You loose, c'est dommage !\n");
	print_score();
	while (!s || !*s || strcmp(s, "exit"))
	{
		if (s)
		{
			free(s);
			s = NULL;
		}
		s = get_next_line(1);
	}
	if (s)
		free(s);
	exit (0);
}

void	print_score(void)
{
	DATA *data = get_data(NULL);

	get_time_score();
	show_elapse_time();
	ft_printfd(1, "\033[38;5;208m°º¤ø,¸¸,ø¤º°`°º¤ø,¸,ø¤°º¤ø,¸ Global Score : %u `°º¤ø,¸,ø¤°º¤ø,¸¸,ø¤º°`°º¤ø,¸#0\n\n", get_global_score());
	ft_printfd(1, "\033[38;5;208m°º¤ø,¸¸,ø¤º°`°º¤ø,¸,ø¤°º¤ø,¸ Level Reached : %u `°º¤ø,¸,ø¤°º¤ø,¸¸,ø¤º°`°º¤ø.#0\n\n", data->level);
}

void	print_victory(char **ss)
{
	char *s = NULL;
	get_data(NULL)->level = 5;
	free_tab(ss);
	ft_printfd(1, "\n\n#g  __/\\\\\\________/\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\________/\\\\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_______/\\\\\\\\\\_________/\\\\\\\\\\\\\\\\\\______/\\\\\\________/\\\\\\___________        \n"); 
	ft_printfd(1, "   _\\/\\\\\\_______\\/\\\\\\_\\/////\\\\\\///______/\\\\\\////////__\\///////\\\\\\/////______/\\\\\\///\\\\\\_____/\\\\\\///////\\\\\\___\\///\\\\\\____/\\\\\\/____________       \n"); 
	ft_printfd(1, "    _\\//\\\\\\______/\\\\\\______\\/\\\\\\_______/\\\\\\/_________________\\/\\\\\\_________/\\\\\\/__\\///\\\\\\__\\/\\\\\\_____\\/\\\\\\_____\\///\\\\\\/\\\\\\/______________      \n"); 
	ft_printfd(1, "     __\\//\\\\\\____/\\\\\\_______\\/\\\\\\______/\\\\\\___________________\\/\\\\\\________/\\\\\\______\\//\\\\\\_\\/\\\\\\\\\\\\\\\\\\\\\\/________\\///\\\\\\/________________     \n"); 
	ft_printfd(1, "      ___\\//\\\\\\__/\\\\\\________\\/\\\\\\_____\\/\\\\\\___________________\\/\\\\\\_______\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\//////\\\\\\__________\\/\\\\\\_________________    \n"); 
	ft_printfd(1, "       ____\\//\\\\\\/\\\\\\_________\\/\\\\\\_____\\//\\\\\\__________________\\/\\\\\\_______\\//\\\\\\______/\\\\\\__\\/\\\\\\____\\//\\\\\\_________\\/\\\\\\_________________   \n"); 
	ft_printfd(1, "        _____\\//\\\\\\\\\\__________\\/\\\\\\______\\///\\\\\\________________\\/\\\\\\________\\///\\\\\\__/\\\\\\____\\/\\\\\\_____\\//\\\\\\________\\/\\\\\\_________________  \n"); 
	ft_printfd(1, "         ______\\//\\\\\\________/\\\\\\\\\\\\\\\\\\\\\\____\\////\\\\\\\\\\\\\\\\\\_______\\/\\\\\\__________\\///\\\\\\\\\\/_____\\/\\\\\\______\\//\\\\\\_______\\/\\\\\\_________________ \n"); 
	ft_printfd(1, "          _______\\///________\\///////////________\\/////////________\\///_____________\\/////_______\\///________\\///________\\///__________________#0\n\n\n\n");  
	ft_printfd(1, "           BravoooOOO ! Tu as délivré la mascotte de 42Lausanne !!!\n");
	print_score();
	while (!s || !*s || strcmp(s, "exit"))
	{
		if (s)
		{
			free(s);
			s = NULL;
		}
		s = get_next_line(1);
	}
	if (s)
		free(s);
	exit (0);
}


void run_fr33_th3_duck(char **ss)
{
		int exit_code = 1;
		char	*line;
		int		run;
		int		stop;
		while (exit_code)
		{
			exit_code = fr33_th3_duck();
			if (exit_code)
			{
				run = 1;
				while (run)
				{	
					print_gameover();
					ft_printfd(1, "\nPour retry tape                    : y\nPour abandonné et tout perdre tape : n\nPicoShell $> ");
					line = get_next_line(1);
					if (!line || !*line)
						run = 1;
					else if (!strcmp(line, "y"))
					{
						run = 0;
						stop = 0;
					}
					else if (!strcmp(line, "n"))
					{
						run = 0;
						stop = 1;
					}
					else
						run = 1;
					free(line);
					line = NULL;
				}
			}
			if (stop)
				break;
		}
		if (exit_code)
			print_loose(ss);
		else
			print_victory(ss);
}

void	exec_cmd(char **ss)
{
	if (!strcmp(*ss, "key"))
		key(ss);
	else if (!strcmp(*ss, "status"))
		get_status();
	else if (!strcmp(*ss, "indice"))
		get_hint();
	else if (!strcmp(*ss, "fr33_th3_duck") && get_data(NULL)->level == 4)
		run_fr33_th3_duck(ss);
	else if (!strcmp(*ss, "man"))
		man_exec(ss);
	else
		ft_printfd(1, "Pas de commande de ce nom\n");
}

int	main(int ac, char **av, char **env)
{
	char **ss;
	DATA data;

	(void)ac;
	(void)av;
	data.env = env;
	data.level_hint_stat = 0;
	data.max_used_hints = 0;
	data.time_score = 0;
	data.hint_score = 5600000;
	get_data(&data);
	gen_timer();
	data.level = 0;
	fallout();
	ft_printfd(1, "Your start key :\n#k%s#0\n", KEY_1);
	while (1)
	{
		ft_printfd(1, "PicoShell $> ");
		ss = ft_split(get_next_line(0), ' ');
		if (ss)
		{
			exec_cmd(ss);
			free_tab(ss);
		}
	}
	return (0);
}
