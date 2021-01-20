#include "schedule.h"

#define BAR "===============\n"

Node::Node(const Date& d){
    data = d; 
    next = NULL;
}

Schedule::Schedule(){
    root = NULL, last = NULL, current = NULL;
    length = 0;
}

Schedule::~Schedule(){
    clear();
}

void Schedule::add(Date &d){
    Node *date = new Node(d);
    Node *p, *q;

    p = root;
    q = NULL;

// Looking for insert location
    while(p){
        if(p->data>d){
           break; 
        }
        else{
           q = p;
           p = p->next; 
        }
    }
    
    if(!q){
        date->next = p;
        root = date;        
    }
    else{
        q->next = date;
        date->next = p;
    }
    length++;
}

void Schedule::remove(float x){
    Node *p, *q;
    p = root;
    q = NULL;

    while(p){
        if(x == p->data.getKey()){
            break;
        }
        else{
            q = p;
            p = p->next;
        }
    }

    if(p){
        if(!q){
            root = p->next; 
        }
        else{
            q->next = p->next;
        }
        delete p;
        length--;
    }
}

void Schedule::clear(){
    Node *p;
    p = root;

    while(p){
        root = p;
        p = p->next;
        delete root;
    }
    root = NULL;
    length = 0;
}

void Schedule::print(std::ostream &o){
    Node *p, *q;
    p = root;
    q = p;

    o << "\n" << BAR;
    o << "=      " << q->data.getMonth() << "      =" ;
    o << "\n" << BAR;

    while(p){
        if(p->data.getMonth() != q->data.getMonth()){
            q = p;
            o << "\n" << BAR;
            o << "=       " << q->data.getMonth() << "      =";
            o << "\n" << BAR;
        }
        p->data.print(o);
        p = p->next;
        
    }
}

void Schedule::write(std::ostream &o){
    Node *p;
    p = root;
    while(p){
        o << p->data.getKey() << " " << p->data.getMonth() << " " << p->data.getDay() << " " << p->data.readNotes();
        if(p->next){
            o << "\n";
        }
        p = p->next;
    }
}


