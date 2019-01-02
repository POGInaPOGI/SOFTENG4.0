#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include <stdlib.h>
#include <cstring>
#include<string.h>
#include<fstream>
#include<sstream>

using namespace std;

struct node{
	
};

struct soft
{
	int id,search;
	char title[100],size[5],prio[5];
	bool validator;
	string temp;
	string word;
};

int choice ();
void menu();
void InputProject();
void viewA();
void viewC();
int main(){
	while (1){
		system("cls");
	menu();
	choice();
	}
}

int choice (){
	char choice;
	
	cin >> choice;
	system("cls");
	switch(choice){
		case '1': InputProject();  break;
				
		case '2':	system ("cls");
				cout << "a.) One Project" << endl;
				cout << "b.) Completed Project" << endl;
				cout << "c.) All Project" <<endl;
				cout << "Choose from the following: " ;
				cin >> choice;
				system("cls");
				switch (choice){
					case 'a':
					case 'A': viewA(); break;
					case 'b': 
					case 'B': break;
					case 'c':
					case 'C': viewC(); break;
					default : break;
				}; break;
			
		case '3': cout<<"3"<<endl ; break;
			
		case '4':	cout<<"4"<<endl ; break;
			
		case '5':	exit(0); break;
			
		default: cout<<"default" <<endl;
	}
	
}

void menu (){
	cout <<"Menu" << endl;
	cout << "[1] - Input Project Details "<< endl;
	cout << "[2] - View Projects  " << endl;
	cout << "[3] - Schedule Projects  " << endl;
	cout << "[4] - Get a Project  "  << endl;
	cout << "[5] - Exit"  << endl << endl;
	
	cout << "PLEASE CHOOSE YOUR CHOICE: ";
		
	
}

void InputProject(){
	soft s1;
	fstream fileNamen ("Input.txt");
	s1.id=1;
	s1.validator=false;
	while (fileNamen.getline(s1.title,50,'\n'))s1.id=s1.id+1;
	fileNamen.close();
	
	fileNamen.open("Input.txt",ios::app);

	cout << "Enter title: ";
	cin >> s1.title;
	
	cout << "Enter a number of pages between 50 to 500: ";
	cin >> s1.size;
	s1.validator=true;
	for (int i=0;i<strlen(s1.size);i++){
		if (isalpha(s1.size[i])){
			s1.validator =false;
		}
	}
		while(s1.validator==false||atoi(s1.size)<50||atoi(s1.size)>500){
			
		cout << "Invalid number of pages, please try again: ";
		cin >> s1.size;
		s1.validator =true;
			for (int i=0;i<strlen(s1.size);i++){
				if (isalpha(s1.size[i])){
				s1.validator =false;
				}
			}
		}
	s1.validator=false;
	cout << "Enter the priority of the project : ";
	cin >> s1.prio;
	s1.validator=true;
	
	for (int i=0;i<strlen(s1.prio);i++){
		if (isalpha(s1.prio[i])){
			s1.validator =false;
		}
	}
	
	while (s1.validator==false||atoi(s1.prio)<=0){
	
		cout << "Invalid number of priority please try again: ";
		cin >> s1.prio;
		s1.validator=true;
		for (int i=0;i<strlen(s1.prio);i++){
			if (isalpha(s1.prio[i])){
				s1.validator =false;
			}
		}	
	}
	
	fileNamen << s1.id << "\t" << s1.title << "\t" <<s1.size << "\t" << s1.prio << endl;
	fileNamen.close();
	
	cout << "ID" << "\t" << "title" << "\t" << "no. pages" << "\t" << "Prio. Level" << endl;
	cout << s1.id << "\t" << s1.title << "\t" <<s1.size << "\t\t" << s1.prio << endl;
	cout << "Press any key to continue";
	getch();
}
	
void viewA(){
	fstream fileNamen("Input.txt");
	soft s1;
	
	cout << "Enter the ID of the project to be searched: ";
	cin >> s1.search;
	
	while (fileNamen>>s1.id>>s1.title>>s1.size>>s1.prio){
		if(s1.search==s1.id){
			break;
		}
	}
	if (s1.search==s1.id) 
		cout << "ID: " << s1.id << "\t" << "Title: " << s1.title << "\t" << "Pages: " << s1.size << "\t" << "Prioty Level: " << s1.prio<<endl;
	else 
		cout << "ID NOT FOUND" << endl;
		
	cout << "Press any key to continue";
	getch();
}

void viewB(){
	soft s1;
	fstream fileNamen("Completed.txt");	
	cout << "ID" << "\t" << "title" << "\t" << "no. pages" << "\t" << "Prio. Level" << endl;
	while(fileNamen>>s1.id>>s1.title>>s1.size>>s1.prio){
		cout << s1.id << "\t" << s1.title << "\t" <<s1.size << "\t\t" << s1.prio << endl;
	}
	cout<<"Press any key to continue";
	getch();
	
	fileNamen.close();
}

void viewC(){
	soft s1;
	fstream fileNamen("Input.txt");	
	cout << "ID" << "\t" << "title" << "\t" << "no. pages" << "\t" << "Prio. Level" << endl;
	while(fileNamen>>s1.id>>s1.title>>s1.size>>s1.prio){
		cout << s1.id << "\t" << s1.title << "\t" <<s1.size << "\t\t" << s1.prio << endl;
	}
	cout<<"Press any key to continue";
	getch();
	
	fileNamen.close();
	
}
