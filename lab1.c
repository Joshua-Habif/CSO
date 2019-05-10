/*
 * IMPORTANT: WRITE YOUR NAME AND NetID BELOW.
 * 
 * Last Name: Habif
 * First Name: Joshua
 * Netid: jh5653
 * 
 * You will do your project in this file only.
 * Do not change function delarations. However, feel free to add new functions if you want.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define nextelement(start, i, incr) (start + (i*incr)) /* my macro for f1 */

/* Function declarations: do not change that, but you may add your own functions */
void f1(int, int, int);
void f2(char *);
void f3(char *, int);
void f4(int *, int);
void f5(int, int);

/* Add here function declarations of your own, if any. */


/*********************************************************************************/

/* 
 * Do  NOT change anything in main function 
 */
int main(int argc, char * argv[])
{
  int option = 0;
  int i, j, k;
  int * list;
  
  if(argc < 2 )
  {
     fprintf(stderr,"Usage: lab1 num [input]\n");
     fprintf(stderr,"num: 1, 2, 3, 4, or 5\n");
     exit(1);
  }
  
  option = atoi(argv[1]);
  
  switch(option)
  {
    case 1: if(argc != 5)
	    {
	      fprintf(stderr,"Usage: lab1 1 A B C\n");
	      fprintf(stderr,"A, B, and C: Positive integers where A <= B and C < B \n");
	      exit(1);
	    }
	    i = atoi(argv[2]);
	    j = atoi(argv[3]);
	    k = atoi(argv[4]);
	   
	    f1(i, j, k);
	    
	    break;
	    
	    
    case 2: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 2 filename\n");
	      fprintf(stderr,"filename: the name of the file containing the characters\n");
	      exit(1);
	    }
	    
	    f2(argv[2]);
	    
	    break;

	    
    case 3: if(argc != 4)
	    {
	      fprintf(stderr,"Usage: lab1 3 filename gen\n");
	      fprintf(stderr,"filename: the name of the file containing the characters\n");
	      fprintf(stderr,"gen: number of generations nonzero positive integer \n");
	      exit(1);
	    }
	    
	    i = atoi(argv[3]);
	    f3(argv[2], i);
	    
	    break; 
	    
	    
    case 4: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 4 num\n");
	      fprintf(stderr,"num: nonzero positive integer = number of elements in the array\n");
	      exit(1);
	    }
	    
	    i = atoi(argv[2]);
	    if(!(list = (int *)malloc(i*sizeof(int))))
	    {
	      fprintf(stderr,"Cannot allocate an integer array of %d elements\n", i);
	      exit(0);
	    }
	    for(j = 0; j < i; j++)
	    {
	      printf("enter element %d: ", j);
	      scanf("%d",&list[j]);
	    }
	    
	    f4(list, i);
	    
	    break;

	    
    case 5: if(argc != 4)
	    {
	      fprintf(stderr,"Usage: lab1 5 A B\n");
	      fprintf(stderr,"A B: positive nonzero integers where A <= B\n");
	      exit(1);
	    } 
	    
	    i = atoi(argv[2]);
	    j = atoi(argv[3]);
	    
	    f5(i, j);
	    
	    break;

	          
	    
    default: fprintf(stderr, "You entered an invalid option!\n");
	     exit(1);
  }
  
  return 0;
}


/********************************************************************************************/
/******* Start filling the blanks from here and add any extra functions you want, if any *****/

/*
 * function 1:
 * intput: start, end, and increment
 * output: print on the screen: start start+incr start+2incr ... end
 * Example: start = 1, end = 5, incr = 3
 * f1 must print on the screen (pay attention to spaces): 1 4 5
 * At the end, print a new line before returning
 * */
