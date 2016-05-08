#include <iostream> 

#include <fstream> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <process.h> 
#include <unistd.h>  
#include <termios.h>
using namespace std;
fstream f1,f2;              /*defining some global variables and objects*/ int     record=0,record1=0; 
int     ph=-1; 
int     alpha=0,kl; 
 

void getpwd(char ch[])     /*function to get the password*/ 
{     char k; int q=0; 
      cout<<"\nEnter The password :"; 
 
      do{  k=getchar(); 
     cout<<int(k);
 	   if((int (k)!=10)||int(k)!=127) 
 	   { 
 	     ch[q++]=k;  	   } 
 
 	   if((int(k)==10)&&(q>0)) 
 	   { 
 	     cout<<"\b"<<" "<<"\b";  	     q--; 
 	   } 
 	   ch[q+1]='\0'; 
 
 	}while(int (k)!=10) ; 
 
 } 
 
 
class login 
{            int usercode; 
 	     char usr[50]; 
 	     char pwd[50]; 
 
 public: 
 
     void saveusr() 
 	{       cout<<"\nEnter the New username :";  	 	gets(usr); 
	 	getpwd(pwd); 
	 	cout<<"\nEnter 1 for Librarian,2 for Staff,3 for Student :"; 
 	 	cin>>usercode; 
 	} 
 
 
  int chkusr(char usrchk[],char pwdchk[]); 
 
  void dispuser() 
  { cout<<"\nUser Name :"<<usr;  cout<<"\nUser Type :"; 
 	    if(usercode==1) 
 	 	cout<<"Librarian"; 
 	    else if(usercode == 2) 
 	 	cout<<"Staff";  	    else  	 	cout<<"Student"; 
  } 
 
 
}; 
int login::chkusr(char usrchk[],char pwdchk[]) 
{   int klj; 
 
 	if(strcmp(usr,usrchk)==0) 
 	  {if (strcmp(pwd,pwdchk)==0) 
 	 	{klj=usercode;  	 	alpha=1; 
 	 	} 
 	  else 
 	 	{klj=-1;  	 	alpha=-1; 
 	 	} 
 	  }  	else 
 	 {klj=-1;  	  alpha=-1; 
 	 } 
    return klj; 
 
} login log3; 
 
 
void loginscreen1() 
{     
   login log1,log2; 
   int i,j; 
   char chkuser[50],chkpass[50]; 
  char pqr; 
      do 
       {     if(alpha==1) 
 	 	{cout<<"\nWrong user data"; 
 	 	cout<<"\nPress any Key to exit else press enter To continue"; 
 	 	pqr=getchar(); 
 	     if(int(pqr)!=13) 
 	 	exit(0); 
 	 	} 
    
 	cout<<"*************************Welcome To "; 
 	cout<<"Library Management***********************"; 
 	cout<<"\n                                          " ; 
 	cout<<"       v1.01.04.15 Build Stable.001";  	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";  	cout<<"----------------------------(c)Copyright 2015 Sainyam Kapoor-------------------- ";  	 	cout<<"\n\nUsername :";  	gets(chkuser); 
 	getpwd(chkpass); 
 	 	if(chkuser[0]=='#'&&chkpass[0]=='#')  //bypass in case of deleted login data 
 	 	   ph=1;  	 	else 
 	 	  { 
 	 	  f1.open("login.dat",ios::binary|ios::in); 
 	 	  while(f1.read((char*)&log1,sizeof(log1))) 
 	 	     { 
 	 	     i=log1.chkusr(chkuser,chkpass); 
 	 	     if(i!=-1) 
 	 	     {  	 	     ph=i;  	 	     alpha=0; 
 	 	     break; 
 	 	     } 
 	 	     } 
 	 	     f1.close(); 
 	 	     if(ph==-1) 
 	 	 	alpha=1; 
 
 	 	 } 
 	}while(ph==-1) ; 
 
 }  /*Changes value of ph to 1 for librarian 2 for clerk ,3 for normal user ,-1 if user not found*/ 
 
 
 
