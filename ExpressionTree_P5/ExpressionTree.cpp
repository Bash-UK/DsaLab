#include<iostream>
#include<ctype.h>
#include<string>

using namespace std;

class expnode{
    public:
    char data;
    expnode *left,*right;

};
template<class T>
class stack{
public:
    T st[20];
    int top;
    stack(){
        top=-1;
    }

    T push(T p){
        if(!isfull()){
            top++;
            st[top]=p;
        }
    }

    T isempty(){
        if(top==-1)
            return true;
        return false;
    }
    
    bool isfull(){
        if(top==19)
            return 1;
        return 0;
    }

    T pop(){
        T temp;
        temp=st[top];
        top--;
        return temp;
    }

    T gettop()
    {
        return st[top];
    }


};




class exptree{

  
  
    public:
          expnode *Root;
          exptree(){
              Root=NULL;
          }
        void createNode();
        void nonrecin(expnode *);

       
        string pre_to_post()
        {   
            string prefix;
            cout<<"enter prefix : ";
            cin>>prefix;
            int prelen = prefix.length();
            stack<string> s1;
            string pop1,pop2;
            string result;            
            for (int i = prelen ; i >= 0; i--)
            {
                if(prefix[i] == '^' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '+' || prefix[i] == '-')
                {
                    pop1 = s1.pop();
                    pop2 = s1.pop();
                    result = pop1 + pop2 + prefix[i];
                    s1.push(result);
                }
                else if((prefix[i] >= 'a' && prefix[i] <= 'z') || (prefix[i] >= 'A' && prefix[i] <= 'Z'))
                {
                    s1.push(string(1,prefix[i]));
                }
            }
               return s1.gettop();

        }

    

};

void exptree :: createNode(){

    expnode *temp,*t1,*t2;
    stack s1;
    char z[20];
    char c;
    cout<<"Enter the pre expresssion: "<<endl;
    cin>>z;
    cout<<"\n You Entered the expression: ";
    int i=0;
    while(z[i]!=NULL){
        cout<<z[i]<<" ";
        i++;
    }

     i=0;
    while(z[i]!=NULL)
    {
    c=z[i];
    temp= new expnode;
    temp->left=temp->right=NULL;
    temp->data=c;

    if(c>='a' && c<='z'){
        s1.push(temp);
    }else{
        t2=s1.pop();
        t1=s1.pop();
        temp->left=t1;
        temp->right=t2;
        s1.push(temp);
        }
        i++;
    }
      Root=s1.pop();
    cout<<endl; 
}


void exptree:: nonrecin(expnode *T)
{
    stack s;
    while(T != NULL)
    {
        s.push(T);
        T=T->left;
    }
    cout<<"\nInorder traversal: ";
    while(!s.isempty())
    {
        T=s.pop();
        cout<<T->data<<" ";
        T=T->right;
        while(T != NULL)
        {
            s.push(T);
            T=T->left;
        }

    }cout<<endl;
}












int main(){
    exptree expobj;
  expobj.createNode();
  expobj.nonrecin(expobj.Root);
    expobj.pre_to_post();
    return 0;
}