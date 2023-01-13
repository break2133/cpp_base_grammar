#include <iostream>

using namespace std;

static int arr[] = {1, 2, 3, 4, 5};
static string hello = "Hell0!";

class data_for_test {
private:
    int priv_data=0;/* data */
public:
    void set_priv_data(int tar)
    {
        priv_data = tar;
    }

    int ret_priv_data(void) 
    {
        return priv_data;
    }
};

class ad_para_and_ret : public data_for_test {
private:
    char err_char;
public:
    void copy_priv_data(int &tar)
    {
        tar = this->ret_priv_data();
    }

    char &set_hello(int index)
    {
        if (index < hello.size())
        {
            return hello[index];
        }
        return err_char;
    }
};



int main(void)
{
    int a = 5;
    cout << "Basic data type" << endl;
    cout << "a=" << a << endl;

    int &b = a;
    //int &c = NULL;    //Err
    b = 10;

    cout << "a=" << a << endl;
    cout << "b=" << a << endl;

    cout << endl << "Class" << endl;
    /* New a obj of test class. */
    data_for_test * test_obj = new data_for_test;
    test_obj->set_priv_data(5);
    cout << "Private Data=" << test_obj->ret_priv_data() << endl;

    /* Quote this obj. */
    # if 1
        data_for_test *&ref_obj = test_obj;   //Ref point what is point to obj.
        ref_obj->set_priv_data(10);
    #else
        data_for_test &ref_obj = *test_obj;  //Ref object entity directly.
        ref_obj.set_priv_data(10);
    #endif 
    cout << "Private Data=" << test_obj->ret_priv_data() << endl;

    /* As parameter and return value. */
    cout << endl << "As parameter and return value." << endl;
    ad_para_and_ret * p_r_obj = new ad_para_and_ret;
    
    int c = 5;
    int &d = c;

    p_r_obj->set_priv_data(666);
    p_r_obj->copy_priv_data(d); 
    p_r_obj->set_hello(4) = 'o';

    cout << "Copy Data=" << c << endl;
    cout << hello << endl;

    delete(test_obj);
    delete(p_r_obj);

    return 0;
}
