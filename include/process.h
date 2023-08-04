#ifndef PROCESS_H
#define PROCESS_H

#include <string>

using std::string;
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  int Pid();                               
  std::string User();                      
  std::string Command();                   
  float CpuUtilization();                  
  std::string Ram();                       
  long int UpTime();                       
  bool operator<(Process const& a) const;  
  void SetPid_(int t);

 private:
    int pid_;
    string mem_util_;
    string command_;
    string uid_;
    string user;
    long uptime;
    float cpu_util_;
 
};

#endif