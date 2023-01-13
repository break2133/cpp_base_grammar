#include <iostream>

using namespace std;

class data_for_test {
private:
    int priv_data;/* data */
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

    /* New a obj of test class. */
    data_for_test * test_obj = new data_for_test;
    test_obj->set_priv_data(5);
    cout << "Private Data=" << test_obj->ret_priv_data() << endl;

    /* Quote this obj. */
    data_for_test &quote_obj = *test_obj;
    quote_obj.set_priv_data(10);
    cout << "Private Data=" << test_obj->ret_priv_data() << endl;

    delete(test_obj);

    return 0;
}
