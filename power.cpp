#include <bits/stdc++.h>
using namespace std;

float findPower(int x,int y){
    if(y==0)return 1;
    else if(y%2==0){
        return findPower(x,y/2)*findPower(x,y/2);
    }
    else{
        if(y>0){
            return x*findPower(x,y/2)*findPower(x,y/2);
        }else{
            return findPower(x,y/2)*findPower(x,y/2)/x;
        }
    }
}
int main()
{
    cout<<-1/2<<endl;
    return 0;
}