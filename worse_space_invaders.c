#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

/* Global variables */
int max_box_coords[2] = {21, 41};  // X and Y, respectively
int player_coords[2] = {39, 9};    // ^^^^^^^^^^^^^^^^^^^^^

/* Function Prototypes */
void draw_box(int max_x, int max_y);
void check_plyr_pos(int x, int y);

int main() {
	/* Initialize variables */
	
	
	/* Initialize window */	
	initscr();
	cbreak();
	noecho();
	curs_set(0);

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
		
		refresh();
		check_plyr_pos(player_coords[0], player_coords[1]);

		/* Draw box */
		draw_box(max_box_coords[1], max_box_coords[0]);	
	}	
	endwin();

	return(0);
}

/* Function definitions */

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
