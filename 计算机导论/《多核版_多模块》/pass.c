#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <process.h>
#include <windows.h>
unsigned __stdcall pass(void* p){
	int id = *((int*)p);
	while(1){
	int count3;
	int front=0; 
	int back=0;
	int Imm=0;
	int total1=0;
	ip[id]=ip[id]+4;
	line=(ip[id]/4)-1;
	for(count3=0;count3<8;count3++)
	{
		total1=total1*2+(code[id][line*33+count3]-48);
	}
	
	for(count3=8;count3<12;count3++)
	{
		front=front*2+(code[id][line*33+count3]-48);
		
	}
	for(count3=12;count3<16;count3++)
	{
		back=back*2+(code[id][line*33 + count3]-48);
	}
	Imm=tranImm(code,line,id) ;
	if(total1==0)               {
		output1(code,line,id);
		break;}
	if(total1==1)                 tran(total1,front,back,id,Imm);
	if(total1>=2 && total1<=5)    cal(total1,front,back,id,Imm);
	if(total1>=6 && total1<=8)    logic(total1,front,back,id,Imm);
	if(total1==9 )                campare(total1,front,back,id,Imm);
	if(total1==10 )               jump(total1,front,back,id,Imm);
	if(total1==11 || total1==12)  inout(total1,front,back,id,Imm);
	if(total1==13)   shuang1(Imm, id);
	if(total1==14)   shuang2(Imm, id);
	if(total1==15)   shuang3(Imm, id);
	output1(code,line,id);
}

	
}
void tran(int total1,int front,int back,int id,int Imm){
	checkLock(ax[id][back],id);
	checkLock(ip[id] + 2 + CODESTART[id],id);
	checkLock(ax[id][front],id);
	if(back==0)
	{
		ax[id][front]=Imm;
	}
	 if(back>=5)
	{  
		if(id==0) ax[id][front]=data[ax[id][back]-16384];
		else ax[id][front]=data[ax[id][back]-16384];
	}
	if (back<=4 && back>0){
		if (id==0 )data[ax[id][front]-16384]=ax[id][back];
		else data[ax[id][front]-16384]=ax[id][back];
	}
	
	
}
void cal(int total1,int front,int back,int id,int Imm){
	checkLock(ax[id][back],id);
	checkLock(ip[id] + 2 + CODESTART[id],id);
	checkLock(ax[id][front],id);
	if(total1==2)
	{
		if(back==0)
		{
			ax[id][front]=ax[id][front]+Imm;
		}
		else
		{
			if (id==0 )ax[id][front]=ax[id][front]+data[ax[id][back]-16384];
			else ax[id][front]=ax[id][front]+data[ax[id][back]-16384];
		}
	}
	if(total1==3){
		if(back==0)
		{
			ax[id][front]=ax[id][front]-Imm;
		}
		else
		{
			if (id==0 )ax[id][front]=ax[id][front]-data[ax[id][back]-16384];
			else ax[id][front]=ax[id][front]-data[ax[id][back]-16384];
		}
	}
	if(total1==4)
	{
		if(back==0)
		{
			ax[id][front]=ax[id][front]*Imm;
		}
		else
		{
			if (id==0)ax[id][front]=ax[id][front]*data[ax[id][back]-16384];
			else ax[id][front]=ax[id][front]*data[ax[id][back]-16384];
		}
	}
	if(total1==5)
	{
		if(back==0)
		{
			ax[id][front]=ax[id][front]/Imm;
		}
		else
		{
			if (id==0)ax[id][front]=ax[id][front]/data[ax[id][back]-16384];
			else ax[id][front]=ax[id][front]/data[ax[id][back]-16384];
		}
	}
	
}
void logic(int total1,int front,int back,int id,int Imm){
	checkLock(ax[id][back],id);
	checkLock(ip[id] + 2 + CODESTART[id],id);
	checkLock(ax[id][front],id);
	if(total1==6)
	{
		if(back==0)
		{
			if(ax[id][front] && Imm)
			{
				ax[id][front]=1;
			}
			else 
			{
			    ax[id][front]=0;
			}
		}
		else
		{
			if(id==0){
			if(ax[id][front] && data[ax[id][back]-16384]){
			ax[id][front]=1;
			}
			else
			{
			    ax[id][front]=0;
			}
			}
			else{
				if(ax[id][front] && data[ax[id][back]-16384]){
			ax[id][front]=1;
			}
			else
			{
			    ax[id][front]=0;
			}
			}
		}
	}
	if(total1==7)
	{
	    if(back==0)
		{
			if(ax[id][front] || Imm)
			{
				ax[id][front]=1;
			}
			else 
			{
			    ax[id][front]=0;
			}
		}
		else
		{
			if(id==0){
			
			if(ax[id][front] || data[ax[id][back]-16384])
			{
				ax[id][front]=1;
			}
			else 
			{
			    ax[id][front]=0;
			}
		}
		    else{
		    	if(ax[id][front] || data[ax[id][back]-16384])
			{
				ax[id][front]=1;
			}
			else 
			{
			    ax[id][front]=0;
			}
			}
		}
	}
	if(total1==8)
	{
		if(back==0)
		{
			ax[id][front]=!ax[id][front];
		}
		else
		{
			if(id==0){
			data[ax[id][back]-16384]=!data[ax[id][back]-16384] ;
		}
		    else 	data[ax[id][back]-16384]=!data[ax[id][back]-16384] ;
		}
	}
}
void campare(int total1,int front,int back,int id,int Imm){
	checkLock(ax[id][back],id);
	checkLock(ip[id] + 2 + CODESTART[id],id);
	checkLock(ax[id][front],id);
	if(back==0)
	{
		if(ax[id][front]>Imm)
		{
			flag[id]=1;
		}
		if(ax[id][front]==Imm)
		{
			flag[id]=0;
		}
		if(ax[id][front]<Imm)
		{
			flag[id]=-1;
		}
	}
	else{
		if(id==0){
		
		if(ax[id][front]>data[ax[id][back]-16384])
		{
			flag[id]=1;
		}
		if(ax[id][front]==data[ax[id][back]-16384])
		{
			flag[id]=0;
		}
		if(ax[id][front]<data[ax[id][back]-16384])
		{
			flag[id]=-1;
		}
	}
	    else{
	    		if(ax[id][front]>data[ax[id][back]-16384])
		{
			flag[id]=1;
		}
		if(ax[id][front]==data[ax[id][back]-16384])
		{
			flag[id]=0;
		}
		if(ax[id][front]<data[ax[id][back]-16384])
		{
			flag[id]=-1;
		}
		}
	}
	
}
void jump(int total1,int front,int back,int id,int Imm)
{
	if(back==0)
	{
	    ip[id]=ip[id]+Imm-4;
    }  
	if(back==1)
	{
		if(flag[id]==0)
		{
			ip[id]=ip[id]+Imm-4;
		}
	}
	if(back==2)
	{
		if(flag[id]==1)
		{
		    ip[id]=ip[id]+Imm-4;
		}
	}
	if(back==3)
	{
		if(flag[id]==-1)
		{
		    ip[id]=ip[id]+Imm-4;
		}
	}	
}
void inout(int total1,int front,int back,int id,int Imm)
{
	if(total1==11)
	{
		WaitForSingleObject(IOMutex, INFINITE);
		printf("in:\n",ax[id][front]);
		ReleaseMutex(IOMutex);
		scanf("%d",&ax[id][front]);
	}
	if(total1==12)
	{
		WaitForSingleObject(IOMutex, INFINITE);
		printf("id = %d    out: %hd\n", id + 1, ax[id][front]);
		ReleaseMutex(IOMutex);
	}
}
void shuang1(int Imm,int id){
	short pos = Imm;
	while (threadLock[id]) Sleep(10);
	checkLock(pos, id);
	id == 0 ? (memLock[1][pos] = 1) : (memLock[0][pos] = 1);
}
void shuang2(int Imm,int id){
	short pos = Imm;
	if (id == 0) {
		memLock[1][pos] = 0;
		threadLock[0] = 1;
		threadLock[1] = 0;
	}
	else {
	    memLock[0][pos] = 0;
		threadLock[0] = 0;
		threadLock[1] = 1;
			}
}
void shuang3(int Imm,int id){
	short sleepTime = Imm;
	Sleep(sleepTime);
}
