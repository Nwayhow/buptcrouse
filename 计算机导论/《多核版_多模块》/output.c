#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <process.h>
#include <windows.h>
void output1(char code[][20000*40],int line,int id)
{   
    WaitForSingleObject(IOMutex, INFINITE);
    
    ir[id]=0;
	int count3;
	printf("id = %d\n",id+1);
	if(id==1){
		printf("ip = %d\n",ip[id]+256);
}
    if(id==0) printf("ip = %d\n",ip[id]);
	printf("flag = %d\n",flag[id]);
	
	for(count3=0 ;count3<16;count3++)
	{    
		 ir[id]= ir[id]*2+(code[id][line*33+count3]-48);
	}
	printf("ir = %d\n", ir[id]);
	printf("ax1 = %d ax2 = %d ax3 = %d ax4 = %d\nax5 = %d ax6 = %d ax7 = %d ax8 = %d\n",ax[id][1],ax[id][2],ax[id][3],ax[id][4],ax[id][5],ax[id][6],ax[id][7],ax[id][8]);
    ReleaseMutex(IOMutex);
}

void output2(char code[][20000*40])
{
	int cnt=0;
	int ns=0;
	int count4;
	int count3;
	printf("\ncodeSegment :\n");
	for(count4=0;count4<ip[0]/4-1 ;count4++)
	{
		for(count3=0;count3<32;count3++)
		{
		    ns=ns*2+(code[0][count4*33+count3]-48);
	    }
	
	if(ns==0 ) break;
	printf("%d",ns);
	ns=0; 
	cnt++;
		if(cnt%8==0) 
		{
		    printf("\n");
		}
		else 
		{
		    printf(" ");
		}
	}
	int count5;	
	for(count5=count4;count4<64 ;count4++)
	{
		printf("0");
		cnt++;
		if(cnt%8==0) 
		{
		    printf("\n");
		}
		else 
		{
		    printf(" ");
		}
	}	
	for(count4=0;count4<ip[1]/4-1 ;count4++)
	{
		for(count3=0;count3<32;count3++)
		{
		    ns=ns*2+(code[1][count4*33+count3]-48);
	    }
	
	if(ns==0 ) break;
	printf("%d",ns);
	ns=0; 
	cnt++;
		if(cnt%8==0) 
		{
		    printf("\n");
		}
		else 
		{
		    printf(" ");
		}
	}
	for(count5=count4;count4<64 ;count4++)
	{
		
		printf("0");
		cnt++;
		if(cnt%8==0) 
		{
		    printf("\n");
		}
		else 
		{
		    printf(" ");
		}
	}	
	printf("\ndataSegment :\n");
	cnt=0;
	int i;
	for(i=0;i<(16*16)*2;i=i+2)
	{
		printf("%d",data[i]);
		cnt++;
		if(cnt%16==0) 
		{
		    printf("\n");
		}
		else 
		{
		    printf(" ");
		}
	}
}
