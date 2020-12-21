#include <ncurses.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

void menu();
void about();
void game();
void kuroneko();
void msg(string teller, string s, bool skipGetch);
int act(WINDOW *win);
void move(WINDOW *win, int y, int x, int dir);
void room1();
void room2();
int choice();

bool valid;

int main(){
	initscr();
	noecho();
	curs_set(0);
	refresh();
	menu();
	endwin();
	return 0;
}


void menu(){
  int i, y=8, x=18, sy, sx, c, hl=1, menuReturn;
  const int n = 4;
  char op0[] = "HoBa9l urpa", op1[] = "npogoJlWumb", op2[] = "O6 urpe", op3[] = "BbIumu";
  char *a[n] = {op0, op1, op2, op3};
  bool menuPass;
  getmaxyx(stdscr, sy, sx);

	mvprintw(sy/2-14, sx/2-12, "      ____________ _____ \n");
	mvprintw(sy/2-13, sx/2-12, "      | ___ \\ ___ \\  __ \\\n");
	mvprintw(sy/2-12, sx/2-12, " _ __ | |_/ / |_/ / |  \\/\n");
	mvprintw(sy/2-11, sx/2-12, "| '_ \\|    /|  __/| | __\n");
	mvprintw(sy/2-10, sx/2-12, "| | | | |\\ \\| |   | |_\\ \\\n");
	mvprintw(sy/2-9, sx/2-12,  "|_| |_\\_| \\_\\_|    \\____/\n");

  WINDOW *menu = newwin (y, x, sy/2-5, sx/2-10);
  box(menu, 0, 0);
  wrefresh(menu);
  refresh();

	menuPass=false;
  while(menuPass!=true){
    for(i=1;i<=n;i++){
      if(i==hl){
        mvwprintw(menu, 1, 1, " ");
        mvwprintw(menu, 2, 1, " ");
        mvwprintw(menu, 3, 1, " ");
        mvwprintw(menu, 4, 1, " ");
        mvwprintw(menu, i, 1, ">");
        }
      mvwprintw(menu, i, 2, "%s", a[i-1]);
      wrefresh(menu);
      }
    c = wgetch(menu);
    switch(c){

    case 119:
    hl--;
    if(hl==0) hl = n;
    break;

    case 115:
    hl++;
    if(hl==n+1) hl = 1;
    break;

    case 101:
    menuReturn = hl;
    menuPass = true;
    break;

    default:
    break;
    }
  wrefresh(menu);
  }
  refresh();

  switch(menuReturn){

  case 1:
  wclear(menu);
  delwin(menu);
  refresh();
  //wrefresh(menu);
  game();
  endwin();
  break;

  case 2:
	endwin();
	cout << "ツ";
  break;

  case 3:
  //system("clear");
	delwin(menu);
  refresh();
  about();
  break;

  case 4:
  //endwin();
  break;
  }
}



void game(){
	system("clear");
	msg("Toxa", "- 4yBak, 3ma Be4epuHka omcmou...", false);
	msg("", "9l, koHe4Ho, He xomeJl npu3HaBamb owu6ky, Ho 3mom 6ap 6blJl geucmBumeJlbHo ywaceH", false);
	msg("DuMa", "- JlagHo, nowJlu, mym u BnpaBgy He4ero geJlamb.", false);
	msg("system", "HanpaBJl9lutecb k Bblxogy u3 6apa", true);
	room1();
	system("clear");
	msg("", "cHapyWu 6blJlo xoJlodHo", false);
	msg("", "noroBopu c Toxou", true);
	room2();
	msg("Toxa", "O Hem!", false);
	msg("Toxa", "3mo We gblpa B cI-oWeme!", false);
	msg("Toxa", "u 4mo menepb geJlamb?", false);
	msg("", "...", false);
	msg("Toxa", "Bugumo, cmoum gamb pa3pa6om4uky no6oJlbwe BpeMeHu...", false);
	msg("Toxa", "A mbl kak gyMaewb?", false);
	switch (choice()){
		case 1:
		msg("Toxa", "Hy, oH geucmBumeJlbHo ycmaem...", false);
		break;

		case 2:
		msg("Toxa", "Bugumo, mbl npaB..", false);
		break;

	}
	msg("", "...", false);
	msg("Toxa", "Cyg9l no BceMy, urpa nogxogum k cBoemy Jloru4eckoMy 3aBepweHul-0", false);
	msg("Toxa", "noka!", false);
	msg("akd", "Cnacu6o, 4mo nourpaJlu b 3mo!", false);

}



