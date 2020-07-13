
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define row 10
#define col 50
#include<time.h>
FILE *fp;
void gotoxy(short x, short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

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

void print_seat(int arr[],int n)
{
	int j=8;
	for(int i=1;i<11;i++){
	gotoxy(j+col,2+row);
	if(arr[i-1]==1)
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
void print_info(int arr1[],int m)
{
		char name[20];
		int age;
		double mobile;
		
	
	
	char gender[1];
	printf("enter your name\n");
	scanf("%s",name);
	printf("enter you age");
	scanf("%d",&age);
	printf("enter the mobile number");
	scanf("%lf",&mobile);
	printf("enter your gender");
	scanf("%s",gender);
	printf("\n______________________________________________________________________________________________________\n");
	printf("|                                       XYZ AGENCY                                                    |\n");
	printf("|                                    TICKET INFORMATION                                               |\n");
	printf("|NAME:%s                                                                                         |\n",name);
	printf("|AGE:%d                                                           PHONE NO.:%.0lf                   \n",age,mobile);
	printf("|GENDER:%s                                                                                             |\n",gender);
	printf("|NO. OF TICKETS:%d                                                                                     |\n",m);
	printf("|TICKET NO.");
	for(int i=0;i<m;i++)
	printf("%d ,",arr1[i]);
	printf("                                                                                     \n");
	printf("|_____________________________________________________________________________________________________|\n");
	
	
	
}
int array_counter(int arr[],int n)
{
	int m=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==1)
		m+=1;
	}
	if(m==50)
	return 1;
	else 
	return 0;
}
main()
{
 int arr[50]={0};
 int m,n;
	fp=fopen("database.doc","r");
	int id=0;
 	 fseek(fp,0L,SEEK_END);
 int l=ftell(fp);
 rewind(fp);
	while(ftell(fp)<l-1)
	{
	fscanf(fp,"%d",&id);
	arr[id-1]=1;
	
}
fclose(fp);
int a=array_counter(arr,50);
if(a==1){
fp=fopen("database.doc","w");
for(int i=0;i<50;i++)
arr[i]=50;
}
else
fp=fopen("database.doc","a");
 print_seat(arr,50);
  print_bus();
 printf("\n");
 printf("How many tickets you want:\n");
 scanf("%d",&m);
 int arr1[m];
 for(int i=0;i<m;i++){
 	printf("Select the seat no. for ticket %d\n",i+1);
 scanf("%d",&n);
 check:if(arr[n-1]==1){
 printf("OOPs! this seat is already filled\nEnter other seat");
 scanf("%d",&n);
 goto check;
}
arr[n-1]=1;
arr1[i]=n;
 fprintf(fp,"%d ",n);
}
fclose(fp);
print_info(arr1,m);
}          
 
 
 
 
