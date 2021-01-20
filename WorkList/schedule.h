#include "day.h"

class Node {
private:
    Date data;
    Node *next;
    friend class Schedule;
public:
    Node(const Date &);
};

class Schedule{
private:
    Node *root, *last;
    Node *current;
    int length;
public:
    Schedule();
    ~Schedule();
    void add(Date &);
    void remove(float);

    void clear();
    void print(std::ostream &);
    void write(std::ostream &);

};
