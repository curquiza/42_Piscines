NAME = bureaucrat

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = clang++

C_FILES = Bureaucrat.cpp main.cpp

O_FILES = $(C_FILES:%.cpp=%.o)

################################################################################
#################################### RULES #####################################
################################################################################

all : $(NAME)

$(NAME) : $(O_FILES)
	@$(CC) $(FLAGS) $(O_FILES) -o $@ $(LIB)
	@echo "\033[1;31m-- EXEC ------------------------\033[0m"
	@printf  "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

%.o: %.cpp
	@$(CC) $(FLAGS) -o $@ -c $<
	@printf  "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

clean :
	@rm -rf $(O_FILES)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : clean all fclean re
