#include"Params.h"
#include<stdio.h>

/************************************************************
 outputHistgram : 256�Υҥȥ�ե��Ϥ�� ***********************************************************/
void outputHistgram(long histgram[256]){
    FILE *filePointer;
    int c;
    char fileName[40];
    
    printf("Input histgram text file name: ");
    scanf("%s",fileName);
    
    //output text file
    filePointer = fopen(fileName, "w");
    if(filePointer != NULL){
 for(c=0; c<256; c++){
     //printf("%d:%d\n",c,histgram[c]);
     fprintf(filePointer, "%d\t%ld\n",c,histgram[c]);
 }
 fprintf(filePointer, "\n");
 fclose(filePointer);
 printf("\"%s\" was Outputed.\n", fileName);
    }else{
 printf("File ERROR!\n");
    }
}
