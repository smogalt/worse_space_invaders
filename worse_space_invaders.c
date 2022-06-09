#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/* Global variables */
int max_box_coords[2] = {21, 41};  // X and Y, respectively
int player_coords[2] = {39, 9};    // ^^^^^^^^^^^^^^^^^^^^^
int enemy_y = 2;
int enemy_x;


/* Function Prototypes */
void draw_box(int max_x, int max_y);
void check_plyr_pos(int x, int y);
void check_enemy_y(int y);


int main() {
	/* Seed rand() */
	srand(time(NULL));

	/* Initialize window */	
	initscr();
	cbreak();
	noecho();
	curs_set(0);


	/* Main game loop */
	while(1) {
		/* Player Controls */
		char input_char = getch();
		switch(input_char) {
			case 119 :
				player_coords[0]--;
				break;
			
			case 115 :
				player_coords[0]++;
				break;

			case 100 :
				player_coords[1]++;
				break;

			case 97 :
				player_coords[1]--;
				break;

			case 113 :
				endwin();
				return(0);
			
			default:
				break;
		}
		
		

		clear();	
		mvaddch(player_coords[0], player_coords[1], 'o');
		mvaddstr(42, 7, "WASD, Q to quit");
		check_plyr_pos(player_coords[0], player_coords[1]);
		
		/* Enemy movement */		
		check_enemy_y(enemy_y);
		enemy_y++;
		mvaddch(enemy_y, enemy_x, 'X');
		mvaddch(enemy_y, rand() % 21, 'X');		

		/* Collisions */
		if (enemy_y == player_coords[1] && enemy_x == player_coords[0]) {
			endwin();
			return(0);

		}


		/* Draw box */
		draw_box(max_box_coords[1], max_box_coords[0]);
		
		
		refresh();
	}	
	endwin();

	return(0);
}


/* Function definitions */
void check_enemy_y(int y) {
	switch (y) {
		case 40 :
			enemy_y = 2;
			enemy_x = rand() % 21;
			break;
		
		case 1 :
			enemy_y = 2;
			break;
		
		default:
			break;
	}
}

void draw_box(int max_x, int max_y) { // Draws Box
	
	for (int x_index = 0; x_index <= max_x; x_index++) {
		mvaddch(x_index, 0, '#');
		mvaddch(x_index, max_y, '#');
	}
	
	for (int y_index = 0; y_index <= max_y; y_index++) {
		mvaddch(0, y_index, '#');
		mvaddch(max_x, y_index, '#');
	}
	
	refresh();
}	

void check_plyr_pos(int x, int y) {
	switch (x) {
		case 40 :
			player_coords[0] = 39;
			break;
		
		case 1 :
			player_coords[0] = 2;
			break;
	}

	switch (y) {
		case 20 :
			player_coords[1] = 19;
			break;
		
		case 1 :
			player_coords[1] = 2;
			break;
	}
}
