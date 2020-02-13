#include <cstdio>
#include <iostream>
using namespace std;
class listNode{
    public:
        listNode* next;
        listNode* previous;
        char    data;
        listNode(char data):data(data){};
        int operator > (const listNode &tmp){
            return this->data>tmp.data;
        }
       int operator < (const listNode &tmp){
            return this->data<tmp.data;
        }
};
class LinkedList{
    public:
        listNode* head=nullptr;
        listNode* end=nullptr;
        LinkedList& listPush(char data){
            listNode* tmp=new listNode(data);
            if(end==nullptr && head==nullptr){
                end=head=tmp;
                end->next=nullptr;
                end->previous=nullptr;
            }
            else{
                end->next=tmp;
                tmp->previous=end;
                end=tmp;
                end->next=nullptr;
            }
            return *this;

        }
        LinkedList& listPush(listNode data){
             if(end==nullptr && head==nullptr)
                end=head=&data;
            else{
                end->next=&data;
                (&data)->previous=end;
                end=&data;
                end->next=nullptr;
            }
            return *this;
        }
        listNode* listPop(){
            listNode* tmp;
            if(end==nullptr && head==nullptr)
                return nullptr;
            else if(head==end){
                tmp=head;
                head=end=nullptr;
                return tmp;
            }
            else
            {
                tmp=end;
                end=end->previous;
                end->next=nullptr;
                return tmp;
            }
        }
        listNode* listSelectNumber(int number){
            int i=0;
            listNode* tmp=head;
            while(tmp!=nullptr){
                if(i==number)
                    return tmp;
                tmp=tmp->next;
                i++;
            }
            return nullptr;

        }
        int  printlist(){
            listNode *tmp=head;
            for(tmp;tmp!=nullptr;tmp=tmp->next)
                cout<<tmp->data<<' ';
            cout<<endl;
        } 
        LinkedList&  operator+ (char const & data){
                return listPush(data);
        };
         LinkedList&  operator- (char const & data){
                listNode *tmp=end;
                for(tmp;tmp!=nullptr;tmp=tmp->previous){
                    if(data==tmp->data && tmp==end){
                        if(end==head){
                            this->head=this->end=nullptr;
                            delete tmp;
                            break;
                        }

                        tmp->previous->next=nullptr;
                        end=tmp->previous;
                        delete tmp;
                        break;
                    }
                    else if(data==head->data && tmp==head){
                        tmp->next->previous=nullptr;
                        head=head->next;
                        delete tmp;
                        break;
                    }
                    else if(data==tmp->data){
                        tmp->previous->next=tmp->next;
                        tmp->next->previous=tmp->previous;
                        delete tmp;
                        break;
                    }

                    
                }
                return *this;
                
        }
        listNode& operator[](const int& number){
            return *listSelectNumber(number);
        }
        ~LinkedList(){
            listNode* tmp=head;
            listNode* target=tmp;
            while(tmp!=nullptr){
                tmp=tmp->next;
                delete target;
                target=tmp;
            }
        }
        
};
 ostream& operator<<(ostream&os,const listNode* data){
     os<<data->data;
     return os;
 }
  ostream& operator<<(ostream&os,const listNode& data){
     os<<data.data;
     return os;
 }

 istream &operator>>( istream &is,LinkedList& data) {
     char c;
     is>>c;
     data.listPush(c);
     return is;
 } 
 istream &operator>>( istream &is,LinkedList* data) {
     char c;
     is>>c;
     data->listPush(c);
     return is;
 } 

int main(int argc,char *argv[]){
    LinkedList test;
    test+'A'+'B'+'7'+'0';
    cout<<(*test.listSelectNumber(0)>*test.listSelectNumber(1))<<endl;
    test.printlist();
    cout<<test.listSelectNumber(2)<<endl;
    cout<<test[2]<<endl;
    cin>>test;

    LinkedList* test2=new LinkedList;
    test+'1'+'2';
    cout<<(*test2)[1];
    return 0;
}