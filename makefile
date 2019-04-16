FLAGS= -Wall -Werror -Wextra

DEBUG= -g

NAME= fillit

$(NAME):
	@gcc $(FLAGS) fillit.c get_blocks.c solve_block_array.c validation.c ../libft/*.c -o fillit

all: $(NAME)

test:
	@gcc $(DEBUG) $(FLAGS) test_get_blocks.c get_blocks.c ../libft/*.c -o test

test_clean:
	@rm -r test.dSYM || echo "No test.dSYM found."
	@rm test || echo "No test found."

dbug:
	gcc $(DEBUG) $(FLAGS) fillit.c get_blocks.c solve_block_array.c validation.c ../libft/*.c -o fillit

clean:
	@rm -r fillit.dSYM 2>/dev/null && echo 'Removing Fillit.dSYM' || echo 'Already Removed Fillit.dSYM'

fclean: clean
	@rm fillit 2>/dev/null && echo 'Removing Fillit' || echo 'Already Removed Fillit'

fc:	fclean

re: fclean all
