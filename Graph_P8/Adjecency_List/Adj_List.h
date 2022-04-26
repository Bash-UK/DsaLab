
#include<iostream>
#include<string.h>
using namespace std;
#define max 10
class GraphNode
{
  public:
        char destcity[30];
        int fuel;
        int time;
        GraphNode *next;     
};
class citiesList
{
  public:
        char sourcecity[30];
        citiesList *down;
        GraphNode *nextcity;
};

class Flight
{
        citiesList *Head;
        public:
                void addCities();
                void DisplayHeadCity();
                void addConnection();
                void displayConnection();
                void convertToUpperCase(char*);
                void enquireFlight();
                void checkDirectFlight(char*,char*);
                void checkIndirectFlight(char*,char*);
                citiesList* searchSourceCity(char*);
                GraphNode* searchDestcity(citiesList*,char*);
                Flight()
                {
                        Head = NULL;
                }
};

void Flight::convertToUpperCase(char* str)
{
        for(int i=0;i<sizeof(str);i++)
        {
                str[i] = toupper(str[i]);
        }
}
citiesList* Flight::searchSourceCity(char* str)
{
        citiesList *temp;
        temp = Head;
        while(temp!=NULL)
        {
                if(strcmp(temp->sourcecity,str)==0)
                {
                        return temp;
                }
                temp = temp->down;
        }
        return temp;
}
GraphNode* Flight::searchDestcity(citiesList* srcCity,char* str)
{
        GraphNode *q;
        q = srcCity->nextcity;
        while(q!=NULL)
        {
                if(strcmp(q->destcity,str)==0)   
                        return q;
                q = q->next;
        }
        return q;
}
void Flight::addCities()
{
        char srcCityName[30];
        citiesList *temp = new citiesList;
        citiesList *q;
        cout<<"Enter City Name:";
        cin>>srcCityName;
        temp->down=NULL;
        temp->nextcity=NULL;
        convertToUpperCase(srcCityName);
        strcpy(temp->sourcecity,srcCityName);       
        if(Head==NULL)
        {
                
                Head = temp;
                return;
        }      
//  Add city at top to reduce time complexity
        temp->down = Head;
        Head = temp;
        return;
}
void Flight::DisplayHeadCity()
{
        int count=0;
        citiesList *q;
        q = Head;
        cout<<"Cities are:"<<endl;
        while(q!=NULL)
        {
                count++;
                cout<<count<<"."<<q->sourcecity<<endl;
                q = q->down;
        }
}
void Flight::displayConnection()
{
        int ch;
        citiesList *cl;
        GraphNode *dest;
        DisplayHeadCity();
        cout<<"Select City Sr. no to Display Flight Info:";
        cin>>ch;
        ch--;
        cl = Head;
        for(int i=0;i<ch;i++)
                cl = cl->down;
        cout<<endl<<"Flight Information:"<<endl;
        cout<<"From\t\t\tTo\t\t\tFuel\t\t\tTime"<<endl;
        dest = cl->nextcity;
        while(dest!=NULL)
        {
                cout<<cl->sourcecity<<"\t\t\t"<<dest->destcity<<"\t\t\t"<<dest->fuel<<"\t\t\t"<<dest->time<<endl;
                dest = dest->next;
        }
        return;
}
void Flight::addConnection()
{
        char srcCity[30],destinationCity[30];
        int fuel,time;
        citiesList *srctemp;
        GraphNode *desttemp,*temp;
        cout<<"Enter Source City Name:";
        cin.ignore();
        cin.getline(srcCity,30);
        convertToUpperCase(srcCity);
        srctemp = searchSourceCity(srcCity);
        if(srctemp==NULL)
        {
                cout<<"Source City Not Found....."<<endl;
                cout<<"Add the City to cities list...."<<endl;
                return;
        }
        cout<<"Enter Destination City Name:";
        cin>>destinationCity;
        convertToUpperCase(destinationCity);
        cout<<"Enter Fuel required:";
        cin>>fuel;
        cout<<"Enter Time required:";
        cin>>time;
        desttemp = searchDestcity(srctemp,destinationCity);
        if(desttemp!=NULL)
        {
                desttemp->fuel = fuel;
                desttemp->time = time;
                return;
        }
        temp = new GraphNode;
        temp->fuel = fuel;
        temp->time = time;
        strcpy(temp->destcity,destinationCity);
        if(srctemp->nextcity == NULL)
                srctemp->nextcity = temp;
        else
        {
                temp->next = srctemp->nextcity;   //adding new flight connection at front 
                srctemp->nextcity = temp;
        }
}
void Flight::enquireFlight()
{
        char dest[30],src[30];
        cout<<"Enter Source:";
        cin>>src;
        cout<<"Enter Destination:";
        cin.ignore();
        cin.getline(dest,30);
        convertToUpperCase(src);
        convertToUpperCase(dest);
        checkDirectFlight(src,dest);
}
void Flight::checkDirectFlight(char* srcval,char* destval)
{
        citiesList *src;
        GraphNode *dest;
        src  = searchSourceCity(srcval);
        dest = searchDestcity(src,destval);  
        if(dest != NULL && dest->fuel!=0)
        {
                cout<<"\nFlight Available"<<endl;
                cout<<"Flight Information:"<<endl;
                cout<<srcval<<"->"<<dest->destcity<<endl;
                cout<<"Fuel required: "<<dest->fuel<<"\nTime required: "<<dest->time;
                cout<<endl;
                return;
        }
        else{cout<<"No Direct Flight...checking for connected flights...."<<endl;
       }
        checkIndirectFlight(srcval,destval);
}
void Flight::checkIndirectFlight(char* srcval,char* destval)
{
        citiesList *src,*srctemp;
        GraphNode *q,*destemp;
         src  = searchSourceCity(srcval);
        q = src->nextcity;
        cout<<"Connected Flights:"<<endl;
        while(q!=NULL)
        {
                srctemp = searchSourceCity(q->destcity);
                destemp = searchDestcity(srctemp,destval);   
                if(destemp!=NULL && destemp->fuel!=0)
                { 
                        cout<<"From "<<src->sourcecity<<" Via "<<srctemp->sourcecity<<" To "<<destemp->destcity<<endl;
                        cout<<"Total Fuel:"<<(q->fuel+destemp->fuel)<<endl;
                        cout<<"Total Time:"<<(q->time+destemp->time);
                        cout<<endl;
                }             
                q = q->next;
        }
        cout<<"No More Connected Flights"<<endl;
}