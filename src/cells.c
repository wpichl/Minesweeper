#include "misc.h"

int checkCell(Cell cells[], int x, int y) {
	int result = 0;
	Cell *cell = &cells[x+y*XSIZE];
	if(cell->check) return 0;
	cell->img = cell->adj;
	cell->check = true;
	result++;
	if(cell->adj == 0) {
		int downX = x-1;
		int upX = x+1;
		int downY = y-1;
		int upY = y+1;
		for(int i=downX;i<=upX;i++) {
			for(int j=downY;j<=upY;j++) {
				if( (i>=0) &&
						(j>=0) &&
						(i<XSIZE) &&
						(j<YSIZE) ) {
					result+=checkCell(cells,i,j);
				}
			}
		}
	}
	return result;
}