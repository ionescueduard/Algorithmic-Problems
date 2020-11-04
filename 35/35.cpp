#include<iostream>
#include<vector>

void sortInPlace(std::vector<int> &v)
{
    //sort R
    int i, p;
    p = i = 0;

    while (p < v.size())
    {
        if (v[p] != 'R')
        {
            p++;
        } else {
            v[p++] = v[i];
            v[i] = 'R'; 
			while (i < v.size() && v[++i] == 'R') {}
        }
    }

	while (p >= i && v[--p] == 'B') {}
    while (i < p)
    {
        if (v[i] != 'B')
        {
            i++;
        } else {
            v[i++] = 'G';
            v[p] = 'B';
			while (p >= i && v[--p] == 'B') {}
        }
    }
}


int main3()
{
   std::vector<int> v = {'G', 'B', 'R', 'R', 'B', 'R', 'G'}; //should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
   sortInPlace(v);
   getchar();
   return 0;
}