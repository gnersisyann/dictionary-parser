#pragma once
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 50
#define MAX_ENTRIES 41

typedef struct s_keyval
{
	char	key[MAX_KEY_LENGTH];
	char	value[MAX_VALUE_LENGTH];
}	t_keyval;

int				ft_atoi(char *str);

char			*ft_strchr(const char *s, int c);

int				ft_strlen(const char *str);

char			*ft_strncpy(char *dest, const char *src, unsigned int n);

char			*ft_strstr(char *str, char *to_find);

int				length(int num);

char			*ft_itoa(int num);

size_t			count_file_bytes(const char *file_path);

unsigned char	*read_and_fill(const char *file_path,
					unsigned char *symbols, size_t byte_count);

char			*parse_dictionary(const char *file_path);

void			print_one_digit(struct s_keyval *dict, char digit);

void			print_two_digit_helper(struct s_keyval *dict, int number);

int				is_single_digit(int number);

void			print_two_digit(struct s_keyval *dict, char *digits);

void			print_three_digit(struct s_keyval *dict, char *digits);

int				is_remainder(int number);

void			remainder_zero(struct s_keyval *dict, char *number, int lenght);

void			remainder_one(struct s_keyval *dict, char *number, int length);

void			remainder_two(struct s_keyval *dict, char *number, int length);

void			working(struct s_keyval *dict, char *number);

const char		*skip_spaces(const char *line);

int				ft_isspace(char c);

int				ft_strcmp(char *s1, char *s2);

struct s_keyval	*parse_dictionary_keyval(const char *dictionary,
					struct s_keyval *dict);
