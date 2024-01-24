using namespace std;
#include <iostream>

#include "DataManager.h"
#include "Request.h"
#include "Reader.h"

int main()
{
    Request req;
    Reader r("/tmp/analog.log");
    r.Read(req);
    cout << req;
    return 0;
}