#include "misc.h"

void addObject(Cell cells[], int x, int y) {
	int downX = x-1;
	if(downX<0) downX = 0;
	int downY = y-1;
	if(downY<0) downY = 0;
	int upX = x+1;
	if(upX >= XSIZE) upX = XSIZE-1;
	int upY = y+1;
	if(upY >= YSIZE) upY = YSIZE-1;	
	for(int i=downX; i<=upX; i++) {
		for(int j=downY; j<=upY; j++) {
			cells[i+j*XSIZE].adj++;
		}
	}
}