void msg(string teller, string s, bool skipGetch){
	int sx, sy, c;
	int n = teller.length();
	char a[n+1];
	strcpy (a, teller.c_str());
	int m = s.length();
	char b[m+1];
	strcpy (b, s.c_str());
  getmaxyx(stdscr, sy, sx);
	WINDOW *dialog = newwin (5, sx-2, sy-6, 1);
	wrefresh(dialog);
	box(dialog, 0, 0);
	refresh();
	mvwprintw(dialog, 1, 1, a);
	mvwprintw(dialog, 3, 1, b);
	wrefresh(dialog);
	if(skipGetch==false) getch();
}

int choice(){
	int sx, sy, hl=1, i, n=2, c, menuReturn;
	bool menuPass;
	getmaxyx(stdscr, sy, sx);
	WINDOW *dialog = newwin (5, sx-2, sy-6, 1);
	wrefresh(dialog);
	box(dialog, 0, 0);
	refresh();
	while(menuPass!=true){
		mvwprintw(dialog, 1, 2, "%s", "3mo He mak, oH Hu4ero He geJlaem ueJlblMu gH9lMu");
		mvwprintw(dialog, 2, 2, "%s", "MoWem, y Hero u BnpaBdy MaJlo BpeMeHu");
    for(i=1;i<=n;i++){
      if(i==hl){
        mvwprintw(dialog, 1, 1, " ");
        mvwprintw(dialog, 2, 1, " ");
        mvwprintw(dialog, i, 1, ">");
        }

      wrefresh(dialog);
      }
    c = wgetch(dialog);
    switch(c){

    case 119:
    hl--;
    if(hl==0) hl = n;
    break;

    case 115:
    hl++;
    if(hl==n+1) hl = 1;
    break;

    case 101:
    menuReturn = hl;
    menuPass = true;
    break;

    default:
    break;
    }
	}
	return menuReturn;
}

void about(){
  int sy, sx, y=15, x=40, c;
  getmaxyx(stdscr, sy, sx);
  WINDOW *a = newwin (y, x, sy/2-8, sx/2-20);
  wrefresh(a);
  box(a, 0, 0);
  mvwprintw(a, 2, 2, "%s", "nRPG - 3mo npocma9l RPG-urpa,");
  mvwprintw(a, 3, 2, "%s", "ueJlukoM u noJlHocmbl-O ocHoBaHHa9l");
  mvwprintw(a, 4, 2, "%s", "Ha 6u6Jluomeke New Curses.");
  mvwprintw(a, 5, 2, "%s", "UcxogHblu kog BblJloWeH Ha GitHub'e");
  mvwprintw(a, 6, 2, "%s", "https://github.com/ollyhearn/nRPG");
  mvwprintw(a, 7, 2, "%s", "9l 6ygy pag Jll-O6ou kpumuke");
  mvwprintw(a, 8, 2, "%s", "u npegJloWeHu9lM.");
  mvwprintw(a, 12, 7, "[ENTER] - Bblumu B MeHl-O");
  //move (sy-10, sx);

  wrefresh(a);
  refresh();
  c = getch();
	if (c=='f'){
		c = getch();
		if (c=='f'){
			c = getch();
			if (c=='f'){
				mvprintw(sy/2+10, sx/2-10, "%s", "       :\\     /;               _");
				mvprintw(sy/2+11, sx/2-10, "%s", "      ;  \\___/  ;             ; ;");
				mvprintw(sy/2+12, sx/2-10, "%s", "     ,:-\"'   `\"-:.            / ;");
				mvprintw(sy/2+13, sx/2-10, "%s", "_   /,---.   ,---.\\   _     _; /");
				mvprintw(sy/2+14, sx/2-10, "%s", "_:>((  |  ) (  |  ))<:_ ,-\"\"_,\"");
				mvprintw(sy/2+15, sx/2-10, "%s", "    \\`````   `````/\"\"\"\"\",-\"\"");
				mvprintw(sy/2+16, sx/2-10, "%s", "     '-.._ v _..-'      )");
				mvprintw(sy/2+17, sx/2-10, "%s", "       / ___   ____,..  \\");
				mvprintw(sy/2+18, sx/2-10, "%s", "      / /   | |   | ( \\. \\");
				mvprintw(sy/2+19, sx/2-10, "%s", "     / /    | |    | |  \\ \\");
				mvprintw(sy/2+20, sx/2-10, "%s", "     `\"     `\"     `\"    `\"");
				mvprintw(sy/2+22, sx/2-10, "%s", "KURONEKO! <3");
				getch();
				refresh();
			}
		}
	}
	werase(a);
	wrefresh(a);
	delwin(a);
	menu();
	refresh();

}

