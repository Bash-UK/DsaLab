#include<iostream>
#include<iomanip>
#include<cstring>
#include<string.h>
using namespace std;
#define max 10

class AdjMatrix{
     
    public:
       string city[max];
        int  Time[max][max];
        int  Fuel[max][max];
        void readMatrix(int);
        void display(int);
        void avaiable(int);

};

void AdjMatrix:: readMatrix(int n){
  //  int n;
    //cout<<"Enter the no. of cities: "<<endl;
   // cin>>n;                                     //no of cities
  
    for (int i = 0; i < n; i++)             //accepting the names of cities
    {   
        cout<<"Enter name of city "<<i+1<<": ";
        cin>>city[i];
    }
    cout<<"\n\nEnter the Time and Fuel information: "<<endl; 
    cout<<"\nNote :  If flight not available put '0' at place of time and fuel \n"<<endl;   //Accepting time and fuel for each
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            {   if(city[i]==city[j]) {
                    Time[i][j]=0;
                    Fuel[i][j]=0;
                continue;}
                cout<<"\nTime required from "<<city[i]<<" to "<<city[j]<<":  ";
                cin>>Time[i][j];
                cout<<"\nFuel required from "<<city[i]<<" to "<<city[j]<<":  ";
                cin>>Fuel[i][j];
            }    
    }  
    cout<<endl;
} //end read matrix


void AdjMatrix:: display(int n){
    cout<<endl;
    cout<<"\n\n Displaying available Flights!!\n"<<endl;
    cout<<setw(8)<<"From"<<setw(8)<<" \t\t "<<setw(8)<<"To"<<setw(8)<<" \t\t "<<setw(8)<<"Time"<<setw(8)<<" \t\t "<<setw(8)<<"Fuel"<<setw(8)<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        { if(city[i]==city[j] && Time[i][j]==0 && Fuel[i][j]==0) continue;
           cout<<setw(8)<<city[i]<<setw(8)<<" \t\t "<<setw(8)<<city[j]<<setw(8)<<" \t\t "<<setw(8)<<Time[i][j]<<setw(8)<<" \t\t "<<setw(8)<<Fuel[i][j]<<setw(8)<<endl;
        
        }
    }  

}


void AdjMatrix::avaiable(int n){
    string cityA;
    string cityB;
   int flag=0;
    cout<<"\n\nEnquire about Flight detail: "<<endl;
    cout<<"\nFrom City: "<<endl;
    cin>>cityA;
    cout<<"\nTo City: "<<endl;
    cin>>cityB;
    
    for (int  i = 0; i<n ; i++)
    {
        for (int j = 0; j <n; j++)
     { 
        
         if(cityA==city[i] && cityB==city[j]&& Time[i][j]!=0 && Fuel[i][j]!=0){
                flag=1;
                cout<<"\nFlight available from "<<city[i]<<" To "<<city[j]<<"!";
                cout<<"\n\nFlight Details:  "<<endl;
                cout<<"Time required : "<<Time[i][j]<<"\nFuel required: "<<Fuel[i][j]<<endl;     
        }
     }
    
    }
    if (flag==0)
    {
        
            cout<<"\nSorry Flight not available."<<endl;
    }
    
}
