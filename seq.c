#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_DISK_BLOCKS 32
#define TOTAL_DISK_INODES 8

#ifndef MAX
#define MAX 15
#endif

int blockStatus[TOTAL_DISK_BLOCKS]; // free = 0 
int blockStart;

struct file_table {
  char fileName[20];
  int startBlock;
  int fileSize;
  int allotStatus;
};

struct file_table fileTable[TOTAL_DISK_BLOCKS - TOTAL_DISK_INODES];

int AllocateBlocks(int Size) {
  int i = 0, count = 0, inList = 0, nextBlock = 0;
  int allocStartBlock = TOTAL_DISK_INODES;
  int allocEndBlock = TOTAL_DISK_BLOCKS - 1;
  
  // check whether sufficient free blocks are available
  for (i = 0; i < (TOTAL_DISK_BLOCKS - TOTAL_DISK_INODES); i++)
    if (blockStatus[i] == 0)
      count++;
  if (count < Size)
    return 1; // not enough free blocks 
  
  count = 0;
  while (count < Size) {
    nextBlock = (rand() % (allocEndBlock - allocStartBlock + 1)) + allocStartBlock;
    
    for (i = nextBlock; i < (nextBlock + Size); i++) {
      if (blockStatus[i] == 0)
      
        count = count + 1;
      else {
        count = 0;
        break;
      }
    }
  }
  blockStart = nextBlock;
  for (int i = 0; i < Size; i++) {
    blockStatus[blockStart + i] = 1;
  }
  if (count == Size)
    return nextBlock; // success
  else
    return 1; // not successful
}

void main() {
  int i = 0, j = 0, numFiles = 0, nextBlock = 0, ret = 1, totalFileSize = 0;
  char s[20];
  //-- - 
  char *header[] = {"FILE_fileName", "FILE_SIZE", "BLOCKS_OCCUPIED"};
  
  printf("File allocation method: SEQUENTIAL\n");
  printf("Total blocks: %d\n", TOTAL_DISK_BLOCKS);
  printf("File allocation start at block: %d\n", TOTAL_DISK_INODES);
  printf("File allocation end at block: %d\n", TOTAL_DISK_BLOCKS - 1);
  printf("Size (kB) of each block: 1\n\n");
  printf("Enter no of files: ");
  scanf("%d", &numFiles);
  
  //numFiles = 3;
  for (i = 0; i < numFiles; i++) {
    //-- -
    printf("\nEnter the name of file #%d: ", i+1);
    scanf("%s", fileTable[i].fileName);
    printf("Enter the size (kB) of file #%d: ", i+1);
    scanf("%d", &fileTable[i].fileSize);
    
    //strcpy(fileTable[i].fileName, "testfile");
    srand(1234);
    ret = AllocateBlocks(fileTable[i].fileSize);

    //-- - 
    if (ret == 1) {
      exit(0); 
    } else {
      fileTable[i].startBlock = ret;
    }
  }
  //-- -  
  printf("\n%*s %*s %*s\n", -MAX, header[0], -MAX, header[1], MAX, header[2]);
  //Seed the pseudo-random number generator used by rand() with the value seed 
  srand(1234);
  //-- -    
  for (j = 0; j < numFiles; j++) {
    printf("\n%*s %*d ", -MAX, fileTable[j].fileName, -MAX, fileTable[j].fileSize);
    for(int k=0;k<fileTable[j].fileSize;k++) {
      printf("%d%s", fileTable[j].startBlock+k, (k == fileTable[j].fileSize-1) ? "" : "-");
    }
  }
  printf("\nFile allocation completed. Exiting.\n");
}

