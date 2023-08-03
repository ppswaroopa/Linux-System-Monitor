#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>
#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// Return this process's ID
int Process::Pid() { return pid_; }

// Return this process's CPU utilization
float Process::CpuUtilization() { 
    string line;
    string key;
    string comm, state;
    long long int pid,ppid,pgrp,session,tty_nr,tgpid,flags,minflt,cminflt,majflt,cmajflt,utime,stime,cutime,cstime,priority,nice,num_threads,iteralvalue,starttime;
    std::ifstream filestream(LinuxParser::kProcDirectory +'/' + to_string(pid_) +LinuxParser::kStatFilename);
    if (filestream.is_open()) {
        std::getline(filestream, line);
        std::istringstream linestream(line);
        linestream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr >> tgpid >> flags >> minflt >> cminflt >> majflt >> cmajflt >> utime >> stime >> cutime >> cstime >> priority >> nice >>num_threads >> iteralvalue >> starttime;
    }
    long long total_time, uptime, Hertz, second;

    total_time = utime + stime;
    total_time =  total_time + cutime + cstime;
    Hertz = sysconf(_SC_CLK_TCK);
    uptime = LinuxParser::UpTime();
    second = uptime - (starttime / Hertz);
    float percentage;
    if (second == 0){
        percentage = 0;
    }
    else {
        percentage = 100 * ((total_time / Hertz) / second);
    }

    cpu_util_ = percentage;
    return percentage; 
}

// Return the command that generated this process
string Process::Command() {
    command_ = LinuxParser::Command(pid_);
    return command_; 
}

// Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

// Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid_); }

// Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); 
}

// Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const { 
    return cpu_util_ < a.cpu_util_; 
}

void Process::SetPid_(int t){
    pid_ = t;
}