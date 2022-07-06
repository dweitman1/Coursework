#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "PriorityQueue.h"
#include "Process.h"
#include "Complex.h"

using namespace std;

/*
Author: Daniel Weitman
Creation Date: 11/02/18
Last Update: 11/12/18
Description: Main for a simulation of different processes going through a CPU.
*/

int main(){
    
    int cores, exeMin, exeMax, lvls, simLength;
    double newProcesses, newProcessAmount;
    
    //Number of cores that can work on a process per cycle
    cout << "Input the number of CPU cores: ";
    cin >> cores;
    
    //Minimum number of cycles it takes to complete a process
    cout << "Input the minimum number of execution cycles per process: ";
    cin >> exeMin;
    
    //Maximum number of cycles it takes to complete a process
    cout << "Input the maximum number of execution cycles per process: ";
    cin >> exeMax;
    
    //Number of priority levels processes can have
    cout << "Input the number of priority levels: ";
    cin >> lvls;
    
    //Number of processes added to queue per cycle
    cout << "Input the number of new processes per cycle: ";
    cin >> newProcesses;
    
    //How many cycles are to be simulated
    cout << "Input the length of the simulation in cycles: ";
    cin >> simLength;
    
    PriorityQueue<Process> processQueue;//queue of processes
    int CPU[cores];//int array of size number of cores
    Process temp;//for temporarily storing processes 
    int idleTime = 0;//Time CPUs were not working on a process
    Process randProcess;//Random process to be added to queue
    int exeRange = exeMax - exeMin + 1;//range for processes exeTimes
    int count = 0;//Processes completed
    int sum = 0;//Wait time of completed processes
    
    srand(time(0));
    
    //For loop that iterates one cycle up to simLength 
    for(int i = 0; i < simLength; i++){
        
        for(int j = 0; j < cores; j++){
            
            //Fill CPU with processes from priorityQueue
            if(CPU[j] == 0 && !processQueue.isEmpty()){
                temp = processQueue.dequeue();
                CPU[j] = temp.getExeTime();
                sum = sum + (i - temp.getTimeStamp());
                count++;
            }
                
            //Increment idleTime if core still open
            if(CPU[j] == 0){
                idleTime++;
            }
            
            //Decrement CPU value simulate a process being worked on
            if(CPU[j] > 0){
                CPU[j]--;
            } 
        }
        
        //Creates a new random process
        newProcessAmount += newProcesses;
   
        while(newProcessAmount >= 1){
            
            randProcess.setExeTime(rand() % exeRange + exeMin);
            randProcess.setTimeStamp(i);
            
            processQueue.enqueue(randProcess, rand() % lvls + 1);
            
            newProcessAmount -= 1;
        }
    }
   
    //Display results of simulation
    cout << "=====Simulation Results=====" << endl;
    cout << "Idle time = " << idleTime << endl;
    cout << "Processes completed = " << count  << endl;
    cout << "Total wait time of completed processes = " << sum << endl;
    cout << "Number of processes remaining in queue = " << processQueue.size()<< endl;
    
    //Display results relevant to queue with elements still inside
    if(!processQueue.isEmpty()){
        int unexecutedTime = 0;
        long totalWait = 0;
        int maxWait = 0;
        for(int i = 0; i < processQueue.size(); i++){
            unexecutedTime += processQueue[i].data.getExeTime();
            totalWait += simLength - processQueue[i].data.getTimeStamp();
        }
        
        maxWait = simLength - processQueue[0].data.getTimeStamp();
        
    cout << "Total execution time needed for unprocessed processes = " << unexecutedTime << endl;
    
    cout << "Total wait time for unprocessed processes = " << totalWait << endl;
    cout << "Maximum wait time for unprocessed processes = " << maxWait << endl;
    }
    
    
    return 0;
}
