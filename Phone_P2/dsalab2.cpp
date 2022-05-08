#include<iostream>
#include<cstring>
using namespace std;
# define Max 10

class phdetail{
       
       public:
        string name;
        long int phno;
        bool IsEmpty=true;
        
};



class phbook{
        phdetail ph[Max];
	//int hashtable[Max];
	public:
			 phbook(){
				for(int i=0;i<Max;i++)	
				{
					ph[i].name="none";
					ph[i].phno=0;
				}			
			}
			void display(){
			        cout<<"  Contact Name   Number "<<endl;
				for(int i=0;i<Max;i++)	
				{       
					cout<<i<<"= "<<ph[i].name<<"   "<<ph[i].phno<<endl<<endl;
				}		
			}
			int hash(string name){
      int sum = 0;
        for (int k = 0; k < name.length(); k++)
            sum = sum + int(name[k]);
        return  sum % Max; 
		}
	
			void insert();
			void search();
			void delete1();
			void qinsert();
			void qsearch();
			void qdelete();
};//end of class

void phbook::insert(){

				int pos;
				bool flag=false;
				string name;
				long int phone; 
				cout<<"\nEnter the name And phone number respectively seperated by space: ";
				cin>>name>>phone;
			
				pos=hash(name);
		
			if(ph[pos].IsEmpty){
					ph[pos].name=name;
					ph[pos].phno=phone;
					ph[pos].IsEmpty=false;
					flag=true;
					}
			else
			    {
						for(int i=(pos+1)%Max; i!=pos; i=(i+1)%Max){
							if(ph[i].IsEmpty){
							      ph[i].name=name;
					                      ph[i].phno=phone;
					                      ph[i].IsEmpty=false;
					                      flag=true;
							      break;
							 }	
						} 
		if(flag) {
		    cout<<"Inserted Successfully";
                    cout<<"\n After Inserting.....\n";
		    display();
		}				                   
		else if(flag==false)
	        {cout<<"\nHash Table is Full";}
						
					}
		
  display();
}
void phbook::search(){
        bool flag=false;
        string name;
        cout<<"\n Enter the Contact name: ";
        cin>>name;
		int pos;
		int cnt=1;
		pos=hash(name);
			if(ph[pos].name==name){
				cout<<"\n Contact Name:  "<<ph[pos].name<<"\nContact Number: "<<ph[pos].phno<<endl;
					cout<<"No. of comparison:"<<cnt<<endl;
					flag=true;
					}
			else 
					{
						for(int i=(pos+1)%Max; i!=pos; i=(i+1)%Max){
						 cnt++;	
						if(ph[i].name==name){
						cout<<"\n Contact Name:  "<<ph[i].name<<"\nContact Numbe: "<<ph[i].phno<<endl;
					        cout<<"No. of comparison:"<<cnt<<endl;
								flag=true;
								break;
							 }

						}

					}
		   if(flag==false)
			{
                         cout<<"\nElement not found!";
			}
		
}//end of search

void phbook:: delete1(){
        bool flag=false;
        string name;

        cout<<"\n Enter the Contact name to delete : ";
        cin>>name;
		int pos;
		int cnt=1;
		pos=hash(name);
			if(ph[pos].name==name){
				cout<<"\n Contact Name:  "<<ph[pos].name<<"\nContact Number: "<<ph[pos].phno<<endl;
			
					ph[pos].name="none";
					ph[pos].phno=0;
					    ph[pos].IsEmpty=true;
				flag=true;
				
					}
		         else         
					{
					for(int i=(pos+1)%Max; i!=pos; i=(i+1)%Max){
						 
						if(ph[i].name==name){
				                 cout<<"\n Contact Name:  "<<ph[i].name<<"\nContact Number: "<<ph[i].phno<<endl;
					        ph[i].name="none";
					        ph[i].phno=0;
						ph[i].IsEmpty=true;	
			                                        flag=true;						
								break;
							 }
						}

					}
		if(flag){
		
			cout<<"\n Deleted Successfully...."<<endl;}
		else
		{cout<<"Element not Found!"<<endl;}
				 
				 
				display();
}//end of delete

