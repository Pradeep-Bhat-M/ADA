#include <bits/stdc++.h>
using namespace std;

int match(string text, string pattern)
{
    int count = 0;
    int i, k, p_size = pattern.length();
    int table[126];
    for(i = 0; i < 126; i++)        // world full of hello   
        table[i] = p_size;          //               hello
    for(int j = 0; j <= p_size - 2; j++)
        table[pattern[j]] = p_size - 1 - j;

    i = p_size - 1;
    while(i <= text.length()-1)
    {
        count++;
        k = 0;
        while(k <= p_size-1 && pattern[p_size-1-k] == text[i-k])
        {
            k++;
            count++;
        }
        if(k == p_size)
        {
            cout << "\n Count = " << count;
            return (i - p_size + 1);
        }
        else
            i = i + table[text[i]];
    }
    cout << "\n Count = " << count;
    return -1;
}

void openFile(string fileName, char T[])
{
    int i, g = 0;
    int MAX=30000;
    char buffer[MAX];
    ifstream infile(fileName);
    while( !infile.eof())
    {
        infile.getline(buffer,MAX);
        //cout<<buffer<<"="<<strlen(buffer)<<endl;
        
        i=0;
        while(i<strlen(buffer))
        {
            T[g++]=buffer[i];
            i++;
        }
        T[g++]='\n';
    }
}

int main()
{
    string fileName, pattern;
    cout << "\n Enter text file : ";
    getline(cin, fileName);
    fileName = "text.txt";
    char text[100000];
    openFile(fileName, text);
    cout <<" \n Text in File : " << text;
    cout << "\n Enter the pattern to find : ";
    getline(cin, pattern);
    int result = match(text, pattern);
    if(result >= 0)
        cout << "\n Pattern found at index " << result;
    else
        cout << "\n Pattern Not found";
    return 0;
}