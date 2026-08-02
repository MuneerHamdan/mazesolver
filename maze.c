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
  {"#.####.#"},
  {"#......#"},
  {"########"}
};

typedef struct {
  int y;
  int x;

  char active;
} Player;


void printmap() {
  // print _map
  printf("\n");
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n"); 
  }
  printf("\n");
}

Player* solve(Player* p) {

  printf("solving\n");

  if (map[p->y+1][p->x+0] == 'E') {
    map[p->y][p->x] = 'x';
    p->y+=1;
    p->x+=0;
    printf("hello1\n");
    map[p->y][p->x] = 'O';
    p->active = 'E';
  }
  else if (map[p->y-1][p->x+0] == 'E') {
    map[p->y][p->x] = 'x';
    p->y-=1;
    p->x+=0;
    printf("hello2\n");
    map[p->y][p->x] = 'O';
    p->active = 'E';
  }
  else if (map[p->y+0][p->x+1] == 'E') {
    map[p->y][p->x] = 'x';
    p->y+=0;
    p->x+=1;
    printf("hello3\n");
    map[p->y][p->x] = 'O';
    p->active = 'E';
  }
  else if (map[p->y+0][p->x-1] == 'E') {
    map[p->y][p->x] = 'x';
    p->y+=0;
    p->x-=1;
    printf("hello4\n");
    map[p->y][p->x] = 'O';
    p->active = 'E';
  }
  else if (map[p->y+1][p->x+0] == '.') {
    map[p->y][p->x] = 'x';
    p->y+=1;
    p->x+=0;
    printf("hello1\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y-1][p->x+0] == '.') {
    map[p->y][p->x] = 'x';
    p->y-=1;
    p->x+=0;
    printf("hello2\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y+0][p->x+1] == '.') {
    map[p->y][p->x] = 'x';
    p->y+=0;
    p->x+=1;
    printf("hello3\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y+0][p->x-1] == '.') {
    map[p->y][p->x] = 'x';
    p->y+=0;
    p->x-=1;
    printf("hello4\n");
    map[p->y][p->x] = 'O';
  }
  return p;
}

int main() {

  // print initial map
  printmap();

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
  printmap();

  int count = 0;
  // find empty nearby position
  while (p.active != 'E') {
    if (count > 100) {
      printf("couldnt solve within 100 attempts\n");
      break;
    }
    solve(&p);
    printf("after solve %d: p.y: %d, p.x: %d, p.active: %c\n", count, p.y, p.x, p.active);
    printmap();
    count++;
  }

  return 0;
}
