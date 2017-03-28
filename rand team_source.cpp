#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main(){
	char ans;
	bool choose=true;
	while(choose){
	int max=0,people=0,outp=0,p=0;
	srand(time(NULL));//seed
	//data enter
	cout<<"MAX:";
	cin>>max;
	cout<<"How many people in one team? ";
	cin>>people;
	cout<<"except:";
	cin>>outp;

	//creat array
	int out[outp],s[max];
	for(int i=1;i<=max;i++) s[i]=i;
	//store num min to max
	if(outp!=0){
		for(int j=1;j<=outp;j++){
			cout<<"num"<<j<<":";
			cin>>p;
			s[p]=0;
		}
	}

	//rand algorithm
	int r1=0,r2=0,temp=0;
	for(int i=1;i<=max;i++){
			r1=1+(rand()%max);
			r2=1+(rand()%max);
			temp=s[r1];
			s[r1]=s[r2];
			s[r2]=temp;
		}

	//print
	int count=0,team=1;
	cout<<"--------------------------------"<<endl;
	for(int l=1;l<=max;l++){
		if(s[l]!=0){
			cout<<setw(3)<<s[l];
			count++;
			if(count%people==0){
			cout<<endl;
			}
		}
	}
	cout<<"\n--------------------------------"<<endl;
	cout<<"again ? [Y/N]";
	cin>>ans;
	if(ans=='N'||ans=='n'){
		choose=false;
	}

	}
	return EXIT_SUCCESS;
}
