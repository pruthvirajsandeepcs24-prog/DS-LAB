
#include <stdio.h>

int n;
int adj[10][10];
int visited[10];
int queue[10];
int front = -1, rear = -1;

void enqueue(int v)
{
if (rear == 9)
return;
if (front == -1)
front = 0;
queue[++rear] = v;
}

int dequeue()
{
return queue[front++];
}

void bfs(int start)
{
int i, v;

enqueue(start);
visited[start] = 1;

while (front <= rear)
{
v = dequeue();
printf("%d ", v);

for (i = 0; i < n; i++)
{
if (adj[v][i] == 1 && visited[i] == 0)
{
enqueue(i);
visited[i] = 1;
}
}
}
}

int main()
{
int i, j, start;

printf("Enter number of vertices: ");
scanf("%d", &n);

printf("Enter adjacency matrix:\n");
for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
scanf("%d", &adj[i][j]);
}
}

for (i = 0; i < n; i++)
visited[i] = 0;

printf("Enter starting vertex: ");
scanf("%d", &start);

printf("BFS Traversal: ");
bfs(start);

return 0;
}
