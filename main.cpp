/* This program is to display the total charge should be paid by each customer, number of customers.
total weight of fabric (kg) and total charge for all customers */
#include <iostream>                //to handle output (cout) and input (cin)
#include <cctype>                  //library function for tolower
using namespace std;  //variable created inside namespace


//function prototype to store value and processed value in a computer memory
int inputData(int &ID ,double &W ,char &C , char &S);
double calcBasicCharge (double &W , double &T);
double calcAddService (char &Serv ,double &SC);
double displayReceipt(int &ID , double &W ,char &S , double &Tp); //function prototype

int main()   //main function
{
    //variable declaration
int custID ;
double weightFabric ,basicCharge ,serviceCharge ,totalPay ;
char custStatus ,service  ;

int count = 0;
char nextCust ='Y';
double sum = 0.0;
while (tolower(nextCust)!='n'){   //while loop unti line 40


inputData(custID , weightFabric , custStatus , service); //function call
calcBasicCharge(weightFabric, basicCharge); //function call
calcAddService (service,serviceCharge); //function call


if(tolower (custStatus) == 'r'){
totalPay = calcBasicCharge(weightFabric, basicCharge) + calcAddService(service,serviceCharge) - 1; //calculate the total pay if the customer is regular
}
if(tolower (custStatus) == 'w'){
totalPay = calcBasicCharge(weightFabric, basicCharge) + calcAddService(service,serviceCharge); //calculate the total pay if the customer is new
}
displayReceipt(custID , weightFabric ,service ,totalPay); //function call

count = count + 1; //to calculate total customer entry
sum+=totalPay;  // to calculate total collection
cout << "Next customer (Y / N) :";
cin >> nextCust;
}
cout << "Total customer :"<<count<<endl; //display the total customer entry
cout << "Total collection :RM"<<sum ; // display the total collection from the sale


   return 0;
}

int inputData(int &ID ,double &W ,char &C , char &S){
cout << "Enter your customer ID : ";
cin >> ID;                                // input for customer ID
cout << "Enter customer status (R -regular / W -new) :";
cin >> C;                                 //input for customer status
cout << "Enter weight of fabric : ";
cin >> W;                                 //input of weight of fabric

cout << "\n  (A)        No additional service"<<endl;                         // Label display for additional service
cout << "  (B)        Fabric and collection service          - extra charge RM3.00 "<<endl;
cout << "  (C)        Delivery service only                  - extra charge RM3.00 "<<endl;
cout << "  (D)        Fabric collection and delivery service - extra charge RM6.00"<<endl<<endl;
cout << "Enter additional service if any : ";
cin >> S ;                                //input for additional service

}
double calcBasicCharge(double &W , double &T ){
if(W <= 4){
    T = W * 2; //calculate the basic charge if the weight is lower or equal than 4kg
}
else {
    T = (W-4) * 1.5 + 8; //calculate the basic charge if the weight is greater than 4kg
}
return T ;  //return the value of the basic charge to main function
}
double calcAddService (char &Serv ,double &SC){
if (tolower (Serv) == 'a'){
    SC = 0;             //to declare the value of the service charge if the customer choose a / A label
}
else if (tolower (Serv) == 'b'){
    SC = 3;             //to declare the value of the service charge if the customer choose b / B label
}
else if (tolower (Serv) == 'c'){
    SC = 3;             //to declare the value of the service charge if the customer choose c / C label
}
else if (tolower (Serv)== 'd'){
    SC = 6;             //to declare the value of the service charge if the customer choose d / D label
}
return SC;   // return the value of the service charge to main function
}
double displayReceipt(int &ID , double &W ,char &S ,double &Tp){
cout <<"\n------------ ROTAN TUNGGAL FABRIC FOLDING SERVICE ------------------------"<<endl<<endl;
cout << "Customer ID: "<<ID<<endl;    //display label for customer ID
cout << "Fabric Weight: "<<W<<"kg"<<endl; // display label for fabric weight

if (tolower (S) == 'a'){
    cout << "Additional Service: (A) No additional service"<<endl;   //display the type of additional service that the customer chose
}
if (tolower (S) == 'b'){
    cout << "Additional Service: (B) Fabric and collection service"<<endl;    //display the type of additional service that the customer chose

}
if (tolower (S) == 'c'){
    cout << "Additional Service: (C) Delivery service only"<<endl;     //display the type of additional service that the customer chose

}
if (tolower (S) == 'd'){
    cout << "Additional Service: (D) Fabric and collection and delivery service"<<endl;   //display the type of additional service that the customer chose

}
else{
    cout << "Wrong char , pease retry again"<<endl;
}

   cout<< "Total payment : RM"<< Tp <<endl;   //display the total payment that the customer need to pay



cout <<"\n--------------------- THANK YOU VERY MUCH !------------------------------- " << endl<<endl;
cout <<"==========================================================================="<<endl;
}
