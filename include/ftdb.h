/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftdb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 22:25:17 by bschroed          #+#    #+#             */
/*   Updated: 2017/05/05 22:25:17 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTDB_H
# define FTDB_H

# include <string.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>

# define FIRST_STRING_LIMIT 4
# define SECOND_STRING_LIMIT 5
# define THIRD_STRING_LIMIT 6
# define FOURTH_STRING_LIMIT 1
# define OPERATOR_STRING_LIMIT 3
# define EOS(s) ((s)+strlen(s))

typedef char*		(*t_command)(char*);
typedef int			(*t_cmp)(char*, char*);
typedef void		(*t_help)(void);
typedef int			(*t_bool_op)(int, int);

typedef struct		s_lst
{
	void			*content;
	size_t			content_size;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_list
{
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct		s_table
{
	char			*name;
	char			**field;
	char			*size;
}					t_table;

t_list				*g_users;
t_lst				*g_tb_list;
t_table				*g_table;

int					g_operators;
int					g_operators2;
int					g_max_users;
int					g_max_columns;
int					g_last_index;
int					g_ret_value;
int					g_table_name;
int					g_column;
int					g_column2;
int					g_update_column;
int					g_bool_oper;

char				**g_valid_first;
char				**g_valid_field;
char				**g_valid_fourth;
char				**g_valid_operator;
char				**g_valid_where;
char				*g_update_value;
char				**g_valid_bool;
char				*g_value;
char				*g_value2;
char				**g_new_data;
char				***g_file_data;

void				init_first(void);
void				init_fields(t_table *g_table);
void				init_tables(void);
void				init_operators(void);
void				help_select(void);
void				help_insert(void);
void				help_update(void);
void				help_drop(void);
void				help_delete(void);
void				help_create(void);
void				init_bool_operations(void);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_listaddback(t_list **alst, t_list *new);
void				f_lstadd(t_lst **alst, t_lst *new);
void				f_listaddback(t_lst **alst, t_lst *new);
void				init_cmp_funct(t_cmp *cmp);
void				parse_from_table(void);
void				parse_values(char *input);
void				init_bool_funct(t_bool_op *bp);

void				init_command_funct(t_command *command);
void				error(char *msg);
void				rewrite_table_header_after_drop(t_lst **g_tb_list);
void				write_to_file_after_delete(void);
void				create_table_file(char *tb_name, int size);
void				add_table_to_header_file(char *tb_name, char **info, int
					size);
void				init_bool_operations();
void				reset_condition_values(void);

int					cmp_equals(char *s1, char *s2);
int					cmp_less_than(char *s1, char *s2);
int					cmp_greater_than(char *s1, char *s2);
int					validate_command(char *first);
int					validate_column(char *second);
int					validate_from(char *third);
int					validate_table(char *fourth);
int					validate_operator(char *third);
int					validate_equal(char *input);
int					validate_into(char *input);
int					validate_set(char *input);
int					validate_bool(char *input);
int					validate_values(char *input);
int					validate_where(char *third);
int					validate_new_data(void);
int					validate_formating(char **info, int size);
int					validate_update_data_type(void);
int					validate_field_char(char *min, char *max, char *input);
int					validate_field_int(char *min, char *max, char *input);
int					validate_update_data_type(void);
int					search_table(void);
int					str_isdigit(char *input);
int					help_filter(char *buffer);
int					is_sorting_type_char(void);

int					parse_values_for_insert(char *input);
int					bool_op_none(int c1, int c2);
int					bool_op_and(int c1, int c2);
int					bool_op_or(int c1, int c2);
char				*return_data(void);
char				*insert_data_to_table(void);
char				*update_data_to_table(void);
char				*ft_update(char *input);
char				*ft_insert(char *input);
char				*ft_delete(char *input);
char				*ft_select(char *input);
char				*ft_create(char *input);
char				*ft_drop(char *input);
char				*query_validation(char *argv);
char				*str_toupper(char *str);
char				*ft_where(char *input);
char				*ft_from(char *input);
char				*set(char *input);
char				*ft_strnew(size_t size);
char				*parse_multitoken_string(char *input);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strapp(char const *s1, char const *s2);
char				*ft_set(char *input);
char				*ft_itoa_base(uintmax_t g_value, int base, int is_upper);

char				**ft_split_whitespaces(char *str);
t_table				*find_table(t_lst **g_tb_list, char *input);
t_list				*ft_lstnew(int index);
t_lst				*f_lstnew(void const *content, size_t content_size);
t_help				get_help_funct(int index);
t_cmp				get_cmp_funct(int index);
t_command			get_command_funct(int index);
t_bool_op			get_bool_funct(int index);

#endif
