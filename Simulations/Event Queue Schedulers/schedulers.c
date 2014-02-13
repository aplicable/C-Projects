//~~~~~Pat Lebold~~~~~
//~~~~~02/09/2014~~~~~
//~~~~schedulers.c~~~~

#include "defs.h"

/**schedulers.processFCFS(EventNode **) simulates a First-Come,First-Server system of scheduling
 * @param list - The list we are processing
 * @return void
 */
void processFCFS(EventNode **list){
	int simulatedTime = 0;
	
	//Take the first element of the list
	EventNode *eventProcessed = getNextEvent(list);
	printListHeader();
	
	//cycle through all of the events
	while(eventProcessed!=NULL){
	
		//if the arrival time of the next element is greater than the current-time, fast forward time to the next element's arrival
		if(simulatedTime < eventProcessed->arrival_time)
			simulatedTime = eventProcessed->arrival_time;
			
		//add to the simulated time the amount of time the current-event takes to be processed
		simulatedTime += eventProcessed->cpu_time;
		
		printEvent(eventProcessed,simulatedTime);
		eventProcessed = getNextEvent(list);
	}
}

/**schedulers.processRR(EventNode **,int) simulates a Round-Robin system of scheduling
 * @param list - The list we are processing
 * @param timeSlice - The time our processor will devote to an element before re-queueing it
 * @return void
 */
void processRR(EventNode **list, int timeSlice){
	int simulatedTime = 0;
	
	//Take the first event of the list
	EventNode *eventProcessed = getNextEvent(list);
	printListHeader();
	
	//cycle through all events until they are all processed
	while(eventProcessed!=NULL){
		//if the arrival time of the next event is less than simulated-time than fast-forward time to the arrival of the next event
		if(simulatedTime < eventProcessed->arrival_time){
			simulatedTime = eventProcessed->arrival_time;
		}
		
		if(eventProcessed->cpu_time <= timeSlice){ //if the event will be completely-processed before the time slice is completed
			//add to the simulated time, the time the event will take to process
			simulatedTime += eventProcessed->cpu_time;
			printEvent(eventProcessed,simulatedTime);
		}
		else{ //otherwise:
			//add the time slice to the simulated time
			simulatedTime += timeSlice;
			
			//subtract the time slice from the processing-time of the event (simulating 1 time slice of processing on the event)
			eventProcessed->cpu_time -= timeSlice;
			
			//if the simulated time is less than the next element's arrival time and this event is not fully-processed
			if(eventProcessed->next!=NULL&&simulatedTime < eventProcessed->next->arrival_time){
				//add it back to the beginning of the queue for another round of processing
				addEvent(list,eventProcessed);
			}
			else{//otherwise:
				//append the event to the back of the queue
				appendEvent(list,eventProcessed);
			}
		}
		eventProcessed = getNextEvent(list);
	}
}
