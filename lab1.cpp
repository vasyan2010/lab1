#include <stdlib.h>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

template <typename T>
class ARR{   
	private:
		struct list
		{
			T num;
			list *next;
			list *prev;
		};
		int size; 
		list *head;
		list *end;
		
	public:
		ARR()
		{ 
			head=NULL;
			end=NULL;
			size=0;
		};
		~ARR(){};
		/* 6 */
		void at(int index)
		{
			printf("Search by Index\n");
			list *gettingList; 
			if (index>size)
			{
				printf("No item with this index exists\n");
				gettingList=NULL;
			}
			else
			{
				gettingList=head;
				for (int i=1;i<index;i++)
				{
					gettingList=gettingList->next;
				}
				printf("Element with an index %d = ",index);
				cout<<gettingList->num<<endl;
			}
		}
		/* 6 with pointer */
		list * getForIndex(int index)
		{
			list *gettingList; 
			if (index>size)
			{
				printf("No item with this index exists.\n");
				gettingList=NULL;
			}
			else
			{
				gettingList=head;
				for (int i=1;i<index;i++)
				{
					gettingList=gettingList->next;
				}
			}
			return gettingList;
		}
		/* 1 */
		void push_back(T addElement)
		{
			printf("Add item to end of list\n");
			list *addingList;
			addingList = new list;
			addingList->num = addElement;
			addingList->prev=end;
			addingList->next=NULL;
			if (isEmpty())
				head=addingList;
			else
			 	end->next=addingList;
			end=addingList;
			size++;
		};
		/* 2 */
		void push_front(T addElement)
		{
			printf("Add item to the top of the list\n");
			list *addingList;
			addingList = new list;
			addingList->num = addElement;
			addingList->next=head;
			addingList->prev=NULL;
			if (isEmpty())
				end=addingList;
			else
			 	head->prev=addingList;
			head=addingList;
			size++;
		};
		/* 3 */
		void pop_back()
		{
			printf("Delete last item\n");
			if (!isEmpty())
			{
				list *deletingList;
				deletingList=end;
				end=end->prev;
				end->next=NULL;
				delete deletingList;
				size--;
				printf("The list was not empty, the item was deleted.\n");			
			}
			else
			{
				printf("The list is empty, can not delete item\n");
			}
		};
		/* 4 */
		void pop_front()
		{
			printf("Delete first item\n");
			if (!isEmpty())
			{
				list *deletingList;
				deletingList=head;
				head=head->next;
				head->prev=NULL;
				delete deletingList;
				size--;
				printf("The list was not empty, the item was deleted.\n");
			}
			else
			{
				printf("The list is empty, can not delete item\n");
			}
		};
		/* 5 */
		void insert(int index,T addElement)
		{
			printf("Add item before %d list item\n",index);
			list *nextList = getForIndex(index);
			if(nextList==NULL)
			{
				printf("Element is NOT added because the pointer to %d is NULL\n",index);
			}
			else
			{
				list *addingList;
				addingList = new list;
				addingList->num = addElement;
				addingList->next=nextList;
				addingList->prev=nextList->prev;
				if(index==1)
					head=addingList;
				else
					nextList->prev->next=addingList;
				nextList->prev=addingList;
				size++;
			}
		};
		/* 7 */
		void remove(int index)
		{
			printf("Delete list item with index %d\n",index);
			list *deletingList = getForIndex(index);
			if(deletingList==NULL)
			{
				printf("The item is NOT deleted, because the pointer to the %d element is NULL\n",index);
			}
			else
			{
				deletingList->next->prev=deletingList->prev;
				deletingList->prev->next=deletingList->next;
				if (deletingList==head)
					head=deletingList->next;
				if (deletingList==end)
					end=deletingList->prev;
				delete deletingList;
				size--;
				printf("The list was not empty, the item was deleted.\n");			
			}
		};
		/* 8 */
		int get_size()
		{
			return size;
		};
		/* 9 */
		void clear()
		{
			while (size!=0)
			{
				list *deletingList=head;
				head=head->next;
				delete deletingList;
				size--;
			}
			printf("List cleared\n");			
		};
		/* 10 */
		void set(int index,T addElement)
		{
			printf("Replacing a list item with an index %d\n",index);
			list *replaceList = getForIndex(index);
			if(replaceList==NULL)
			{
				printf("The item is NOT modified, because the pointer to the %d element is NULL\n",index);
			}
			else
			{
				replaceList->num=addElement;
				printf("List item with %d changed\n",index);
			}
		};
		/* 11 */
		bool isEmpty()
		{
			if (size==0) 
			return true;
			else
			return false;
		};
		/* 12 */
		list * getHead()
		{
			return head;
		}
		friend ostream& operator <<(ostream& out, ARR& List) 
		{
			if (List.isEmpty())
			{
		        out << "the list is empty\n";
		    }
		    else
			{
		        typename ARR<T>::list* node;
		        node = List.getHead();
		        for (int i = 0; i < List.get_size(); i++)
				{
		            out << node->num << ' ';
		            node = node->next;
		        }
		        out << '\n';
		    }
			return out; 
		}
};

