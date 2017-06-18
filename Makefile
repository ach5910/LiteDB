SERVER = server

CLIENT = client

CC = gcc

INC = include

CFLAGS += $(foreach d, $(INC), -I $d)

SERVER_BASE =		server.c \
					setup.c \

SERVER_CLAUSES =	ft_from.c \
					ft_where.c \
					ft_set.c \

SERVER_LIB =		list.c \
					lst.c \
					split.c \
					str_toupper.c \
					str_isdigit.c \
					ft_strnew.c \
					ft_itoa_base.c \
					ft_strapp.c \
					ft_strjoin.c \


SERVER_OPERATORS =	cmp_equals.c \
					cmp_funct_setup.c \
					cmp_greater_than.c \
					cmp_less_than.c \
					bool_op_and.c \
					bool_op_funct_setup.c \
					bool_op_none.c \
					bool_op_or.c \
					init_operations_conditions.c \

SERVER_QUERYING =	cmd_funct_setup.c \
					parse_from_table.c \
					parse_multitoken_string.c \
					parse_values_for_insert.c \
					query_validation.c \
					find_table.c \
					return_data.c \
					search_table.c \


SERVER_VALIDATION = validate_column.c \
					validate_command.c \
					validate_equal.c \
					validate_from.c \
					validate_into.c \
					validate_operator.c \
					validate_set.c \
					validate_values.c \
					validate_where.c \
					validate_formating.c \
					validate_new_data.c \
					validate_bool.c \
					validate_update_data_type.c \


SERVER_STATEMENTS =	ft_delete.c \
					ft_insert.c \
					ft_select.c \
					ft_update.c \
					ft_create.c \
					ft_drop.c \

SERVER_FILE_MODS =	update_data_to_table.c \
					insert_data_to_table.c \
					rewrite_table_header_after_drop.c \
					add_table_to_header_file.c \
					create_table_file.c \
					write_to_file_after_delete.c \


SERVER_SRC += $(addprefix src/server/, $(SERVER_BASE))
SERVER_OBJ += $(addprefix obj/server/, $(SERVER_BASE:.c=.o))

SERVER_SRC += $(addprefix src/server/clauses/, $(SERVER_CLAUSES))
SERVER_OBJ += $(addprefix obj/server/clauses/, $(SERVER_CLAUSES:.c=.o))

SERVER_SRC += $(addprefix src/server/lib/, $(SERVER_LIB))
SERVER_OBJ += $(addprefix obj/server/lib/, $(SERVER_LIB:.c=.o))

SERVER_SRC += $(addprefix src/server/operators/, $(SERVER_OPERATORS))
SERVER_OBJ += $(addprefix obj/server/operators/, $(SERVER_OPERATORS:.c=.o))

SERVER_SRC += $(addprefix src/server/querying/, $(SERVER_QUERYING))
SERVER_OBJ += $(addprefix obj/server/querying/, $(SERVER_QUERYING:.c=.o))

SERVER_SRC += $(addprefix src/server/statements/, $(SERVER_STATEMENTS))
SERVER_OBJ += $(addprefix obj/server/statements/, $(SERVER_STATEMENTS:.c=.o))

SERVER_SRC += $(addprefix src/server/file_modifications/, $(SERVER_FILE_MODS))
SERVER_OBJ += $(addprefix obj/server/file_modifications/, $(SERVER_FILE_MODS:.c=.o))

SERVER_SRC += $(addprefix src/server/validation/, $(SERVER_VALIDATION))
SERVER_OBJ += $(addprefix obj/server/validation/, $(SERVER_VALIDATION:.c=.o))

CLIENT_BASE =	client.c \

CLIENT_HELP =	help_create.c \
				help_delete.c \
				help_drop.c \
				help_filter.c \
				help_funct_setup.c \
				help_insert.c \
				help_select.c \
				help_update.c \

CLIENT_SRC += $(addprefix src/client/, $(CLIENT_BASE))
CLIENT_OBJ += $(addprefix obj/client/, $(CLIENT_BASE:.c=.o))

CLIENT_SRC += $(addprefix src/client/help/, $(CLIENT_HELP))
CLIENT_OBJ += $(addprefix obj/client/help/, $(CLIENT_HELP:.c=.o))

all: $(SERVER) $(CLIENT)

$(SERVER_OBJ): | obj/server

obj/server:
	mkdir -p $@

$(SERVER_OBJ): | obj/server/clauses

obj/server/clauses:
	mkdir -p $@

$(SERVER_OBJ): | obj/server/lib

obj/server/lib:
	mkdir -p $@

$(SERVER_OBJ): | obj/server/operators

obj/server/operators:
	mkdir -p $@

$(SERVER_OBJ): | obj/server/querying

obj/server/querying:
	mkdir -p $@

$(SERVER_OBJ): | obj/server/validation

obj/server/validation:
	mkdir -p $@

$(SERVER_OBJ): | obj/server/statements

obj/server/statements:
	mkdir -p $@

$(SERVER_OBJ): | obj/server/file_modifications

obj/server/file_modifications:
	mkdir -p $@

$(CLIENT_OBJ): | obj/client

obj/client:
	mkdir -p $@

$(CLIENT_OBJ): | obj/client/help

obj/client/help:
	mkdir -p $@

obj/server%.o: src/server%.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/server/clauses%.o: src/server/clauses%.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/server/lib%.o: src/server/lib%.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/server/operators%.o: src/server/operators%.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/server/querying%.o: src/server/querying%.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/server/validation%.o: src/server/validation%.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/server/statements%.o: src/server/statements%.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/server/file_modifications%.o: src/server/file_modifications%.c
	$(CC) $(CFLAG) -o $@ -c $<

obj/client%.o: src/client%.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/client/help%.o: src/client/help%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(SERVER): $(SERVER_OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

$(CLIENT): $(CLIENT_OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(SERVER_OBJ)
	rm -rf $(CLIENT_OBJ)

fclean: clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)
	rm -rf obj

re: fclean all

.PHONY: all clean fclean re
