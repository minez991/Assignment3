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

void printarray(int* imagearray,int width,int height){
	fprintf(stderr,"\n\n\nANything\n\n\n");
	int x,y;
	for(y=0;y < width;y++){
		for(x= 0; x < height;x++){
			if (x != width){
				fprintf(stderr, "\n\n\nINWIDTH\n\n\n" );
				fprintf(stderr,"%d",imagearray[366]);
			}else{
				fprintf(stderr, "\n" );
			}
		}
	}
}

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
	int image_num_array[width][height];

	while (y < height-1){
		scanf("%i",&pix);
		scanf("%i",&len);

		for(i = 0;i < len; i++){
			fprintf(stderr, "debug : %d\n------------\ny = %d\n,i = %d\npix = %d\nlen=%d\n------------\n",debug_counter,y,i,pix,len);
			if(x == width){
				printf("\n");
				x = 0;
				y += 1;
			}
			image_num_array[x][y] = pix;
			fprintf(stderr,"Input to %d,%d ->>%d\n",x,y,image_num_array[x][y] );
			printf("%c", printchar(pix,greylevel));
			x = x+1;
		};

	}
	fprintf(stderr,"\n\n\n\n");
	printarray(&image_num_array,width,height);
	fprintf(stderr, "debug : %d\ny = %d\n",debug_counter,y);
	return 0;
}
