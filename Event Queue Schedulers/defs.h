//~~~~~Pat Lebold~~~~~
//~~~~~02/09/2014~~~~~
//~~~~~~~defs.h~~~~~~~

//include the following libraries

#include <stdio.h>
/*used for:
 *scanf();
 *printf();
 */
 
#include <stdlib.h>
/*used for:
 *malloc();
 *atoi();
 */

 /**Our linked-list structure
  * @param process_id - the id of the event
  * @param arrival_time - items are sorted in the list by this value
  * @param cpu_time - how much time the cpu takes to process this event
  * @param *next - The event that follows this event
  */
struct EventNode{
	int process_id;
	int arrival_time;
	int cpu_time;
	struct EventNode *next;
};

//replace all instances of 'EventNode' in the code with 'struct EventNode'
typedef struct EventNode EventNode;

//function prototypes below:

//list.c
EventNode *createNode( int, int, int );
void addEvent( EventNode **start, EventNode *newEvent );
void appendEvent( EventNode **list, EventNode *newEvent );
EventNode *getNextEvent( EventNode **start );

//graphics.c
void printListHeader( void ); 
void printEvent( EventNode *node, int );

//schedulers.c
void processFCFS( EventNode **list );
void processRR( EventNode **list, int );
