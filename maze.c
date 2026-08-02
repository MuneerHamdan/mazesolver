#include <stdio.h>

#define WIDTH 8
#define HEIGHT 8

char _map[8][8] = {
  {"########"},
  {"S...####"},
  {"###.####"},
  {"#......#"},
  {"#.####.#"},
  {"#.####.E"},
  {"#......#"},
  {"########"}
};

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
} Player;


Player* solve(Player* p) {

  printf("solving\n");
  printf("p->y: %d, p->x: %d\n", p->y, p->x);
  if (map[p->y+1][p->x+0] == '.') {
    map[p->y][p->x] = _map[p->y][p->x];
    p->y+=1;
    p->x+=0;
    printf("hello1\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y-1][p->x+0] == '.') {
    map[p->y][p->x] = _map[p->y][p->x];
    p->y-=1;
    p->x+=0;
    printf("hello2\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y+0][p->x+1] == '.') {
    map[p->y][p->x] = _map[p->y][p->x];
    p->y+=0;
    p->x+=1;
    printf("hello3\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y+0][p->x-1] == '.') {
    map[p->y][p->x] = _map[p->y][p->x];
    p->y+=0;
    p->x-=1;
    printf("hello4\n");
    map[p->y][p->x] = 'O';
  }
  printf("p->y: %d, p->x: %d\n", p->y, p->x);
  return p;
}

int main() {

  // print _map
  printf("\n");
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n"); 
  }
  printf("\n");

  // put player on map
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

  // print updated map
  printf("\n");
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n"); 
  }
  printf("\n");
  
  // find empty nearby position
 // printf("p.y: %d, p.x: %d\n", p.y, p.x);
  solve(&p);
  printf("p after solve1: p.y: %d, p.x: %d\n", p.y, p.x);

  // make updated map
  printf("\n");
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", map[i][j]);

    }
    printf("\n"); 
  }
  printf("\n");
//  printf("p.y: %d, p.x: %d\n", p.y, p.x);

  printf("p before solve2: %d, %d", p.y, p.x);
  solve(&p);
  // make map
  printf("\n");
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", map[i][j]);

    }
    printf("\n"); 
  }
  printf("\n");
  //printf("p.y: %d, p.x: %d\n", p.y, p.x);


  return 0;
}
