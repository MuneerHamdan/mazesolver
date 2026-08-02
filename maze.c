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

  if (map[p.y+1][p.x+0] == '.') {
    map[p.y][p.x] = '.';
    p.y = p.y+1;
    p.x = p.x+0;
    printf("hello1\n");
    map[p.y][p.x] = 'O';
  }
  else if (map[p.y-1][p.x+0] == '.') {
    map[p.y][p.x] = '.';
    p.y = p.y-1;
    p.x = p.x+0;
    printf("hello2\n");
    map[p.y][p.x] = 'O';
  }
  else if (map[p.y+0][p.x+1] == '.') {
    map[p.y][p.x] = '.';
    p.y = p.y+0;
    p.x = p.x+1;
    printf("hello3\n");
    map[p.y][p.x] = 'O';
  }
  else if (map[p.y+0][p.x-1] == '.') {
    map[p.y][p.x] = '.';
    p.y = p.y+0;
    p.x = p.x-1;
    printf("hello4\n");
    map[p.y][p.x] = 'O';
  }

  p.active = map[p.y][p.x];
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
        p.y = i;
        p.x = j;
        map[i][j] = 'O';
        break;
      }
    }
  }
  p.active = map[p.x][p.y];
  
  solve(p);
  // make map
  printf("\n");
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", map[i][j]);

    }
    printf("\n"); 
  }
  printf("\n");

  printf("p.y: %d, p.x: %d\n", p.y, p.x);
  printf("p.active = %c\n'", p.active);


  return 0;
}
