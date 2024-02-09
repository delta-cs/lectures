#include <stdio.h>
#include <stdlib.h>

typedef unsigned int ui;

typedef struct {
    ui weight;
    ui cost;
} Item;

ui max(ui a, ui b) { return (a > b) ? a : b; }


ui knapsack_bottom_up(ui maxWeight, Item *items, ui numberOfItems, ui **memo) {
    if (numberOfItems < 1) return 0;

    for (int i = 0; i < numberOfItems; i++) {
        Item item = items[i];
        for (int j = 0; j <= maxWeight; j++) {
            // This item's weight is bigger
            // than Knapsack capacity
            // This combination cannot be in the optimal solution
            // Keep the knapsack as is, without this item
            if (item.weight > j) {
                memo[i + 1][j] = memo[i][j];
                continue;
            }

            memo[i + 1][j] = max(
                    // Option 1: add this item into knapsack
                    // -- Add cost of this item and cost of the rest of the knapsack
                    item.cost + memo[i][j - item.weight],
                    // Option 2: throw away this item
                    // -- Do not add cost of this item
                    memo[i][j]
            );
        }
    }

    return memo[numberOfItems][maxWeight];
}

ui knapsack(ui maxWeight, Item *items, ui numberOfItems) {
    // 2D array | matrix
    ui **memo = (ui **) malloc((numberOfItems + 1) * sizeof(ui *));

    for (int i = 0; i < numberOfItems + 1; i++) {
        memo[i] = (ui *) malloc((maxWeight + 1) * sizeof(ui));
    }

    // initialize table to all 0
    for (int i = 0; i < numberOfItems + 1; i++) {
        for (int j = 0; j < maxWeight + 1; j++) {
            memo[i][j] = 0;
        }
    }

    ui result = knapsack_bottom_up(maxWeight, items, numberOfItems, memo);

    for (int i = 0; i <= numberOfItems; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            printf("%8d", memo[i][j]);
        }
        printf("\n");
    }

    return result;
}

/*

10
4
5 10
4 40
6 30
3 50

*/

int main() {
    ui maxWeight;
    scanf("%u", &maxWeight);

    ui numberOfItems;
    scanf("%u", &numberOfItems);

    Item *items = (Item *) malloc(numberOfItems * sizeof(Item));

    for (int i = 0; i < numberOfItems; i++) {
        Item *item = items + i;
        scanf("%d %d", &item->weight, &item->cost);
    }

    printf("%u\n", knapsack(maxWeight, items, numberOfItems));
    return 0;
}
