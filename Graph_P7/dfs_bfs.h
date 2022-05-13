#include<iostream>
#include "stack.h"
#include<string.h>
using namespace std;

class areaNode{

	public :
		char areaName[30];
		areaNode *next;
};

class areaList{

	public:
		int areaNumber;
		char areaHeadName[30];
		areaList *down;
		areaNode *nextArea;
		int visited;
};

class Area{

public:
	areaList *Head;
	void readAreas();
	Stack<areaList*> s1;
	void displayAreas();
	void displaydest(areaList*);
	areaList* searchArea(char*);
	areaNode* searchDestinationArea(areaList*,char*);
	void ToUpperCase(char*);
	void DFS();
	void readConnection();
	int notVisited(areaList*);
	Area(){
		Head=NULL;
	}	
	

};
 void Area::ToUpperCase(char* str)
{
        for(int i=0;i<sizeof(str);i++)
        {
                str[i] = toupper(str[i]);
        }
}
areaList* Area :: searchArea(char* str){
		 
	areaList *q;
	q = Head;
	while(q!=NULL){
		for(int i=0; i<sizeof(str);i++){
		if(q->areaHeadName[i]==str[i])
		{
			return q;
		}	}
		q=q->down;	
	}
	return q;
} 
areaNode *Area :: searchDestinationArea(areaList* srctemp,char* destn)
{
	areaNode *a;
	a = srctemp->nextArea;
	while(a!=NULL)
	{
		if(strcmp(a->areaName,destn)==0)
			return a;
		a = a->next;
	}
	return a;
}

void Area:: readAreas()
{
	char AreaName[30];
	int AreaNumber;
	
	areaList *temp=new areaList;
	areaList *q;
	cout<<"\n Enter Area number: ";
	cin>>AreaNumber;
	cout<<"\n Enter Area Name: ";
	cin.ignore();
	cin.getline(AreaName,30);
	temp->down=NULL;
	temp->nextArea=NULL;
	ToUpperCase(AreaName);
	strcpy(temp->areaHeadName,AreaName);
	temp->areaNumber=AreaNumber;
	if(Head==NULL){
		Head=temp;
		return;
	}
	temp->down=Head; 
	Head=temp;
	return;
	
}
void Area::readConnection()
{
        char srcArea[30],destinationArea[30];
        areaList *srctemp;
        areaNode *desttemp,*temp;
		
        cout<<"Enter Source Area Name:";
        cin.ignore();
        cin.getline(srcArea,30);
        ToUpperCase(srcArea);
        srctemp = searchArea(srcArea);
		
        if(srctemp==NULL)
        {
                cout<<"Source Area Not Found....."<<endl;
                cout<<"Add the Area to cities list...."<<endl;
                return;
        }
        cout<<"Enter Destination Area Name:";
        cin>>destinationArea;
        ToUpperCase(destinationArea);
        desttemp = searchDestinationArea(srctemp,destinationArea);
     	 temp = new areaNode;
        strcpy(temp->areaName,destinationArea);
        if(srctemp->nextArea == NULL)
                srctemp->nextArea = temp;
		displaydest(srctemp);
 }

void Area:: displayAreas(){
	
        areaList *q;
        q = Head;
		areaNode *a;
        cout<<"Areas are: "<<endl;
        while(q!=NULL)
        {
                cout<<q->areaNumber<<"."<<q->areaHeadName<<endl;
			
                q = q->down;
        }
		return;
}

void Area:: displaydest(areaList* src){

	    areaNode *q;
        q = src->nextArea;

        cout<<"dest Areas are: "<<endl;
        while(q!=NULL)
        {
                cout<<q->areaName<<endl;
			
                q = q->next;
        }
		return;
}

int Area::notVisited(areaList* v){
	areaList* temp= Head;
	while(temp==v){
		if (temp->visited==0)
		{
			return 1;
		}
		else	
			return 0;
		temp=temp->down;
	}
	return 0;
}

void Area::DFS(){
	areaList *temp;

	temp=Head;
	areaNode *q;
	areaList *v;
	while(temp!=NULL) 
	{
		temp->visited=0;
		temp=temp->down;
	}
	cout<<"DFS: ";
	temp = Head;
	s1.push(temp);
	while(!s1.underflowCondition()){
		v=s1.pop();
		cout<<v->areaNumber<<". "<<v->areaHeadName<<endl;
		if (notVisited(v))
		{
			v->visited=1;
			q=v->nextArea;
		while(q!=NULL){
			s1.push(searchArea(q->areaName));
			q=q->next;
			}
		}
		
	}

}
