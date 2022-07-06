#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <math.h>

/*
Author: Daniel Weitman
Creation Date: 11/02/18
Last Update: 11/12/18
Description: Main for a simulation of different processes going through a CPU.
*/

using namespace std;

class Process{
    
    private:
        int exeTime;//Time needed for process to execute
        int timeStamp;//Time when added to queue
        
    public:
        Process(int time = 1, int stamp = 0);
        Process(const Process &obj);
        ~Process();
        
        void setExeTime(int);
        int getExeTime();
        void setTimeStamp(int);
        int getTimeStamp();
        
        const Process operator =(const Process &right);
        friend ostream &operator <<(ostream &, const Process &);
   
};


/*
 * Desciption: Default constructor.
 * Parameters: int time, int stamp.
 * Return: None.
 */
Process::Process(int time, int stamp){
    exeTime = time;
    timeStamp = stamp;
}


/*
 * Desciption: Copy constructor.
 * Parameters: Process object.
 * Return: None.
 */
Process::Process(const Process &obj){
    exeTime = obj.exeTime;
    timeStamp = obj.timeStamp;
}


/*
 * Desciption: Destructor.
 * Parameters: None.
 * Return: None.
 */
Process::~Process(){
    
}


/*
 * Desciption: Sets exeTime.
 * Parameters: int exeTime.
 * Return: None.
 */
void Process::setExeTime(int a){
    exeTime = a;
}


/*
 * Desciption: Gets exeTime.
 * Parameters: None.
 * Return: int exeTime.
 */
int Process::getExeTime(){
    return exeTime;
}


/*
 * Desciption: Sets timeStamp.
 * Parameters: int timeStamp.
 * Return: None.
 */
void Process::setTimeStamp(int a){
    if(a < 1){
        timeStamp = 1;
        return;
    }
    timeStamp = a;
}


/*
 * Desciption: Gets timeStamp.
 * Parameters: None.
 * Return: int timeStamp.
 */
int Process::getTimeStamp(){
    return timeStamp;
}


/*
 * Desciption: Assignment operator overload.
 * Parameters: Process obj.
 * Return: Process object.
 */
const Process Process::operator=(const Process &obj){
    exeTime = obj.exeTime;
    timeStamp = obj.timeStamp;
    return *this;
}


/*
 * Desciption: Displays a formatted Process.
 * Parameters: ostream, Process object.
 * Return: stream.
 */
ostream &operator <<(ostream &strm, const Process &pro){
    cout << "[" << pro.exeTime << ", " << pro.timeStamp << "]" << endl;
    return strm;
}
#endif
