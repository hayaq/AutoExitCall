#include <stdio.h>
#include "aec.h"

int Sub()
{
	int ret = 0;
	printf("Sub() in = %d\n",ret);
	OnExitScope(){
		printf("Sub() exit = %d\n",ret);
		return ++ret;
	};
	++ret;
	printf("Sub() out = %d\n",ret);
	return ++ret;
}

int main(void){
	int v = Sub();
	printf("Sub() result = %d\n",v);
}
