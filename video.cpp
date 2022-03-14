#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<iomanip.h>
long pos;
int n=0,cno=0,n1;
struct date d;
validate_string1(char* s)
{
 for(int va = 0;va<strlen(s);va++)
 {
  if(!isalpha(s[va]))
  return -1;
 }
 return 0;
}

validate_string(char* s)
{
 for(int va = 0;va<strlen(s);va++)
 {
  if(!isalnum(s[va])&&s[va]!=' ')
  return -1;
 }
 return 0;
}

validate_int(char* t)
{
 for(int re=0;re<strlen(t);re++)
 {
  if(!isdigit(t[re]))
  return -1;
 }
 return 0;
}

class CD
{
 char cdname[50];
 char cdlang[50];
 public:
 char status[20];
 int cdno;
 void add_cd();
 void show_cd();
 void modify();
 void val();
}k;

void CD::val()
{
strcpy(status,"ISSUED");
}

void CD::add_cd()
{
  cdno=random(2000-10+1)+10;
  cout<<"Enter the CD Name   : ";
  Y1:
  gets(cdname);
  int e=validate_string(cdname);
  if(e==-1)
  {
   cout<<"Invalid CD Name.Enter a valid CD Name.\n";
   goto Y1;
  }
  if(cno==1)
  cdno=rand();
  cout<<"Specify CD Language : ";
  Y2:
  gets(cdlang);
  e=validate_string1(cdlang);
  if(e==-1)
  {
   cout<<"Invalid CD Language. Try Again.\n";
   goto Y2;
  }
  strcpy(status,"AVAILABLE");
}

void CD::modify()
{
  cout<<"Enter new CD Name       : ";
  Y1:
  gets(cdname);
  int e=validate_string(cdname);
  if(e==-1)
  {
   cout<<"Invalid CD Name.Enter a valid CD Name.\n";
   goto Y1;
  }
  if(cno==1)
  cdno=rand();
  cout<<"Specify new CD Language : ";
  Y2:
  gets(cdlang);
  e=validate_string1(cdlang);
  if(e==-1)
  {
   cout<<"Invalid CD Language. Try Again.\n";
   goto Y2;
  }
  strcpy(status,"AVAILABLE");
}

void CD::show_cd()
{
 if(n==0)
 {
   cout<<"No CDs present in the library.\n";
   getch();
   goto LX;
 }
 cout<<"\n\tCD Name    : "<<cdname;
 cout<<"\n\tCD Number  : "<<cdno;
 cout<<"\n\tCD Language: "<<cdlang;
 cout<<"\n\tCD Status  : "<<status<<"\n";
 LX:
}

validate_string2(char* s)
{
 for(int va = 0;va<strlen(s);va++)
 {
  if(!isalpha(s[va])&&s[va]!=' ')
  return -1;
 }
 return 0;
}

int customers=0;
class Customer
{
 public:
 int cdtaken;
 char tel[11];
 char custname[50];
 int token,custno;
 Customer::Customer()
 {
  token=0;
  cdtaken=0;
  strcpy(tel,"NULL");
  strcpy(custname,"NULL");
 }
 void add_cust();
 void display_cust();
 void cmodify();
}cust,custs;

void Customer::add_cust()
{
  custno=random(2000-10+1)+10;
  cout<<"Enter Customer Name    : ";
  Y3:
  gets(custname);
  int e = validate_string2(custname);
  if(e==-1)
  {
   cout<<"Invalid Customer Name. Try again.\n";
   goto Y3;
  }
  if(cno==1)
  custno=rand();
  cout<<"Enter Telephone Number : ";
  Y4:
  gets(tel);
  e=validate_int(tel);
  if(e==-1)
  {
   cout<<"Invalid Telephone Number. Only Digits Allowed.\n";
   goto Y4;
  }
}

