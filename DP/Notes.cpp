// Following are the two main properties of a problem that suggests that the given problem can be solved using Dynamic programming.
// 1) Overlapping Subproblems 
// 2) Optimal Substructure

// 1-> Overlapping Subproblems
//  Dynamic Programming is mainly used when solutions of the same subproblems are needed again and again.

// 2-> Optimal Substructure
//  A given problems has Optimal Substructure Property if optimal solution of the given problem can be obtained by using    optimal solutions of its subproblems. 

//  How to classify a problem as a Dynamic Programming Problem? 
// --> Typically, all the problems that require maximizing or minimize certain quantities or counting problems that say to count the arrangements under certain conditions or certain probability problems can be solved by using Dynamic Programming.

//--> All dynamic programming problems satisfy the overlapping subproblems property and most of the classic dynamic problems also satisfy the optimal substructure property. Once, we observe these properties in a given problem, be sure that it can be solved using DP.

// 1) Overlapping Subproblems: 
// Like Divide and Conquer, Dynamic Programming combines solutions to sub-problems. Dynamic Programming is mainly used when solutions of the same subproblems are needed again and again. In dynamic programming, computed solutions to subproblems are stored in a table so that these don’t have to be recomputed. 

// 2) Optimal Substructure: A given problems has Optimal Substructure Property if optimal solution of the given problem can be obtained by using optimal solutions of its subproblems. 
// ->
// For example, the Shortest Path problem has following optimal substructure property: 
// If a node x lies in the shortest path from a source node u to destination node v then the shortest path from u to v is combination of shortest path from u to x and shortest path from x to v. The standard All Pair Shortest Path algorithm like Floyd–Warshall and Single Source Shortest path algorithm for negative weight edges like Bellman–Ford are typical examples of Dynamic Programming. 

// There are following two different ways to store the values so that these values can be reused: 
// a) Memoization (Top Down) 
// b) Tabulation (Bottom Up)

// a) Memoization (Top Down): The memoized program for a problem is similar to the recursive version with a small modification that looks into a lookup table before computing solutions. We initialize a lookup array with all initial values as NIL. Whenever we need the solution to a subproblem, we first look into the lookup table. If the precomputed value is there then we return that value, otherwise, we calculate the value and put the result in the lookup table so that it can be reused later.

// b) Tabulation (Bottom Up): The tabulated program for a given problem builds a table in bottom-up fashion and returns the last entry from the table. For example, for the same Fibonacci number, we first calculate fib(0) then fib(1) then fib(2) then fib(3), and so on. So literally, we are building the solutions of subproblems bottom-up. 


//5 Easy steps to solve Dp problems

/*

1. Define subproblems
2. Guess (Part of solution)
3. Recurrence
4. Recurse + Memoize / Bottom up
  -Check acyclic / Topo order
5. Solve original problem

** Time complexity = (# of subproblems * time taken per subproblem (time/subproblem))

*/

/*
Subproblems for String and sequences

-Suffixes
-Prefixes
 ---> O(n)
 
-Substrings --> O(n^2)
*/