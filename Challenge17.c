
#include <stdio.h>
#include <string.h>

#define N 5

char *name[N] = {
    "Root", "Documents", "Pictures",
    "notes.txt", "photo.jpg"
};

int graph[N][N] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0}
};

int bfs(int start, char target[])
{
    int visited[N] = {0};
    int queue[N], front = 0, rear = 0;
    int i, v, found = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        v = queue[front++];
        printf("%s ", name[v]);

        if (strcmp(name[v], target) == 0)
            found = 1;

        for (i = 0; i < N; i++)
        {
            if (graph[v][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
    return found;
}

int dfs(int v, char target[], int visited[])
{
    int i, found = 0;

    visited[v] = 1;
    printf("%s ", name[v]);

    if (strcmp(name[v], target) == 0)
        found = 1;

    for (i = 0; i < N; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
        {
            if (dfs(i, target, visited))
                found = 1;
        }
    }

    return found;
}

int main()
{
    int i, start, visited[N] = {0};
    char target[30];
    int bfsFound, dfsFound;

    printf("FILE SYSTEM SEARCH\n");

    printf("\nNodes:\n");
    for (i = 0; i < N; i++)
        printf("%d - %s\n", i, name[i]);

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    printf("\nEnter starting node (0-4): ");
    scanf("%d", &start);

    if (start < 0 || start >= N)
    {
        printf("Invalid starting node!\n");
        return 0;
    }

    printf("Enter file name to search: ");
    scanf("%29s", target);

    bfsFound = bfs(start, target);

    printf("DFS Traversal: ");
    dfsFound = dfs(start, target, visited);
    printf("\n");

    if (bfsFound)
        printf("BFS: File found\n");
    else
        printf("BFS: File not found\n");

    if (dfsFound)
        printf("DFS: File found\n");
    else
        printf("DFS: File not found\n");

    return 0;
}