void phbook::qinsert(){
                                
             int pos;
             bool flag=false;
       	string name;
	long int phone; 
	cout<<"\nEnter the name And phone number respectively seperated by space: ";
	cin>>name>>phone;
			
	pos=hash(name);
		
			if(ph[pos].IsEmpty){
					ph[pos].name=name;
					ph[pos].phno=phone;
					ph[pos].IsEmpty=false;
					flag=true;
					}
		else 
			{
			for(int i=0; i<Max;i++){
			        int h = (pos+i*i)%Max;//quadratic probing hash function
			       	if(ph[h].IsEmpty){
					        ph[h].name=name;
					        ph[h].phno=phone;
							ph[h].IsEmpty=false;	
			                flag=true;						
					        break;
							 }	
			}
			}

		
			if(flag) {
		    cout<<"Inserted Successfully";
                    cout<<"\n After Inserting.....\n";
		    display();}
						                   
		else 
	        {cout<<"\nHash Table is Full";}
						
		display();			
					
		
}//end of qinsert

void phbook::qsearch(){

		 bool flag=false;
        string name;
        cout<<"\n Enter the Contact name: ";
        cin>>name;
	int pos;
	int cnt=1;
	pos=hash(name);
	if(ph[pos].name==name){
	        cout<<"\n Contact Name:  "<<ph[pos].name<<"\nContact Number: "<<ph[pos].phno<<endl;
	        cout<<"No. of comparison:"<<cnt<<endl;
	        flag=true;
			}
	else 
		{
		for(int i=0; i<Max;i++){
		int h = (pos+i*i)%Max;
		cnt++;		
		      if(ph[i].name==name){
		        cout<<"\n Contact Name:  "<<ph[i].name<<"\nContact Numbe: "<<ph[i].phno<<endl;
			 cout<<"No. of comparison:"<<cnt<<endl;
	                flag=true;
		break;
			 }

		}

	}
	if(flag==false)
	 {cout<<"Element not Found!"<<endl;}
				
				
}//end of qsearch

void phbook:: qdelete(){
               bool flag=false;
        string name;
        cout<<"\n Enter the Contact name to delete : ";
        cin>>name;
		int pos;
		int cnt=1;
		pos=hash(name);
			if(ph[pos].name==name){
				cout<<"\n Contact Name:  "<<ph[pos].name<<"\nContact Number: "<<ph[pos].phno<<endl;
				ph[pos].name="none";
				ph[pos].phno=0;
			         ph[pos].IsEmpty=true;
				flag=true;
				
					}
		   else 
					{
						for(int i=0; i<Max;i++){
						int h = (pos+i*i)%Max;
						 cnt++;
						if(ph[h].name==name){
				                 cout<<"\n Contact Name:  "<<ph[h].name<<"\nContact Number: "<<ph[h].phno<<endl;
					        ph[h].name="none";
					        ph[h].phno=0;
					         cout<<"No. of comparison:"<<cnt<<endl;
						ph[h].IsEmpty=true;	
			                        flag=true;						
					                break;
							 }
						}

					}
		if(flag){
			cout<<"\n Deleted Successfully...."<<endl;}
		else
		{cout<<"Element not Found!"<<endl;}
			
		display();
}//end of qdelete

void linearProb(){
	phbook ht;
	ht.display();
	int choice;
	do{
			cout<<" \nMenu\n1] Insert \n2] Search \n3] Delete \n4]Display \n5] Exit \n "<<endl;	
			cout<<"Enter your choice: ";
			cin>>choice;
			switch(choice){
			
				case 1:
						ht.insert();		
						break;
				case 2: ;
						ht.search();
						break;
				case 3: 
						ht.delete1();
						break;
						
				case 4:         ht.display();
				                break;
				case 5: cout<<"Exiting.....\n\n";
						exit(0);
                default: cout<<"Invalid Choice. ";
			}
	
	}while(true);

}//end of Linear probing


void quadProb(){
	phbook ht;
	ht.display();
	bool loop=true;
	int choice;
	do{
			cout<<" \nMenu\n1]Insert \n2] Search \n3]Delete \n4]Display \n5]Exit \n "<<endl;	
			cout<<"Enter your choice: ";
			cin>>choice;
			switch(choice){
			
				case 1:
					    ht.qinsert();		
				            break;
				case 2: 
					    ht.qsearch();
					    break;
				case 3:
					    ht.qdelete();
						break;
				case 4: ht.display();
				        break;
				case 5: cout<<"Exiting.....";
						loop=false;
				default: cout<<"Invalid ";
			}
	
	}while(loop);
	
}

int main(){

	int choice;
	do{
			cout<<" \nMenu\n1]Linear Probing \n2] Quadratic probing\n3]Exit "<<endl;	
			cout<<"Enter your choice: ";
			cin>>choice;
			switch(choice){
			
				case 1: 
						linearProb();				
						 
						  break;
				case 2:  
						quadProb();
							break;
				case 3: exit(0);
      }
   }while(true);
return 0;

}





