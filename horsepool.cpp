#include <bits/stdc++.h>
using namespace std;

int match(string text, string pattern)
{
    int i, k, p_size = pattern.length();
    int table[126];
    for(i = 0; i < 126; i++)        // world full of hello   
        table[i] = p_size;          //               hello
    for(int j = 0; j <= p_size - 2; j++)
        table[pattern[j]] = p_size - 1 - j;

    i = p_size - 1;
    while(i <= text.length()-1)
    {
        k = 0;
        while(k <= p_size-1 && pattern[p_size-1-k] == text[i-k])
            k++;

        if(k == p_size)
            return (i - p_size + 1);
        else
            i = i + table[text[i]];
    }
    return -1;
}

void openFile(string text, string fileName)
{
    int i = 0;
    char ch;
    ifstream file;
    file.open(fileName);
    while( !file.eof())
    {
        file >> ch;
        cout << ch;
        text[i++] = ch;
    }
    file.close();
}

int main()
{
    string text;
    string fileName, pattern;
    cout << "\n Enter text file : ";
    getline(cin, fileName);
    openFile(text, fileName);
    cout << "\n Enter the pattern to find : ";
    getline(cin, pattern);
    int result = match(text, pattern);
    if(result >= 0)
        cout << "\n Patter found at index " << result;
    else
        cout << "\n Patter Not found";
    return 0;
}