#include <string>
#include <sstream>

#include "processor.h"
#include "linux_parser.h"

using std::string;

// Return the aggregate CPU utilization
float Processor::Utilization() { 
    string line;
    string key;
    long long int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    std::ifstream filestream(LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
    if (filestream.is_open()) {
        std::getline(filestream, line);
        std::istringstream linestream(line);
        linestream >> key >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;
    }

    idle = idle + iowait;
    long long int nonidle = user + nice + system + irq + softirq + steal;
    long long int totaltime = idle + nonidle;

    float hold =  (totaltime - idle);

    float percentage = hold / totaltime;

    return percentage; 
}