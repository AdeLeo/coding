#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int i;

    cout << "size:" << v.size() << endl;

    for(i = 0; i < 5; i++)
    {
        v.push_back(i);
    }

    cout << "size:" << v.size() << endl;

    for(i = 0; i < 5; i++)
    {
        cout << "value of v [" << v[i] << "]" << endl;
    }

    vector<int>::iterator iter = v.begin();
    while(iter != v.end())
    {
        cout << "value of v=" << *iter << endl;
        iter++;
    }

    return 0;
}
