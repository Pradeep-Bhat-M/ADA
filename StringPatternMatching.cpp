#include<bits/stdc++.h>
using namespace std;

int findPattern(string s, string text)
{
    int count, n, m, j;
    //bool found = false;
    n = s.length();
    m = text.length();
    //count = 0;
    //cout << "n : "<<n<<" m : "<<m <<endl;
    for( int i = 0; i < m; i++)
    {
        //found = false
        count = 0;
        for(j = 0; j < n; j++)
        {
            if(s[j] != text[i+j])
                break;
            count++;
            //cout << " " << count;
        }
        if(count == n)
            return i;
        // if(found and j == n)
        //     return i;
    }
    return -1;
}

int main()
{
    string s, text;
    int index;
    cout << "\n Enter Text : ";
    getline(cin, text);
    cout << "\n Enter Pattern : ";
    getline(cin, s);

    index = findPattern(s,text);
    if(index != -1)
    {
        cout << "\n Pattern Found at index " << index << "\n\n";
        return 0;
    }
    cout << "\n Patter Not Found!!\n\n";
    return 0;
}