template <typename T>
void main_menu(T)
{
	T enteredValue;
	ARR<T> list;
	int flagToEnd=0;
	int menuChoice;
	int enteredIndex;
	do{
		cout<<"\n\n\n\t=== Menu ==="<<endl;
		cout<<"1. Adding a new item to the end of the list."<<endl;
		cout<<"2. Adding a new item to the top of the list."<<endl;
		cout<<"3. Delete last item."<<endl;
		cout<<"4. Delete first item."<<endl;
		cout<<"5. Adding a new item before the item with the specified index."<<endl;
		cout<<"6. Displaying information about an item by its index."<<endl;
		cout<<"7. Deleting an item by its index."<<endl;
		cout<<"8. List size display."<<endl;
		cout<<"9. Clearing the list."<<endl;
		cout<<"10. Replacing an item by index with a passed item."<<endl;
		cout<<"11. List output."<<endl;
		cout<<"\n0. Exit."<<endl;
		cin>>menuChoice;
	    switch (menuChoice)
	    {
        case 1:
            {
            	cout<<"Enter the stored value of the item to be added: ";
            	cin>>enteredValue;
            	list.push_back(enteredValue); 
                break;
            }
        case 2:
            {
            	cout<<"Enter the stored value of the item to be added: ";
            	cin>>enteredValue;
            	list.push_front(enteredValue); 
                break;
            }
        case 3:
            {
              	list.pop_back(); 
                break;
            }
        case 4:
            {
               	list.pop_front();
                break;
            }
        case 5:
            {
            	cout<<"Enter the stored value of the item to be added: ";
            	cin>>enteredValue;
            	cout<<"Enter the index of the item before which you want to put a new item. (1-"<<list.get_size()<<"): ";
            	cin>>enteredIndex;
            	list.insert(enteredIndex, enteredValue); 
                break;
            }
        case 6:
            {
            	cout<<"Enter the item index: ";
            	cin>>enteredIndex;
 				list.at(enteredIndex);         
                break;
            }
        case 7:
            {
            	cout<<"Enter the item to be deleted: ";
            	cin>>enteredIndex;
    		 	list.remove(enteredIndex);
                break;
            }
        case 8:
            {
   				cout<<"Size list:"<<list.get_size()<<"\n";
                break;
            }
        case 9:
            {
 				cout<<"List cleared\n";
 				list.clear();
                break;
            }
        case 10:
            {
 				cout<<"Enter the stored value of the replacement item: ";
            	cin>>enteredValue;
            	cout<<"Enter the index of the item to be replaced.(1-"<<list.get_size()<<"): ";
            	cin>>enteredIndex;
            	list.set(enteredIndex, enteredValue); 
                break;
            }
        case 11:
            {
 				cout<<list;         
                break;
            }
        case 0:
            {
                flagToEnd=1;
                break;
           }
    	}
    }while(flagToEnd==0);
}

void minor_menu()
{
	int Choice;
	cout<<"\tSelect the type of data you need to work with."<<endl;
	cout<<"1. int."<<endl;
	cout<<"2. float."<<endl;
	cout<<"3. char."<<endl;
	cout<<"4. double."<<endl;
	cout<<"5. bool."<<endl;
	cin>>Choice;

	switch (Choice)
	    {
        case 1:
            {
            	int type;
            	main_menu(type);
                break;
            }
        case 2:
            {
            	float type;
            	main_menu(type);
                break;
            }
        case 3:
            {
            	char type;
              	main_menu(type);
                break;
            }
        case 4:
            {
            	double type;
               	main_menu(type);
                break;
            }
        case 5:
            {
            	bool type;
            	main_menu(type);
                break;
            }
    	}
}

int main()
{ 
	SetConsoleOutputCP(1251);

     minor_menu();
	return 0;
}
