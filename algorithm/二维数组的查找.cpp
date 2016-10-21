#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        bool find(vector<vector<int> > array, int target)
        {
            int i = 0;
            int j = array[0].size() - 1;

            while(i < array.size() && j >= 0 && target != array[i][j])
            {
                if(target > array[i][j])
                    i++;
                else
                    j--;
            }

            if(i < array.size() && j >= 0 && target == array[i][j])
            {
                return true;
            }

            else
                return false;
        }
};

int main()
{
    Solution s;
    vector<vector<int> > arr;
    vector<int> a;
    a.push_back(1);
    a.push_back(7);
    a.push_back(9);
    arr.push_back(a);
    a.clear();
    a.push_back(2);
    a.push_back(8);
    a.push_back(10);
    arr.push_back(a);
    a.clear();
    a.push_back(3);
    a.push_back(11);
    a.push_back(14);
    arr.push_back(a);
    
    cout << boolalpha << s.find(arr, 5) << endl;

    return 0;
}
