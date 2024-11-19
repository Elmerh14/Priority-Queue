#include "priorityQueue.h"
#include <iostream>

using namespace std;

int main() 
{
    PriorityQueue queue1;
    int menu, value;

    while(true)
    {
        cout << "Please enter a enter a choice (1-4)\n";
        cout << "1. Insert an item into the queue\n";
        cout << "2. Delete the minimum value\n";
        cout << "3. Print the queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: \n";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Enter value to insert (enter -1 after entering you input to procced): ";
             while(true)
            {
                cin >> value;
                if(value == -1) break;
                queue1.insert(value);
            }
            break;

        case 2:
            //try catch error handling
            try
            {
                queue1.deleteMin();
            }
            catch(const exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        
        case 3:
            cout << "Priority Queue: ";
            queue1.printQueue();
            break;

        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice, Try again. \n";
            break;
        }

    }
    return 0;
}
