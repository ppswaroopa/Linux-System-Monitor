#include <string>

#include "format.h"

using std::string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) { 
    int hours, minutes, sec;
    sec = seconds % 60;
    hours = seconds / 3600;
    minutes = ((seconds - sec) % 3600) / 60;

    string t = std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(sec);

    return t; 
}