void room1(){
	int sx, sy, i, j, c, x, y, a, b;
	x=3;
	y=16;
	ifstream level;
	const int wy=24;
	const int wx=80;
	int r[wx][wy];
	level.open("room1.txt");
	getmaxyx(stdscr, sy, sx);
	WINDOW *room = newwin (wy+2, wx+2, sy-34, sx/2-43);
	for(i=1;i<wy+1;i++){
		for(j=1;j<wx+1;j++){
			level >> r[i][j];
			if (r[i][j] == 1) mvwprintw(room, i, j, "%c", '#');
			if (r[i][j] == 2) mvwprintw(room, i, j, "%c", 'E');
			if (r[i][j] == 3){
				mvwprintw(room, i, j, "%s", "[:)]");
				mvwprintw(room, i+1, j, "%s", "/()\\");
				mvwprintw(room, i+2, j, "%s", " ll");
			}
			if (r[i][j] == 8){
				mvwprintw(room, i, j, "%s", "[:D]");
				mvwprintw(room, i+1, j, "%s", "/()\\");
				mvwprintw(room, i+2, j, "%s", " ll");
				mvwprintw(room, i-1, j-5, "%s", "He mopMo3u!");
			}
		}
	}
	mvwprintw(room, y, x, "%s", "(:3)");
	mvwprintw(room, y+1, x, "%s", "/()\\");
	mvwprintw(room, y+2, x, "%s", " ll");
	box(room, 0, 0);
	refresh();
	wrefresh(room);
	while(1){
		a = act(room);
		if (a>=1 && a<=4){
						switch (a){
							case 1:
							//if(r[y-1][x]==0 && r[y-1][x+1]==0 && r[y-1][x+2]==0 && r[y-1][x+3]==0){
								move(room, y, x, a);
								y--;
							//}
							break;
							case 2:
							//if(r[y][x-1]==0 && r[y+1][x-1]==0 && r[y+2][x-1]==0){
								move(room, y, x, a);
								x--;
							//}
							break;
							case 3:
							//if(r[y+3][x]==0 && r[y+3][x+1]==0 && r[y+3][x+2]==0 && r[y+3][x+3]==0){
								move(room, y, x, a);
								y++;
							//}
							break;
							case 4:
							//if(r[y][x+4]==0 && r[y+1][x+4]==0 && r[y+3][x+4]==0){
								move(room, y, x, a);
								x++;
							//}
							break;
					}
				}
			if (a==5) if (x>74 && y>20) break;
		}
		wclear(room);
		wrefresh(room);
		delwin(room);
		refresh();

}

