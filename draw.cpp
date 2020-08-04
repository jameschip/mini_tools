#include <ncurses.h>

void add_colour( int c ) {
    attron( COLOR_PAIR( c ) );  
    addch(' ');
    attron( COLOR_PAIR( c ) );
}

void move_print( bool line, int row, int col, int last_colour, int * sq ) {
    *sq = 1;
    if ( line ) {
    	add_colour( last_colour );
        wmove( stdscr, row, col );
	} else {
		wmove( stdscr, row, col );
	}
}


int main( int argc, char *argv[] ) {

    int row,col,ch,c_row,c_col,sq_r,sq_c;
    bool line = false;
    int last_colour,sq_size = 1;
    
	initscr();
	cbreak();
    noecho();
    
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }
    
	keypad(stdscr, TRUE);
    getmaxyx( stdscr,row,col );
	refresh();

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK); 
    init_pair(2, COLOR_WHITE, COLOR_RED); 
    init_pair(3, COLOR_WHITE, COLOR_GREEN);    
    init_pair(4, COLOR_WHITE, COLOR_YELLOW); 
    init_pair(5, COLOR_WHITE, COLOR_CYAN);
    init_pair(6, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(7, COLOR_WHITE, COLOR_BLUE); 
    init_pair(8, COLOR_BLACK, COLOR_WHITE);    
    bkgd( COLOR_PAIR(8) );
    clear();    

	while( (ch = getch()) != 'q' ) {

		getyx( stdscr, c_row, c_col );

        switch(ch) {	

            case KEY_LEFT:
                if ( c_col > 0) 
                	move_print( line, c_row, c_col - 1, last_colour, &sq_size );
				break;

			case KEY_RIGHT:
                if ( c_col < col )
                	move_print( line, c_row, c_col + 1, last_colour, &sq_size );
				break;

			case KEY_UP:
                if ( c_row > 0)
                	move_print( line, c_row - 1, c_col, last_colour, &sq_size );
                break;

			case KEY_DOWN:
                if ( c_row < row )
                	move_print( line, c_row + 1, c_col, last_colour, &sq_size );
				break;
            
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                last_colour = ch - 48;
                add_colour( last_colour );
                line = false;
                sq_size = 1;
                break;

			case 'c':
				bkgd( COLOR_PAIR(8) );
				clear();
                line = false;
                sq_size = 1;
                break;

            case 'l':
                line = !line;            
				break;

            case 'r':
                sq_size++;
                for ( sq_r = c_row; sq_r < c_row + sq_size; sq_r++ ) {
                    for ( sq_c = c_col; sq_c < c_col + sq_size + 1; sq_c++ ) {
                        add_colour( last_colour );
                    }
                    move( sq_r, c_col );
                }
                move( c_row, c_col );
                break; 
				
            default:
                break;
		}
	}		
	
	endwin();
	return 0;
}

