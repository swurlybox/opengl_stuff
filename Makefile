LIB = 	-lGL -lglfw
SRC	=	src/main.c src/glad.c
BIN = 	main
INC	=	-Iincludes

# Make sure the soname for the libraries exist, as ld looks for library.so
# rather than library.so.x. Create a symbolic link from library.so to 
# library.so.x if needed.
$(BIN): $(SRC) 
	gcc -o main $(SRC) $(INC) $(LIB)

clean:
	rm main
