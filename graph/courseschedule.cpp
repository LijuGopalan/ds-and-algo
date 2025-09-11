/*
    Course Schedule

    Problem Statement:
    There are a total of `numCourses` courses you have to take, labeled from 0 to `numCourses - 1`.
    You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that
    you must take course `bi` first if you want to take course `ai`.
    Return `true` if you can finish all courses. Otherwise, return `false`.

    This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle
    exists, it's impossible to finish all courses (a circular dependency).

    Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: true
    Explanation: To take course 1 you should have finished course 0. So it is possible.

    Example 2:
    Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    Output: false
    Explanation: To take course 1 you should have finished course 0, and to take course 0
    you should also have finished course 1. So it is impossible.
*/

#include <iostream>
#include <vector>

/**
 * @brief Helper function to detect a cycle in a directed graph using DFS.
 *
 * @param course The current course/node being visited.
 * @param adj The adjacency list representation of the graph.
 * @param visited A vector to keep track of visited nodes in the overall DFS traversal.
 * @param recursionStack A vector to keep track of nodes in the current recursion stack.
 * @return True if a cycle is detected, false otherwise.
 */
bool hasCycle(int course, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<bool>& recursionStack) {
    // Mark the current node as visited and part of the current recursion stack
    visited[course] = true;
    recursionStack[course] = true;

    // Recurse for all the neighbors
    for (int neighbor : adj[course]) {
        // If the neighbor is not visited, then recurse on it
        if (!visited[neighbor]) {
            if (hasCycle(neighbor, adj, visited, recursionStack)) {
                return true;
            }
        }
        // If the neighbor is in the current recursion stack, then there is a cycle
        else if (recursionStack[neighbor]) {
            return true;
        }
    }

    // Remove the node from the recursion stack as we backtrack
    recursionStack[course] = false;
    return false;
}

/**
 * @brief Determines if all courses can be finished given the prerequisites.
 *
 * This function models the courses and prerequisites as a directed graph and checks
 * for cycles. If a cycle exists, it's impossible to complete all courses.
 *
 * @param numCourses The total number of courses.
 * @param prerequisites A 2D vector where each element is a pair [course, prerequisite].
 * @return True if all courses can be finished, false otherwise.
 */
bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    // Create an adjacency list for the graph.
    // The edge prereq -> course means course depends on prereq.
    std::vector<std::vector<int>> adj(numCourses);
    for (const auto& p : prerequisites) {
        adj[p[1]].push_back(p[0]); // p[1] is a prerequisite for p[0]
    }

    std::vector<bool> visited(numCourses, false);
    std::vector<bool> recursionStack(numCourses, false);

    // Check for a cycle in the graph by visiting each course
    for (int i = 0; i < numCourses; ++i) {
        if (!visited[i]) {
            if (hasCycle(i, adj, visited, recursionStack)) {
                return false; // A cycle was found, impossible to finish
            }
        }
    }

    return true; // No cycles were found
}

/**
 * @brief Main function to test the canFinish function.
 * @return 0 on successful execution.
 */
int main() {
    // Example 1: Possible to finish
    int numCourses1 = 4;
    std::vector<std::vector<int>> prerequisites1 = {{1, 0}, {2, 1}, {3, 2}};
    std::cout << "Can finish courses for example 1? "
              << (canFinish(numCourses1, prerequisites1) ? "Yes" : "No")
              << " (Expected: Yes)" << std::endl;

    // Example 2: Impossible to finish (cycle 0->1->0)
    int numCourses2 = 2;
    std::vector<std::vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    std::cout << "Can finish courses for example 2? "
              << (canFinish(numCourses2, prerequisites2) ? "Yes" : "No")
              << " (Expected: No)" << std::endl;

    return 0;
}
