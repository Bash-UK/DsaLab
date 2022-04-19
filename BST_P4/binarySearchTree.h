#include<iostream>
using namespace std;

class Bnode{

	public:
	      int data;
	 	Bnode *leftNode;
	      Bnode*rightNode;

};

class Btree{

	private:
	
	public:
Bnode *rootNode;

	Bnode *createNode();
		void intializeRootNode();
		void insertNewNode();
		void search(int key);
		void rin(Bnode *treeNode);
		void rpre(Bnode *treeNode);
		void rpost(Bnode *treeNode);
		void display(int choiceParameter);
		void nrecin();
		void nrecpre();
		void nrecpos();
		int height(Bnode *rootNode);
		int nodeinlongestpath(Bnode *rootNode);
		int min();
		
		};




Bnode *Btree::createNode(){

Bnode *temp;
	int nodeData = 0;

	cout<<"\nEnter an integer value to create a node: ";
	cin>>nodeData;
	

	temp = new Bnode();
	if(temp == NULL){
		cout<<"Memory Allocation Failed!";
		return nullptr;		
	}else{
		temp -> leftNode = NULL;
		temp -> rightNode = NULL;
		temp -> data = nodeData;

		cout<<"\nNode created successfully!";
		
	}
	return temp;
}


void Btree::display(int choiceParameter){

Bnode *temp;
	temp = rootNode;

	switch(choiceParameter){
	case 1:	cout<<endl<<"In-Order Traversal displaying....\n";
			rin(temp);
			break;
	
	case 2:
			cout<<endl<<" Pre-Order Traversal displaying\n";
			rpre(temp);
			break;
	
	case 3:
			cout<<endl<<" Post-Order Traversal displaying\n";
			rpost(temp);
			break;
	
	default:
		cout<<endl<<"Invalid choice ";		
	}
}



void Btree::intializeRootNode(){

	cout<<"Creating root node...."<<endl;


	rootNode = createNode();
	if(rootNode == NULL){
		cout<<"Root node creation failed!";
	}else{
		cout<<"\nRoot Node created.";
	}

}

void Btree::insertNewNode(){

Bnode *temp, *newNode;
	
	temp = rootNode;
	newNode = createNode();

	while(temp != NULL){
		while(temp->data!=newNode->data){
		if(temp -> data > newNode -> data){
			if(temp -> leftNode == NULL){
				temp -> leftNode = newNode;
				return;
			}else{
				temp = temp -> leftNode;
			}
		}else{
			if(temp -> rightNode == NULL){
				temp -> rightNode = newNode;
				return;
			}else{
				temp = temp -> rightNode;
			}
		}
	}
 		cout<<"\nsame node cannot be inserted;";
		break;
	}
}

void Btree::rin(Bnode *treeNode){

	if(treeNode != NULL){
		rin(treeNode -> leftNode);
		cout<<" "<<treeNode -> data;
		rin(treeNode -> rightNode);
	}
}

void Btree::rpre(Bnode *treeNode){

	if(treeNode != NULL){
		cout<<" "<<treeNode -> data;
	rpre(treeNode -> leftNode);
		rpre(treeNode -> rightNode);
	}

}

void Btree::rpost(Bnode *treeNode){


	if(treeNode != NULL){
	
		rpost(treeNode -> leftNode);
		rpost(treeNode -> rightNode);
		cout<<" "<<treeNode -> data;
	}



}



int Btree:: height(Bnode *Root){			
		int lh,rh;
		if(Root==NULL)return 0;
		if(Root->leftNode==NULL && Root->rightNode==NULL)return 1;
		lh=height(Root->leftNode);
		rh=height(Root->rightNode);
		if(lh>rh)return(lh+1);
		else 
		return rh+1;
		}


/* void Btree:: Mirror(Bnode *Root){
 	Bnode *temp;
	if(Root!=NULL){
		temp=Root->left;
		Root->left=Root->right;
		Root->right=temp;
		Mirror(Root->left);
		Mirror(Root->right);
	}

*/ }








void Btree:: search(int key){

	Bnode *temp=rootNode;
	int cmp=1;
	while (temp!=NULL)
	{
		if (temp->data==key){
			cout<< "\nNode found!\n";
			cout<<"No. of comparison: "<<cmp;
		return;}
		else if(key<temp->data){
			temp=temp->leftNode;
			cmp++;
		}
		else	{
			temp=temp->rightNode;
			cmp++;
			}
	}
	cout<< "\nNode not Found!\n";
}

int Btree:: min(){
	int mini;
	Bnode *temp=rootNode;
	while(temp!=NULL){
		mini=temp->data;
		temp=temp->leftNode;
	}
	return mini;
}
