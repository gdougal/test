NAME			=	bot

CPP				=	clang++

FLAGS			=	-Wall -Wextra -Werror

SRC		=			big_int.cpp \
                    bot.cpp \
                    main.cpp \

OBJ_DIR			=	./obj/

O_FILE			=	$(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRC))

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_DIR) $(O_FILE)
	$(CPP) $(FLAGS) $(O_FILE) -o $(NAME)

$(O_FILE): $(OBJ_DIR)%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)



.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)

PHONY: fclean
fclean: clean
	@rm -f $(NAME)

.PHONY: re
re:		fclean all