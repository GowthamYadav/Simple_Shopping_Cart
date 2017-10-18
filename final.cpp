#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;

class cart
{
 private:        //  declaring the private functions
      int capacity;            //the private fucntions 
 //once entered cannot be changed and is not accessible
     int elements_in_cart=0;
     struct product
     {
         int product_code;      
         string product_name;
         int product_cost;
         int product_rating;
         product *next;
     }*list;
 public:       // here we are Initialising the fuctions
     cart();         // empty list constructor
    void  init(int n);
    void asc_name_sorting();
    void des_name_sorting();
    void sorting();
    void ratingsort();
    int count();
    void insert();
    void  remove();
    void del();
    void display();
    void  currentTotal();
 };
cart::cart()    // constructor
{
    list=NULL;
}
 void cart::init(int n)
 {
     capacity=n;
 }
// to add an item in to the cart
void cart :: insert()
{
	product *p;
	int n;

	cout<<"elements in cart now:"<<
	elements_in_cart<<endl;


	if (elements_in_cart == capacity)
	{
		cout<<"cart is full"<<endl;
		return;
	}
	p=new product;     // create new node
	cout << "\nenter the product code\n";
	cin >> p->product_code;
	cout << "\nenter the product name\n";
	{	
	cin.ignore(100,'\n');
	getline(cin,p->product_name);
    }
	//cin >> p->product_name;
	cout << "\nenter the product cost\n";
	cin >> p->product_cost;
	cout<<"\npopuarity of the product\n";
    cin>>p->product_rating;
    if(p->product_rating>5)
{
    cout<<"you can rate the product on the scale of 0-5"<<endl<<"Enter the correct rate"<<endl;
    cin>>p->product_rating;
}
    p->next=list;        // head now follows p
	list=p;          // p is now the head
	elements_in_cart++;
}

//to remove an item from the cart
void cart::del()      // remove front item
{   int num;
    cout<<"\n\tEnter product code you need to remove\t";
    cin>>num;
    cout<<num<<endl;
   product *old,*temp;  // save current head
   temp=list;
   while(temp!=NULL)   //checks whether the node is empty or not ..if found proceed to if loop
   {
     if(temp->product_code==num)    //check the node for  a data
      {

             if(temp==list)

            list=temp->next;
        else
        old->next=temp->next;    // skip over old head
         
	delete temp;           // delete the old head
       
	return ;
     }
        else
        {
            old=temp;
            temp=temp->next;
        }

  }
 cout<<"\n\tYour required product is absent"<<endl;
}
// to view the items that are present in the cart
void cart :: display()
{
	product *p;

	p=list;
	if(p==NULL)
	   {
	   
		cout << "\n There are no products in the cart to display\n";
	   }
	 else  
		
		cout<<"\n\t\t\"PRODUCTS IN YOUR CART ARE\"\n";
	for (p=list;p!=NULL;p=p->next)
	{
	    cout<<"\tproduct code:"<<p->product_code<<"\tproduct name:"<<p->product_name<<"\t product cost:Rs"<<p->product_cost<<"\tProduct Ratings:"<<p->product_rating<<endl;
	}
}
// to calculate the net amount from the cart also display the items in cart
void cart :: currentTotal()
{
	product *p;
	int total_cost=0;
	p=list;
	if(p==NULL)
		cout<<"\nYour cart is empty\n";
	else
	{
			
    cout<<"\t____________________________________________________________\n";

	for (p=list;p!=NULL;p=p->next)
	{
        total_cost+=p->product_cost;
		cout<<"\tYour product code:\t"<<p->product_code<<"\tYour product cost:\t"<<p->product_cost<<"\n";
	}
    cout<<"\t____________________________________________________________\n";
cout<<"\t__________________________\n";
cout<<"\n\tCurrent total cost:Rs."<<total_cost<<"\n";
cout<<"\t__________________________\n";
    }
}
//to arrange the elements in ascending order (low to high price)
void cart::asc_name_sorting()   //sorting according low to high price
{
product *temphead=list;
product *tempnode=NULL;
int tempproduct_code;
int counter=0;
int tempproduct_cost;
string tempproduct_name;
int tempproduct_rating;
while(temphead)
{
temphead=temphead->next;
counter++;
}
temphead=list;                                              
for(int j=0;j<counter;j++)
{
while(temphead->next)
{
if(temphead->product_cost>temphead->next->product_cost)
{
tempproduct_cost=temphead->product_cost;
temphead->product_cost=temphead->next->product_cost;
temphead->next->product_cost=tempproduct_cost;

tempproduct_code=temphead->product_code;
temphead->product_code=temphead->next->product_code;
temphead->next->product_code=tempproduct_code;

tempproduct_name=temphead->product_name;
temphead->product_name=temphead->next->product_name;
temphead->next->product_name=tempproduct_name;

tempproduct_rating=temphead->product_rating;
temphead->product_rating=temphead->next->product_rating;
temphead->next->product_rating=tempproduct_rating;

temphead=temphead->next;

}
else
temphead=temphead->next;
}
temphead=list;
}
display();
}
//to arrange the elements in ascending order (high to low price)
void cart::des_name_sorting()    //sorting according high to low price
{
product *temphead=list;
product *tempnode=NULL;
int tempproduct_code;
int counter=0;
int tempproduct_cost;
string tempproduct_name;
int tempproduct_rating;
while(temphead)
{
temphead=temphead->next;
counter++;
}
temphead=list;
for(int j=0;j<counter;j++)
{
while(temphead->next)
{
if(temphead->product_cost<temphead->next->product_cost)
{

tempproduct_cost=temphead->product_cost;
temphead->product_cost=temphead->next->product_cost;
temphead->next->product_cost=tempproduct_cost;

tempproduct_code=temphead->product_code;
temphead->product_code=temphead->next->product_code;
temphead->next->product_code=tempproduct_code;

tempproduct_name=temphead->product_name;
temphead->product_name=temphead->next->product_name;
temphead->next->product_name=tempproduct_name;

tempproduct_rating=temphead->product_rating;
temphead->product_rating=temphead->next->product_rating;
temphead->next->product_rating=tempproduct_rating;

temphead=temphead->next;


}
else
temphead=temphead->next;
}
temphead=list;
}
display();
}

