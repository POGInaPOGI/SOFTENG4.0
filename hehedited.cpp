/* 
References:
https://www.youtube.com/watch?v=U-MfAoL6qjM - Linked list
http://www.cplusplus.com/reference/cctype/isdigit/ - isdigit
http://www.cplusplus.com/reference/cctype/ispunct/ - ispunct
https://stackoverflow.com/questions/17017563/char-array-with-cin-getline - cin.getline()
*/
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
#include<math.h>
#include <ctype.h>
#include<time.h>
#include <stdlib.h>
#include <cstring>
#include<string.h>
#include<fstream>
#include<sstream>
#include<dos.h>


using namespace std;							//standard header

string inputs = "Input project.txt";			//filename for projects details input
string scheds = "Schedule project.txt";			//filename for projects scheduled
string complt = "Completed Project.txt";		//filename for projects completed

struct node{
	int id,size,prio;
	string title;
	node *next;
};

struct soft
{
	int id,search;
	char title[100],size[5],prio[5];
	bool validator; //validates whether true or false
	string temp;
	string word;
};

class que{ //a class for queue
public:
	node* head;
	node* tail;
	que(){
		head=NULL;
		tail=NULL;
	}
	void add(string t,int i,int s,int p){ //add project to the queue
		node* q = new node;
		q->title=t;
		q->id=i;
		q->size=s;
		q->prio=p;
		q->next=NULL;
		if(!head){
			head=q;
		}
		else{
			tail->next=q;
		}
		tail=q;
	}
	void sort(node** pp){ //add sort added projects on the queue
		node *p=*pp;
		*pp=NULL;
		while (p)
		{
	        node** lhs = &p;
	        node** rhs = &p->next;
	        bool swapped = 0;
	    
		    while (*rhs)
			{
	            if ((*rhs)->prio < (*lhs)->prio || (((*rhs)->prio == (*lhs)->prio) && ((*rhs)->size < (*lhs)->size))) {
	                swap(*lhs, *rhs);
	                swap((*lhs)->next, (*rhs)->next);
	                lhs = &(*lhs)->next;
	                swapped = 1;
	            }
	            else {
	                lhs = rhs;
	                rhs = &(*rhs)->next;
	            }
	        }
	        *rhs = *pp;
	        if (swapped) {
	            *pp = *lhs;
	            *lhs = NULL;
	        }
	        else {
	            *pp = p;
	            break;
	        }
	    }
	}
} INPUTS, SCHEDS, COMPLT; //essential for projects input details, projects schedules, projects completed

void reader(const char* f){ //filereader
	fstream r;
	r.open(f,ios::in);
		if(f==inputs.c_str()) INPUTS=que();
		else if(f==complt.c_str()) COMPLT=que();
		else SCHEDS=que();
	
	if(!r){
		r.open(f,ios::out);
		r.close();
		reader(f);
	}
	else{
		while(!r.eof())
		{
			string token[3];
			string title;
			int id, size, prio;
			
			getline(r,token[0],' '); id=atoi(token[0].c_str());
			getline(r,title,' ');
			getline(r,token[1],' '); prio=atoi(token[1].c_str());
			getline(r,token[2],'\n');size=atoi(token[2].c_str());
			
			if(!r.eof()) {
				if(f==inputs.c_str()) INPUTS.add(title,id,prio,size);
				else if(f==complt.c_str()) COMPLT.add(title,id,prio,size);
				else SCHEDS.add(title,id,prio,size);
			}
		}
		r.close();
	}
}
void writer(const char* f){ //filewriter
	fstream w;
	w.open(f,ios::out);
	node* q;
	if(f==inputs) q = INPUTS.head;
	else if(f==complt.c_str()) q = COMPLT.head;
	else q = SCHEDS.head;
	while(q != NULL) {
		w<<q->id<<" "<<q->title<<" "<<q->prio<<" "<<q->size<<endl;
		q=q->next;
	}
	reader(f);
}

