#include "model.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
void rand_team::creat_array(int s[])
{
    for(int i=1;i<=max;i++) s[i]=i;
    //store num to max
}
    //rand algorithm
void rand_team::rand_algorithm(int s[]){
    srand(time(NULL));
     int r1=0,r2=0,temp=0;
     for(int i=1;i<=max;i++){
            r1=1+(rand()%max);
            r2=1+(rand()%max);
            temp=s[r1];
            s[r1]=s[r2];
            s[r2]=temp;
     }
}

    //print
std::string rand_team::out_put(int s[])
{

    std::stringstream ss;
    int count=0;
    //cout<<"--------------------------------"<<endl;
    for(int l=1;l<=max;l++){
        if(s[l]!=0){
            ss<<s[l]<<"\t";
            count++;
            if(count%people==0){
            ss<<"\n";
            }
        }
    }
    std::string str=ss.str();
    return str;
}
/*
    cout<<"\n--------------------------------"<<endl;
    cout<<"again ? [Y/N]";
    cin>>ans;
    if(ans=='N'||ans=='n'){
        choose=false;
    }

    }

}*/
