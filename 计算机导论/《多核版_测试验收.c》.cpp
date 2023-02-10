#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <process.h>
#include <windows.h>
void  read    (char code[][20000*40]);
unsigned __stdcall pass(void* p);
int   tranImm (char code[][20000*40],int line,int id);
void  tran    (int total1,int front,int back,int id,int Imm);
void  cal     (int total1,int front,int back,int id,int Imm);
void  logic   (int total1,int front,int back,int id,int Imm);
void  campare (int total1,int front,int back,int id,int Imm);
void  jump    (int total1,int front,int back,int id,int Imm);
void  inout   (int total1,int front,int back,int id,int Imm);
void  shuang1 (int Imm,int id);
void  shuang2 (int Imm,int id);
void  shuang3 (int Imm,int id);
void  checkLock(int pos, int id);
void  output1 (char code[][20000*40],int line,int id);
void  output2 (char code[][20000*40]);
int flag[2]={0};//±êÖ¾¼Ä´æÆ÷ 
int ip[2]={0};//³ÌÐò¼Ä´æÆ÷
int ir[2]={0};//Ö¸Áî¼Ä´æÆ÷
int line=0;
int data[40000]={0};
int ax[2][10]={0};
char code[2][20000*40];
HANDLE hThread1, hThread2, IOMutex;
bool memLock[2][32 * 1024];	
const int CODESTART[2] = { 0,256 };
bool threadLock[2];	
int main(void)
{
    data[0]=100;
	int n=0; 
	int m=0;
	for(m=0;m<2;m++){
    for(n=0;n<20000*40;n++)
	{
		code[m][n]='0'; 
	}
}   
	read(code);
	int id1 = 0, id2 = 1;
	void* p1 = &id1, * p2 = &id2;
	IOMutex = CreateMutex(NULL, FALSE, NULL);
	hThread1 = (HANDLE)_beginthreadex(NULL, 0, pass, p1, 0, NULL);
	hThread2 = (HANDLE)_beginthreadex(NULL, 0, pass, p2, 0, NULL);
	WaitForSingleObject(hThread1, INFINITE);
	CloseHandle(hThread1);
	WaitForSingleObject(hThread2, INFINITE);
	CloseHandle(hThread2);
	output2(code);
	
} 
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


int   tranImm(char code[][20000*40],int line,int id)
{
	int Imm=0;
	int count3;
	for(count3=16;count3<32;count3++)
	{
		Imm=Imm*2+(code[id][line*33+count3]-48);
	}
    if(Imm<=32767)
	{
	    return Imm;
	}
	else 
	{
	    return Imm-65536;
	}

}

	
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
void checkLock(int pos, int id) {
	while (memLock[id][pos]) Sleep(10);
}

