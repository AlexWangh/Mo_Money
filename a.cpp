node *p;
p=Head;
while (p!=nullptr){
    print(p->value);
    p=p->next;
}





Transaction *tail=p_head;
  Transaction *p_node2=p_head,*p_node3=nullptr,*p_node4=p_head,*p_node8=nullptr,*p_node9=nullptr;
  bool value;
  int nums=0,i,z=0;
  bool k=true;

  while (tail!=nullptr){
    nums=nums+1;
    tail=tail->get_next();
  }

  tail=p_head;
  int *sign=new int[nums];
  
  while (p_node4->get_next()!=nullptr){
    if (p_node4)
    for (i=0;i<nums;i++){
      if (sign[i]==(p_node4->get_trans_id())){
        k=false;
        break;
      }
    }
    continue;
    if (k=true){
      sign[z]=p_node4->get_trans_id();
    }

    while((p_node2->get_next())!=nullptr){
      value=*p_node2<(*p_node4);

      if (value==true){
        if (p_node2!=p_head){
          (p_node3->set_next(p_node4));
        }
        else{
          p_head=p_node4;
        }
        p_node4->set_next(p_node2);
      }
      p_node3=p_node2;//since we want to put tail between p_node2 and the node before it, p_node3 is the node before p_node2
      p_node2=(p_node2->get_next());
    }
    p_node2=p_head;
    p_node4=(p_node4->get_next());  
    z++;
  }








  Transaction *p_node7=p_head,*p_node8=p_head,*p_node11=p_head;
  int i,z,j,l,num_nodes=1;
  bool have_or_not;
  if (p_head==nullptr){
    num_nodes=0;
  }
  
  while (p_node7->get_next()!=nullptr){
    num_nodes++;
    p_node7=(p_node7->get_next());
  }
  p_node7=p_head;
  int arr[num_nodes];
  
  for (i=0;i<num_nodes;i++){
    j=i-1;
    Transaction *p_node9=nullptr,*p_node10=nullptr;
    
    for (z=0;z<num_nodes;z++){
      arr[z]=-1;
    }
      for (l=0;l<num_nodes;l++){
        if (p_node11->get_trans_id()==arr[l]){
          have_or_not=true;          
          break;
        }
        else{
          have_or_not=false;
          arr[p_node11->get_trans_id()]=p_node11->get_trans_id();
        }
      }
      if (have_or_not){
        i=i-1;
        continue;
      }

    for (z=0;z<num_nodes;z++){
      p_node7=p_node8;
      p_node8=p_node8->get_next();

      if ((p_node7->get_trans_id())==0){
        p_head=p_node7;
        break;
      }
      if ((p_node7->get_trans_id())==i){
        p_node9=p_node7;
      }

      if ((p_node7->get_trans_id())==j){
        p_node10=p_node7;
      }

      if (p_node9!=nullptr && p_node10!=nullptr){
        p_node10->set_next(p_node9);
      }

      if ((p_node7->get_trans_id())==(num_nodes-1)){
        p_node7->set_next(nullptr);
      }
    }
  }







 Transaction *p_node10=p_head;
  while ((p_node10->get_next())!=nullptr){
    p_node10=(p_node10->get_next());
  }

  int nums=p_node10->get_trans_id()+1;
  int arr[nums];
  int i,k,j,l;

  for (i=0;i<nums;i++){
    Transaction *p_node11=p_head;
    while(p_node11!=nullptr){
      if (i==(p_node11->get_trans_id())){
        arr[i]=(p_node11->get_trans_id());
      }
      p_node11=(p_node11->get_next());
    }

    for (i=0;i<nums;i++){
      j=arr[i];
      l=arr[i+1];
      Transaction *p_node12=p_head,*p_first=nullptr,*p_second=nullptr;

      while(p_node12!=nullptr){
        if ((p_node12->get_trans_id()==j)){
          p_first=p_node12;
        }
        else if ((p_node12->get_trans_id()==l)){
          p_second=p_node12;
        }
        p_node12=(p_node12->get_next());
      }

    }





  }

  Transaction *p_node7=p_head,*p_node8=p_head;
if (p_head==nullptr){
  
}
 while (p_node7->get_next()!=nullptr){
  while (p_node8->get_next()!=p_node7){
    if (p_node7)

    p_node8=p_node8->get_next;
  }

  p_node7=p_node7->get_next;
 }






    Transaction *p_node5=nullptr,*tail2=p_head;
    double acb=0,new_acb=0;
    double acb_per_share=0;
    unsigned int share_balance=0;
    double cgl=0;

    while ((tail2->get_next())!=nullptr){
      if (tail2==p_head){
        if (tail2->get_trans_type()==true){

          acb=(tail2->get_amount());
          share_balance=(tail2->get_shares());
        }
        else {
          acb=(-1)*(tail2->get_amount());
          share_balance=(-1)*(tail2->get_shares());
        }
      }

      else{
        if (tail2->get_trans_type()==true){
          acb=(p_node5->get_acb())+(tail2->get_amount());
          share_balance=(p_node5->get_share_balance())+(tail2->get_shares());
        }
        else {
          acb=(p_node5->get_acb())-(tail2->get_amount());
          share_balance=(p_node5->get_share_balance())-(tail2->get_shares());
        }
      }

      acb_per_share=acb/share_balance;

      if (acb_per_share<=0){
        acb_per_share=acb_per_share*(-1);
      }

      if(tail2->get_trans_type()==false){
        cgl=acb_per_share*(p_head->get_shares())*(-1)-(p_head->get_amount());
      }
      p_node5=tail2;
      tail2=(tail2->get_next());
    }

        while ((tail2->get_next())!=nullptr){
      p_node5=tail2; 
      tail2=(tail2->get_next());
    }

    acb=(p_node5->get_acb());
    new_acb=(tail2->get_amount());

    if (tail2->get_trans_type()==true){
      acb=acb+new_acb;
    }
    else{
      acb=acb-new_acb;
    }

    tail2=p_head;
    while ((tail2->get_next())!=nullptr){
      if (tail2->get_trans_type()==true){
      share_balance=share_balance+(tail2->get_shares());
      }
      else{
        share_balance=share_balance-(tail2->get_shares());
      }
      tail2=(tail2->get_next());
    }

    acb_per_share=acb/share_balance;

    tail2=p_head;
    while ()








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