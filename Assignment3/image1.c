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
	int width,height,greylevel,x,y,i,pix,len,debug_counter;
	x = 0;
	y = 0;
	debug_counter = 0;
	scanf("%i",&width);
	fprintf(stderr, "%s%d\n","Width: ",width );
	scanf("%i",&height);
		fprintf(stderr, "%s%d\n","height: ",height );
	scanf("%i",&greylevel);
	int imagesize = width* height;
	char image_num_array[width+1][height];

	while (y < height-1){
		scanf("%i",&pix);
		scanf("%i",&len);

		for(i = 0;i < len; i++){
			fprintf(stderr, "debug : %d\n------------\ny = %d\n,i = %d\npix = %d\nlen=%d\n------------\n",debug_counter,y,i,pix,len);
			if(x == width){
				if (y < height-1){
					image_num_array[x][y] = '\n';
					printf("\n");
					x = 0;
					y += 1;
				}else{
					image_num_array[x][y] = '\0';
				}
			}
			image_num_array[x][y] = printchar(pix,greylevel);
			printf("%c", printchar(pix,greylevel));
			x = x+1;
		};

	}

	fprintf(stderr, "debug : %d\ny = %d\n",debug_counter,y);
	return 0;
}
