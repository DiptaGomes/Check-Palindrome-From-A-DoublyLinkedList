#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<math.h>
int a[100], c=0;
using namespace std;
struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;

class double_llist
{
    public:
        void create_list(int value)
        {
            struct node *s, *temp;
            temp = new(struct node);
            temp->info = value;
            temp->next = NULL;
            if (start == NULL)
            {
                temp->prev = NULL;
                start = temp;
            }
            else
            {
                s = start;
                while (s->next != NULL)
                    s = s->next;
                s->next = temp;
                temp->prev = s;
            }
        }
        void add_begin(int value)
        {
            if (start == NULL)
            {
                cout<<"First Create the list."<<endl;
                return;
            }
            struct node *temp;
            temp = new(struct node);
            temp->prev = NULL;
            temp->info = value;
            temp->next = start;
            start->prev = temp;
            start = temp;
            cout<<"Element Inserted"<<endl;
        }
        void add_after(int value, int pos)
        {
            if (start == NULL)
            {
                cout<<"First Create the list."<<endl;
                return;
            }
            struct node *tmp, *q;
            int i;
            q = start;
            for (i = 0;i < pos - 1;i++)
            {
                q = q->next;
                if (q == NULL)
                {
                    cout<<"There are less than ";
                    cout<<pos<<" elements."<<endl;
                    return;
                }
            }
            tmp = new(struct node);
            tmp->info = value;
            if (q->next == NULL)
            {
                q->next = tmp;
                tmp->next = NULL;
                tmp->prev = q;
            }
            else
            {
                tmp->next = q->next;
                tmp->next->prev = tmp;
                q->next = tmp;
                tmp->prev = q;
            }
            cout<<"Element Inserted"<<endl;
        }
        void delete_element(int value)
        {
            struct node *tmp, *q;
             /*first element deletion*/
            if (start->info == value)
            {
                tmp = start;
                start = start->next;
                start->prev = NULL;
                cout<<"Element Deleted"<<endl;
                free(tmp);
                return;
            }
            q = start;
            while (q->next->next != NULL)
            {
                /*Element deleted in between*/
                if (q->next->info == value)
                {
                    tmp = q->next;
                    q->next = tmp->next;
                    tmp->next->prev = q;
                    cout<<"Element Deleted"<<endl;
                    free(tmp);
                    return;
                }
                q = q->next;
            }
             /*last element deleted*/
            if (q->next->info == value)
            {
                tmp = q->next;
                free(tmp);
                q->next = NULL;
                cout<<"Element Deleted"<<endl;
                return;
            }
            cout<<"Element "<<value<<" not found"<<endl;
        }
        void display_dlist()
        {
            struct node *q;
            if (start == NULL)
            {
                cout<<"List empty,nothing to display"<<endl;
                return;
            }
            q = start;
            cout<<"The Doubly Link List is :"<<endl;
            while (q != NULL)
            {
                cout<<q->info<<" <-> ";
                a[c] = q->info;
                c++;
                q = q->next;
            }
            cout<<"NULL"<<endl;
        }
        void count()
        {
            struct node *q = start;
            int cnt = 0;
            while (q != NULL)
            {
                q = q->next;
                cnt++;
            }
            cout<<"Number of elements are: "<<cnt<<endl;
        }
        void reverse()
        {
            struct node *p1, *p2;
            p1 = start;
            p2 = p1->next;
            p1->next = NULL;
            p1->prev = p2;
            while (p2 != NULL)
            {
                p2->prev = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = p2->prev;
            }
            start = p1;
            cout<<"List Reversed"<<endl;
        }
        double_llist()
        {
            start = NULL;
        }
};

int convert_array_number(int arr[])
{
    int number=0;
    for(int i=c-1; i>=0; i--)
    {
        number = number + ( a[i] * pow(10, i));
        //cout << a[i];
    }
    //cout << "The Number is: " << number << endl;
    return number;
}

void checkPalindrome()
{
    int num, n, digit, rev = 0;
    num = convert_array_number(a);
    //cout << "Check: " << num  << endl;
    n = num;
    do
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);
     cout << " The reverse of the number is: " << rev << endl;
     if (n == rev)
         cout << " The number is a palindrome.";
     else
         cout << " The number is not a palindrome.";

}


int main()
{
    int choice, element, position;
    double_llist dl;
    dl.create_list(1);
    dl.add_after(2, 1);
    dl.add_after(3, 2);
    dl.add_after(1, 3);
    dl.display_dlist();

    checkPalindrome();
    return 0;
}

