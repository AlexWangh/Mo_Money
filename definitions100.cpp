#include <cassert>
#include <iomanip>
#include <iostream>

#include "project4.hpp"
#include "History.hpp"
#include "Transaction.hpp"

////////////////////////////////////////////////////////////////////////////////
// Definitions for Transaction class
////////////////////////////////////////////////////////////////////////////////
//
//

// Constructor
// TASK 1
//Give the value to each class variable and object variables.

Transaction::Transaction(std::string ticker_symbol, unsigned int day_date, unsigned int month_date,unsigned year_date, 
bool buy_sell_trans, unsigned int number_shares, double trans_amount){

  symbol=ticker_symbol;
  day=day_date;
  month=month_date;
  year=year_date;
  if (buy_sell_trans){
    trans_type="Buy";
  }
  else {
    trans_type="Sell";
  }
  shares=number_shares;
  amount=trans_amount;
  trans_id=Transaction::assigned_trans_id;
  acb=0.0;
  acb_per_share=0.0;
  share_balance=0;
  cgl=0.0;
  p_next=nullptr;

  Transaction::assigned_trans_id=Transaction::assigned_trans_id+1;
}


// Destructor
// TASK 1
//
Transaction::~Transaction(){


}


// Overloaded < operator.
// TASK 2
//Compare the date by year,month, and day respectively. Then compare trans_id.

bool Transaction::operator<( Transaction const &other ){
  if (other.year<year){
    return true;
  }
  else if (other.year>year){
    return false;
  }
  else if (other.year==year){
    if (other.month<month){
      return true;
    }
    else if(other.month>month){
      return false;
    }
    else if (other.month==month){
      if (other.day<day){
        return true;
      }
      else if (other.day>day){
        return false;
      }
      else{
        if (trans_id<other.trans_id){
          return true;
        }
        else {
          return false;
        }
      }
    }
  }
}

// GIVEN
// Member functions to get values.
//
std::string Transaction::get_symbol() const { return symbol; }
unsigned int Transaction::get_day() const { return day; }
unsigned int Transaction::get_month() const { return month; }
unsigned int Transaction::get_year() const { return year; }
unsigned int Transaction::get_shares() const { return shares; }
double Transaction::get_amount() const { return amount; }
double Transaction::get_acb() const { return acb; }
double Transaction::get_acb_per_share() const { return acb_per_share; }
unsigned int Transaction::get_share_balance() const { return share_balance; }
double Transaction::get_cgl() const { return cgl; }
bool Transaction::get_trans_type() const { return (trans_type == "Buy") ? true: false ; }
unsigned int Transaction::get_trans_id() const { return trans_id; }
Transaction *Transaction::get_next() { return p_next; }

// GIVEN
// Member functions to set values.
//
void Transaction::set_acb( double acb_value ) { acb = acb_value; }
void Transaction::set_acb_per_share( double acb_share_value ) { acb_per_share = acb_share_value; }
void Transaction::set_share_balance( unsigned int bal ) { share_balance = bal ; }
void Transaction::set_cgl( double value ) { cgl = value; }
void Transaction::set_next( Transaction *p_new_next ) { p_next = p_new_next; }

// GIVEN
// Print the transaction.
//
void Transaction::print() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(4) << get_trans_id() << " "
    << std::setw(4) << get_symbol() << " "
    << std::setw(4) << get_day() << " "
    << std::setw(4) << get_month() << " "
    << std::setw(4) << get_year() << " ";


  if ( get_trans_type() ) {
    std::cout << "  Buy  ";
  } else { std::cout << "  Sell "; }

  std::cout << std::setw(4) << get_shares() << " "
    << std::setw(10) << get_amount() << " "
    << std::setw(10) << get_acb() << " " << std::setw(4) << get_share_balance() << " "
    << std::setw(10) << std::setprecision(3) << get_acb_per_share() << " "
    << std::setw(10) << std::setprecision(3) << get_cgl()
    << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// Definitions for the History class
////////////////////////////////////////////////////////////////////////////////
//
//


// Constructor
// TASK 3
//
History::History(){
  p_head=nullptr;
}


// Destructor
// TASK 3
//
History::~History(){

  Transaction *p_node6=p_head;

  //delete the dynamically allocated array that we created
  while(p_node6!=nullptr){
    Transaction *t=p_node6;
    p_node6=p_node6->get_next();    
    delete t;
  }
}


