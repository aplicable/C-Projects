//~~~~~Pat Lebold~~~~~
//~~~~~02/09/2014~~~~~
//~~~~~~~main.c~~~~~~~

#include "defs.h"

int main( int argc, char **argv){
	if(argc != 3){ //check to make sure the user entered the correct amount of arguments
		printf("You have entered the incorrect quantity of arguments.\n");
		printf("The format to run this program is:\n");
		printf("$ ./main num_of_sources time_slice\n");
	}
	else{
		//The front of the queue of events
		EventNode *enteredEvents = NULL;
		int sources = atoi(argv[1]);
		if(sources==0)//If the user has entered 0 for the number of sources, terminate
			printf("You have chosen not to enter any events. Why would you do that?\n\n");
		else{//otherwise:
			int timeSlice = atoi(argv[2]);
			int n;
			
			//prompt the user enter the events
			printf("Enter the events you wish to simulate in the format:\n\n");
			printf("process_id arival_time cpu_time\n\n");
			
			//For every event the user said (s)he would type in:
			for(n=0;n<sources;n++){
				int process_id;
				int arrival_time;
				int cpu_time;
				
				//scan in the values
				scanf("%d %d %d",&process_id,&arrival_time,&cpu_time);
				printf("Event Entered: %8d%8d%8d\n",process_id,arrival_time,cpu_time);
				
				//create an event with those values
				EventNode *event = createNode(process_id,arrival_time,cpu_time);
				
				//add that event to the queue
				addEvent(&enteredEvents, event);
			}
			printf("\nEvents have been entered. ");
			
			if(timeSlice==0){//If the entered timeslice is 0
				//Simulate the FCFS scheduler
				printf("Simulating FCFS Scheduler.\n\n");
				processFCFS(&enteredEvents);
			}
			else{//otherwise
				//Simulate the RoundRobin scheduler
				printf("Simulating Round-Robin Scheduler.\n\n");
				processRR(&enteredEvents,timeSlice);
			}
		}
	}
	return 0;
}