void cart::ratingsort()    //sorting according ratings
{
product *temphead=list;
product *tempnode=NULL;
int tempproduct_rating;
int counter=0;
int tempproduct_cost;
int tempproduct_code;
string tempproduct_name;

while(temphead)
{
temphead=temphead->next;
counter++;
}
temphead=list;
for(int j=0;j<counter;j++)
{
while(temphead->next)
{
if(temphead->product_rating<temphead->next->product_rating)
{

tempproduct_name=temphead->product_name;
temphead->product_name=temphead->next->product_name;
temphead->next->product_name=tempproduct_name;

tempproduct_cost=temphead->product_cost;
temphead->product_cost=temphead->next->product_cost;
temphead->next->product_cost=tempproduct_cost;

tempproduct_code=temphead->product_code;
temphead->product_code=temphead->next->product_code;
temphead->next->product_code=tempproduct_code;

tempproduct_rating=temphead->product_rating;
temphead->product_rating=temphead->next->product_rating;
temphead->next->product_rating=tempproduct_rating;
temphead=temphead->next;
}
else
temphead=temphead->next;
}
temphead=list;
}
display();
}
//reading from file
void file(string filename)
{
	ifstream fp(filename.c_str());
      {
	  
    if( fp.fail())
    {
        cout << "Sorry data file not found...." << endl;
    }
    else
    {
            char rec[80];
            do
            {
                    fp.getline( rec , 80);
                    cout << rec << endl;
            }
            while( !fp.eof());
            fp.close();
    }
}

	}	


int main()
{
   cart c1;
   int choice,n,c;
   void file(string filename);
   cout<<"\n \t                ~!WELCOME TO ONLINE SHOPPING!~  \n ";
   cout<<"\t -----------------------------------------------------\n";
   cout  << "\n enter the desired cart size:\t";
   cin >> n;
   c1.init(n);
   l1: cout<<"1 Offers\n2 Electronics\n\n\n";
    cin>>c;
    switch(c)
      {
      	case 1:file("d:/offers.txt");
      	        break;
      	case 2:file("d:/electronics.txt");
      	        break;
		default:
		         break;		      	
		 }
   
  do
{
cout<<"\t-----------------------------------------------------------";
cout<<"\n \t1:\tAdd a Product into your cart\n\n\t2:\tRemove an Product from your cart\n\n\t3:\tDisplay products in the your cart\n\n\t";
cout<<"4:\tShow curent total cost of all products in your cart\n\n\t5:\tSort Products\n\n\t6:\tcontinue\n\t";
cout<<"-----------------------------------------------------------\n";
cout<<"\n\nEnter your choice\t";
cin>>choice;

      switch(choice)
      {
           case 1:
                  c1.insert();
                  break;
           case 2:
                  c1.del();
                  break;
           case 3:
                  c1.display();
                  break;
           case 4:
			      c1.currentTotal();
                  break;
           case 5:
cout<<"\n\t --->> 1 to view from low to high price\n\tor\n\t --->> 2 to view from high to low price\n\tor\n\t ---> 3 to view according to ratings ";
cout<<"\n Enter your choice\t";
int num;
cin>>num;
if(num==1)
c1.asc_name_sorting();
else if(num==2)
c1.des_name_sorting();
else
c1.ratingsort();
break;
          case 6:goto l1;
                    break;
        default:
           	       exit(0);
           	       break;
  }
}
while(choice != 7);
return 0;
}


