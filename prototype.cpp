#include <ncurses.h>
#include <stdlib.h>

void menu();
void about();
void game();
void kuroneko();
void msg(char teller[], char s[], bool skipGetch);
void room1();

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
reset:
  //system("clear");
  refresh();
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
  keypad(menu, true);

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

    case KEY_UP:
    hl--;
    if(hl==0) hl = n;
    break;

    case KEY_DOWN:
    hl++;
    if(hl==n+1) hl = 1;
    break;

    case 10:
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
  game();
  endwin();
  break;

  case 2:

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
	msg("BumaJl9l", "- 4yBak, 3ma Be4epuHka omcmou...", false);
	msg("", "9l, koHe4Ho, He xomeJl npu3HaBamb owu6ky, Ho 3mom 6ap 6blJl geucmBumeJlbHo ywaceH", false);
	msg("DuMa", "- JlagHo, nowJlu, mym u BnpaBgy He4ero geJlamb.", false);
	msg("system", "HanpaBJl9lutecb k Bblxogy u3 6apa", true);
	room1();

}

void msg(char teller[], char s[], bool skipGetch){
		int sx, sy;
  	getmaxyx(stdscr, sy, sx);
		WINDOW *dialog = newwin (5, sx-2, sy-6, 1);
		wrefresh(dialog);
		box(dialog, 0, 0);
		refresh();
		mvwprintw(dialog, 1, 1, "%s", teller);
		mvwprintw(dialog, 3, 1, "%s", s);
		wrefresh(dialog);
		if (skipGetch==false) getch();
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
		int sx, sy;
		getmaxyx(stdscr, sy, sx);
		WINDOW *room = newwin (40, 120, sy/2-24, sx/2-60);
		box(room, 0, 0);
		refresh();
		wrefresh(room);
		getch();
}