void Customer::display_cust()
{
  if(customers==0)
  {
   cout<<"\n\t\tNo customers present in the records.\n";
   getch();
   goto LP;
  }
  else
  {
   cout<<endl;
   cout<<"\n\tCUSTOMER NAME   : "<<custname;
   cout<<"\n\tCUSTOMER NUMBER : "<<custno;
   cout<<"\n\tTELEPHONE NUMBER: "<<tel;
   cout<<"\n\tCD ISSUED       : ";
   if(token==1)
   {
     cout<<"Yes\n";
     cout<<"\tCD Borrowed     : "<<cdtaken;
   }
   else
     cout<<"No\n";
   LP:
  }
}

void Customer::cmodify()
{
  cout<<"Enter new Customer Name    : ";
  Y3:
  gets(custname);
  int e = validate_string2(custname);
  if(e==-1)
  {
   cout<<"Invalid Customer Name. Try again.\n";
   goto Y3;
  }
  if(cno==1)
  custno=rand();
  cout<<"Enter new Telephone Number : ";
  Y4:
  gets(tel);
  e=validate_int(tel);
  if(e==-1)
  {
   cout<<"Invalid Telephone Number. Only Digits Allowed.\n";
   goto Y4;
  }
}

class Transact
{
 public:
 int cust_no;
 int cd_no;
 char particular[20];
 int pday;
 int pmon;
 int pyear;
 void get_number()
 {
  cust_no = cust.custno;
  cd_no = k.cdno;
 }

 void disp_details()
 {
  cout<<setw(13)<<cust_no<<setw(10)<<cd_no<<setw(15)<<particular<<setw(10)<<pday<<"/"<<pmon<<"/"<<pyear;
 }
}T;