struct date 
{int dd,mm,yy; 
}; 
void getdate(date &d1,int q=0) 
{  int k=0;    do{       if(k!=0) 
       {cout<<"\nIncorrect Date\nPlease Re-enter the correct Date(dd mm yyyy)"; 
 	cin>>d1.dd>>d1.mm>>d1.yy; 
       } 
     if(k==0&&q==0) 
       {cout<<"\nEnter the Date of Purchase(dd mm yyyy) :"; 
 	cin>>d1.dd>>d1.mm>>d1.yy; 
       } 
     if(k==0&&q==1) 
       {cout<<"\nEnter the Date of Issue(dd mm yyyy) :"; 
 	cin>>d1.dd>>d1.mm>>d1.yy; 
       } 
     if((d1.mm>12)||(d1.dd>31)) 
       {k=1; 
       } 
 
     else if(d1.mm==1||d1.mm==3||d1.mm==5||d1.mm==7||d1.mm==8||d1.mm==10||d1.mm==12) 
       {if(d1.dd>31) 
 	  k=1;  	else  	  k=0; 
       } 
 
     else if(d1.mm==4||d1.mm==6||d1.mm==9||d1.mm==11) 
       {if(d1.dd>30) 
 	  k=1;  	else 
 	  k=0; 
       }       else 
       {if(((d1.yy%4==0)&&(d1.yy%100!=0))||(d1.yy%400==0)) 
 	{if(d1.dd>29)  	 k=1; 
 	} 
 	else 
 	 if(d1.dd>28)  	 k=1; 
       } 
 
      }while(k!=0); 
} 
 
class books 
{ 	int bookno; 
char bookname[80]; 
char authorname[50]; 
date dop; 
public: 
 	int issue; /*0 for not issued and 1 for issued*/ 
 	date doi;  	char usrname[50];  	int usrcode;  	void enterbook(int bookno);  	void dispbook()  	{cout<<"\n\nBook Name :";  	 cout<<bookname;  	 cout<<"\nBook Code :"; 
 	 cout<<bookno;  	 cout<<"\nAuthor's name :"; 
 	 cout<<authorname;  	 cout<<"\nIssued or Not Issued :"; 
 	 if(issue==1)  	 {cout<<"issued"; 
 	  cout<<"\nDate of Issue :"<<doi.dd<<"/"<<doi.mm<<"/"<<doi.yy;  	  cout<<"\nBook Is Issued to :"<<usrname<<"\nUserCode :"<<usrcode; 
 
 
 	 } 
 	 else 
 	 cout<<"Not Issued";  	 cout<<"\nDate of Purchase(dd/mm/yy) :"<<dop.dd<<"/"<<dop.mm<<"/"<<dop.yy; 
 	 } 
 	 int chkbook(int bukno)  	  { if(bukno==bookno)  	      alpha=bookno; 
 	    else  	      alpha=-1  ; 
 	   return alpha; 
 	  } 
  int retbookno()   {return bookno;}   char *retbookname() 
 	 {return bookname;} 
}; 
 
 
void books::enterbook(int bookno1) 
 
{     bookno=bookno1;       cout<<"\nEnter a Book Name :";       gets(bookname); 
      cout<<"\nEnter the Author name :";       gets(authorname); 
     getdate(dop); 
     cout<<"\nIssued or Not Issue (1 For issue And 0 for not issued) :"; 
     int kl=0;      rec:      if(kl!=0)       cout<<"\nPlease Re-enter :"; 
      cin>>kl;       if(kl==0||kl==1) 
      {issue=kl; 
 	if(kl==1) 
 	 {getdate(doi,kl);  	 cout<<"\nPlease Enter the Issuer's Name :";  	 gets(usrname); 
 	 cout<<"\n Now Please enter the Issuer's Code :";  	 cin>>usrcode; 
 	 } 
      }       else 
       goto rec;        cout<<"\nBook code for entered book is "<<bookno; 
 
} books b1,b2,b3; 
 
void newrecord() 
{ 	record=0; 
 	f2.open("books.dat",ios::binary|ios::in); 
 	while(f2.read((char*)&b1,sizeof(b1))) 
 	{record++;} 
 	record+=1; 
 	f1.open("books.dat",ios::binary|ios::out|ios::app); 
 	b2.enterbook(record); 
 	f1.write((char*)&b2,sizeof(b2));  	f1.close();  	f2.close(); 
} 
 
 
void disprecord() 
{ 	 record=0; 
 	 f2.open("books.dat",ios::binary|ios::in);  	 while(f2.read((char*)&b1,sizeof(b1)))  	 {cout<<"\n\n\nData For Record No :"<<++record; 
 	 b1.dispbook(); 
 	 } 
 	 f2.close(); 
} 
 
