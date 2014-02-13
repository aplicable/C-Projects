//~~~~~Pat Lebold~~~~~
//~~~~~02/09/2014~~~~~
//~~~~~graphics.c~~~~~

#include "defs.h"

void printListHeader( void ){
	printf("%8s%14s\n\n","Time (ms)","Event ID");
}

void printEvent(EventNode *node, int simulatedTime){
	printf("%8d%14d\n",simulatedTime,node->process_id);
}
