#include "day.h"

Date::Date(){
    month = 1, day = 1, year = 1970, time = 0;
    notes = "n/a";
    key = getMonth()*100 + getDay();
}
Date::~Date(){
    month = 1, day = 1, year = 1970, time = 0;
    notes = "n/a";
}

void Date::reader(std::istream &i){
    i >> key >> month >> day;
    getline(i, notes);
}

void Date::setMonth(int x){
    if(x<=12 && x>0){
        month = x;
        key = month*100 + getDay();
    }
    else{
        return;
    }
}

void Date::setDay(int x){
    // not worth any more logic
    if(x<= 31 && x > 0){
        day = x;
        key = getMonth()*100 + day;
    }
    else{
        return;
    }
}

void Date::setYear(int x){
    if(x<30){
        year = x;
    }
    else if(x>2020){
        year = x*0.001;
    } 
    else{
        return;
    }
}

void Date::writeNotes(std::string x){
    if(x.length() > 0 && x.length() < 256){
        notes = x;
    }
    else{
        return; }
}

void Date::print(std::ostream& o){
    o << std::setw(2) << std::setfill('0') << getDay() << std::endl;
    o << readNotes() << "\n\n";
}

int Date::compareTo(Date &d){
    if(key == d.getKey()){
        return 0;
    }
    else if(key > d.getKey()){
        return 1;
    }
    else if(key < d.getKey()){
        return -1;
    }
    else{
        return 0;
    }
}

bool Date::operator>(Date& d){
    return(compareTo(d) == 1);
}

bool Date::operator<(Date& d){
    return(compareTo(d) == -1);
}

bool Date::operator==(Date& d){
    return(compareTo(d) == 0);
}
