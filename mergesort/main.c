//
//  main.c
//  mergesort
//
//  Created by Yang YanQing on 13-7-3.
//  Copyright (c) 2013年 Yang YanQing. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int mytimes = 0;

long int mergeandsort( int* array , int length_array ){
    mytimes ++;
    if (length_array == 1) {
        return 0;
    }
    
	int length_a = length_array / 2;
	int length_b = length_array - length_a;
	int *a = (int *)malloc(sizeof(int) * length_a);
	int *b = (int *)malloc(sizeof(int) * length_b);
	//printf("mytimes %d  lengtharray : %d   length a : %d    length b: %d\n" , mytimes , length_array ,length_a, length_b);
	for (int i = 0 ; i < length_a ; i ++ )
		a[i] = array[i];
	for (int i = 0 ; i < length_b ; i ++) {
		b[i] = array[length_a + i];
	}
	
	long int x = mergeandsort( a , length_a);
	long int y = mergeandsort( b , length_b);
	long int z = 0;
	int i = 0 , j = 0 , k = 0;
	for ( ; k < length_array && i < length_a && j < length_b ; ) {
		if(a[i] <= b[j]){
			array[k ++] = a[i ++];
			continue;
		}
		if(a[i] > b[j]){
			array[k ++] = b[j ++];
			z += (length_a - i);
			continue;
		}
	}
	
	for ( ; i < length_a  ; ) {
		array[ k ++] = a[ i ++ ];
	}
	for ( ; j < length_b  ; ) {
		array[ k ++] = b[ j ++ ];
	}
	free(a);
    free(b);
    //printf("x=%ld y=%ld z=%ld return=%ld\n",x,y,z , x+y+z);
	return x+y+z;
}

int main(int argc, char *argv[]) {
	
    FILE *fp;
    int array[100000];
    if((fp=fopen("IntegerArray.txt","r"))==NULL) /* 打开一个由argv[1]所指的文件*/
    {
        printf("not open");
        exit(0);
    }
    for (int i = 0 ; i < 100000 ; i ++) {
        fscanf(fp, "%d", &array[i]);
    }
    fclose(fp);
    
	//int array[6] = {1,3,5,2,6,4};
	//int array[ ] = {1,9,6,7,8,2,3,4,5,10};
	//printf("%d\n",sizeof(array));
	long int answer = mergeandsort( array , (int)(sizeof(array)/sizeof(int)));	
    
    printf("answer is :%ld\n",answer);
    //for (int i = 0 ; i <  (int)(sizeof(array)/sizeof(int)); i ++) {
    //    printf("%d ",array[i]);
    //}
    
}

