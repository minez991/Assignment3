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

int xy(int x,int y,int width){
	int coordinate = x + y*width;
	return coordinate;
}

int two_avg(int p1,int p2){
	int avg = (p1+p2)/2;
	return avg;
}
int four_avg(int p1,int p2,int p3,int p4){
	int avg = (p1+p2+p3+p4+1)/4;
	return avg;
}

void double_img(int image_num_array[],int double_array[], int width,int height,int greylevel){
	int p1,p2,p3,p4,x,y;
		for (y = 0 ;y < (2*height-1);y++){

			if (y%2 == 0){
				for (x = 0; x < (2*width) -1;x++){
					if (x%2 == 0){
						double_array[xy(x,y,(2*width)-1)] = image_num_array[xy(x/2,y/2,width)];
						fprintf(stderr, "printing x = %d , y = %d,array code = %d ,value = %d\n", x,y,xy(x,y,(2*width)-1),double_array[xy(x,y,(2*width)-1)]);
						printf("%c",printchar(double_array[xy(x,y,(2*width)-1)],greylevel));
					}else if(x%2 != 0){
						double_array[xy(x,y,(2*width)-1)] = two_avg(image_num_array[xy((x-1)/2,y/2,width)],image_num_array[xy((x+1)/2,y/2,width)]);
						fprintf(stderr, "printing x = %d , y = %d,array code = %d ,value = %d\n", x,y,xy(x,y,(2*width)-1),double_array[xy(x,y,(2*width)-1)]);
						printf("%c",printchar(double_array[xy(x,y,(2*width)-1)],greylevel));
					}
				}

			}else if (y%2 != 0){
				for(x = 0; x < (2*width)-1; x++){
					if(x%2 == 0){
						double_array[xy(x,y,(2*width)-1)] = two_avg(image_num_array[xy(x/2,(y+1)/2,width)],image_num_array[xy(x/2,(y-1)/2,width)]);
						fprintf(stderr, "printing x = %d , y = %d,array code = %d ,value = %d\n", x,y,xy(x,y,(2*width)-1),double_array[xy(x,y,(2*width)-1)]);
						printf("%c",printchar(double_array[xy(x,y,(2*width)-1)],greylevel));
					}else if(x%2 != 0){
					p1 = image_num_array[xy((x-1)/2,(y-1)/2,width)];
					p2 = image_num_array[xy((x-1)/2,(y+1)/2,width)];
					p3 = image_num_array[xy((x+1)/2,(y-1)/2,width)];
					p4 = image_num_array[xy((x+1)/2,(y+1)/2,width)];
					double_array[xy(x,y,(2*width)-1)] = four_avg(p1,p2,p3,p4);
					fprintf(stderr, "printing x = %d , y = %d,array code = %d ,value = %d avg = 4\n", x,y,xy(x,y,(2*width)-1),double_array[xy(x,y,(2*width)-1)]);
					printf("%c",printchar(double_array[xy(x,y,(2*width)-1)],greylevel));
				}
			}
		}
		printf("\n");
	}
}

int main(){
	int width,height,greylevel,i,pix,len,counter;
	counter = 0;
	i = 0;
	scanf("%i%*c",&width);
	fprintf(stderr, "%s%d\n","Width: ",width );
	scanf("%i%*c",&height);
	fprintf(stderr, "%s%d\n","height: ",height );
	scanf("%i%*c",&greylevel);
	fprintf(stderr, "%s%d\n","grey: ",greylevel );
	int imagesize = width* height;
	int image_num_array[8000];
	int double_array[16000];

	while (counter < imagesize){
		scanf("%i%*c",&pix);
		fprintf(stderr,"pix: %d\n",pix);
		scanf("%i%*c",&len);
		fprintf(stderr,"len: %d\n",len);

		for (i = 0; i < len;i++){
			if(pix==1){
				image_num_array[counter] = 3;
				counter++;
			}else{
				image_num_array[counter] = pix;
				counter++;
			}
		}
		fprintf(stderr, "debug couter: %d\n",counter);
	}
	fprintf(stderr, "\n\n\n------------------------------Double Image------------------------------------\n\n\n");
	double_img(image_num_array,double_array,width,height,4);

	return 0;
}
