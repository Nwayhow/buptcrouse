#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <process.h>
#include <windows.h>
void checkLock(int pos, int id) {
	while (memLock[id][pos]) Sleep(10);
}
