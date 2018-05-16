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
					return (' ');
				case 1:
					return ('.');
				case 2:
					return(':');
				case 3:
					return('#');
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

int return_grad_number(int p1,int p2,int p3,int p4){
	int gradlist[4],gh,gv,gp,gn,i,l;
	gh = abs((p1-p2+p3-p4)/2);
	gv = abs((p1-p3+p2-p4)/2);
	gp = abs(p1-p4);
	gn = abs(p2-p3);
	gradlist[0] = gh;
	gradlist[1] = gv;
	gradlist[2] = gp;
	gradlist[3] = gn;
	l = gradlist[0];
	for (i = 0; i < 4; i++){
		if(gradlist[i] > l){
			l = gradlist[i];
		}
	}
	return l;
}
void calc_grad_array(int image_num_array[],int width,int height,int greylevel){
	fprintf(stderr,"\n\n\nANything\n\n\n");
	int x,y,counter, p1, p2, p3, p4;
	counter = 0;
	for (y = 0 ;y < height-1;y++){
		fprintf(stderr,"First for Y: %d\n",y);
		for (x = 0; x < width -1 ;x++){
			p1 = image_num_array[xy(x,y,width)];
			p2 = image_num_array[xy(x+1,y,width)];
			p3 = image_num_array[xy(x,y+1,width)];
			p4 = image_num_array[xy(x+1,y+1,width)];
			image_num_array[counter] = return_grad_number(p1,p2,p3,p4);
			printf("%c",printchar(image_num_array[counter],greylevel));
			counter++;
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
	calc_grad_array(image_num_array,width,height,greylevel);

	return 0;
}