void menu(); //Main menu
void InputProject(); // Input Project Details option
void viewA(); // View All Projects
void view1(); // View One Project
void viewC(); // View Completed Projects
void viewS(); // View Updated Schedule
void makeS(); // Create Schedule
void get(); // Get Project
void header(); //Members' names 

//Main Program
int main(){
	reader(inputs.c_str());
	reader(scheds.c_str());
	reader(complt.c_str());
	menu();
}

void menu (){ //Main Menu 
	soft s1;
	while(1){
		X0:	system("cls");
		header();
		cout << "1.  Input Project Details "<< endl;
		cout << "2.  View Projects  " << endl;
		cout << "3.  Schedule Projects  " << endl;
		cout << "4.  Get a Project  "  << endl;
		cout << "5.  Exit"  << endl << endl;	
		cout << "PLEASE CHOOSE YOUR CHOICE: ";
		switch(_getch()){
			case '1': InputProject(); break; //Menu Option 1: Input Project Details
			case '2': 						//Menu Option 2: View Projects
				X1:	system("cls");
					cout << "a.) One Project" << endl;
					cout << "b.) Completed Project" << endl;
					cout << "c.) All Project" <<endl;
					cout << "d.) Go back" <<endl;
					cout << "Choose from the following: " ;
						switch(tolower(_getch())){
						system("cls");
						case 'a': view1(); s1.validator=true; break;
						case 'b': viewC(); s1.validator=true; break;
						case 'c': viewA(); s1.validator=true; break;
						case 'd':  s1.validator=true;break;
						default : break;
					};
				break;
			case '3': 						//Menu Option 3: Schedule Projects
				X2:	system("cls");
					cout << "a.) View Updated Schedule" << endl;
					cout << "b.) Create Schedule" << endl;
					cout << "c.) Go back" << endl;
					cout << "Choose from the following: " ;
					switch(tolower(_getch())){
						system("cls");
						case 'a':viewS();s1.validator=true; break;
						case 'b': makeS();s1.validator=true; break;
						case 'c':s1.validator=true; break;
						default : break;
			};
				break;
			case '4': get(); break;			//Menu Option 4: Get Project
			case '5': exit(0); break;		//Menu Option 5: Exit
			default : goto X0; break;
		}
	}
}
void InputProject(){ 
	system("cls");
	soft s1;
	fstream fileNamen (inputs.c_str());
	s1.id=1;
	s1.validator=false;
	while (fileNamen.getline(s1.title,50,'\n'))s1.id=s1.id+1;
	fileNamen.close();
	
	
	cout << "Enter title: ";
	cin >> s1.title; 
	s1.validator=true;
		
	cout << "Enter a number of pages between 50 to 500: ";
	cin >> s1.size;
	s1.validator=true;
	for (int i=0;i<strlen(s1.size);i++){
		if (isalpha(s1.size[i])||ispunct(s1.size[i])){
			s1.validator =false;
		}
	}
		while(s1.validator==false||atoi(s1.size)<50||atoi(s1.size)>500){
			
		cout << "Invalid number of pages, please try again: ";
		cin >> s1.size;
		s1.validator =true;
			for (int i=0;i<strlen(s1.size);i++){
				if (isalpha(s1.size[i])||ispunct(s1.size[i])){
				s1.validator =false;
				}
			}
		}
	s1.validator=false;
	cout << "Enter the priority of the project : ";
	cin >> s1.prio;
	s1.validator=true;
	
	for (int i=0;i<strlen(s1.prio);i++){
		if (isalpha(s1.prio[i])||ispunct(s1.prio[i])){
			s1.validator = false;
		}
	}
	
	while (s1.validator==false||atoi(s1.prio)<=0){
	
		cout << "Invalid number of priority please try again: ";
		cin >> s1.prio;
		s1.validator=true;
		for (int i=0;i<strlen(s1.prio);i++){
			if (isalpha(s1.prio[i])||ispunct(s1.prio[i])){
				s1.validator =false;
			}
		}	
	}
	fileNamen.open(inputs.c_str(),ios::app);
	fileNamen << s1.id << " " << s1.title << " " <<s1.size << " " << s1.prio << endl;
	fileNamen.close();
	
cout << left<< setw(7)<< "ID" << "\t" << "title"<< setw(26) << "\t" << "No. of Pages"<< setw(8) << "\t" << "Priority Number" << endl;
cout << left << setw(7) << s1.id << "\t" << s1.title << setw(22) << "\t" << s1.size << setw(22) << "\t" << s1.prio << endl; 
	reader(inputs.c_str());
	system("pause");
}
void viewA(){
	system("cls");
	cout<<"ID:    Title:                    No. of Pages:  Priority Number:\n";
	node* q = INPUTS.head;
	while (q != NULL)
	{
		cout<<left<<setw(7)<<q->id<< "\t"<<setw(26)<<q->title<<setw(8)<< ""<<q->size<<setw(13)<< ""<<q->prio<<"\n";
		q=q->next;
	}
	system("pause");
}
void viewC(){
	system("cls");
	cout<<"ID:    Title:                    No. of Pages:  Priority Number:\n";
	node* q = COMPLT.head;
	while (q != NULL)
	{
		cout<<left<<setw(7)<<q->id<<setw(26)<<q->title<<setw(8)<< ""<<q->size<<setw(13)<< ""<<q->prio<<"\n";
		q=q->next;
	}
	system("pause");
}
void view1(){
	system("cls");
	fstream fileNamen(inputs.c_str());
	soft s1;
	
	cout << "Enter the ID number of the project to be searched: ";
	cin >> s1.search;
	
	while (fileNamen>>s1.id>>s1.title>>s1.size>>s1.prio){
		if(s1.search==s1.id){
			break;
		}
	}
	if (s1.search==s1.id) {
			
		cout<<endl<<"ID:    Title:                    No. of Pages:  Priority Number:\n";
		cout<<left<<setw(7)<<s1.id<<setw(26)<<s1.title<<setw(8)<< ""<<s1.size<<setw(13)<< ""<<s1.prio<<"\n";}
	else 
		cout << "ID NOT FOUND" << endl;
		cout << endl;
	system("pause");
}
void viewS(){
	system("cls");
	cout<<"ID:    Title:                    No. of Pages:  Priority Number:\n";
	node* q = SCHEDS.head;
	while (q != NULL)
	{
		cout<<left<<setw(7)<<q->id<<setw(26)<<q->title<<setw(8)<< ""<<q->size<<setw(13)<< ""<<q->prio<<"\n";
		q=q->next;
	}
	system("pause");
}
void makeS(){
	SCHEDS = que();
	node* dp = INPUTS.head;
	while(dp)
	{
		bool f=0;
		node* ok = COMPLT.head;
		if(!ok) f=1;
		else
		{
			while(ok && !f) {
				if(dp->id==ok->id) ok=ok->next;
				else f=1;
			}
		}
		if(f) SCHEDS.add(dp->title,dp->id,dp->size,dp->prio);
		dp=dp->next;
	}
	
	SCHEDS.sort(&SCHEDS.head);
	writer(scheds.c_str());
	cout<<"\nSchedule Created\n";
	system("pause");
	viewS();
}
void get(){
	node* toget = SCHEDS.head;
	if(toget)
	{
		COMPLT.add(toget->title,toget->id,toget->size,toget->prio);
		cout<<"\nProject "<<toget->title<<" has been completed.\n";
		SCHEDS.head=toget->next;
		writer(scheds.c_str());
		writer(complt.c_str());
	}
	else cout<<"\nNo scheduled projects yet\n";
	system("pause");
}
void header(){
	cout << "\t\t\t    John Mheynard Azuela" << "   " << "John Marklenard Macatangay" << "   "<< "Smith Ramoy" << endl;
	cout << "_______________________________________________________________________________________________________________________";
	cout << endl << "\t\t\t\t\t\tM A I N  M E N U" << endl;
	cout << "_______________________________________________________________________________________________________________________" << endl << endl;
}
