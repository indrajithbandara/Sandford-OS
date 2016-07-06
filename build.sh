echo "Building Debug Version..."
clang -ggdb -ansi -Weverything -Werror -lglfw -lGL game.c -o ./debug/game
splint game.c
echo "Building..."
clang -O2 -lglfw -lGL game.c -o ./build/game
echo "Done"
