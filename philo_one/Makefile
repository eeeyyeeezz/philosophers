#/*
#;;;;;   MAKEFILE
#;;;;;   gmorra's philosophers  
#;;;;;   team created 2021-06-18 14:52 MSK:+0300
#;;;;;   team locked ???? 
#*/

NAME = philo_one

CFLAGS = -Wall -Wextra -Werror

HEADER = philo_one.h

CC = gcc

SRC =	declare_pars.c\
		philo_eat.c\
		philo_one.c\
		gettime.c\
		threads.c\
		errors.c\
		utils.c\
		mutex.c\

# COLORS

RED = "\033[1;31m"
BLUE = "\033[0;34m"
YELLOW = "\033[0;33m"
WHITE = "\033[1;37m"
GREEN = "\033[1;32m"
PURPLE = "\033[0;35m"
GRAY = "\033[1;30m"
NORMAL = "\033[0m"
MARK = "U+2713"

# COLORS

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(HEADER) $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo ${GREEN} "Compiling ${NAME} completed!" ${NORMAL}

clean:
	@rm -f $(OBJ)
	@echo ${RED} "Clean completed!" ${NORMAL}

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re