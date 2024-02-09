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

ui knapsack_memoization(ui maxWeight, Item *items, ui numberOfItems, MemoCell **memo) {
    if (numberOfItems < 1) return 0;

    MemoCell *memoCell = &memo[numberOfItems][maxWeight];

    if (memoCell->value != 0) return memoCell->value;

    Item lastItem = items[numberOfItems - 1];

    // Last item's weight is bigger
    // than Knapsack capacity maxWeight
    // This item cannot be in the optimal solution
    if (lastItem.weight > maxWeight) {
        memoCell->preWeight = maxWeight;
        return knapsack_memoization(maxWeight, items, numberOfItems - 1, memo);
    }

    // Option 1: add last item into knapsack
    // -- Add cost of this item and cost of the rest of the knapsack
    // -- Subtract last item weight from maximal weight (capacity) in recursive call
    ui addCost = lastItem.cost + knapsack_memoization(maxWeight - lastItem.weight, items, numberOfItems - 1, memo);
    // Option 2: throw away last item
    // -- Do not add cost of this item
    // -- Keep maximal weight (capacity)
    ui dontAddCost = knapsack_memoization(maxWeight, items, numberOfItems - 1, memo);

    // Take the larger value of these two options and assign the previous weight
    if (addCost > dontAddCost) {
        memoCell->value = addCost;
        memoCell->preWeight = maxWeight - lastItem.weight;
    } else {
        memoCell->value = dontAddCost;
        memoCell->preWeight = maxWeight;
    }

    return memoCell->value;
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

    ui result = knapsack_memoization(maxWeight, items, numberOfItems, memo);

    // Memo debug print
    for (int i = 0; i <= numberOfItems; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            printf("%8d", memo[i][j].value);
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
