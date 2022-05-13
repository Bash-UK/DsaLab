#include<iostream>
#include<string.h>
using namespace std;
#define MAX 26
class Node
{
    public:
        char word[30];
        char meaning[30];
        Node* next;
};
class Dictionary
{
    Node* Dict[MAX];
    public:
        int Hashing(char);
        void insert();
        bool search();
        void display();
        void display(Node*);
        Dictionary()
        {
            for(int i=0;i<MAX;i++)
            {
                Dict[i] = NULL;
            }
        }
};
int Dictionary::Hashing(char key)
{
    if(key>='A' && key<='Z')
        key = key-65;
    else if(key>='a' && key<='z')
        key = key-97;
    return key % MAX;
}
void Dictionary::insert()
{
    Node* temp = new Node;
    char word[30],mean[30];
    int index;
    cout<<"Enter a Word:";
    cin>>word;
    cout<<"Enter Meaning:";
    cin>>mean;
    index = Hashing(word[0]);
    if(Dict[index]==NULL)
    {
        strcpy(temp->word,word);
        strcpy(temp->meaning,mean);
        temp->next = NULL;
        Dict[index] = temp;
    }
    else
    {
        strcpy(temp->word,word);
        strcpy(temp->meaning,mean);
        temp->next = Dict[index];
        Dict[index] = temp;
    }
}
void Dictionary::display()
{
    Node* temp = new Node;
    for(int i=0;i<MAX;i++)
    {
        cout<<"\n["<<(char)(i+65)<<"/"<<(char)(i+97)<<"]";
        if(Dict[i]==NULL)
        {
            cout<<"-->NULL";
            continue;
        }
        temp = Dict[i];
        while(temp!=NULL)
        {
            cout<<"-->"<<temp->word;
            temp = temp->next;
        }
    }
}
void Dictionary::display(Node* temp)
{
        cout<<"\n["<<tolower(temp->word[0])<<"/"<<toupper(temp->word[0])<<"]";
        cout<<"-->"<<temp->word;
}


bool Dictionary::search(char* match)
{
    Node* temp = new Node;
    for(int i=0;i<MAX;i++)
    {
        if(Dict[i]!=NULL)
        {
            temp = Dict[i];
            while(temp!=NULL)
            {
                /*strcasecmp is used to compare string with ignoring cases*/
                if(strcasecmp(temp->word,match)==0 || strcasecmp(temp->meaning,match)==0)
                    return true;
                temp = temp->next;
            }
        }
    }
    return false;
}

int main()
{
   Dictionary d1;
   bool flag=true;
   char outerchoice,innerchoice;
   while(flag)
   {
        cout<<"\nMENU:"<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Search"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter Choice:";
        cin>>outerchoice;
        switch(outerchoice)
            {
                    case '1':
                            d1.insert();
                    break;
                    case '2':
                            d1.search();
                    break;
                    case '3': 
                            d1.display();
                    break;
                    case '4':
                            //d1.delete1();
                    break;
                    case '5':
                        cout<<"Exiting...";
                        flag=false;
                    break;
                    default:
                        cout<<"Invalid Option"<<endl;
            }
   }
   return 0; 
}
