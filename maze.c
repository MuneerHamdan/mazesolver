#include <stdio.h>

#define WIDTH 8
#define HEIGHT 8

char map[8][8] = {
  {"########"},
  {"S...####"},
  {"###.####"},
  {"#......#"},
  {"#.####.#"},
  {"#.####.E"},
  {"#......#"},
  {"########"}
};

typedef struct {
  int y;
  int x;

  char active;
} Player;


void solve(Player p) {
}

int main() {

  // make map
  printf("\n");
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", map[i][j]);

    }
    printf("\n"); 
  }
  printf("\n");


  // player
  Player p;
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (map[i][j] == 'S') {
        p.y = j;
        p.x = i;
      }
    }
  }
  

  printf("p.y: %d, p.x: %d\n", p.x, p.y);
  return 0;
}
