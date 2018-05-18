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

int smooth_avg(int p1,int p2,int p3,int p4,int p5,int p6,int p7,int p8,int p9){
	int avg = (p1+ 2*p2 + p3 + 2*p4 + 4*p5 + 2*p6 + p7 + 2*p8 + p9 + 7)/16;
	return avg;
}
void printarray(int array[],int width,int height,int greylevel){
	int x,y;
	for (y = 0;y<height;y++){
		for(x = 0;x <width; x++){
			printf("%c",printchar(array[xy(x,y,width)],greylevel));
		}
		printf("\n");
	}
}
void smoothing(int double_array[],int smooth_array[], int width,int height,int greylevel){
	static int smooth_it = 1;
	fprintf(stderr,"\n\n\n--------- This is iteration %d of smoothing------ \n\n\n",smooth_it);
	smooth_it++;
	int x,y,p1,p2,p3,p4,p5,p6,p7,p8,p9;
	int double_width = (2*width)-1;
	int double_height = (2*height)-1;

	for (y = 0 ; y <double_height; y++){
		for(x = 0; x < double_width ; x++){

			if (y == 0 || (y == double_height-1) || (x == 0) || (x == double_width -1) ){
				smooth_array[xy(x,y,double_width)] = double_array[xy(x,y,double_width)];
				fprintf(stderr,"%c",printchar(smooth_array[xy(x,y,double_width)],greylevel));
			}else{
				p1 = double_array[xy(x-1,y-1,double_width)];
				p2 = double_array[xy(x-1,y,double_width)];
				p3 = double_array[xy(x-1,y+1,double_width)];
				p4 = double_array[xy(x,y-1,double_width)];
				p5 = double_array[xy(x,y,double_width)];
				p6 = double_array[xy(x,y+1,double_width)];
				p7 = double_array[xy(x+1,y-1,double_width)];
				p8 = double_array[xy(x+1,y,double_width)];
				p9 = double_array[xy(x+1,y+1,double_width)];
				smooth_array[xy(x,y,double_width)] = smooth_avg(p1,p2,p3,p4,p5,p6,p7,p8,p9);
				fprintf(stderr,"%c",printchar(smooth_array[xy(x,y,double_width)],greylevel));
			}
		}
		fprintf(stderr,"\n");
	}
}

void double_img(int image_num_array[],int double_array[], int width,int height,int greylevel){
	int p1,p2,p3,p4,x,y;
	int double_width = (2*width)-1;
	int double_height = (2*height)-1;

		for (y = 0 ;y < (double_height);y++){

			if (y%2 == 0){
				for (x = 0; x < (2*width) -1;x++){
					if (x%2 == 0){
						double_array[xy(x,y,double_width)] = image_num_array[xy(x/2,y/2,width)];
						/*fprintf(stderr, "printing x = %d , y = %d,array code = %d ,value = %d\n", x,y,xy(x,y,double_width),double_array[xy(x,y,double_width)]);*/
						fprintf(stderr,"%c",printchar(double_array[xy(x,y,double_width)],greylevel));
					}else if(x%2 != 0){
						double_array[xy(x,y,double_width)] = two_avg(image_num_array[xy((x-1)/2,y/2,width)],image_num_array[xy((x+1)/2,y/2,width)]);
						/*fprintf(stderr, "printing x = %d , y = %d,array code = %d ,value = %d\n", x,y,xy(x,y,double_width),double_array[xy(x,y,double_width)]);*/
						fprintf(stderr,"%c",printchar(double_array[xy(x,y,double_width)],greylevel));
					}
				}

			}else if (y%2 != 0){
				for(x = 0; x < double_width; x++){
					if(x%2 == 0){
						double_array[xy(x,y,double_width)] = two_avg(image_num_array[xy(x/2,(y+1)/2,width)],image_num_array[xy(x/2,(y-1)/2,width)]);
						/*fprintf(stderr, "printing x = %d , y = %d,array code = %d ,value = %d\n", x,y,xy(x,y,double_width),double_array[xy(x,y,double_width)]);*/
						fprintf(stderr,"%c",printchar(double_array[xy(x,y,double_width)],greylevel));
					}else if(x%2 != 0){
					p1 = image_num_array[xy((x-1)/2,(y-1)/2,width)];
					p2 = image_num_array[xy((x-1)/2,(y+1)/2,width)];
					p3 = image_num_array[xy((x+1)/2,(y-1)/2,width)];
					p4 = image_num_array[xy((x+1)/2,(y+1)/2,width)];
					double_array[xy(x,y,double_width)] = four_avg(p1,p2,p3,p4);
					/*fprintf(stderr, "printing x = %d , y = %d,array code = %d ,value = %d avg = 4\n", x,y,xy(x,y,double_width),double_array[xy(x,y,double_width)]);*/
					fprintf(stderr,"%c",printchar(double_array[xy(x,y,double_width)],greylevel));
				}
			}
		}
		fprintf(stderr,"\n");
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
	int double_width = (2*width)-1;
	int double_height = (2*height)-1;
	int imagesize = width* height;
	int image_num_array[8000];
	int double_array[16000];
	int smooth_first_array[16000];
	int smooth_second_array[16000];
	int smooth_third_array[16000];


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
	smoothing(double_array,smooth_first_array,width,height,4);
	smoothing(smooth_first_array,smooth_second_array,width,height,4);
	smoothing(smooth_second_array,smooth_third_array,width,height,4);
	printarray(smooth_third_array,double_width,double_height,4);

	return 0;
}