// read_history(...): Read the transaction history from file.
// TASK 4
//
void History:: read_history(){
  ece150::open_file();

  //insert all the nodes to the linked_list.
  while (ece150::next_trans_entry()){

    Transaction *node=new Transaction (ece150::get_trans_symbol(),ece150::get_trans_day(),
    ece150::get_trans_month(),ece150::get_trans_year(),ece150::get_trans_type(),
    ece150::get_trans_shares(),ece150::get_trans_amount());
    
    insert(node);
  }
    ece150::close_file();
}// create linked_list

// insert(...): Insert transaction into linked list.
// TASK 5
//
void History::insert( Transaction *p_new_trans ){
  Transaction *p_node=p_head;

  //let p_head points to the first node
  if (p_head==nullptr){
    p_head=p_new_trans;
  }
  else {
    while((p_node->get_next())!=nullptr){ 
      p_node=(p_node->get_next());
    }//get the last node

    //insert the new node after the last node in the linked-list.
    p_node->set_next(p_new_trans);
  }
}

// sort_by_date(): Sort the linked list by trade date.
// TASK 6
//
void History::sort_by_date(){
  Transaction *p_node7=p_head,*p_node8=p_head,*p_node9=p_head;
  if (p_head==nullptr){
    return;
  }
 while (p_node7!=nullptr){
  while (p_node8->get_next()!=p_node7){
    if (*p_node7<*p_node8){
      p_node9->set_next(p_node7);
      p_node7->set_next(p_node8);
    }

    p_node9=p_node8;
    p_node8=(p_node8->get_next());
  }
  p_node8=p_head;

  p_node7=(p_node7->get_next());
 }

}

// update_acb_cgl(): Updates the ACB and CGL values.
// TASK 7
//
void History::update_acb_cgl(){

  Transaction *pre=nullptr,*node=p_head;
  double acb=0,new_acb=0;
  double acb_per_share=0;
  unsigned int share_ba=0;
  double cgl=0;

  while (node!=nullptr){
    if (node->get_trans_type()==true){
    acb=acb+(node->get_amount());
    share_ba=share_ba+(node->get_shares());
    acb_per_share=acb/share_ba;
    cgl=0;
    }
    else{
      acb=acb-acb_per_share*(node->get_shares());
      share_ba=share_ba-(node->get_shares());
      acb_per_share=acb/share_ba;
      (node->get_amount())-(node->get_shares())*acb_per_share;
    }
    node->set_acb(acb);
    node->set_acb_per_share(acb_per_share);
    node->set_share_balance(share_ba);
    node->set_cgl(cgl);

    node=node->get_next();
  }

}

// compute_cgl(): )Compute the ACB, and CGL.
// TASK 8
double History::compute_cgl(unsigned int year){
  return 0.0;

}

// print() Print the transaction history.
//TASK 9
//
void History::print(){
  Transaction* node=p_head;

  while(node!=nullptr){
    std::cout << std::setprecision(2) << std::fixed;//we need to get the number of digits as 2
    std::string trans_type;

    //instead of 1 and 0, we need to print the trans_type to the form of "Buy" or "Sell".
    if (node->get_trans_type()==1){
      trans_type="Buy";
    }
    else {
      trans_type="Sell";
    }

    std::cout<<node->get_trans_id()<<"\t";
    std::cout<<node->get_symbol()<<"\t";
    std::cout<<node->get_day()<<"\t";
    std::cout<<node->get_month()<<"\t";
    std::cout<<node->get_year()<<"\t";
    std::cout<<trans_type<<"\t";
    std::cout<<node->get_shares()<<"\t";
    std::cout<<node->get_amount()<<"\t";
    std::cout<<node->get_acb()<<"\t";
    std::cout<<node->get_share_balance()<<"\t";
    std::cout << std::setprecision(3) << std::fixed;//we need to keep the number of digits as 3
    std::cout<<node->get_acb_per_share()<<"\t";
    std::cout<<node->get_cgl()<<"\n";

    node=node->get_next();
  }
}

// GIVEN
// get_p_head(): Full access to the linked list.
//
Transaction *History::get_p_head() {return p_head;}
