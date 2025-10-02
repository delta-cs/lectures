#include <stdio.h>
#include <stdlib.h>

typedef unsigned int ui;

typedef struct {
    ui value;
    ui preWeight;
} MemoCell;

typedef struct {
    ui weight;
    ui cost;
} Item;

ui max(ui a, ui b) { return (a > b) ? a : b; }

ui knapsack_bottom_up(ui maxWeight, Item *items, ui numberOfItems, MemoCell **memo) {
    if (numberOfItems < 1) return 0;

    for (int i = 0; i < numberOfItems; i++) {
        Item item = items[i];
        for (int j = 0; j <= maxWeight; j++) {
            MemoCell *memoCell = &memo[i + 1][j];

            // This item's weight is bigger
            // than Knapsack capacity
            // This combination cannot be in the optimal solution
            // Keep the knapsack as is, without this item
            if (item.weight > j) {
                memoCell->value = memo[i][j].value;
                memoCell->preWeight = j;
                continue;
            }

            // Option 1: add this item into knapsack
            // -- Add cost of this item and cost of the rest of the knapsack
            ui addCost = item.cost + memo[i][j - item.weight].value;
            // Option 2: throw away this item
            // -- Do not add cost of this item
            ui dontAddCost = memo[i][j].value;

            // Take the larger value of these two options and assign the previous weight
            if (addCost > dontAddCost) {
                memoCell->value = addCost;
                memoCell->preWeight = j - item.weight;
            } else {
                memoCell->value = dontAddCost;
                memoCell->preWeight = j;
            }
        }
    }

    return memo[numberOfItems][maxWeight].value;
}

ui knapsack(ui maxWeight, Item *items, ui numberOfItems) {
    // 2D array | matrix
    MemoCell **memo = (MemoCell **) malloc((numberOfItems + 1) * sizeof(MemoCell *));

    for (int i = 0; i < numberOfItems + 1; i++) {
        memo[i] = (MemoCell *) malloc((maxWeight + 1) * sizeof(MemoCell));
    }

    // initialize table to all 0
    for (int i = 0; i < numberOfItems + 1; i++) {
        for (int j = 0; j < maxWeight + 1; j++) {
            memo[i][j].value = 0;
            memo[i][j].preWeight = 0;
        }
    }

    ui result = knapsack_bottom_up(maxWeight, items, numberOfItems, memo);

    // Memo debug print
    for (int i = 0; i <= numberOfItems; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            printf("%8d", memo[i][j].value, memo[i][j].preWeight);
        }
        printf("\n");
    }

    // Items list print
    printf("Items to add:\n");

    ui currentWeight = maxWeight;
    for (ui i = numberOfItems; i > 0; i--) {
        MemoCell current = memo[i][currentWeight];

        if (currentWeight > current.preWeight) {
            // The previous weight is lower - the item was added
            printf("%u\n", i);
        }

        currentWeight = current.preWeight;
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
        scanf("%u %u", &item->weight, &item->cost);
    }

    printf("The total cost: %u\n", knapsack(maxWeight, items, numberOfItems));
    return 0;
}
