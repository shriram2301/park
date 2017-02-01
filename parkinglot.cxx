#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
#define SIZE 100
int i=0,j=0,n;
class Car; //forward declaration

class ParkingSystem  // parking system class
 { int levels,slots;
  int p[SIZE][SIZE];
  
  public:
   virtual void getDetails(); //function to be overridden
   void show();
   void  checkassign(Car &obj);
   void reset(int l,int m);   
   


};
 
class Car:public ParkingSystem{ //car class
public:
 //char name[SIZE];
 int type;
 int level;
 int slot,time;
 int charges=1;

void getDetails();
void leave(ParkingSystem &pr);
 

 
};
void ParkingSystem::reset(int l,int m)
{ 
    p[l][m]=0;
}

void ParkingSystem::getDetails() //creating parking lot
{ 
   cout<<"\n enter the details of parking system";
   cin>>levels>>slots;
    for(i=0;i<levels;i++)
 {   for(j=0;j<slots;j++)
   {
       p[i][j]=0;
}

}

}

void ParkingSystem::show() //showing details
{
    for(i=0;i<levels;i++)
    {  cout<<"\n";
      for(j=0;j<slots;j++)
{     cout<<p[i][j]<<"\t";
}
}
}
void ParkingSystem::checkassign(Car &obj) // checking availability and assign
{   int j=0;
    while(j<slots)
   {    if(p[obj.level][j]==0)
        {p[obj.level][j]=1;
        obj.slot=j;
         break;
       }
           j++;     // I haven't genera
}   
         
      

  
}


void Car::leave(ParkingSystem &pr)//leaving lot
{   int h1=4,h2=2,h4=1; 
    cout<<"enter time \n";
      cin>>time;
    
      
cout<<"\nCharges are :="<<charges;// chuck this math I will do later

  pr.reset(level,slot);
     
    
  

}

void Car::getDetails()// get car id level info and overriding
{
   cout<<"\n enter the cars level" ;
   cin>>level;
  level=level-1;


}



int main()
{ int count;
  ParkingSystem pr; // can I use a pointer here also? I didn't bother cause there is only one instance of it 
  Car *c;
  pr.getDetails();
  pr.show();
cout<<"\n enter the number of cars entering";
cin>>n;
c=new Car[n];

   
     for(i=0;i<n;i++)
  {      c[i].getDetails();
      pr.checkassign(c[i]);

}
     pr.show();     
      for(i=n-1;i>=0;i--)
    {    c[i].leave(pr);
        
}
   pr.show();
delete c;
   
  
return 0;
}
