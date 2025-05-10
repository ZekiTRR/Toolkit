#include <iostream>
#include <ctime>

using namespace std;

void secsmer()
{
    time_t late = time(NULL);
    for(;;){
        time_t now = time(NULL);
        int remaining = static_cast<int>(now - late);
        _sleep(1000);

        cout << "Seconds: " << remaining << endl;
    }
}