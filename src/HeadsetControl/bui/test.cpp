#include<iostream>

using namespace std;

int main(){
    char command[50];
    sprintf(command, "%s", "./headsetcontrol -b");
    int ret = system(command);
    cout << ret;
    return 0;
}
