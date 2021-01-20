#include "schedule.h"
#include <fstream>

using namespace std;

void clearScreen();

int main(){

    int counter = 0;
    Schedule mainList;
    Date tmp;
    int option = 0;

    ifstream fs("log//2021");

    if (!fs.fail()) {
        while(!fs.eof()){
            tmp.reader(fs);
            mainList.add(tmp); 
        }
    }

    fs.close();
    
    while(option != 5){

        clearScreen();
        cout << "Scheduler: \n1. Add\n2. Remove\n3. List\n4. Clear\n5. Exit";    
        cout << "\n\n Option: ";
        cin >> option;
        
        if(option == 1){
            while(true){
                clearScreen();

                cout << "Add Date: \n";
                cout << "\nDay: ";
                cin >> counter;
                tmp.setDay(counter);
                cout << "\nMonth: ";
                cin >> counter;
                tmp.setMonth(counter);

                cout << "\nNotes: \n";
                string notes;
                getchar();
                getline(cin, notes);
                tmp.writeNotes(notes);
                cout << "Is this correct? (y/n) \n\n";
                tmp.print(cout);

                char apples;
                cin >> apples;
                clearScreen();

                if(apples == 'y'){
                    break;
                }
                
            }
            mainList.add(tmp);
        }
        else if(option == 2){
            cout << "Name id: ";
            float id;
            cin >> id;
            mainList.remove(id);
        }
        else if(option == 3){
            mainList.print(cout);
            cin.ignore();
            getchar();
        }
        else if(option == 4){
            cout << "Clear Data? (y/n): ";
            char apples;
            cin >> apples;

            if(apples == 'y'){
                mainList.clear();
            }
        }
        else if(option == 5){
            ofstream fs("log//2021");
            mainList.write(fs);
            fs.close();
            break;
        }
    }
}



void clearScreen(){
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
