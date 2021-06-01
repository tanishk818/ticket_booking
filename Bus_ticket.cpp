#include <iostream>
#include <windows.h>
#include<time.h>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
#define row 10
#define col 50
FILE *fp;
void gotoxy(short x, short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
//print_bus() prints the bus outline 
void print_bus()
{
	gotoxy(1+col,1+row);
 printf("____________________________________________________________");
 for(int i=2;i<13;i++){//96//
 gotoxy(61+col,i+row);
 printf("|\n");}
for(int i=2;i<13;i++)
{
gotoxy(0+col,i+row);
 printf("|\n");}
gotoxy(1+col,12+row);
 printf("____________________________________________________________");
}
// print_seat() prints filled and unfilled seats in the bus
// filled seat is represented by [X] 
// unfilled seat is represented by [Seat_Number].Seat_Number lies in the range between 1 to 50.
void print_seat(int arr[],int n)
{
	int j=8;
	for(int i=1;i<11;i++){
	gotoxy(j+col,2+row);
	if(arr[i-1]==1) // arr is  data structure with arr[i]=1 represents filled seat. On the other hand arr[i]=0 represents unfilled one
		printf("[X]");
	else
 		printf("[%d]",i);
 j+=5;
}
j=8;
for(int i=1;i<11;i++){
	gotoxy(j+col,3+row);
 	if(arr[i+9]==1)
		printf("[X]");
	else
 		printf("[%d]",i+10);
 j+=5;
}
j=8;
for(int i=1;i<11;i++){
	gotoxy(j+col,4+row);
 	if(arr[i+19]==1)
		printf("[X]");
	else
 		printf("[%d]",i+20);
 j+=5;
}
j=8;
for(int i=1;i<11;i++){
	gotoxy(j+col,9+row);
 	if(arr[i+29]==1)
		printf("[X]");
	else
 		printf("[%d]",i+30);
 j+=5;
}
j=8;
for(int i=1;i<11;i++){
	gotoxy(j+col,10+row);
	 if(arr[i+39]==1)
		printf("[X]");
	else
 		printf("[%d]",i+40);
 j+=5;
}

}
// array_counter returns the number of filled seats in the bus.
int array_counter(int arr[],int n)
{
	int m=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==1)
		m+=1;
	}
	return m;
}
// print_ch prints character ch n number of times in a row.
void print_ch(char ch,int n){
	for(int i=0;i<n;i++)
		cout<<ch;
}
// print_hist print the information of temp data structure and prints it.
void print_hist(vector<string>& temp)
{	
	string date=temp[1];
	string name=temp[0];
	string age=temp[2];
	string mobile=temp[3];
	string gender=temp[4];
	vector<int> arr1;
	for(int i=6;i<temp.size();i++)
		arr1.push_back(stoi(temp[i]));
	cout<<endl<<" ";
	print_ch('_',90);
	cout<<endl<<"|";
	print_ch(' ',40);
	cout<<"XYZ AGENCY";
	print_ch(' ',40);
	cout<<"|"<<endl<<"|";
	print_ch(' ',36);
	cout<<"TICKET INFORMATION ";
	print_ch(' ',35);
	cout<<"|"<<endl<<"|NAME: "<<name;
	print_ch(' ',92-name.length()-8);
	cout<<"|"<<endl<<"|DATE: "<<date;
	print_ch(' ',92-date.length()-8);
	cout<<"|"<<endl<<"|AGE: "<<age;
	print_ch(' ',46-age.length()-6);
	cout<<"MOBILE: "<<mobile;
	print_ch(' ',46-19);
	cout<<"|"<<endl<<"|GENDER: "<<gender;
	print_ch(' ',92-gender.length()-9);
	cout<<"|"<<endl<<"|NO. OF TICKETS: "<<arr1.size();
	print_ch(' ',92-to_string(arr1.size()).length()-18);
	cout<<"|"<<endl<<"|TICKET NO. : ";
	int cnt=14,i;
	for(i=0;i<arr1.size()-1;i++){
		
		cout<<arr1[i]<<",";
		cnt+=to_string(arr1[i]).length()+1;
	}
	cout<<arr1[i];
	cnt+=to_string(arr1[i]).length();
	print_ch(' ',92-cnt-1);
	cout<<"|"<<endl<<"|";
	print_ch('_',90);
	cout<<"|";

}
// print_info takes user input(Name,Mobile,Age,Gender) & prints in form of ticket &  stores the user information to user database
void print_info(vector<int>& arr1)
{	ofstream fp1;
  	fp1.open ("user.doc", ios::app);
	string date=currentDateTime();
	string name;
	int age;
	string mobile;
	char gender;
	cout<<"enter your name ";
	cin.ignore();
	getline(cin,name);
	cout<<"enter you age\n";
	cin>>age;
	while(age<0){
		cout<<"Age can't be negative";
		cout<<"\n enter correct age ";
		cin>>age;
	}
	cout<<"enter the mobile number";
	cin>>mobile;
	while(mobile.length()!=10){
		cout<<"Not a valid phone number!";
		cout<<"\nenter a valid one";
		cin>>mobile;
	}
	cout<<"enter your gender";
	cin>>gender;
	string data=name+","+date+","+to_string(age)+","+mobile+","+gender+","+to_string(arr1.size())+",";
	cout<<endl<<" ";
	print_ch('_',90);
	cout<<endl<<"|";
	print_ch(' ',40);
	cout<<"XYZ AGENCY";
	print_ch(' ',40);
	cout<<"|"<<endl<<"|";
	print_ch(' ',36);
	cout<<"TICKET INFORMATION ";
	print_ch(' ',35);
	cout<<"|"<<endl<<"|NAME: "<<name;
	print_ch(' ',92-name.length()-8);
	cout<<"|"<<endl<<"|DATE: "<<date;
	print_ch(' ',92-date.length()-8);
	cout<<"|"<<endl<<"|AGE: "<<age;
	print_ch(' ',46-to_string(age).length()-6);
	cout<<"MOBILE: "<<mobile;
	print_ch(' ',46-19);
	cout<<"|"<<endl<<"|GENDER: "<<gender;
	print_ch(' ',92-to_string(gender).length()-9);
	cout<<"|"<<endl<<"|NO. OF TICKETS: "<<arr1.size();
	print_ch(' ',92-to_string(arr1.size()).length()-18);
	cout<<"|"<<endl<<"|TICKET NO. : ";
	int cnt=14,i;
	for(i=0;i<arr1.size()-1;i++){
		data+=to_string(arr1[i])+",";
		cout<<arr1[i]<<",";
		cnt+=to_string(arr1[i]).length()+1;
	}
	
	data+=to_string(arr1[i])+",";
	data+="\n";
	cout<<arr1[i];
	cnt+=to_string(arr1[i]).length();
	print_ch(' ',92-cnt-1);
	cout<<"|"<<endl<<"|";
	print_ch('_',90);
	cout<<"|";
	fp1<<data;
	fp1.close();
	//cout<<data;

}
// booking module
void book_ticket(){
	int arr[50]={0}; // intializing bus 
	//database.doc contains the seat number that is already filled.
    fp=fopen("database.doc","r"); // reading database.doc
    int id=0;
    fseek(fp,0L,SEEK_END);
    int l=ftell(fp);
    rewind(fp);
	// reading seat from the database
    while(ftell(fp)<l-1)
    {
        fscanf(fp,"%d",&id);
        arr[id-1]=1;
    }
    fclose(fp);//closing the database
	vector<int>arr1;//data structure to store next booking seats
	int m,n;
	int a=array_counter(arr,50);//Number of already filled seats in the bus
	int filled=a;
    if(a==50){// if all seats are filled overwrite the database.doc 
        fp=fopen("database.doc","w");
        for(int i=0;i<50;i++)
            arr[i]=50;
		filled=0;
    }
    else// if there are vacant seats in bus open the database.doc in append mode
        fp=fopen("database.doc","a");
	//printing bus structure
    print_seat(arr,50);
    print_bus();
    cout<<endl;
    cout<<"How many tickets you want:\n";
    cin>>m;
	if(m>50-filled){// If required number of tickets is less than the number of vacant ones
		cout<<"Not enough seats available\n";
		exit(0);
	}
	if(m==0) exit(0);
    for(int i=0;i<m;i++){
        cout<<"Select the seat no. for ticket "<<i+1<<endl;
    	cin>>n;
		check:if(n<=0||n>50){//Seat number is not in the range 1 to 50(inclusive)
			cout<<"Enter seat number between 1 to 50\nEnter other seat :";
			scanf("%d",&n);
			goto check;
		}
		if(arr[n-1]==1){// if requested seat number is already filled up
			printf("OOPs! this seat is already filled\nEnter other seat :");
			scanf("%d",&n);
			goto check;
		}
		
    	arr[n-1]=1;
    	arr1.push_back(n);
    	fprintf(fp,"%d ",n);// appending seat number to database.doc
    }
    fclose(fp);
    print_info(arr1); // printing ticket informtion 
}
// retriving module
void retrive_ticket(){
	cout<<"enter the name";
	string str;
	getline(cin,str);
	cout<<"Enter the date(format:YYYY-MM-DD)";
	string dat;
	getline(cin,dat);
	ifstream fin;
	string line;
    fin.open("user.doc");
	int flag=0,cnt=0;
	vector<string> temp;
    while (fin) {
        getline(fin, line);
		string s="";
		//cout<<line<<endl;
		cnt=0;
        for(int i=0;i<line.length();i++){
			if(cnt!=1&&line[i]==','){
				temp.push_back(s);
				s="";
				cnt++;
			}
			else if(cnt==1&&line[i]==','){
				s=s.substr(0,10);
				temp.push_back(s);
				s="";
				cnt++;
			}
			else s+=line[i];
		}
		//cout<<temp[0]<<" "<<temp[1]<<endl;
		if(temp[0]==str&&temp[1]==dat){
			flag=1;
			break;
			
		}
		else temp.clear();
    }
	fin.close();
	if(flag)
	print_hist(temp);
	else cout<<"No Matching records! Book a new ticket";
}
//driver code
main()
{	//Menu System
	int ch;
	cout<<"Hey! Welcome to XYZ AGENCY"<<endl;
	cout<<"1.Retrive previously booked tickets"<<endl;
	cout<<"2.Book a new ticket"<<endl;
	cout<<"Enter your choice: ";
	scanf("%d",&ch);
	cin.ignore();
	switch(ch){
		case 1:
			//retrive module
			retrive_ticket(); // Retriving previously booked ticket on the system 
			break;
		case 2:
			// Booking module
			book_ticket(); // Booking new ticket on the system 
			break;
		default:
			cout<<"Enter a valid choice";
			break;
	}
	
	
}          