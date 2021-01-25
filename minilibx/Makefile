


SRC= interface.swift
OBJ=$(SRC:.swift=.o)


NAME=libmlx.dylib

INC=-I.
#OPTI=-Ounchecked

all: $(NAME)

$(NAME): $(OBJ)
	swiftc $(INC) -o $(NAME) -emit-library $(OBJ) -lz



%.o: %.swift
	swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@
clean:
	rm -f $(NAME) $(OBJ) *.swiftdoc *~

