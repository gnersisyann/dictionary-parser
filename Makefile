.SILENT:

NAME	=	parser
SOURCES	=	./*.c ./*/*.c
FLAGS	=	-Wextra -Wall	

make: fclean
	@ cc $(FLAGS) $(SOURCES) -o $(NAME)

fclean:
	rm -rf ./$(NAME)
