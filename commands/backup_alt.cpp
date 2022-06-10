#include<bits/stdc++.h>
using namespace std;

class User {
  private:

  int userId;
  string name;
  string email;
  int mobilenumber;

  public :
 
  int getuserId(){
    return this->userId;
  }
 
  string getname(){
    return this->name;
  }
 
  string getemail(){
    return this->email;
  }
 
  int getmobilenumber(){
    return this->mobilenumber;
  }

  void setuserId(int userId){
    this->userId = userId;
  }
 
  void setname(string name){
    this->name = name;
  }
 
  void setemail(string email){
    this->email = email;
  }
 
  void setmobilenumber(int mobilenumber){
    this->mobilenumber = mobilenumber;
  }

  user(string name,string email,int mobilenumber){
    setuserId(rand());
    setname(name);
    setemail(email);
    setmobilenumber(mobilenumber);
  }

};


class expense{
  private:
  int amount;
  string date;
  public:
  int getamount(){
    return this->amount;
  }

  string getDate(){
    return thsi->date;
  }

  void setamount(int amount){
    this->amount = amount;
  }

  void setDate(string date){
    this->date = date;
  }
  
};


int32_t main(){

}


// user        userId , name  , email , mobile  number
// Expense     EQUAL  , EXACT   or      PERCENT ------- amount -------- date + time
//