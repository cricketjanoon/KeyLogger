#include <iostream>
#include <windows.h>

#include "Helper.h"
#include "KeyConstants.h"
#include "Base64.h"
#include "IO.h"

using namespace std;

int main()
{
    std::string str {"Ma"};
    std::string encoded_str = Base64::base64_encode(str);

    cout << "Base 64 encoded: " << encoded_str << endl;

    MSG Msg;

    while(GetMessage(&Msg, NULL, 0, 0)){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    cout << "Shahbaz Ali" << endl;
    return 0;
}
