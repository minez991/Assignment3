#include <stdio.h>
#include <stdlib.h>

void clear_input_buffer(){	/*clear input buffer*/
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
	}

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

void printarray(int image_num_array[],int width,int height,int greylevel){
	fprintf(stderr,"\n\n\nANything\n\n\n");
	int x,y,counter;
	counter = 0;
	for (y = 0 ;y < height;y++){
		fprintf(stderr,"First for Y: %d\n",y);
		for (x = 0; x < width;x++){
			printf("%c",printchar(image_num_array[counter],greylevel));
			counter++;
		}
		printf("\n");
	}
}

int main(){
	int width,height,greylevel,i,pix,len,counter,line,x;
	counter = 0;
	i = 0;
	line = 0;
	x = 0;
	scanf("%i%*c",&width);
	fprintf(stderr, "%s%d\n","Width: ",width );
	scanf("%i%*c",&height);
	fprintf(stderr, "%s%d\n","height: ",height );
	scanf("%i%*c",&greylevel);
	fprintf(stderr, "%s%d\n","grey: ",greylevel );
	int imagesize = width* height;
	int image_num_array[8000];

	while (counter < imagesize){
		scanf("%i%*c",&pix);
		fprintf(stderr,"pix: %d\n",pix);
		scanf("%i%*c",&len);
		fprintf(stderr,"len: %d\n",len);

		for (i = 0; i < len;i++){
			image_num_array[counter] = pix;
			counter++;
		}
		fprintf(stderr, "debug : %d\n",counter);

	}
	printarray(image_num_array,width,height,greylevel);

	return 0;
}
