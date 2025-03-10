/*
Problem
Monk is a multi-talented person, and prepares results for his college in his free time. (Yes, he is still in love with his old college!) He gets a list of students with their marks. The maximum marks which can be obtained in the exam is 100.

The Monk is supposed to arrange the list in such a manner that the list is sorted in decreasing order of marks. And if two students have the same marks, they should be arranged in lexicographical manner.

Help Monk prepare the same!

Input format:
On the first line of the standard input, there is an integer N, denoting the number of students. N lines follow, which contain a string and an integer, denoting the name of the student and his marks.*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,multiset<string>>m; 
    int n;
    cin >> n;
    for(int i=0;i<n;++i){
        int marks;
        string name;
        cin>>name>>marks;
        m[marks].insert(name);
    }
    auto current_it=--m.end();
    while(true){
        auto &students=(*current_it).second;
        int marks=(*current_it).first;
        for(auto student: students){
            cout<<student<<" "<<marks<<endl;
        }
        if(current_it==m.begin()) break;
        current_it--;
    }
}