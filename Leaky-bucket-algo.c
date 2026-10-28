#include <stdio.h>

int main()
{
    int bucket_size, output_rate;
    int n, incoming, stored = 0;
    int i, sent, dropped;

    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);

    printf("Enter output rate: ");
    scanf("%d", &output_rate);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\nEnter incoming packet size: ");
        scanf("%d", &incoming);

        if (stored + incoming <= bucket_size)
        {
            stored += incoming;
            printf("Packet accepted\n");
        }
        else
        {
            dropped = stored + incoming - bucket_size;
            stored = bucket_size;
            printf("Overflow: %d units discarded\n", dropped);
        }

        sent = (stored < output_rate) ? stored : output_rate;
        stored -= sent;

        printf("Transmitted: %d units\n", sent);
        printf("Remaining in bucket: %d units\n", stored);
    }

    printf("\nAll packets processed.\n");

    return 0;
}
