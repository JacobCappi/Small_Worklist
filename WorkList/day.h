#include <iostream>
#include <string>
#include <iomanip>


class Date{
private:
    int month, day, year;
    int time;
    float key;
    std::string notes;
public:
    Date();
    ~Date();

    void reader(std::istream &i);

    void setMonth(int);
    void setDay(int);
    void setYear(int);
    void setTime(int);
    void writeNotes(std::string);

    int getMonth(){return month;}
    int getYear(){return year;}
    int getDay(){return day;}
    int getTime(){return time;}
    int getKey(){return key;}
    std::string readNotes(){return notes;}

    void print(std::ostream&);
    
    int compareTo(Date &); 
    bool operator>(Date &);
    bool operator<(Date &);
    bool operator==(Date &);
    
};
