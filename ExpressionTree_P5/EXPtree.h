#include<iostream>
#include<stack>

using namespace std;

class expnode{
    public:
    char data;
    expnode *left,*right;

};

class exptree{

    expnode *Root;
    stack <expnode>obj;
    public:
        expnode *createNode(string data,int explen);
		//void intializeRootNode();
        void *expinit();
		void Expconstruct();


    

};

expnode *exptree:: createNode(string data,int explen){

    expnode *temp;

        //cin>>data


	temp= new expnode();
	if(temp == NULL){
		cout<<"Memory Allocation Failed!";
		return nullptr;		
	}else{
		temp -> left = NULL;
		temp -> right = NULL;
		temp -> data = data[explen];

		cout<<"\nNode created successfully!";

	}
	return temp;
    
  
}

void *exptree :: expinit(){
    string expression;
    cout <<"Enter the expression:";
    cin>> expression;

    expnode *expnodes[expression.length()];

     for(int i=0 ; i<expression.length() ; i++){
       expnodes[i] =  createNode(expression,i);
     }

    return *expnodes;
} 

void Expconstruct(){

            
}