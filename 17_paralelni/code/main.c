#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>

// struct for 3SAT clause
typedef struct {
    int a;
    int b;
    int c;
} Clause;

// struct for 3SAT formula
typedef struct {
    int num_vars;
    int num_clauses;
    Clause *clauses;
} Formula;

// struct for 3SAT solution
typedef struct {
    int num_vars;
    int *vars;
} Solution;

// function that generates a random 3SAT formula
Formula generate_formula(int num_vars, int num_clauses) {
    Formula formula;
    formula.num_vars = num_vars;
    formula.num_clauses = num_clauses;
    formula.clauses = (Clause *) malloc(num_clauses * sizeof(Clause));

    for (int i = 0; i < num_clauses; i++) {
        formula.clauses[i].a = rand() % num_vars;
        formula.clauses[i].b = rand() % num_vars;
        formula.clauses[i].c = rand() % num_vars;
    }

    return formula;
}

// print a formula
void print_formula(Formula formula) {
    printf("%d\n", formula.num_vars);
    printf("%d\n", formula.num_clauses);

    for (int i = 0; i < formula.num_clauses; i++) {
        printf("%d %d %d\n", formula.clauses[i].a, formula.clauses[i].b, formula.clauses[i].c);
    }
}

// load formula from stdin
Formula load_formula() {
    Formula formula;

    scanf("%d", &formula.num_vars);
    scanf("%d", &formula.num_clauses);

    formula.clauses = (Clause *) malloc(formula.num_clauses * sizeof(Clause));

    for (int i = 0; i < formula.num_clauses; i++) {
        scanf("%d %d %d", &formula.clauses[i].a, &formula.clauses[i].b, &formula.clauses[i].c);
    }

    return formula;
}

// check if formula is satisfied by a solution
int check_solution(Formula formula, Solution *solution) {
    for (int i = 0; i < formula.num_clauses; i++) {
        int a = formula.clauses[i].a;
        int b = formula.clauses[i].b;
        int c = formula.clauses[i].c;

        if (solution->vars[a] == 0 && solution->vars[b] == 0 && solution->vars[c] == 0) {
            return 0;
        }
    }

    return 1;
}

// solve recursively 3SAT formula
int solve(Formula formula, Solution *solution, int index) {
    if (index == formula.num_vars) {
        return check_solution(formula, solution);
    }

    solution->vars[index] = 0;
    if (solve(formula, solution, index + 1)) {
        return 1;
    }

    solution->vars[index] = 1;
    if (solve(formula, solution, index + 1)) {
        return 1;
    }

    return 0;
}

// kick off recursive solver
int solve_formula(Formula formula, Solution *solution) {
    solution->num_vars = formula.num_vars;
    solution->vars = (int *) malloc(formula.num_vars * sizeof(int));

    return solve(formula, solution, 0);
}

// print solution
void print_solution(Solution solution) {
    for (int i = 0; i < solution.num_vars; i++) {
        printf("%d ", solution.vars[i]);
    }
    printf("\n");
}


int main(int argc, char **argv) {
    // if first program argument is --generate, generate a random formula
    if (argc > 1 && strcmp(argv[1], "--generate") == 0) {
        srand(time(NULL));

        Formula formula = generate_formula(atoi(argv[2]), atoi(argv[3]));

        print_formula(formula);

        return 0;
    }

    Formula formula = load_formula();

    Solution solution;

    clock_t t_start = clock();

    if (solve_formula(formula, &solution)) {
        print_solution(solution);
    } else {
        printf("No solution found\n");
    }

    clock_t t_end = clock();

    double seconds = (double) (t_end - t_start) / CLOCKS_PER_SEC;

    printf("Calculated in %f seconds\n", seconds);

    return 0;
}
