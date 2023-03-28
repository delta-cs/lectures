#include <stdio.h>
#include <stdlib.h>

typedef unsigned int ui;

typedef struct {
    ui weight;
    ui cost;
} Item;

ui max(ui a, ui b) { return (a > b) ? a : b; }

ui knapsack(ui maxWeight, Item *items, ui numberOfItems) {
    if (maxWeight == 0 || numberOfItems == 0) return 0;

    Item lastItem = items[numberOfItems - 1];

    // Last item's weight is bigger
    // than Knapsack capacity maxWeight
    // This items cannot be in the optimal solution
    if (lastItem.weight > maxWeight) {
        return knapsack(maxWeight, items, numberOfItems - 1);
    }

    // Take maximum value of these two options
    return max(
            // Option 1: add last item into knapsack
            // -- Add cost of this item and cost of the rest of the knapsack
            // -- Subtract last item weight from maximal weight (capacity) in recursive call
            lastItem.cost + knapsack(maxWeight - lastItem.weight, items, numberOfItems - 1),
            // Option 2: throw away last item
            // -- Do not add cost of this item
            // -- Keep maximal weight (capacity)
            knapsack(maxWeight, items, numberOfItems - 1)
    );
}

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