void room2(){
	int sx, sy, i, j, c, x, y, a, b;
	x=3;
	y=15;
	ifstream level;
	const int wy=24;
	const int wx=80;
	int r[wx][wy];
	level.open("room2.txt");
	getmaxyx(stdscr, sy, sx);
	WINDOW *room = newwin (wy+2, wx+2, sy-34, sx/2-43);
	for(i=1;i<wy+1;i++){
		for(j=1;j<wx+1;j++){
			level >> r[i][j];
			if (r[i][j] == 1) mvwprintw(room, i, j, "%c", '#');
			if (r[i][j] == 2) mvwprintw(room, i, j, "%c", 'E');
			if (r[i][j] == 3){
				mvwprintw(room, i, j, "%s", "[:D]");
				mvwprintw(room, i+1, j, "%s", "/()\\");
				mvwprintw(room, i+2, j, "%s", " ll");
				mvwprintw(room, i-1, j, "%s", "Toxa");
			}
			if (r[i][j] == 9){
				mvwprintw(room, i, j, "%s", "/");
				mvwprintw(room, i, j+1, "%s", "-------");
				mvwprintw(room, i+1, j, "%s", "|");
				mvwprintw(room, i+2, j, "%s", "|");
				mvwprintw(room, i+3, j, "%s", "|");
				mvwprintw(room, i+4, j, "%s", "|");
				mvwprintw(room, i+5, j, "%s", "\\");
				mvwprintw(room, i+1, j+9, "%s", "|");
				mvwprintw(room, i+2, j+9, "%s", "|");
				mvwprintw(room, i+3, j+9, "%s", "|");
				mvwprintw(room, i+4, j+9, "%s", "|");
				mvwprintw(room, i+5, j+1, "%s", "-------");
				mvwprintw(room, i+5, j+9, "%s", "/");
				mvwprintw(room, i, j+9, "%s", "\\");

			}
		}
	}
	mvwprintw(room, y, x, "%s", "(:3)");
	mvwprintw(room, y+1, x, "%s", "/()\\");
	mvwprintw(room, y+2, x, "%s", " ll");
	box(room, 0, 0);
	wrefresh(room);
	refresh();

	while(1){
		a = act(room);
		if (a>=1 && a<=4){
						switch (a){
							case 1:
								move(room, y, x, a);
								y--;
							break;
							case 2:
								move(room, y, x, a);
								x--;
							break;
							case 3:
								move(room, y, x, a);
								y++;
							break;
							case 4:
								move(room, y, x, a);
								x++;
							break;
					}
				}
			if (a==5) if (x==27 && y==15) break;
		}
}



void move(WINDOW *win, int y, int x, int dir){
	switch (dir){
		case 1:
			mvwprintw(win, y-1, x, "%s", "(:3)");
			mvwprintw(win, y, x, "%s", "/()\\");
			mvwprintw(win, y+1, x, "%s", " ll ");
			mvwprintw(win, y+2, x, "%s", "    ");
		break;
		case 2:
			mvwprintw(win, y, x-1, "%s", "(:3)");
		 	mvwprintw(win, y+1, x-1, "%s", "/()\\");
			mvwprintw(win, y+2, x-1, "%s", " ll ");
			mvwprintw(win, y, x+3, "%s", " ");
			mvwprintw(win, y+1, x+3, "%s", " ");
			mvwprintw(win, y+2, x+3, "%s", " ");
		break;
		case 3:
			mvwprintw(win, y+1, x, "%s", "(:3)");
			mvwprintw(win, y+2, x, "%s", "/()\\");
			mvwprintw(win, y+3, x, "%s", " ll ");
			mvwprintw(win, y, x, "%s", "    ");
		break;
		case 4:
			mvwprintw(win, y, x+1, "%s", "(:3)");
			mvwprintw(win, y+1, x+1, "%s", "/()\\");
			mvwprintw(win, y+2, x+1, "%s", " ll ");
			mvwprintw(win, y, x, "%s", " ");
			mvwprintw(win, y+1, x, "%s", " ");
			mvwprintw(win, y+2, x, "%s", " ");
		break;
	}
}

int act(WINDOW *win){
	int c;
	c = wgetch(win);
	switch (c){

	case 119:
	c=1;
	break;

	case 97:
	c=2;
	break;

	case 115:
	c=3;
	break;

	case 100:
	c=4;
	break;

	case 101:
	c=5;
	break;

	case 27:
	c=0;
	break;
}

	return c;
}