void main()
{
 randomize();

 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\BGI\\");
 setcolor(GREEN);
 setbkcolor(BLACK);
 settextstyle(1,0,4);
 outtextxy(100,150,"VIDEO LIBRARY MANAGEMENT");
 outtextxy(255,200,"SYSTEM");
 delay(2000);

 //counting the number of CDs
 ifstream fbb("DISK.dat",ios::in|ios::binary);
 if(fbb!=0)
 {
  while(!fbb.eof())
  {
   fbb.read((char *)&k,sizeof(k));
   if(fbb.eof()) break;
   ++n;
  }
  fbb.close();
 }

 L1:
 clrscr();
 textmode(3);
 textcolor(BLACK);
 textbackground(GREEN);
 cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");

 cout<<"\n\tChoose one of the following options.\n";
 cout<<"\tA. Add CD to Library.\n";
 cout<<"\tB. Display all the available CDs.\n";
 cout<<"\tC. Display all CDs.\n";
 cout<<"\tD. Display a specific CD.\n";
 cout<<"\tE. Modify CD details.\n";
 cout<<"\tF. Delete a CD from Library.\n";
 cout<<"\tG. Issue a CD.\n";
 cout<<"\tH. Return a CD.\n";
 cout<<"\tI. Add new customer details to Database.\n";
 cout<<"\tJ. Display details of all Customers.\n";
 cout<<"\tK. Display details of one Customer.\n";
 cout<<"\tL. Modify Customer details.\n";
 cout<<"\tM. Delete Customer Details from Database.\n";
 cout<<"\tN. Show all previous transactions.\n";
 cout<<"\tO. Show previous transactions of a specific Customer.\n";
 cout<<"\tP. Exit.\n";
 char ch;
 cin>>ch;
 //************ADDING A CD***************
 if(ch=='A'|| ch=='a')
 {
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                               ADD NEW CD TO LIBRARY                            ");
  cno=1;
  k.add_cd();
  ofstream fa("DISK.dat",ios::app|ios::binary);
  fa.write((char*)&k,sizeof(k));
  cout<<"CD Added Succesfully.\n";
  n++;
  getch();
  fa.close();
  textmode(LASTMODE);
  goto L1;
 }  //****************DISPLAYING ALL AVAILABLE CDS********************
 else if(ch=='B' || ch=='b')
 {
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                                   AVAILABLE CDs                                ");
  ifstream fb("DISK.dat",ios::in|ios::binary);
  if(fb!=0)
  {
   int found=0;
   while(!fb.eof())
   {
    fb.read((char*)&k,sizeof(CD));
    if(fb.eof()) break;
    if(strcmpi(k.status,"AVAILABLE")==0)
    {
       k.show_cd();
       found=1;
    }
   }
   if(found==0)
     cout<<"\n\t\tNo CDs found";
   fb.close();
  }
  else
    cout<<"\n\t\tFile not found/CD file does not exists";
  getch();
  textmode(LASTMODE);
  goto L1;
 } //*************DISPLAYING ALL CDS***************
 else if(ch=='C' || ch=='c')
 {
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                                      ALL CDs                                   ");
  textmode(3);
  ifstream fc("DISK.dat",ios::in|ios::binary);
  if(fc!=0)
  {
   int fdn=0;
   while(!fc.eof())
   {
    fc.read((char*)&k,sizeof(k));
    if(fc.eof()) break;
    k.show_cd();
    ++fdn;
   }
   if(fdn==0)
     cout<<"\n\t\tCDs not found";
   fc.close();
  }
  else
    cout<<"\n\t\tFile not found/CD file does not exists";
  getch();
  textmode(LASTMODE);
  goto L1;
 }   //***************DISPLAY DETAILS OF A CD*******************
 else if(ch=='D'|| ch=='d')
 {
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                                     CD DETAILS                                 ");
  cout<<"\n\nEnter the CD Number of the CD to be displayed : ";
  int num;
  char s[20];
  Y5:
  cin>>s;
  int e = validate_int(s);
  if(e==-1)
  {
   cout<<"Invalid Input. Enter a valid CD Number with only digits.\n";
   goto Y5;
  }
  num=atoi(s);
  ifstream fd("DISK.dat",ios::in|ios::binary);
  if(fd!=0)
  {
   int fou=0;
   while(!fd.eof())
   {
    fd.read((char*)&k,sizeof(k));
    if(fd.eof()) break;
    if(k.cdno==num)
    {
      k.show_cd();
      ++fou;
      break;
    }
   }
   if(fou==0)
       cout<<"\n\t\tCD not found";
   fd.close();
  }
  else
    cout<<"\n\t\tFile not found/CD file does not exists";
  getch();
  textmode(LASTMODE);
  goto L1;
 }  //*******************MODIFY CD*******************
 else if(ch=='E' || ch=='e')
 {
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                                 MODIFY CD DETAILS                              ");
  cno=0;
  L4:
  cout<<"Enter the CD Number of the CD to be modified.\n";
  int num;
  char s1[11];
  Y6:
  cin>>s1;
  int e = validate_int(s1);
  if(e==-1)
  {
   cout<<"Invalid Input. Enter a CD number with digits only.\n";
   goto Y6;
  }
  num=atoi(s1);
  fstream fe1("DISK.dat",ios::in|ios::out|ios::binary);
  if(fe1!=0)
  {
   while(!fe1.eof())
   {
    pos=fe1.tellg();
    fe1.read((char*)&k,sizeof(k));
    if(fe1.eof())  break;
    if(k.cdno==num)
    {
      cno=2;
      cout<<"EXISTING CD DETAILS:-\n";
      k.show_cd();
      cout<<"\nEnter the modifications to be made.\n";
      k.modify();
      fe1.seekg(pos);
      fe1.write((char*)&k,sizeof(k));
      cout<<"CD Details Modified Succesfully.\n";
      break;
    }
   }
   fe1.close();
   if(cno==0)
   {
    cout<<"CD not found. Try Again.\n";
    goto L4;
   }
  }
  else
    cout<<"\n\t\tFile not found/CD file does not exists";
  getch();
  textmode(LASTMODE);
  goto L1;
 } //************DELETE A CD***************
 else if(ch=='F' || ch=='f')
 {
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                               DELETE CD FROM LIBRARY                           ");
  int num;
  char s[20];
  Y7:
  cout<<"\n\nEnter the number of the CD to be deleted: ";
  cin>>s;
  int e = validate_int(s);
  if(e==-1)
  {
   cout<<"Invalid Input. Enter a CD number with digits only.\n";
   goto Y7;
  }
  num=atoi(s);
  ifstream ff1("DISK.dat",ios::in|ios::binary);
  ofstream ff2("TEMP.dat",ios::out|ios::binary);
  if(ff1!=0)
  {
   int w=0;
   while(!ff1.eof())
   {
     ff1.read((char*)&k,sizeof(k));
     if(ff1.eof()) break;
     if(k.cdno==num && strcmpi(k.status,"Available")==0)
     {
      w=1;
      cout<<"\nEXISTING CD DETAILS:-\n";
      k.show_cd();
      LF:
      cout<<"\nAre you sure you want to delete? (Y/N) : ";
      char yes;
      cin>>yes;
      yes=toupper(yes);
      if(yes=='N')
      {
       ff2.write((char*)&k,sizeof(k));
       cout<<"\n\t\tCD not deleted";
      }
      else if(yes!='Y' && yes!='N')
      {
       cout<<"Choose a valid option, and try again.\n";
       goto LF;
      }
      else if(yes=='Y')
      {
	--n;
	cout<<"\n\t\tCD deleted sucessfully";
      }
     }
     else if(k.cdno!=num)
	  ff2.write((char*)&k,sizeof(k));
   }
   if(w==0)
   {
    cout<<"\nCD not found or CD is issued to a customer.So cannot delete";
    getch();
   }
   ff1.close();
   ff2.close();
   remove("DISK.dat");
   rename("TEMP.dat","DISK.dat");
  }
  else
  {
     cout<<"\n\t\tFile not found/CD file does not exists";
     ff2.close();
  }
  getch();
  textmode(LASTMODE);
  goto L1;
 }//***************ISSUING A CD*******************
 else if(ch=='G' || ch=='g')
 {
  int a;
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("              	            VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                                    ISSUE CD                                    ");
  L3:
  int c,cdd;
  cout<<"\n\tEnter customer number : ";
  cin>>c;
  cout<<"\n\tEnter Cd number       : ";
  cin>>cdd;
  ifstream ifile("DISK.dat",ios::in|ios::binary);
  int q2=0;    //CD not issued
  int cdfound=0;
  while(!ifile.eof())
  {
   ifile.read((char *)&k,sizeof(k));
   if(ifile.eof()) break;
   if(k.cdno==cdd)
   {
    cdfound=1;
    if(strcmp(k.status,"ISSUED")==0)
    {
      q2=1;    //CD issued
      break;
    }
   }
  }
  ifile.close();
  if(q2==1)
  {
     cout<<"\n\t\tThis CD is already issued";
     getch();
  }
  else if(cdfound==0)
  {
     cout<<"\n\t\tCD not found";
     getch();
  }
  else
  {
   ifstream ifile("VIDEO.dat",ios::in|ios::binary);
   int q1=0;  //Customer has not taken any CD
   int custfound=0;
   while(!ifile.eof())
   {
    ifile.read((char*)&cust,sizeof(cust));
    if(cust.custno==c)
    {
      custfound=1;
     if(cust.token==1)
     {
      q1=1; //Customer has already taken a CD
      break;
     }
    }
   }
   ifile.close();
   if(custfound==0)
   {
       cout<<"\n\t\tCustomer not found";
       getch();
   }
   else if(q1==1)
   {
     cout<<"\n\t\tCustomer has already taken a CD";
     getch();
   }
   else
   {
   if(q2==0 && q1==0)
   {
    fstream ft("TRANS.dat",ios::app|ios::binary);
    fstream ifile1("VIDEO.dat",ios::in|ios::out|ios::binary);
    fstream ofile1("DISK.dat",ios::out|ios::in|ios::binary);
    long int pp;
    //updating DISK.dat file
    while(!ofile1.eof())
    {
      pp=ofile1.tellg();
      ofile1.read((char *)&k,sizeof(k));
	      if(ofile1.eof()) break;
      if(k.cdno==cdd)
      {
	 strcpy(k.status,"ISSUED");
	 ofile1.seekp(pp);
	 ofile1.write((char *)&k,sizeof(k));
	 break;
      }
    }
    //updating customer file & Transaction file
    while(!ifile1.eof())
    {
     pp=ifile1.tellg();
     ifile1.read((char *)&cust,sizeof(cust));
     if(ifile1.eof()) break;
     if(cust.custno==c)
     {
       T.cust_no=c;
       T.cd_no=cdd;
       getdate(&d);
       T.pday=d.da_day;
       T.pmon=d.da_mon;
       T.pyear=d.da_year;
       strcpy(T.particular,"Issue");

       cust.cdtaken=cdd;
       cust.token=1;
       ifile1.seekp(pp);
       ifile1.write((char*)&cust,sizeof(cust));
       ft.write((char *)&T,sizeof(T));
       break;
     }
    }
    ifile1.close();
    ft.close();
    cout<<"\n\t\tCD issued sucessfully";
   }
  }
  }
  getch();
  textmode(LASTMODE);
  goto L1;
 } //**************RETURNING A CD*******************
 else if(ch=='H' || ch=='h')
 {
  int a;
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                                    RETURN CD                                    ");
  L10:
  int c,cdd;
  cout<<"Enter customer number: ";
  cin>>c;
  cout<<"Enter Cd number: ";
  cin>>cdd;
  fstream ifile3("VIDEO.dat",ios::in | ios::out | ios::binary);
  fstream ofile3("DISK.dat",ios::in | ios::out | ios::binary);
  fstream fh("TRANS.dat",ios::app | ios::binary);
  long int pl;
  int r1=0;
  while(!ifile3.eof())
  {
   pl=ifile3.tellg();
   ifile3.read((char*)&cust,sizeof(cust));
   if(cust.custno==c && cust.token==1 && cust.cdtaken==cdd)
   {
    //updating transaction file
    T.cust_no=c;
    T.cd_no=cdd;
    strcpy(T.particular,"Returning");
    getdate(&d);
    T.pday=d.da_day;
    T.pmon=d.da_mon;
    T.pyear=d.da_year;
    fh.write((char *)&T,sizeof(T));

    //updating customer file
    ifile3.seekp(pl);
    cust.cdtaken=0;
    cust.token=0;
    ifile3.write((char*)&cust,sizeof(cust));
    r1=1;//customer has taken cd
    break;
   }
  }
  ifile3.close();
  fh.close();
  if(r1==0)
  {
   cout<<"\nThis customer has not taken this cd";
   getch();
  }
  else
  {
   while(!ofile3.eof())
   {
    pl=ofile3.tellg();
    ofile3.read((char *)&k,sizeof(k));
    if(k.cdno==cdd)
    {
     strcpy(k.status,"AVAILABLE");
     ofile3.seekp(pl);
     ofile3.write((char*)&k,sizeof(k));
     break;
    }
   }
   cout<<"\n\t\tCD Returned sucessfully";
   ofile3.close();
  }
  getch();
  textmode(LASTMODE);
  goto L1;
 } //*************ADD CUSTOMER DETAILS*****************
 else if(ch=='I' || ch=='i')
 {
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                               ADD CUSTOMER DETAILS                             ");
  Customer ct;
  ct.add_cust();
  fstream f1("VIDEO.dat",ios::app|ios::binary);
  if(f1!=0)
  {
   f1.write((char*)&ct,sizeof(ct));
   n1++;
   cout<<"Customer Details succesfully added.\n";
   f1.close();
  }
  else
    cout<<"\n\t\tFile not opened";
  getch();
  textmode(LASTMODE);
  goto L1;
 } //****************DISPLAY ALL CUSTOMER DETAILS*******************
 else if(ch=='J' || ch=='j')
 {
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                          DISPLAY ALL CUSTOMER'S DETAILS                       ");
  ifstream f2("VIDEO.dat",ios::in|ios::binary);
  if(f2==0)
  {
    cout<<"\n\t\tNo customers added";
  }
  else
  {
   customers=0;
   while(!f2.eof())
   {
    f2.read((char*)&cust,sizeof(cust));
    if(f2.eof()) break;
    customers++;

    cust.display_cust();
   }
   f2.close();
   if(customers==0)
       cout<<"\n\t\tCustomers not found";
  }
  getch();
  textmode(LASTMODE);
  goto L1;
 }  //************DISPLAY DETAILS OF A CUSTOMER**************
 else if(ch=='K' || ch=='k')
 {
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                          DISPLAY ONE CUSTOMER'S DETAILS                        ");
  cout<<"\n\nEnter the customer number to be displayed : ";
  int p;
  char s1[20];
  Y13:
  cin>>s1;
  int e = validate_int(s1);
  if(e==-1)
  {
   cout<<"Invalid Input. Enter a Customer number with digits only.\n";
   goto Y13;
  }
  p=atoi(s1);
  ifstream f3("VIDEO.dat",ios::in|ios::binary);
  if(f3!=0)
  {
   int yfound=0;
   while(!f3.eof())
   {
    f3.read((char*)&cust,sizeof(cust));
    if(f3.eof()) break;
    if(cust.custno==p)
    {
     cust.display_cust();
     yfound=1;
     break;
    }
   }
   f3.close();
   if(yfound==0)
      cout<<"\n\t\tCustomer not found";
  }
  else
    cout<<"\n\t\tFile not opened";
  getch();
  textmode(LASTMODE);
  goto L1;
 } //****************MODIFY CUSTOMER DETAILS******************
 else if(ch=='L' || ch=='l')
 {
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                              MODIFY CUSTOMER DETAILS                            ");
  cno=0;
  L6:
  cout<<"\nEnter customer number to be modified : ";
  int t;
  char s1[20];
  Y14:
  cin>>s1;
  int e = validate_int(s1);
  if(e==-1)
  {
   cout<<"Invalid Input. Enter a customer number with digits only.\n";
   goto L6;
  }
  t=atoi(s1);
  fstream fo("VIDEO.dat",ios::out|ios::in|ios::binary);
  if(fo!=0)
  {
   long int pos;
   while(!fo.eof())
   {
    pos=fo.tellg();
    fo.read((char*)&cust,sizeof(cust));
    if(fo.eof()) break;
    if(t==cust.custno)
    {
     cno=2;
     cout<<"CURRENT DETAILS:-\n";
     cust.display_cust();
     cout<<"Modify details:-\n";
     cust.cmodify();
     fo.seekg(pos);
     fo.write((char*)&cust,sizeof(cust));
     cout<<"\nCustomer Details succesfully modified.\n";
     break;
    }
   }
   if(cno==0)
   {
    cout<<"Customer not found. Try Again.\n";
    goto L6;
   }
   fo.close();
  }
  else
     cout<<"\n\t\tFile not opened";
  getch();
  textmode(LASTMODE);
  goto L1;
 }  //*************DELETE CUSTOMER DETAILS****************
 else if(ch=='M' || ch=='m')
 {
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                              DELETE CUSTOMER DETAILS                           ");
  L7:

  cout<<"Enter customer number to be deleted : ";
  int t;
  char s1[20];
  Y15:
  cin>>s1;
  int e = validate_int(s1);
  if(e==-1)
  {
   cout<<"Invalid Input. Enter a CD number with digits only.\n";
   goto Y15;
  }
  t=atoi(s1);
  ifstream fin("VIDEO.dat",ios::in|ios::binary);
  ofstream fout("TEMP.dat",ios::out|ios::binary);
  int cy=0,fou=0;
  while(!fin.eof())
  {
   fin.read((char*)&cust,sizeof(cust));
   if(fin.eof()) break;
   if(t==cust.custno)
   {
    fou=1;
    if(cust.token==0)
    {
     cy=1;
     cout<<"CURRENT DETAILS:-\n";
     cust.display_cust();
     cout<<"Are you sure you want to delete customer details.? (Y/N)\n";
     char no;
     Y16:
     cin>>no;
     no=toupper(no);
     if(no!='Y'&& no!='N')
     {
      cout<<"Invalid Input. Choose either Y or N.\n";
      goto Y16;
     }
     if(no=='N')
     {
      fout.write((char*)&cust,sizeof(cust));
      cout<<"\n\t\tCustomer details are not deleted";
     }
     else if(no=='Y')
       cout<<"\n\t\tCustomer details are deleted successfully";
    }
    else
    {
     cout<<"\n\t\tThis customer has taken a cd. so cannot be deleted";
     getch();
     break;
    }
   }
   else
   {
    fout.write((char*)&cust,sizeof(cust));
   }
  }
   fin.close();
   fout.close();
   if(cy==1)
   {
   remove("VIDEO.DAT");
   rename("TEMP.dat","VIDEO.dat");
   }
   if(fou==0)
     cout<<"\n\t\tCustomer not found";
   getch();
   textmode(LASTMODE);
   goto L1;
 } //***************HISTORY OF ALL TRANSACTIONS*****************
 else if(ch=='N' || ch=='n')
 {
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                               HISTORY OF TRANSACTIONS                          ");
  ifstream fm("TRANS.dat",ios::in|ios::binary);
  if(fm!=0)
  {
   int cnt=1;
   while(!fm.eof())
   {
    if(cnt==1)
       cout<<setw(5)<<"\nS.No."<<setw(13)<<" Customer No."<<setw(10)<<"Cd Number"<<setw(15)<<"Particular"<<setw(12)<<"Date";
    fm.read((char*)&T,sizeof(T));
    if(fm.eof()) break;
    cout<<"\n"<<setw(3)<<cnt<<": ";
    T.disp_details();
     cnt++;
   }
   fm.close();
  }
  else
     cout<<"\n\t\tNo transactions happened";
  getch();
  textmode(LASTMODE);
  goto L1;
 } //**************TRANSACTIONS OF A CUSTOMER*****************
 else if(ch=='O' || ch=='o')
 {
  int ch1,e;
  char sd[20];
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  cprintf("                              HISTORY OF TRANSACTIONS                           ");
  ifstream fm1("TRANS.dat",ios::in|ios::binary);
  int cnt=1;
  OL:
  cout<<"Enter Customer no. : ";
  cin>>sd;
  e=validate_int(sd);
  if(e==-1)
  {
   cout<<"\ninvalid input.Enter again";
   goto OL;
  }
  ch1=atoi(sd);
  int fu=0;
  while(!fm1.eof())
  {
   fm1.read((char*)&T,sizeof(T));
   if(fm1.eof()) break;
   if(T.cust_no==ch1)
   {
    if(fu==0)
       cout<<setw(5)<<"\nS.No."<<setw(13)<<"Customer No."<<setw(10)<<"Cd Number"<<setw(15)<<"Particular"<<setw(12)<<"Date";
    ++fu;

    cout<<"\n"<<setw(5)<<cnt;
    T.disp_details();
    cnt++;
   }
  }
  if(fu==0)
     cout<<"\n\tNo transactions";
  getch();
  fm1.close();
  textmode(LASTMODE);
  goto L1;
 }
 else if(ch=='P' || ch=='p')
 {
  exit(0);
 }
 else
 {
  textmode(3);
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  cprintf("                          VIDEO LIBRARY MANAGEMENT SYSTEM                       ");
  textcolor(BLACK);
  textbackground(RED);
  cprintf("                                 INVALID CHOICE                                 ");
  cout<<"Enter a valid option, and try again.\n";
  getch();
  textmode(LASTMODE);
  goto L1;
 }
}