void f1(int start, int end, int incr)
{
  
  /* print on the screen start start+incr start+2incr by using a for loop */
  /* the for loop should check that the current value does not exceed the end*/
  /* the forumla for the next term in the series is (start + (i*incr)) stored as a macro */
  int cur; /*stores the potential next element to be printed */ 
  for(int i=0; (cur=nextelement(start, i, incr)) <= end; i++)
    printf("%d ", cur);

  /* print the end */
   printf("%d\n",end);

  return;
}


/*********************************************************************************/

/* 
 * function 2:
 * intput: filename for a file that contains characters in upper/lower case as well as spaces
 * output: filename.reverse that contains the same characters as the original but the case is 
 *         reversed and the spaces are intact
 * Note1: filename can be any name, for example: info.txt or characters or data.info, ...
 * Note2: The given file will not contain anything but alphabets and spaces.
 */
void f2(char * filename)
{
  FILE *fptr1, *fptr2;
  /* Open file for reading*/
  fptr1 = fopen(filename, "r");
  /* Test for successful open*/
  if(fptr1 == NULL){  
    printf("Could not open file.\n");
    exit(1);
  }
  /* Find the length of the char array filename */
  int length=0;
  for(; (filename[length]) != '\0'; ++length){}

   /* Create a new chararray that will store the file name + .reverse */
  char newfilename[length+9];
  for(int i=0; (filename[i]) != '\0'; ++i)
    newfilename[i] = filename[i];
  newfilename[9]='.';
  newfilename[10]='r';
  newfilename[11]='e';
  newfilename[12]='v';
  newfilename[13]='e';
  newfilename[14]='r';
  newfilename[15]='s';
  newfilename[16]='e';
  newfilename[17]='\0';
  
  /* Creating new file for writing  with same name as original with .reverse*/
  fptr2 = fopen(newfilename, "w");

  /*Will store every read character in this variable c*/
  char c;
  /* Find every single character until the EOF signifier*/
  while((c=getc(fptr1)) != EOF)
    {
      if((c>=65) && (c<=90)) /* If it's upper according to # then make lower*/
	{
	  fprintf(fptr2, "%c", tolower(c));
	}
      else if((c>=97) && (c<=122)) /* and viec versa*/
	{
	  fprintf(fptr2, "%c", toupper(c));
	}
      else /*leave unchanged if it's not upper or lower */
	{
	  fprintf(fptr2, "%c", c);
	
	}
    }
  fclose(fptr1);
  fclose(fptr2);
  return;
}


/*********************************************************************************/

/*
 * function 3:
 * Two inputs: - filename that contains a 3x3 matrix of cels. Each cell is either 1 or  0. 
 *             - a positive number of generations
 * output: print on the screen the 3x3 matrix, one row per line,
 *           following the following rules
 * rule 1: a cell that has 2 or 3 neighboring 1's becomes 1 in the next generation
 * rule 2: any other case, the cell becomes in the next generation 
 * Example: If the file has 0110101000 
 * It means the first row is: 011 
 * the second row is 010  and the 3rd row is 000 
 */
