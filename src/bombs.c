#include "misc.h"

void setBombs(Cell cells[], int bombs,int x, int y) {
	for(int i=0; i < bombs; i++) {
		int x0 = coin(0,XSIZE);
		int y0 = coin(0,YSIZE);
		if(cells[x0+y0*XSIZE].bomb) {
			i--;
		} else {
			if(x != x0 || y != y0) {
				cells[x0+y0*XSIZE].bomb = true;
				addObject(cells,x0,y0);
			}
		} 
	}
}