void disuser() 
{  	record1=0; 
f2.open("login.dat",ios::binary|ios::in); while(f2.read((char*)&log3,sizeof(log3))) {cout<<"\n\n\nData For Record No :"<<++record1; 
log3.dispuser(); 
} f2.close(); 
} 
 
void editrecord() 
{ 	int er; 
 	cout<<"\nEnter The Book code to be Edited :"; 
 	cin>>er; 
 	cout<<"\nEnter Book details"; 
 	b1.enterbook(er); 
 	f1.open("books.dat",ios::out|ios::binary|ios::ate);  	f1.seekp((er-1)*sizeof(b1),ios::beg); 
 	f1.write((char*)&b1,sizeof(b1)); 
 	f1.close(); 
} void issuebookno() { 	int ch,alpha=1; 
 	cout<<"\nEnter the Book Code to be Issued :"; 
 	cin>>ch; 
 	f1.open("books.dat",ios::in|ios::binary);  	f2.open("temp.dat",ios::out|ios::binary);  	while(f1.read((char*)&b3,sizeof(b3))) 
 	 	{if (b3.retbookno()==ch) 
 	 	 	{  if(b3.issue==1) 
      {cout<<"\nAlready Issued";       cout<<"\nIt is issued to :"<<b3.usrname;       cout<<"\nUser Code Is :"<<b3.usrcode;       cout<<"\nDate of issue is :"  ; 
 	 	 	   cout<<b3.doi.dd<<"\\"<<b3.doi.mm<<"\\"<<b3.doi.yy; 
 
 	 	 	   } 
 
 	 	 	   else 
 	 	 	  {cout<<endl; 
 	 	 	  b3.dispbook(); 
 	 	 	  cout<<"\nBook is now issued";  	 	 	  b3.issue=1; 
 	 	 	  cout<<"\nEnter the Issuer's name :";  	 	 	  gets(b3.usrname); 
 	 	 	  cout<<"\nEnter the Issuer's code :";  	 	 	  cin>>b3.usrcode; 
 	 	 	  getdate(b3.doi,alpha); 
 	 	 	  } 
 
 	 	 	   f2.write((char*)&b3,sizeof(b3)); 
 
	 	 	} 
	 	else 
	 	 	f2.write((char*)&b3,sizeof(b3)); 
	 	} 
f1.close(); f2.close(); 
 	fstream file3("books.dat",ios::out|ios::binary);  	fstream file4("temp.dat",ios::in|ios::binary);  	while(file4.read((char*)&b3,sizeof(b3))) 
 	{file3.write((char*)&b3,sizeof(b3)); 
 	} 
 	file3.close();  	file4.close(); 
 	remove("temp.dat"); 
 
 
 
} 
 
 
void issuebookname() 
{ 	alpha=1; 
 	char ch[80]; 
 	cout<<"\nEnter the Book Name to be issued :";  	gets(ch); 
 	f1.open("books.dat",ios::in|ios::binary);  	f2.open("temp.dat",ios::out|ios::binary);  	while(f1.read((char*)&b3,sizeof(b3)))  	 	{if (strcmp(ch,b3.retbookname())==0) 
 	 	 	{  if(b3.issue==1) 
      {cout<<"\nAlready Issued";       cout<<"\nIt is issued to :"<<b3.usrname;       cout<<"\nUser Code Is :"<<b3.usrcode;       cout<<"\nDate of issue is :"  ; 
 	 	 	   cout<<b3.doi.dd<<"\\"<<b3.doi.mm<<"\\"<<b3.doi.yy; 
 
 	 	 	   } 
 	 	 	   else 
 	 	 	  {cout<<endl; 
 	 	 	  b3.dispbook(); 
 	 	 	  cout<<"\n\nThe book Is now issued"; 
 	 	 	  cout<<"\nEnter the issuer's name"; 
 	 	 	  gets(b3.usrname); 
 	 	 	  cout<<"\nEnter the issuer's code";  	 	 	  cin>>b3.usrcode; 
 	 	 	  b3.issue=1; 
 	 	 	  getdate(b3.doi,alpha); 
	 	 	  } 
	 	 	   f2.write((char*)&b3,sizeof(b3)); 
	 	 	} 
	 	else 
	 	 	f2.write((char*)&b3,sizeof(b3)); 
	 	} 
f1.close();  	f2.close(); 
 	fstream file3("books.dat",ios::out|ios::binary);  	fstream file4("temp.dat",ios::in|ios::binary);  	while(file4.read((char*)&b3,sizeof(b3))) 
 	{file3.write((char*)&b3,sizeof(b3)); 
 	} 
 	file3.close();  	file4.close(); 
 	remove("temp.dat"); 
 
 
 
} 
 
 
void returnbook() {int ch; 
cout<<"\nEnter the book code to be returned :"; cin>>ch; f1.open("books.dat",ios::in|ios::binary); f2.open("temp.dat",ios::out|ios::binary); while(f1.read((char*)&b3,sizeof(b3))) 
{ {if (b3.retbookno()==ch)   {if(b3.issue==0) 
  cout<<"Already returned";   else 
  {b3.issue=0;   cout<<"\nBook is now returned"; 
  } 
  } 
  }f2.write((char*)&b3,sizeof(b3)); 
 
 
}f1.close(); 
f2.close(); 
 
fstream file3("books.dat",ios::out|ios::binary);  fstream file4("temp.dat",ios::in|ios::binary);  while(file4.read((char*)&b3,sizeof(b3))) 
 {file3.write((char*)&b3,sizeof(b3)); 
  }   file3.close();   file4.close(); 
remove("temp.dat"); 
 
} 
void returnbookname() {char ch[50]; 
cout<<"\nEnter the Book Name to be returned :"; gets(ch); f1.open("books.dat",ios::in|ios::binary); f2.open("temp.dat",ios::out|ios::binary); while(f1.read((char*)&b3,sizeof(b3))) 
{ {if (strcmp(ch,b3.retbookname())==0) 
  {if(b3.issue==0)   cout<<"Already returned";   else 
  {b3.issue=0;   cout<<"\nBook is now Returned"; 
  } 
  } 
  }f2.write((char*)&b3,sizeof(b3)); 
 
 
}f1.close(); f2.close(); 
 
fstream file3("books.dat",ios::out|ios::binary);  fstream file4("temp.dat",ios::in|ios::binary);  while(file4.read((char*)&b3,sizeof(b3))) 
 {file3.write((char*)&b3,sizeof(b3)); 
  }   file3.close();   file4.close(); 
remove("temp.dat"); 
 
} 
 
 
void checkbook() {int lk=0; 
int ch; cout<<"\nEnter the Book Code to be Searched :"; cin>>ch; f1.open("books.dat",ios::in|ios::binary); while(f1.read((char*)&b3,sizeof(b3))) 
{if (b3.retbookno()==ch)  {lk=1;  cout<<"\nHere's the Book Data";  b3.dispbook(); 
} 
} f1.close(); if(lk==0) 
{cout<<"\nSorry I was Unable to find the book"; 
} 
} 
 
 
void checkbookname() {int lk=0; char ch[50]; 
cout<<"\nEnter the Book Name to be Searched :"; 
gets(ch); f1.open("books.dat",ios::in|ios::binary); while(f1.read((char*)&b3,sizeof(b3))) {if (strcmp(ch,b3.retbookname())==0) 
 {lk=1; 
 cout<<"\nHere's the Book Data :"; 
   b3.dispbook();  } }f1.close(); if(lk==0) 
{cout<<"\nSorry I was Unable to find the book"; 
} 
} 
 
 
void menu1() 
{         	int ch; 
 	cout<<"Welcome"; 
 	cout<<"\n\nAvailable options for you";  	cout<<"\n1)Enter A new Record";  	cout<<"\n2)Edit a record";  	cout<<"\n3)Issue a Book(by book code)";  	cout<<"\n4)Issue a Book(by book name)";  	cout<<"\n5)Return a book(by book code)";  	cout<<"\n6)Return a book(by book name)";  	cout<<"\n7)Check for a book(by book code)";  	cout<<"\n8)Check for a book(by book name)";  	cout<<"\n9)Add A new User ";  	cout<<"\n10)Display All Books Record";  	cout<<"\n11)Display all user data";  	cout<<"\n12)Exit the program";  	cout<<"\nPlease Enter Your Choice :"; cin>>ch; switch(ch) { case 1: newrecord(); 
	 	break; 
 	case 2: editrecord(); 
 	 	break; 
 	case 3: issuebookno(); 
 	 	break; 
 	case 4: issuebookname();
 	 	break; 
 	case 5: returnbook(); 
 	 	break; 
 	case 6: returnbookname(); 
 	 	break; 
 	case 7: checkbook(); 
 	 	break; 
 	case 8: checkbookname(); 
 	 	break; 
 	case 9: log3.saveusr();  	 	f2.open("login.dat",ios::binary|ios::out|ios::ate); 
 	 	f2.write((char*)&log3,sizeof(log3)); 
 	 	f2.close();  	 	break; 
 	case 10: disprecord(); 
 	 	break; 
 	case 11: disuser(); 
 	 	break; 
 	case 12: exit(0);  	default:cout<<"\nSome Error is Detected Please Contact its Programmer(Sainyam)"; 
 	} 
 
 } 
 
 void menu2() 
{         	int ch; 
 	cout<<"Welcome"; 
 	cout<<"\n\nAvailable options for you";  	cout<<"\n1)Enter A new Record";  	cout<<"\n2)Edit a record";  	cout<<"\n3)Issue a book(by book code)";  	cout<<"\n4)Issue a book(by book name)";  	cout<<"\n5)Return a book(by book code)";  	cout<<"\n6)Return a book(by book name)";  	cout<<"\n7)Check for issued book(by book code)";  	cout<<"\n8)Check for issued book(by book name)";  	cout<<"\n9)Display All the Books Record";  	cout<<"\n10)Exit the program";  	cout<<"\nPlease Enter Your Choice :"; cin>>ch; switch(ch) { 
case 1: newrecord(); 
	 	break; 
 	case 2: editrecord(); 
 	 	break; 
 	case 3: issuebookno(); 
 	 	break; 
 	case 4: issuebookname();
 	 	break; 
 	case 5: returnbook(); 
 	 	break; 
 	case 6: returnbookname(); 
 	 	break; 
 	case 7: checkbook(); 
 	 	break; 
 	case 8: checkbookname(); 
 	 	break; 
 	case 9: disprecord(); 
 	 	break; 
 	case 10: exit(0);  	default:cout<<"\nSome Error is Detected Please contact its Programmer(Sainyam)"; 
 	} 
 
} 
 
 
void menu3() 
{         	int ch; 
 	cout<<"Welcome"; 
 	cout<<"\n\nAvailable options for you";  	cout<<"\n1)Check for issued book(by book code)";  	cout<<"\n2)Check for issued book(by book name)";  	cout<<"\n3)Display All Books Record";  	cout<<"\n4)Exit the program"; 
 	cout<<"\nPlease Enter Your Choice :"; 
 	cin>>ch; 
 	switch(ch) 
 	{ 
 	case 1: checkbook(); 
 	 	break; 
 	case 2: checkbookname();  	 	break; 
 	case 3: disprecord();  	 	break; 
 	case 4: exit(0);  	default:cout<<"\nSome Error is Detected Please contact its Programmer(Sainyam)"; 
 	} 
 
} 
 
 
int main() 
{ 
 	char kh;  	loginscreen1();  	 
 	if(ph==1||ph==2||ph==3)
 	{cout<<"";  	 do{ 
 	    switch(ph)  	    {case 1: menu1(); 
 	 	     break; 
 	     case 2: menu2(); 
 	 	     break; 
 	     case 3: menu3(); 
 	 	     break; 
 	     default:cout<<"\nSome error is Detected Please contact its Programmer(Sainyam)"; 
 	    } 
 
 
 	 	cout<<"\nDo you want to continue(y/n)"; 
 	 	cin>>kh; 
 
 
 
 	    }while(kh=='y'); 
 	 } 
 return 0;
} 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
