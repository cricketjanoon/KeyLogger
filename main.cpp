#include <iostream>
#include <windows.h>

#include "Helper.h"
#include "KeyConstants.h"

using namespace std;

int main()
{
    MSG Msg;

    while(GetMessage(&Msg, NULL, 0, 0)){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    cout << "Shahbaz Ali" << endl;
    return 0;
}
