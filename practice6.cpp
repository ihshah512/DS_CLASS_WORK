#include <iostream>
#include <string>

using namespace std;

class Test
{

private:
    int *m_ar[5]; //memory already allocated we have to inatizle it to nullptr

public:
    Test()
    {

        for (int i = 0; i < 5; i++)
        {

            m_ar[i] = nullptr;
        }
    }

    ~Test()
    {

        for (int i = 0; i < 5; i++)
        {

            if (m_ar != nullptr)
            { //if we dont check it program will abort or exit or abnoral termination
                delete m_ar[i];
                m_ar[i] = nullptr;
            }
        }
        //delete m_ar; complier will delete it by itself as it is sitting at the first index of array
    }

    bool set(int index, int value)
    {

        bool result = false;
        if (index >= 0 && index < 5)
        { // what if index is > 5??????

            if (m_ar[index] == nullptr)
            {

                m_ar[index] = new int;
            }
            *m_ar[index] = value;
            result = true;
        }
        return result;
    }

    int get(int index) const
    {

        int value = -1000;
        if (index >= 0 && index < 5 && m_ar[index] != nullptr)
        {

            value = *m_ar[index];
        }
        return value;
    }
    //copy constructor we have this in project as wel

    Test(const Test &rhs)
    {
        //first we would check rather rhs has allocted memory
        //since rhs is an object of the Test and this object contains
        //pointers of integer arrays so we need to access them to
        //see rahter they are nullptr or not if tey are not null
        //it means they have some values we cant assue that val is
        //same as we have in our integer array thus we need to
        //allocate memory and assgin integer array points to our
        //rhs object
        for (int i = 0; i < 5; i++)
        {

            if (rhs.m_ar[i] != nullptr)
            {
                m_ar[i] = new int(*rhs.m_ar[i]);
            }
            else
            {
                m_ar[i] = nullptr;
            }
        }
    }

    const Test &operator=(const Test &rhs)
    {

        /*OEPRATOR is used to copy the contents of one object to another
after both objects have been crated. we need deep copy 
diff b/w copy constrcutor and assingent operator
1. copy cons used when we are creating a new object as copy of existing object
2. In case of copy constrcutor we are creating copy of new object
from an existing object by using copy constructor
e.g. Test t1; Test t2 = t1; //copy constructor
e.g. Test t1; Test t2; t2 = t1 // assingment operator t1 = t2
in assaingment operator we are copying data from one object to 
another existing object. Deleting the old memmory first
*/
        //Delete the old memory

        if (this != &rhs) //if not equal
        {
            for (int i = 0; i < 5; i++)
            {
                delete m_ar[i];
                m_ar[i] = nullptr;
            }

            for (int j = 0; j < 5; j++)
            {
                if (rhs.m_ar[j] != nullptr)
                {
                    m_ar[j] = new int(*rhs.m_ar[j]);
                }
                else
                {
                    m_ar[j] = nullptr;
                }
            }
        }

        return *this;
    }
};

int main()
{

    return 0;
}
