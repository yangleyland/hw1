/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr testcase;
  cout<<"PRELIMINARY TESTS"<<endl;
  //initial test for push_back
  testcase.push_back("a");
  cout<<"Pushing back one value on empty set, should output just 'a' and size 1: "<<endl;
  cout <<"size: "<< testcase.size()<<", "<< testcase.get(0)<<endl;
  cout<<"Retrieving front value and back value from a 1 item set, should return 'aa':"<<endl;
  cout<<testcase.front()<<testcase.back()<<endl;
  testcase.push_back("b");
  testcase.push_back("c");
  testcase.push_back("d");
  cout<<"Pushing back 3 values on a non-empty set, should output just 'abcd' and size 4: "<<endl;
  cout<<"size: "<< testcase.size()<<", "<<testcase.get(0)<<testcase.get(1)<<testcase.get(2)<<testcase.get(3)<<endl;
  cout<<"Retrieving front and back item from a multi-item set, should return 'ad': "<<endl;
  cout<<testcase.front()<<testcase.back()<<endl;
  testcase.clear();

  //initial test for push_front
  testcase.push_front("a");
  cout<<"Pushing front one value on empty set, should output just 'a' and size 1: "<<endl;
  cout <<"size: "<< testcase.size()<<", "<< testcase.front()<<endl;
  testcase.push_front("b");
  testcase.push_front("c");
  testcase.push_front("d");
  cout<<"Pushing front 3 values on a non-empty set, should output just 'dcba' and size 4: "<<endl;
  cout<<"size: "<< testcase.size()<<", "<<testcase.get(0)<<testcase.get(1)<<testcase.get(2)<<testcase.get(3)<<endl;

  //intial test for pop_back
  testcase.pop_back();
  cout<<"popping back of dcba, should output just 'dcb' and size 3: "<<endl;
  cout<<"size: "<< testcase.size()<<", "<<testcase.get(0)<<testcase.get(1)<<testcase.get(2)<<endl;

  //initial test for pop_front
  testcase.pop_front();
  cout<<"popping front of dcb, should output just 'cb' and size 2"<<endl;
  cout<<"size: "<< testcase.size()<<", "<<testcase.get(0)<<testcase.get(1)<<endl;

  //large set test cases
  cout<<"LARGE TEST CASES"<<endl;
  testcase.clear();
  
  for (int i=0; i<50; i++)
  {
    testcase.push_front("a");
  }
  for (int i=0; i<50; i++)
  {
    testcase.push_back("b");
  }
  cout<<"pushes 50 a's to the front and 50 b's to the back, should have size 100"<<endl;
  cout<<"size: "<<testcase.size()<<", ";
  for (int i=0; i<100; i++)
  {
    cout<<testcase.get(i);;
  }
  cout<<endl;

  testcase.pop_front();
  testcase.pop_back();

  cout<<"pop front and back of large set, should have size 98: "<<endl;
  cout<<"size: "<<testcase.size()<<", ";
  for (int i=0; i<98; i++)
  {
    cout<<testcase.get(i);;
  }
  cout<<endl;
  return 0;
}
