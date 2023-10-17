#include <iostream>
using namespace std;

class Array
{
private:
    int *ptr;
    int length;
    int sizeArr;
public:
    Array(int sizeArr)
    {
        length=0;
        this->sizeArr=sizeArr;
        ptr = new int [sizeArr];
    }
    void addArray(int newValue)
    {
        ptr[length++]=newValue;
    }
    int Search(int val)
    {
        for(int i=0; i<length; i++)
        {
            if(ptr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    void print()
    {
        cout<<"Display Array Content \n";
        for(int i=0; i<length; i++)
        {
            cout<<ptr[i]<<" ";
        }
        cout<<endl;
        cout<<"Length: "<<length<<endl;
    }
    void insertValue(int value,int index)
    {
        --index;
        if(index>=0&&index<sizeArr)
        {
            for(int i=length; i>index; --i)
            {
                ptr[i]=ptr[i-1];
            }
            ptr[index]=value;
            length++;
        }
        else
        {
            cout<<"index out of range or array is full \n";
        }
    }
    void Delete(int index)
    {
        --index;
        if(index>=0&&index<sizeArr)
        {
            for(int i=index; i<length; ++i)
            {
                ptr[i]=ptr[i+1];
            }
            length--;
        }
        else
        {
            cout<<"index out of range\n";
        }
    }
    int getSize()
    {
        return sizeArr;
    }
    int getLength()
    {
        return length;
    }
    ~Array()
    {
        delete [] ptr;
        ptr = nullptr;
    }
};

int main()
{
    int si;
    cout<<"Enter Size Of Array"<<endl;
    cin>>si;
    Array arr(si);
    while(true)
    {
        cout<<"1- Fill Array \n"
            <<"2- Add New Item \n"
            <<"3- Search Item \n"
            <<"4- Print Array \n"
            <<"5- Insert new Value \n"
            <<"6- print length \n"
            <<"7- delete item \n"
            <<"0- Exit"<<endl;
        int key;
        cin>>key;
        switch(key)
        {
        case 1:
        {
            if(arr.getLength() > 0)
            {
                cout<<"It already has elements"<<endl;
            }
            else
            {
                int numberOfItems=0;
                cout<<"How Many Items you want to fill ? \n";
                cin>>numberOfItems;
                if(numberOfItems > arr.getSize())
                {
                    cout<<"you cannot exceed the array size \n";
                }
                else
                {
                    for(int i=0; i<numberOfItems; i++)
                    {
                        int newValue;
                        cout<<"Enter item number"<<i+1<<endl;
                        cin>>newValue;
                        arr.addArray(newValue);
                    }
                }
            }
        }
        break;
        case 2:
        {
            if(arr.getLength() >= arr.getSize())
            {
                cout<<"you can not exceed the array size \n";
            }
            else
            {
                int newVal;
                cout<<"Add New Value"<<endl;
                cin>>newVal;
                arr.addArray(newVal);
            }

        }
        break;
        case 3:
        {
            if(arr.getLength() == 0)
            {
                cout<<"No items"<<endl;
            }
            else
            {
                int key1;
                cout<<"Enter Number: "<<endl;
                cin>>key1;
                int ser = arr.Search(key1);
                if(ser == -1)
                {
                    cout<<"Not Exist"<<endl;
                }
                else
                {
                    cout<<"Exist index is: "<<ser+1<<endl;
                }
            }
        }
        break;
        case 4:
        {
            if(arr.getLength() == 0)
            {
                cout<<"No items"<<endl;
            }
            else
            {
                arr.print();
            }
        }
        break;
        case 5:
        {
            int val,index;
            cout<<"Enter Value & Index: "<<endl;
            cin>>val>>index;
            arr.insertValue(val,index);
        }
        break;
        case 6:
        {
            cout<<"============"<<endl<<"Length: "<<arr.getLength()<<endl<<"============"<<endl;
        }
        break;
        case 7:
        {
            int index;
            cout<<"Enter Index to delete: "<<endl;
            cin>>index;
            arr.Delete(index);
        }
        break;
        case 0:
        {
            return 0;
        }
        break;
        }
    }

    return 0;
}
