#include<iostream>
#include<string>
using namespace std;

class Bnode{

	public:
	    string word;
        string meaning;
	 	Bnode *left;
	    Bnode *right;
     
        Bnode(string x, string y){
            word=x;
            meaning =y;
            left=NULL;
            right=NULL;
        }

};

class Dictionary{

    public:     
            Bnode *root;
            Dictionary(){
                root=NULL;
            }
            void insert(Bnode *,string,string);
            void display_asc(Bnode *);
            void display_desc(Bnode *);
            void search(Bnode *,string);
            void update_word(Bnode *,string);
            Bnode *minNode(Bnode *);
            
    
};


void Dictionary:: insert(Bnode *p,string key,string keymeaning){

    if(key<p->word){
        if(p->left!=NULL){
            insert(p->left,key,keymeaning);
        }else{
            p->left=new Bnode(key,keymeaning);
        }
    }else if(key>p->word){
        if(p->right!=NULL){
            insert(p->right,key,keymeaning);
        }else
            p->right=new Bnode(key,keymeaning);
    }else{
        cout<<"\nSame Node cannot be Inserted!\n";
    }
}

void Dictionary::display_asc(Bnode *p){

    if(p->left!=NULL)
        display_asc(p->left);
    cout<<"\n"<<p->word<<"\t--->\t"<<p->meaning;
    if(p->right!=NULL)
        display_asc(p->right);
    
}

void Dictionary::display_desc(Bnode * p){

    if(p->right!=NULL)
        display_desc(p->right);
    cout<<"\n"<<p->word<<"\t--->\t"<<p->meaning;
    if(p->left!=NULL)
        display_desc(p->left);                                                              
}

void Dictionary::search(Bnode* p, string key)
{
	 int count = 0;
	while(p!=NULL)
	{	
         if(key == p->word)
		{   count++;
		    cout<<"\nWord: "<<p->word<<endl<<"Meaning: "<<p->meaning<<endl;
            cout<<"No. of Comparison required : "<<count<<endl;
            return;
		}
	    else if(key < p->word)
		{
			count++;
			p = p->left;
		}

		else if(key > p->word)
		{
			count++;
			p = p->right;
		}

	
	}

	cout<<"\nWord not found!";
}


Bnode *Dictionary::minNode(Bnode * p){
   p=root;
    while(p->left!=NULL){
       
        p=p->left;
    }
    return p;
}

void Dictionary::update_word(Bnode *p,string key){

    while(p!=NULL){
        if(key<p->word)
          {  p=p->left;}
        else if(key>p->word)
           { p=p->right;}
        else if (key==p->word){
            cout<<"\nWord: "<<p->word<<"\nEnter its new meaning! "<<"\n\nMeaning: "<<endl;
            cin>>p->meaning;
            cout<<"\nMeaning updated!";
            return;
        }
    }
    cout<<"\n Word Not Found!";
}


int main(){

    int choice, n;
	string newWord,updateWord, searchWord, newMeaning;
	Dictionary D;
	do{
	cout<<"\n\nDICTIONARY: ";
	cout<<"\n\n1. Insert new words";
	cout<<"\n2. Display the dictionary in ascending order";
	cout<<"\n3. Display the dictionary in descending order";
	cout<<"\n4. update a word";
	cout<<"\n5. Search";
    cout<<"\n6. Exit";
	cout<<"\n\nEnter your choice: ";
	cin>>choice;

    switch(choice){
    
        case 1:cout<<"How many Words do you want to insert: ";
            cin>>n;
            for(int i=0;i<n;i++){
                cout<<"\nEnter  a new word: ";
                cin>>newWord;
                cout<<"Enter its meaining:";
                cin>>newMeaning;

                if(D.root==NULL)
                    D.root= new Bnode(newWord,newMeaning);
                else
                    D.insert(D.root,newWord,newMeaning);  
            }break;
        
        case 2:
                D.display_asc(D.root);
	        	break;
        case 3:
		        D.display_desc(D.root);
		        break;
        case 4: 
                cout<<"\nEnter a word to update its meaning: ";
                cin>>updateWord;
                D.update_word(D.root,updateWord);
                break;
        case 5:
                cout<<"\nEnter a word to search : ";
                cin>>searchWord;
                D.search(D.root,searchWord);
                break;    
   
        case 6: 
                exit(0);
        default:
                cout<<"Invalid Input!";
              
        }
    }while(choice<=6);
    return 0;


}