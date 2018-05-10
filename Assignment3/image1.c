#include <stdio.h>
#include <stdlib.h>	

char printchar(int pix,int greylevel){
	switch(greylevel){
		case 2:
			switch(pix){
				case 0:
					return ('#');
				case 1:
					return (' ');;
				default :
					return 'N';
				}
		case 3:
			switch(pix){
				case 0:
					return ('#');
				case 1:
					return ('.');
				case 2:
					return(' ');
				default :
					return 'N';
				}
		case 4:
			switch(pix){
				case 0:
					return ('#');
				case 1:
					return (':');
				case 2:
					return('.');
				case 3:
					return(' ');
				default :
					return 'N';
				}
	};
	return 'N';
};


int main(){
	int width,height,greylevel,x,y,i,pix,len;
	x = 0;
	y = 0;
	scanf("%i",&width);
	scanf("%i",&height);
	scanf("%i",&greylevel);
	int imagesize = width* height;
	char image_num_array[width+1][height];

	while (y <= height){
		scanf("%i",&pix);
		fprintf(stderr, "%d\n", pix);
		scanf("%i",&len);
		fprintf(stderr, "%d\n", len);

		for(;x <= len; x++){
			if(x == width){				/*for not terminate*/
				image_num_array[x][y] = '\n';
				printf("\n");
				x = 0;
				y += 1;
			}
			image_num_array[x][y] = printchar(pix,greylevel);
			printf("%c", printchar(pix,greylevel));
		}
	}
	return 0;
/*
	char imagearray[width][height];
	for (i = 0; i <= height; i++){
		for (j = 0; j <= width; i++){

		}
	}*/


}