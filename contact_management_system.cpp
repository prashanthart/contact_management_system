//Contact management system
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
class contact{
	public:
		
		char name[50];
		long long num;
		char address[50];
	
		
			void getdata(){
				fflush(stdin);
				cout<<"Name          : ";
				cin.getline(name,50);
				cout<<"Phone(mobile) : ";
				cin>>num;
				cin.ignore();
				cout<<"Address       : ";
				cin.getline(address,50);
				system("cls");
				
			}
			void putdata(){
				cout<<"  \n___________________________\n";
				cout<<"  Name          : "<<name<<endl;
				cout<<"  Phone(mobile) : "<<num<<endl;
				cout<<"  Address       : "<<address;
					
			}
	
};

int main_menu();
int count=0;
int main(){
	int col,flag=0,select,k,f=1;
	string sname;

string pas="1234";
string pass;
char value;
	contact a[60];
	int i=0,j;
	cout<<"\n\t\t\t\t\tCONTACT MANAGEMENT SYSTEM\n";
	cout<<"\t\t\t\t\t-------------------------\n\n";
		cout<<"\n  Admin : you can Edit/Delete an existing contact(pass : 1234)"<<endl;
		start :
	cout<<"  select you as\n  [1] Admin"<<endl;
	cin>>select;

 if(select==1)
{
	label:
cout<<"  you selected as Admin\nEnter the password : ";
cin>>pass;
if(pass!=pas)
{
	cout<<"  invalid-  if you forgot the password enter [1] : ";
	cin>>value;
	if(value=='1'){
	
	cout<<"Enter new password (integer number)  : ";
	cin>>pas;
	goto label;
}
	else
	goto label;
}
}
system("cls");
if(pass==pas || select==1)
{

	do{
  	col=main_menu();

	switch(col)
	{
		case 1 : //Add new contacts
		 system("cls");
		         cout<<"\n\nEnter the details\n";
		         cout<<"-----------------------\n";
		        
		         if(select==1)
		        {
		         a[count].getdata();
		         i++;
		         count++;
		         cout<<"\n______________________________\n";
		         cout<<"successfully a contact is added\n";
		         cout<<"--------------------------------\n";
		        }

		         break;
		case 2 : // View all contacts
		         system("cls");
		        if(count==0)
		        {
		        	system("cls");
		        	cout<<"\n-----------------------------\n";
		        	cout<<"There is no list of contacts\n";
		        	cout<<"------------------------------\n";
				}
		          for(j=0;j<count;j++)
		          {
		          	a[j].putdata();
				  }
				  break;
		case 3 : //search a contact
		         cout<<"--->enter a name to search : ";
		         cin.ignore();
		         getline(cin,sname);
		         system("cls");
		         for(int i=0;i<count;i++)
		         {
		         	
		         	
		         	if(sname==a[i].name)
		         	{
		         		a[i].putdata();
		         		flag=1;
					 }
				 }
				 if(flag==0 )
				 {
				 	cout<<"\n---------------------\n";
				 	cout<<"contact does not exist";
				 	cout<<"\n---------------------";
				 }
				 break;
		case 4 : //Edit the contact

		         if(select==1)
		         {
				 
		         cout<<"--->Enter a name to edit the contacts : ";
		          flag=0;
		          cin.ignore();
		          getline(cin,sname);
		          for(int i=0;i<count;i++)
		          {
		          	if(sname==a[i].name)
		          	{
					  
		          	a[i].getdata();
		          	flag=1;
		            }
		            
		            if(flag==1)
		            {
					cout<<"\n---------------------\n";
		            cout<<"contact updated";
		            cout<<"\n----------------------";
		            break;
		        }
				  }
				  if(flag==0)
				  {
				  	system("cls");
				  	cout<<"\n---------------------";
				  	cout<<"\nenter a correct name";
				  	cout<<"\n----------------------";
				  }
			}
			else
			{
			  cout<<"--->Login as admin to edit the contacts \n";
		        	goto start;
			}
				  break;
				  
	    case 5 : //Delete the contact
		          if(select==1)
	              {
		          cout<<"--->Enter a name to delete that contact: ";
		          flag=0;
	             cin.ignore();
	             getline(cin,sname);
	             for(int i=0;i<count;i++)
	             {
	             	if(sname==a[i].name)
	             	{
	             		k=i;
	             		while(k<count)
						 {
						 
	             			a[k]=a[k+1];
	             			k++;
	             	     }
	             			flag=1;
	             			system("cls");
	             	        cout<<"\n -------------------------";
	             			cout<<"\n successfully deleted    "<<endl;
	             			cout<<" -------------------------\n";
	             	     count--;
					 }
				 }
				 if(flag==0)
				 {
				 	system("cls");
				 	cout<<"\n-------------------------------------------------";
				  	cout<<"\nEnter a correct name (or) Contact does not exist";
				  	cout<<"\n-------------------------------------------------";
				 }
			}
			else
			{
				cout<<"--->login as admin to delete the contacts\n";
				goto start;
			}
	             break;
	      case 6 : 

                 system("cls");
	      break;
	      case 7 : break;
	      default : 
	      f=0;
	      cout<<"invalid option";
	      break;
	}

if(f==0)
{
	break;
}
}while(col!=7);
}

	return 0;
}


int main_menu() //main menu
{
	int x;
	cout<<"\n";
	cout<<"					        MAIN MENU"<<endl;
	cout<<"					------------------------"<<endl;
	cout<<"					[1] Add a new contact"<<endl;
	cout<<"					[2] List all contacts"<<endl;
	cout<<"					[3] Search for contacts"<<endl;
	cout<<"					[4] Edit a contact"<<endl;
	cout<<"					[5] Delete a contact"<<endl;
	cout<<"					[6] clear screen"<<endl;
	cout<<"					[7] Exit"<<endl;
	cout<<"choose your option : ";
	cin>>x;
	return x;	
}
