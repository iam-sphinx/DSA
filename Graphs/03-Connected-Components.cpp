/*
Connected Components : 
1 --- 2
|     |\
|     | \ 5   6 --- 7  8
|     | / 
3 --- 4 

now suppose we have input 8 (nodes) and 7 (edges)

1 --- 2
1 --- 3
2 --- 4
2 --- 7
4 --- 5
6 --- 7
8 --- 8

Now if you carefully see in first instance we will bet that it is not a graph but if you carefully see input it is and what we called it 
is Connected Components
now for any graph we will take as visited Array of size n + 1 and we call traversel function for all notvisited nodes

like 
int visited[n + 1] = {0};
for(int i=1; i<=n; i++)
{
    if(!visited[i])
    {
        traversal(i);
    }
}
*/