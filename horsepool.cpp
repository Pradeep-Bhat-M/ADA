// #include <bits/stdc++.h>
// using namespace std;

// int match(string text, string pattern)
// {
//     int i, k, p_size = pattern.length();
//     int table[126];
//     for(i = 0; i < 126; i++)
//         table[i] = p_size;
//     for(int j = 0; j <= p_size - 2; j++)
//         table[pattern[j]] = p_size - 1 - j;

//     i = p_size - 1;
//     while(i <= text.length()-1)
//     {
//         k = 0;
//         while(k <= p_size-1 && pattern[p_size-1-k] == text[i-k])
//             k++;

//         if(k == p_size)
//             return (i - p_size + 1);
//         else
//             i = i + table[text[i]];
//     }
//     return -1;
// }

// int main()
// {
//     string text;
//     string pattern;
//     cout << "\n Enter text : ";
//     getline(cin, text);
//     cout << "\n Enter the pattern to find : ";
//     getline(cin, pattern);
//     int result = match(text, pattern);
//     if(result >= 0)
//         cout << "\n Patter found at index " << result;
//     else
//         cout << "\n Patter Not found";
//     return 0;
// }


#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
int g=0;


void input_text(char T[])
{
    int i;
    int MAX=300;
    //char buffer[MAX];
    char ch;
    ifstream infile("ABCD.txt");
    while( !infile.eof())
    {
        // infile.getline(buffer,MAX);
        // cout<<buffer<<"="<<strlen(buffer)<<endl;
        
        // i=0;
        // while(i<strlen(buffer))
        // {
        //     T[g++]=buffer[i];
        //     i++;
        // }
        // T[g++]='\n';
        infile >> ch;
        T[g++] = ch;
    }
}

void input_pattern(char P[])
{
    cout<<"Enter the pattern:"<<endl;
    cin>>P;
    cout<<endl;
}



int main()
{
    
    char T[30000];
    char P[20];
    input_text(T);
    cout<<"The text is as follows: "<<endl<<endl;
    cout<<T<<endl;
    input_pattern(P);
    cout<<"The pattern is: "<<P<<endl<<endl;
    
    int m,n;
    int flag=0;
    n=strlen(T);
    m=strlen(P);
    cout<<"Length of the text = "<<n<<endl;
    cout<<"Length of the pattern = "<<m<<endl<<endl;   //m=length of the pattern
    

    int Table[126];
    for(int i=0;i<126;i++)             //initializing all the values in the shift table to length of the pattern initially
    {
        Table[i]=m;
    }

    for(int j=0;j<=m-2;j++)    //changing the values for those characters present in the pattern
    {
        Table[P[j]]=m-1-j;
    }

    int i=m-1;
    while(i<=n-1)
    {
        int k=0;       //k keeps track of the num of letters which are matched                  
        while(P[m-1-k]==T[i-k] && k<m)
        {
            k++;
        }
        if(k==m)      //tells us that all the letters in the word are matched
        {
            cout<<"Pattern found at position :"<<i-(m-1)<<endl;
            flag++;
            i=i+m;
            
        }
        else     //if k!=m if some letter is mismatched
        {
            i=i+Table[T[i]];
        }

    }

    if(flag==0)
    {
        cout<<"The pattern is'nt present in the text."<<endl;
    }
    cout<<endl;
    return 0;

}