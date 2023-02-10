#ifndef HEADERS_H_
#define HEADERS_H_
void  read    (char code[][20000*40]);
unsigned __stdcall pass(void* p);
int   tranImm (char code[][20000*40],int line,int id);
void  tran    (int total1,int front,int back,int id,int Imm);
void  cal     (int total1,int front,int back,int id,int Imm);
void  logic   (int total1,int front,int back,int id,int Imm);
void  campare (int total1,int front,int back,int id,int Imm);
void  jump    (int total1,int front,int back,int id,int Imm);
void  inout   (int total1,int front,int back,int id,int Imm);
void  shuang1(int Imm,int id);
void  shuang2(int Imm,int id);
void  shuang3(int Imm,int id);
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
#endif
