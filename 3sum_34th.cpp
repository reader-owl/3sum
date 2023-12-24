#include <iostream>
using namespace std;

/*
                        Q. 3 sum problem 

                explanation -  we will be given an array and we have to find the 3 elements which gives sum = 0
                                we cannot take any elment more than once        (i != j != k)

                            arr[] = {-1, 0, 1, 2, -1, -4} 
                                some o/p -  [-1, 0, 1]
                                            [-1, 2, -1]
                                         we have to return unique triplets, like above
                                         [0, 1, -1] is similar to the first one

                                         to solve this problem we have to sort the ans/prblm and then compare it with others

            Brute force -  

        pseudo code
for(i=0; i<n; i++)
{
    for(j=i+1->n)
    {
        for(k=j+1->n)
        {
            if(arr[i] + arr[j] + arr[k] == 0)
            {
                (_, _, _)
            }
        }
    }
}


        Actual code
vector<vector<int>> triplet(int n, vector<int> &num)
{
    
    set<vector<int>> st;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                if(num[i] + num[j] + num[k] == 0)
                {
                    vector<int> temp = {num[i], num[j], num[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());                  // declaring 'ans' and putting 'st' into it in sorted manner
    return ans;
}

            TC - O(N^3 + log(nmbr of unique triplets))
            SC - 2* O(nmbr of triplets)


            Better sol -  from above brute force -  arr[i] + arr[j] + arr[k] = 0
                        we can say that -  arr[k] = -(arr[i] + arr[j])
                                example -  arr[k] = -(-1 -1)
                                                  = 2,      so we have to find 2 in the array for that we will use hashing

        Actual code (refer video)
vector<vector<int>> triplet(int n, vector<int> &num)
{
    set<vector<int>> st;
    for(int i = 0; i < n; i++)
    {
        set<int> hashset;
        for(int j = i + 1; j < n; j++)
        {
            int third = -(num[i] + num[j]);
            if(hashset.find(third) != hashset.end())
            {
                vector<int> temp = (num[i], num[j], third);
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(num[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

                TC - O(N^2 * log(M))        // M - size of set
                SC - O(N) + O(2 * nmbr of unique triplet)


                Optimal Sol -  we will sort first then apply the algorithm
                            lets take an array -  arr[] = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2}     <- we already sorted it

                            we will be using 2 pointer approach

        Actual code (refer video)
vector<vector<int>> triplet(int n, vector<int> &num)
{
    vector<vector<int>> ans;
    sort(num.begin(), num.end());                   // O(N log N)
    for(int i = 0; i < n; i++)                      // O(N)
    {
        if(i > 0 && num[i] == num[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;

        while(j < k)                                // O(N)
        {
            int sum = num[i] + num[j] + num[k];
            if(sum < 0)
            {
                j++;
            }
            else if(sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {num[i], num[j], num[k]};
                ans.push_back(temp);
                j++;
                k--;

                while(j < k && num[j] == num[j - 1])
                    j++;
                while(j < k && num[k] == num[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

                TC - O(N * log N) + O(N * N)
                SC - O(nmbr of unique triplets)
*/

int main()
{
    cout << "Hello World!\n";
}