//~~~~~Pat Lebold~~~~~
//~~~~~02/09/2014~~~~~
//~~~~~~~list.c~~~~~~~

#include "defs.h"

/**list.addEvent(EventNode **, EventNode *) adds an event to the queue
 * @param **start - the location in memory of the beginning of the event-queue
 * @param *newEvent - the event that is being added to the queue
 * @return void
 */
void addEvent( EventNode **start, EventNode *newEvent){

	//the last event visited
	EventNode *last = NULL;
	
	//the current event being visited
	EventNode *current = *start;
		
	/*cycle through events until we reach the end of the list
	 *                           OR
	 *until the arrival_time of the current event is less than
	 *-the arrival_time of the new event we are adding to the queue
	 */
	while(current != NULL && newEvent->arrival_time > current->arrival_time){
		last = current;
		current = current->next;
	}
	
	if(last == NULL){//if the queue is empty
		//add the event to the beginning of the queue
		newEvent->next = *start;
		*start = newEvent;
	}
	else{//otherwise
		//set the new Event as the prior event's 'next event'
		last->next = newEvent;
		//set the next event for our new Event as the current event being visited
		newEvent->next = current;
	}
}

/**list.placeAtEndOfList(EventNode **, EventNode *) places a node at the end of the list passed
 * @param list - the beginning-node of the list
 * @param newEvent - The node we are appending to the list
 * @return void
 */
void appendEvent( EventNode **list, EventNode *newEvent ){
	EventNode *currentNode = *list;
	if(currentNode==NULL){
		*list = newEvent;
		return;
	}
	while(currentNode->next != NULL){
		currentNode = currentNode->next;
	}
	newEvent->next = NULL;
	newEvent->arrival_time = currentNode->arrival_time;
	currentNode->next = newEvent;
}

/**list.createNode(int, int, int) creates a node from 3 values
 * @param process_id - the id of the event
 * @param arrival_time - items are sorted in the list by this value
 * @param cpu_time - how much time the cpu takes to process this event
 * @return EventNode* - The node created from the values passed 
 */
EventNode *createNode(int process_id, int arrival_time, int cpu_time ){
	//allocate enough memory for the node
	EventNode *node = malloc(sizeof(EventNode));
	
	//create the node from the 3 values given
	node->process_id = process_id;
	node->arrival_time = arrival_time;
	node->cpu_time = cpu_time;
	
	//nodes are only given a 'next' value when added to the queue
	node->next = NULL;
	
	return node;
}

/**list.getNextEvent(EventNode**) retrieves (and removes from the queue) the first event in the queue
 * @param **node - the location of the queue
 * @return EventNode* - The node created from the values passed 
 */
EventNode *getNextEvent( EventNode **node ){
	//if the list is empty:
	if(*node==NULL){
		//return null as there are no events in the queue
		return NULL;
	}
	
	//store the value of the first event
	EventNode *temp = *node;
	
	//remove the first event from the list
	*node = (*node)->next;
	
	return temp;
}
