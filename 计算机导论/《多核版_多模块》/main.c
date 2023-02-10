#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <process.h>
#include <windows.h>
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
