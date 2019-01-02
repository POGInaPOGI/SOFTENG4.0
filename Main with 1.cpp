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


int choice ();
void menu();
void InputProject();

int main(){
	while (1){
	
	menu();
	choice();
	}
}

int choice (){
	string title,line;
	int idnum,size,priority;
	int choice;
	char a,b,c,cas2;
	
	cin >> choice;
	switch(choice){
		system("cls");
		case 1: InputProject();  break;
				
		case 2:	cout<<"2"<<endl ; break;
			
		case 3: cout<<"3"<<endl ; break;
			
		case 4:	cout<<"4"<<endl ; break;
			
		case 5:	exit(0); break;
			
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
	fstream fileNamen;
	fileNamen.open("Input.txt");
	int id=1;
	char title[100],pages[4],prio[4];
	bool validator=false;
	while (fileNamen.getline(title,50,'\n'))id=id+1;
	fileNamen.close();
	
	fileNamen.open("Input.txt",ios::app);

	cout << "Enter title: ";
	cin >> title;
	
	cout << "Enter a number of pages between 50 to 500: ";
	cin >> pages;
	validator=true;
	for (int i=0;i<strlen(pages);i++){
		if (isalpha(pages[i])){
			validator =false;
		}
	}
		while(validator==false||atoi(pages)<50||atoi(pages)>500){
			
		
		cout << "Invalid number of pages, please try again: ";
		cin >> pages;
		validator =true;
		
			for (int i=0;i<strlen(pages);i++){
				if (isalpha(pages[i])){
				validator =false;
				}
			}
		}
	validator=false;
	cout << "Enter the priority of the project : ";
	cin >> prio;
	validator=true;
	
	for (int i=0;i<strlen(prio);i++){
		if (isalpha(prio[i])){
			validator =false;
		}
	}
	
	while (validator==false||atoi(prio)<0){
	
		cout << "Invalid number of priority please try again: ";
		cin >> prio;
		
		for (int i=0;i<strlen(prio);i++){
			if (isalpha(prio[i])){
				validator =false;
			}
		}
	}
	
	fileNamen << id << "\t" << title << "\t" <<pages << "\t" << prio << endl;
	fileNamen.close();
	
	cout << "ID" << "\t" << "title" << "\t" << "no. pages" << "\t" << "Prio. Level" << endl;
	cout << id << "\t" << title << "\t" <<pages << "\t" << prio << endl;
	
}
	
	


