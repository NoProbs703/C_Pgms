#include<stdio.h>
#define MAX 5
void dfs(int adj[][MAX],int visited[],int start)
{
 int stack[MAX],top=-1,i,k;
 for(k=0;k<MAX;k++)
  visited[k]=0;
 stack[++top]=start;
 visited[start]=1;

 while(top!=-1)
 {
  start=stack[top--];
  printf("%d->",start);
  for(i=0;i<MAX;i++)
  {
   if(adj[start][i] && visited[i]==0)
   {
    stack[++top]=i;
    visited[i]=1;
   }
  }
 }
}

int main()
{
 int visited[MAX]={0};
 int choice, i, j, adj[MAX][MAX], start;
 do
 {
  printf("Graph Menu\n");
  printf("1. Adjacency Matrix\n");
  printf("2. DFS Traversal\n");
  printf("3. Exit\n");
  printf("\n");
  printf("Enter your choice from 1 to 3: ");
  scanf("%d", &choice);
  printf("\n");

  switch(choice)
  {
   case 1:
          printf("Enter the adjacency matrix:\n");
          for(i=0;i<MAX;i++)
          {
           for(j=0;j<MAX;j++)
           {
            scanf("%d",&adj[i][j]);
           }
          }
          break;
   case 2:
          printf("Enter the starting element: ");
          scanf("%d",&start);
          printf("DFS Traversal:\n");
          dfs(adj, visited, start);
          break;
   case 3:
          printf("Exiting...");
          break;
   default:
           printf("Invalid Choice!");
  }
 }while(choice!=4);
 return 0;
}
