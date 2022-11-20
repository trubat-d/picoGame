#include "../inc/PicoShell.h"

#define WORD_LEN 5
#define MAX_TRIES 5

int	compare_words(char *word1, char *word2)
{
	int	i = 0;
	int j = 0;
	int	*tab;
	int	diff = 0;

	tab = calloc(5, sizeof(int));
	while (word1[i])
	{
		j = 0;
		while (word2[j])
		{
			if (word1[i] == word2[j] && !tab[j])
			{
				tab[j] = 1;
				diff++;
				break ;
			}
			j++;
		}
		i++;
	}
	fflush(0);
	free(tab);
	return (diff);
}

int	compare_list(char *word, char **word_list)
{
	int i = 0;

	if (!word)
		return 0;
	while (word_list[i])
	{
		if (compare_words(word_list[i], word) == WORD_LEN)
			break ;
		i++;
	}
	if (!word_list[i])
		return (0);
	return (1);
}

char	random_char_gen(void)
{
	char	*list = "!@#&(){}[]:;',?/*`~$^+=<>\"\\";
	int		random = rand() % 27;
	return (list[random]);
}

char	*random_char_list(char **word_list)
{
	static int	tab;
	char		*res;
	int			i = 0;
	int			j = 0;
	int			random = rand() % 4;

	if (tab >= 20)
		tab = 0;
	res = calloc(4 + WORD_LEN, sizeof(char));
	while (i < 3 + WORD_LEN)
	{
		if (i >= random && j < WORD_LEN)
			res[i] = word_list[tab][j++];
		else
			res[i] = random_char_gen();
		i++;
	}
	tab++;
	return (res);
}

char	**gen_word_list(int fd)
{
	char	**res;

	res = malloc(501 * sizeof(char *));
	res[500] = 0;
	for (int i = 0; i < 500; i++)
		res[i] = get_next_line(fd);
	return (res);
}

char	**get_word_list(char **word_list)
{
	char	**res;
	int		random;

	res = calloc(21, sizeof(char *));
	for (int i = 0; i < 20; i++)
	{
		random = rand() % 500;
		res[i] = word_list[random];
	}
	return (res);
}

char	*gen_password(char **word_list)
{
	int random = rand() % 20;
	return (word_list[random]);
}

void	ft_putstr_dlay(char *str)
{
	int	i = 0;
	while (str[i])
	{
		usleep(5000);
		printf("%c", str[i]);
		fflush(0);
		i++;
	}
}

void printer(char *address_base, char **word_list, int i)
{
	char	*address;
	char	*list;
	char	*size;

	size = ft_itoa(50 + i);
	address = ft_strjoin(address_base, size);
	ft_printfd(1, "#g");
	ft_putstr_dlay(address);
	free(address);
	free(size);
	list = random_char_list(word_list);
	ft_putstr_dlay("\t");
	ft_putstr_dlay(list);
	free(list);
	ft_putstr_dlay("\t");
	size = ft_itoa(50 + i + 10);
	address = ft_strjoin(address_base, size);
	ft_putstr_dlay(address);
	ft_putstr_dlay("\t");
	free(address);
	free(size);
	list = random_char_list(word_list);
	ft_putstr_dlay(list);
	free(list);
	ft_printfd(1, "#0\n");
}



void	fallout(void)
{
	char	*address_base;
	char	*input;
	int		fd = open("words.txt", O_RDONLY);
	char	**general_list;
	char	**word_list;
	char	*password;
	int		diffs;
	int		tries = 0;

	srand((unsigned int)(time(NULL) * getpid()));
	general_list = gen_word_list(fd);
	while (1)
	{
		word_list = get_word_list(general_list);
		password = gen_password(word_list);
//		printf("Password is : %s\n", password);
		address_base = "0x42-L";
		ft_printfd(1, "\033[38;5;208mEnter the right Password in the list#0\n\n");
		for (int i = 0; i < 10; i++)
			printer(address_base, word_list, i);
		ft_printfd(1, "\n");
		while (1)
		{
			input = 0;
			while (1)
			{
				ft_printfd(1 ,"#gEnter your answer : #0");
				fflush(0);
				input = get_next_line(0);
				if (ft_strlen(input) != WORD_LEN)
				{
					free(input);
					ft_printfd(1, "#rWord must be in the list !#0\n");
					fflush(0);
					continue ;
				}
				else if (!compare_list(input, word_list))
				{
					free(input);
					ft_printfd(1, "#rWord must be in the list !#0\n");
					fflush(0);
				}
				else
					break ;
			}
			diffs = compare_words(input, password);
			if (diffs == WORD_LEN)
			{
				ft_printfd(1, "#pYou are now ready to enter !#0\n");
				free(input);
				free_tab(general_list);
				close(fd);
				return ;
			}
			else
			{
				if (tries == MAX_TRIES - 2)
					ft_printfd(1, "#rCare ! this is your last attempt#0\n");
				ft_printfd(1, "#pSimilar characters to password : %d/%d#0\n", diffs, WORD_LEN);
				tries++;
				free(input);
			}
			if (tries == MAX_TRIES)
			{
				tries = 0;
				system("@cls||clear");
				ft_printfd(1, "#rERROR ! ERROR ! The system has changed \nthe password for security purposes#0\n");
				break ;
			}
		}
	}
}
