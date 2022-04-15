#include<iostream>
#include "binarySearchTree.h"
using namespace std;

int main(){

    Btree BtreeObj;
 
    char ans='y'; 
   int choice;

   do{
     cout<<"\n0] Create a new tree \n1] Insert Node into existing Tree \n2] recursive inorder \n3] recursive preorder \n4] recursive postorder \n5] Height of BST \n6] Search \n7] Nodes in Longest path \n8] Minimum node in tree";
   cout<<"\nEnter your choice:";
   cin>>choice;
   switch(choice){

    case 0:
                BtreeObj.intializeRootNode();
             
                while(ans=='y'){
                
                cout<<"\nDo you want to insert more nodes(n-no,y-yes): ";
                cin>>ans;
                if(ans=='n')break;
                BtreeObj.insertNewNode();
                }
                break;
    case 1:     BtreeObj.insertNewNode();
                break;
  
    case 2:     BtreeObj.display(1);
                cout<<endl;
                break;
    case 3:     BtreeObj.display(2);
                cout<<endl;
                break;
    case 4:     BtreeObj.display(3);
                cout<<endl;
                break;
    case 5:     
                cout<<"\n Height of current BST is: "<<BtreeObj.height(BtreeObj.rootNode);
                break;      
    case 6:     int k;
                cout <<"Enter the key you want to search: ";
                cin>>k;
                BtreeObj.search(k);
                break;
    case 7:     break;
    case 8:
                cout<<"Minimum node in a tree: "<<BtreeObj.min();
                break;
      

   } }while(choice<7);
   
 

    return 0;

}