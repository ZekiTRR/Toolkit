#include <iostream>
#include <ctime>

using namespace std;

/**
 * Function: time
 * Description:
 *   This function prompts the user to enter a number of seconds and then 
 *   counts down from that number. It continuously displays the remaining 
 *   time until it reaches zero, at which point it prints "Time's up!".
 */

void timer()
{
    int secs = 0;
    cout << "Enter the number of seconds: " << endl;
    cin >> secs;

    time_t start = time(NULL);
    time_t end = start + secs;


    for(;;){
        time_t now = time(NULL);
        int remaining = static_cast<int>(end - now);
        if(remaining != 0){
            _sleep(1000);
            cout << "Remaining time: " << remaining << endl;
        }else{
            cout << "Time's up!" << endl << endl << endl;
            break;
            cin.get();
            cin.get();
        }
        
    }


}


    


