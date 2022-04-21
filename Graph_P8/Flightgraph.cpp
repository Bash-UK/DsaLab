
#include<string>
#include"Flight_Adjmatrix.h"
using namespace std;

int main(){

    AdjMatrix matObj;
    int n;

    cout<<"\n \t\t\tWelcome to Flight Management\t\t\t "<<endl;
    cout<<"\nEnter the no. cities you want to insert in the system : ";
    cin>>n;
    int choice;
    
do{
        cout<<"\n \t\t\t Menu \t\t\t"<<endl;
        cout<<"\n1] Enter the flight information."<<endl;
        cout<<"\n2] Display All Flight Details. "<<endl;
        cout<<"\n3] Enquire about flight availability."<<endl;
        cout<<"\n4] Exit.";
        cout<<"\nEnter your Choice : "<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1: 
                matObj.readMatrix(n);
                break;
        case 2: 
                matObj.display(n);
                break;
        case 3: 
                matObj.avaiable(n);
                break;

        default:
            cout<<"\n Thank you for using the system!!"<<endl;
            exit(0);
            break;
        }


}while(choice!=4);


    return 0;

}