#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        if(b<=a){
            b=b+c;
            if(a<=b)
                a=a+d;
            else    
                b=b+d;
        }
        else{
            a=a+c;
            if(b<=a)
                b=b+d;
            else    
                a=a+d;
        }
        if(a>=b)
            cout<<"N"<<"\n";
        else   
            cout<<"S"<<"\n";
    }
}