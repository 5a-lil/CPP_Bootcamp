COMPIL = c++
CPPFLAGS = -Wall -Wextra -Werror -I./ -std=c++98
SRCS = $(addprefix srcs/, main.cpp Vector2-class/Vector2.cpp Graph-class/Graph.cpp utils.cpp)
OBJDIR = obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
NAME = compile.out

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(addprefix $(OBJDIR)/srcs/, Vector2-class Graph-class)

$(NAME): $(OBJDIR) $(OBJS)
	$(COMPIL) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	$(COMPIL) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all