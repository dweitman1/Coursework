#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "PriorityQueue.h"
#include "Process.h"

using namespace std;

/*
Author: Daniel Weitman
Creation Date: 11/02/18
Last Update: 11/13/18
Description: Main for a simulation of different processes going through a CPU.
*/

int main(){
    
    int cores, exeMin, exeMax, lvls, simLength;
    double newProcessesMin, newProcessesMax, stepSize, newProcessAmount;
    
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
    
    cout << "Input the minimum number of new processes per cycle: ";
    cin >> newProcessesMin;
    
    cout << "Input the maximum number of new processes per cycle: ";
    cin >> newProcessesMax;
    
    cout << "Input the step size of new processes per cycle: ";
    cin >> stepSize;
    
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
    long sum = 0;//Wait time of completed processes
    int numSteps = 0;//How many simulations are to be ran
    double load = newProcessesMin;//Which load size is being displayed
    double newProcesses = newProcessesMin;//Initializes new processes to the min
    
    srand(time(0));
    //For loop to determine number of simulations
    for(double i = newProcessesMin; i < newProcessesMax; i = i + stepSize){
        numSteps++;
    }
    //Loop for determining and displaying the results for each simulation
    for(int k = 0; k < numSteps; k++){
        idleTime = 0;
        count = 0;
        sum = 0;
        if(k != 0){
            newProcesses += stepSize;
        }
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
   
  if(k == 0){
        cout << "=====Simulation Results=====" << endl;
        cout << "|Load|" << "   " << "|Idle|" << "  " << "|Completed|" << " " 
        << "|Processed Wait|" << "  " << "|Unprocessed|" << "   " << "|Exe.Needed|"
        << "    " << "|Unpr.Wait|" << " " << "|Unpr.MaxWait|" << endl;
    }
    
    cout << load << " " << idleTime << " " << count << " " 
        << sum << " " << processQueue.size() << " ";
        
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
        
    cout << unexecutedTime << " " << totalWait << " " << maxWait;
    }
    cout << endl;
        load += stepSize;
        processQueue.clear();
    }
    return 0;
}
