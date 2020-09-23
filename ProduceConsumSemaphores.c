#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Declare global variables, including a buffer as a dynamic array of integers */
int *buffer = NULL;
int bufferSize;
int max_fill_size;
int max_empty_size;
int numIterations;

int next_in;
int next_out;

int e; //num Of Empty
int f; //num of full

void option1() {
    
	printf("Enter size of the buffer: ");
	scanf("%d",&bufferSize);
	printf("Enter the max fill size: ");
	scanf("%d", &max_fill_size);
	printf("Enter maximum empty size: ");
	scanf("%d", &max_empty_size);
	printf("Enter number of iterations: ");
	scanf("%d", &numIterations);
	
	buffer = (int *)calloc(bufferSize, sizeof(int));
	
	f = 0;
    e = bufferSize;
    
    next_in = 0;
    next_out = 0;
	
	return;
}

int v(int var) {
/* Increment "variable" if it is less than the size of the buffer */
if(var<bufferSize)
    var = var + 1;
else
    return var;
	return var;
}

int p(int var) {
	/* Decrement "variable" if non-negative */
	if(var>0)
	    var = var -1;
	else
	return var;
	return var;
}

void printBuffer() {
	printf("Buffer= ");
	for(int i =0; i<bufferSize; i++){
	    printf("%d",buffer[i]);
	}
	printf("\n");
	return;
}

void producer() {
	
	/* Declare/initilize k1 of type clock_t to hold random value between 1 and max_fill_size, using function: clock() */
    clock_t k1 = clock() % max_fill_size +1;
	/* For each cell of the buffer to fill from 1 to k1 */
	for(int i = 1; i<= k1; i++){
	    if(e >0) {
	        e = p(e);
	        buffer[next_in] = 1; 
	        next_in = (next_in +1) % bufferSize;
	        f = v(f);
	    }//if
	}//for
	printf("P[%d]: ", k1);
	
		/* if not full, decrement e semaphore */
		/* increment buffer cell referenced by next_in */
		/* increment value of next_in modulo n */ 
		/* increment f semaphore */		
	return;
}			

void consumer() {
	/* Declare/initilize k1 of type clock_t to hold random value between 1 and max_fill_size, using function: clock() */
    clock_t k1 = clock() % max_empty_size +1;
	/* For each cell of the buffer to fill from 1 to k1 */
	for(int i = 1; i<= k1; i++){
	    if(f>0) {
	        f = p(f);
	        buffer[next_out] = 0; 
	        next_out = (next_out +1) % bufferSize;
	        e = v(e);
	    }//if
	}//for
	printf("C[%d]: ", k1);
	
		/* if not empty, decrement f semaphore */
		/* increment buffer cell referenced by next_out */
		/* increment value of next_out modulo n */ 
		/* increment e semaphore */		
	/* call procedure to print contents of buffer */
	return;
}



void option2() { //Simulate function
    clock_t pc;
	/* For each iteration */
	/* Set pc to a random value between 0 and 1 */
	for( int i = 0; i < numIterations; i++){
    	pc = clock() % 2;
    	if(pc == 0)
    	    producer();
    	else
    	    consumer();
    	printBuffer();
    	}
	return;
}



void option3() { //exit
	/* If the buffer is not NULL, free the buffer */
	free(buffer);
	printf("Buffer freed");
	return;
}


int main() {
	int userSelection;
    do{
    printf("\nProducer-Consumer Problem\n");
    printf("--------------------------------\n");
    printf("1) Enter parameters\n");
    printf("2) Simulate on a shared circular buffer\n");
    printf("3) Quit program and free memory\n");
    
    printf("Enter Selection: \n");
    scanf("%d", &userSelection);
    switch(userSelection){
        case 1: option1(); break;
        case 2: option2(); break;
        case 3: option3(); break;
    }

}while(userSelection != 3);
    printf("BYE BYE");
    return 0;
}
