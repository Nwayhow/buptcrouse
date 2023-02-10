#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <process.h>
#include <windows.h>
void read(char code[][20000*40]){
	FILE *fPtr1=fopen("C:\\Users\\16062\\Desktop\\dict1.txt","r") ;
	FILE *fPtr2=fopen("C:\\Users\\16062\\Desktop\\dict2.txt","r") ;
	int count1;
	for(count1=0;!feof(fPtr1);count1++)
	{
		code[0][count1]=getc(fPtr1);
	}
	for(count1=0;!feof(fPtr2);count1++)
	{
		code[1][count1]=getc(fPtr2);
		

	}

	
}
