#include"Adj_List.h"
using namespace std;

int main()
{
        
        Flight F1;
        int choice;
        bool loop=true;
        while(loop)
        {
                cout<<"\nMENU:"<<endl;
                cout<<"1.Add Cities."<<endl;
                cout<<"2.Display Cities."<<endl;
                cout<<"3.Add Flight Info."<<endl;
                cout<<"4.Display All Flight Info."<<endl;
                cout<<"5.Flight Enquiry."<<endl;
                cout<<"6.Exit."<<endl;
                cout<<"Enter the Choice: ";
                cin>>choice;
                cout<<endl;
                switch (choice)
                {
                case 1:
                        F1.addCities();          
                        break;
                case 2:
                        F1.DisplayHeadCity();
                        break;
                case 3:
                        F1.addConnection();
                        break;
                case 4:
                        F1.displayConnection();
                        break;
                case 5:
                        F1.enquireFlight();
                        break;
                case 6:
                        loop = false;
                default:
                        cout<<"Invalid Choice."<<endl;
                        break;
                }
        }
        cout<<"Exiting....."<<endl;
        return 0;
}
