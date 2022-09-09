#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val){
  //empty list
  if (head_==NULL && tail_==NULL) 
  {
    Item* temp = new Item();
    temp->val[0]=val;
    temp->last++;
    head_=temp;
    tail_=temp;
  }
  //if unable to add to end of tail array
  else if (tail_->last==ARRSIZE)
  {
    Item* temp=new Item();
    temp->val[0]=val;
    temp->last++;
    temp->prev=tail_;
    tail_->next=temp;
    tail_=temp;

  }
  else
  {
    tail_->val[tail_->last]=val;
    tail_->last++;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val){
  //empty list
  if (head_==NULL && tail_==NULL) 
  {
    Item* temp = new Item();
    temp->val[ARRSIZE-1]=val;
    temp->last=ARRSIZE;
    temp->first=ARRSIZE-1;
    head_=temp;
    tail_=temp;
  }
  //if unable to add to front of head array
  else if (head_->first==0)
  {
    Item* temp=new Item();
    temp->val[ARRSIZE-1]=val;
    temp->last=ARRSIZE;
    temp->first=ARRSIZE-1;
    head_->prev=temp;
    temp->next=head_;
    head_=temp;
  }
  else
  {
    head_->val[head_->first-1]=val;
    head_->first--;
  }
  size_++;
}

void ULListStr::pop_back(){
  //deallocate if removing the only item in an array
  if (tail_->last==1)
  {
    Item* temp = tail_;
    tail_=tail_->prev;
    delete temp;
  }
  else
  {
    tail_->last--;
  }
  size_--;
}

void ULListStr::pop_front () {
  //deallocate if removing the only item in an array
  if (head_->first==(ARRSIZE-1))
  {
    Item*temp=head_;
    head_=head_->next;
    delete temp;
  }
  else
  {
    head_->first++;
  }
  size_--;
}

std::string const & ULListStr::back() const{

  return (tail_->val[tail_->last-1]);
}

std::string const & ULListStr::front() const{
  return (head_->val[head_->first]);
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  int newloc=(int)loc;
  if (loc>(size_-1))
  {
    return NULL;
  }
  //number of items in head array
  int startsize=head_->last-head_->first;
  int index;
  int boxnumber;
  //index in the given "box"
  index=((newloc-startsize)%10);
  //the linked list # that the loc resides in
  boxnumber=(newloc-startsize-1)/10+1;
  if (newloc<startsize)
  {
    return &head_->val[newloc+(head_->first)];
  }
  Item* cur=head_;
  for (int i=0; i<boxnumber; i++)
  {
    cur=cur->next;
  }
  std::string* value = &(cur->val[index]);
  return value;
}
