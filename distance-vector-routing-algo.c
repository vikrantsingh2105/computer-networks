
#include <stdio.h>

#define INF 999

int main()
{
    int n, i, j, k;
    int cost[10][10], dist[10][10];
    int changed;

    printf("Enter number of routers: ");
    scanf("%d", &n);

    printf("Enter cost matrix (999 for no link):\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];
        }
    }

    do
    {
        changed = 0;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    if (dist[i][k] != INF &&
                        dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] =
                            dist[i][k] + dist[k][j];
                        changed = 1;
                    }
                }
            }
        }
    } while (changed);

    printf("\nFinal Distance Table:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
