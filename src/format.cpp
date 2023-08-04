#include <string>
#include <iomanip>
#include "format.h"

using std::string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) { 
    int hours, minutes, sec;
    sec = seconds % 60;
    hours = seconds / 3600;
    minutes = (seconds % 3600) / 60;

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setfill('0') << std::setw(2) << minutes << ":"
        << std::setfill('0') << std::setw(2) << sec;

    // string t = std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(sec);

    return oss.str(); 
}