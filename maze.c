#include <stdio.h>

#define WIDTH 8
#define HEIGHT 8

#define MAXTRIES 40

int solved = 0;

char map0[8][8] = {
  {"########"},
  {"S...####"},
  {"###.####"},
  {"#......#"},
  {"#.####.#"},
  {"#.####.#"},
  {"#......#"},
  {"########"}
};
char map1[8][8] = {
  {"########"},
  {"S...####"},
  {"###.####"},
  {"#......#"},
  {"#.####.#"},
  {"#.####.E"},
  {"#......#"},
  {"########"}
};

char map2[8][8] = {
  {"########"},
  {"S...####"},
  {"###.####"},
  {"#......#"},
  {"#.####.#"},
  {"#.####.#"},
  {"#......#"},
  {"##E#####"}
};

// bugged
// WHEN GOES P.X = P.X -1 -> CHECKS P.X = -1 -> GOES TO PREVIOUS BLOCK?????????
char map3[8][8] = {
  {"###....E"},
  {"S...####"},
  {"###.####"},
  {"#......#"},
  {"#.####.#"},
  {"#.####.#"},
  {"#......#"},
  {"########"}
};

char map[8][8] = {
  {"###....#"},
  {"S...##.E"},
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

Player players[10];


void printmap() {
  // print map
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
    printf("moved down\n");
    map[p->y][p->x] = 'O';
    p->active = 'E';
    solved = 1;
  }
  else if (map[p->y-1][p->x+0] == 'E') {
    map[p->y][p->x] = 'x';
    p->y-=1;
    p->x+=0;
    printf("moved up\n");
    map[p->y][p->x] = 'O';
    p->active = 'E';
    solved = 1;
  }
  else if (map[p->y+0][p->x+1] == 'E') {
    map[p->y][p->x] = 'x';
    p->y+=0;
    p->x+=1;
    printf("moved right\n");
    map[p->y][p->x] = 'O';
    p->active = 'E';
    solved = 1;
  }
  else if (map[p->y+0][p->x-1] == 'E') {
    map[p->y][p->x] = 'x';
    p->y+=0;
    p->x-=1;
    printf("moved left\n");
    map[p->y][p->x] = 'O';
    p->active = 'E';
    solved = 1;
  }
  printf("after solve: p.y: %d, p.x: %d\n", p->y, p->x);
  return p;
}

Player* traverse(Player* p) {
  if (map[p->y+1][p->x+0] == '.') {

    Player p2;
    players[1] = p2;
    p2.y = p->y+1;
    p2.x = p->x+0;

    printf("players size: %d\n", sizeof(players) / sizeof(Player));
    map[p->y][p->x] = 'x';
//    p->y+=1;
 //   p->x+=0;
    printf("moved down\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y-1][p->x+0] == '.') {
    map[p->y][p->x] = 'x';
    p->y-=1;
    p->x+=0;
    printf("moved up\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y+0][p->x+1] == '.') {
    map[p->y][p->x] = 'x';
    p->y+=0;
    p->x+=1;
    printf("moved right\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y+0][p->x-1] == '.') {
    map[p->y][p->x] = 'x';
    p->y+=0;
    p->x-=1;
    printf("moved left\n");
    map[p->y][p->x] = 'O';
  }
}

Player* backtrack(Player* p) {
  printf("backtracking\n");
  if (map[p->y+1][p->x+0] == 'x') {
    map[p->y][p->x] = '-';
    p->y+=1;
    p->x+=0;
    printf("moved down\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y-1][p->x+0] == 'x') {
    map[p->y][p->x] = '-';
    p->y-=1;
    p->x+=0;
    printf("moved up\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y+0][p->x+1] == 'x') {
    map[p->y][p->x] = '-';
    p->y+=0;
    p->x+=1;
    printf("moved right\n");
    map[p->y][p->x] = 'O';
  }
  else if (map[p->y+0][p->x-1] == 'x') {
    map[p->y][p->x] = '-';
    p->y+=0;
    p->x-=1;
    printf("moved left\n");
    map[p->y][p->x] = 'O';
  }
}

int main() {

  // print initial map
  printmap();

  // put player on map
  Player p;
  players[0] = p;
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

  int count = 1;
//  while (solved != 1) {
  for (int i = 0; i < MAXTRIES; i++) {
    printf("\n\n ----- Attempt %d ----- \n\n", count);
    solve(&p);
    if (solved == 1) {
      printf("solved!!!!!!\n");
      printmap();
      break;
    }
    else if ((map[p.y+1][p.x+0] != '.') && (map[p.y-1][p.x+0] != '.') && (map[p.y+0][p.x+1] != '.') && (map[p.y+0][p.x-1] != '.')) {
      backtrack(&p);
    }
    traverse(&p);
    count++;
    printmap();
  }

    if (solved != 1) {
      printf("couldnt solve within %d attempts\n", MAXTRIES);
    }

  return 0;
}