void f3(char * filename, int gen) {
  /* Task 1: convert the file into a two dimensional array */
  /* Open the file*/
  FILE * fp;
  fp = fopen(filename, "r");
  /* Check if file open was successful*/
  if (fp == NULL) {
    printf("File open was not successful.\n");
    return;
  }
  /* read data from file and convert it into a two-d array*/
  char c;
  /* my 2-d array*/
  int oriarray[3][3];
  int coparray[3][3];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      c = getc(fp);
      oriarray[i][j] = c - '0';
      coparray[i][j] = c - '0';
      getc(fp); /* because of the space chars*/
    }
  }

  /* in each cell, try to look up, down, left, and right. If an element exists, check if it's 0 or 1, if it's 0 ignore, else add to the current counter of neighbors */
  for (int k = 0; k < gen; k++) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        /* printf("element being looked at: [%di][%dj]: %d\n", i, j, oriarray[i][j]);*/
        int neigh = 0;
        /* check if u can go left, go left */
        if (((j - 1) >= 0) && (oriarray[i][j - 1] == 1))
          ++neigh;
        /* check if you can go right, go right */
        if (((j + 1) <= 2) && (oriarray[i][j + 1] == 1))
          ++neigh;
        /* check if you can go up, go up */
        if (((i - 1) >= 0) && (oriarray[i - 1][j] == 1))
          ++neigh;
        /* check if you can go down, go down*/
        if (((i + 1) <= 2) && (oriarray[i + 1][j] == 1))
          ++neigh;
        /* check if you can go NW, go NW*/
        if (((i - 1) >= 0 && (j - 1) >= 0) && (oriarray[i - 1][j - 1] == 1))
          ++neigh;
        /* check if you can go NE, go NE*/
        if (((i - 1) >= 0 && (j + 1) <= 2) && (oriarray[i - 1][j + 1] == 1))
          ++neigh;
        /* check if you can go SW, go SW*/
        if (((i + 1) <= 2 && (j - 1) >= 0) && (oriarray[i + 1][j - 1] == 1))
          ++neigh;
        /* Check if you can go SE, go SE*/
        if (((i + 1) <= 2 && (j + 1) <= 2) && (oriarray[i + 1][j + 1] == 1))
          ++neigh;
        if (neigh == 2 || neigh == 3)
          coparray[i][j] = 1;
        else
          coparray[i][j] = 0;
      }
    }
    /* copy coparray into oriarray*/
    for (int d = 0; (d < 3) ; ++d) {
      for (int l = 0; l < 3; ++l)
        oriarray[d][l] = coparray[d][l];
    }
  }

  /* print the 2-d array*/
  for (int d = 0; d < 3; ++d) {
    for (int l = 0; l < 3; ++l)
      printf("%d ", coparray[d][l]);
    printf("\n");
  }

  return;
}

/*********************************************************************************/

/*
 * function 4
 * intput: an array of n integers
 * output: print on the screen the array sorted in reverse order followed by a new line
 */
void f4(int * num, int n)
{
  /* Sorting using selection sort*/
  int temp; /* will store the value during swap*/
  int imin; /* will keep track of the current selected index*/
  for(int i=0; i<n; ++i)
    {
      /* set imin to the current ith index*/
      imin = i;
       for(int unsortpar=i+1; unsortpar<n; ++unsortpar)
	{
	  /* compare every element in the unsorted part to the ith element*/
	  if(num[unsortpar]<num[imin]) /* if an element in the unsorted part is found to be smaller, set that element to imin*/
	    imin=unsortpar;
	}
       /* if the imin is not i swap num[imin] and num[i]*/
       if(imin != i)
	 {
	  temp = num[imin];
	  num[imin]=num[i];
	  num[i]=temp;
         }
   }
  
  /* print the array per specs -- my array is in ascending order so I'll print it in reverse */
  for(int i=n-1; i>=0; --i)
    printf("%d ",num[i]);
  printf("\n");
  return;
}

/*********************************************************************************/

/* 
 * function 5:
 * input: two positive nonzero integers a and b where a <= b
 * output: print on the screen the non-prime numbers betweeb a and b, 
 *         including a and b themselves if they are non-prime. 
*          0, 1, and 2 are assumed not to be prime, in case you encounter them.
 *         Leave a space between each two numbers.
 *         At the end, print a new line.
 */
void f5(int a, int b)
{
  if(a<0)
    a=0;
  /* Loop from first number to and inculding last*/
  for(int i=a; i<=b; ++i)
    {
      /* If it's 0, 1, or 2 just print it*/
      if(i==0 || i==1 || i==2)
	{
	printf("%d ", i);
	continue;
	}
      /* Check for every possible divisor, but the largest divisor is i/2*/
      for(int j=2; j<i; ++j)
	{
	  if(i%j==0)
	    {
	      printf("%d ", i);
	      break;
	    }
	}
    }
  printf("\n");
  return;
}

/*********************************************************************************/


