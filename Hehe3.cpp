// references https://www.youtube.com/watch?v=U-MfAoL6qjM - linked list
// http://www.cplusplus.com/reference/cctype/isdigit/ - isdigit
// http://www.cplusplus.com/reference/cctype/ispunct/ - ispunct
//https://stackoverflow.com/questions/17017563/char-array-with-cin-getline - cin.getline(
// http://www.cplusplus.com/reference/cctype/tolower/ 

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <ctype.h>
#include<time.h>
#include <stdlib.h>
#include <cstring>
#include<string.h>
#include<fstream>
#include<sstream>
#include<iomanip> //for setw()
using namespace std;

string inputs = "inputs.txt";
string scheds = "scheds.txt";
string complt = "complt.txt";

struct node{
	int id,size,prio;
	string title;
	node *next;
};

struct soft
{
	int id,search;
	char title[100],size[5],prio[5];
	bool validator;
	string temp;
	string word;
};

class que{
public:
	node* head;
	node* tail;
	que(){
		head=NULL;
		tail=NULL;
	}
	void add(string t,int i,int s,int p){
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
	void sort(node**);
} INPUTS, SCHEDS, COMPLT;

void reader(const char* f){
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
void inp(const char* i){
	fstream w;
	w.open(i,ios::out);
	node* q;
	if(i==inputs) q = INPUTS.head;
	else if(i==complt.c_str()) q = COMPLT.head;
	else q = SCHEDS.head;
	while(q != NULL) {
		w<<q->id<<" "<<q->title<<" "<<q->prio<<" "<<q->size<<endl;
		q=q->next;
	}
	reader(i);
}

void menu();
void InputProject();
void viewA();
void view1();
void viewC();
void viewS();
void makeS();
void get();

int main(){
	reader(inputs.c_str());
	reader(scheds.c_str());
	reader(complt.c_str());
	menu();
}

void menu (){
	soft s1;
	while(1){
		system("cls");
		cout << "Menu" << endl;
		cout << "1.  Input Project Details "<< endl;
		cout << "2.  View Projects  " << endl;
		cout << "3.  Schedule Projects  " << endl;
		cout << "4.  Get a Project  "  << endl;
		cout << "5.  Exit"  << endl << endl;	
		cout << "PLEASE CHOOSE YOUR CHOICE: ";
		s1.validator=false;
		switch(_getch()){
			case '1': InputProject(); break;
			case '2':;
			while(s1.validator==false){
			system("cls");
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
			}	
					};
				break;
			case '3': 
			while(s1.validator==false){
			system("cls");
					system("cls");
					cout << "a.) View Schedule" << endl;
					cout << "b.) Create Schedule" << endl;
					cout << "c.) Go back" << endl;
					cout << "Choose from the following: " ;
					switch(tolower(_getch())){
						system("cls");
						case 'a':viewS();s1.validator=true; break;
						case 'b': makeS();s1.validator=true; break;
						case 'c':s1.validator=true; break;
						default : break;
			}
					};
				break;
			case '4': get(); break;
			case '5': exit(0); break;
			default : break;
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
	
	fileNamen.open(inputs.c_str(),ios::app);

	cout << "Enter title without spaces: ";
	cin>> s1.title;
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
	
	fileNamen << s1.id << setw(15) << s1.title << setw(15) << s1.size << setw(15) << s1.prio << endl;
	fileNamen.close();
	
	cout << "ID" << setw(15) << "Title" << setw(15) << "No. pages" << setw(15) << "Prio. Level" << endl;
	cout << s1.id << setw(13) << s1.title << setw(15) << s1.size << setw(13) << s1.prio << endl;
	reader(inputs.c_str());
	system("pause");
}
void viewA(){
	system("cls");
	cout << "ID" << setw(15) << "Title" << setw(15) << "No. pages" << setw(15) << "Prio. Level" << endl;
	node* q = INPUTS.head;
	while (q != NULL)
	{
		cout<<q->id << setw(13) << q->title << setw(15) << q->size << setw(13) << q->prio<<endl;
		q=q->next;
	}
	system("pause");
}
void viewC(){
	system("cls");
	soft s1;
	fstream fileNamen("complt.txt");	
cout << "ID" << setw(15) << "Title" << setw(15) << "No. pages" << setw(15) << "Prio. Level" << endl;
	while(fileNamen>>s1.id>>s1.title>>s1.size>>s1.prio){
		cout << s1.id  << setw(13) << s1.title << setw(15) << s1.size << setw(13) << s1.prio << endl;
	}
	cout<<"Press any key to continue";
	getch();
	
	fileNamen.close();
	
}
void view1(){
	system("cls");
	fstream fileNamen(inputs.c_str());
	soft s1;
	
	cout << "Enter the ID of the project to be searched: ";
	cin >> s1.search;
	
	while (fileNamen>>s1.id>>s1.title>>s1.size>>s1.prio){
		if(s1.search==s1.id){
			break;
		}
	}
	if (s1.search==s1.id) 
		cout << "ID: " << s1.id << setw(15) << "Title: " << s1.title << setw(15) << "Pages: " << s1.size << setw(15) <<  "Priority Level: " << s1.prio<<endl;
	else 
		cout << "ID NOT FOUND" << endl;
		
	system("pause");
}
void viewS(){
	system("cls");
	cout<<"ID:" << setw(15) << "Title:" << setw(15) << "Pages:" << setw(15) << "Priority Lvl:" << endl;
	node* q = SCHEDS.head;
	while (q != NULL)
	{
		cout<<q->id  << setw(13) << q->title  << setw(14) << q->size << setw(13) <<q->prio<<endl;
		q=q->next;
	}
	system("pause");
}
void makeS(){
	SCHEDS = que();
	node* dp = INPUTS.head;
	bool f = 0;
	while(dp)
	{
		node* ok = COMPLT.head;
		
		if (ok!=NULL)
		{
			if(dp->id==ok->id) ok=ok->next;
			else f=1;
		}
		else f=1;
		if(f) SCHEDS.add(dp->title,dp->id,dp->size,dp->prio);
		dp=dp->next;
	}
	
	system("cls");
	SCHEDS.sort(&SCHEDS.head);
	inp(scheds.c_str());
	cout<<"Schedule Created\n";
	system("pause");
}
void get(){
	node* toget = SCHEDS.head;
	if(toget)
	{
		COMPLT.add(toget->title,toget->id,toget->size,toget->prio);
		cout<<"Project "<<toget->title<<" has been completed." << endl;
		SCHEDS.head=toget->next;
		inp(scheds.c_str());
		inp(complt.c_str());
	}
	else cout<<"No scheduled projects yet" << endl;
	system("pause");
}

void que :: sort(node** pp){
	node *p=*pp;
	pp=NULL;
	while (p)
	{
        node** lhs = &p;
        node** rhs = &p->next;
        bool swapped = 0;
    
	    while (*rhs)
		{
            if ((*rhs)->prio < (*lhs)->prio || ((*rhs)->prio == (*lhs)->prio && (*rhs)->size < (*lhs)->size)) {
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
