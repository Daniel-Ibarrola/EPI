//
// Created by daniel on 13/09/23.
//
#include "gtest/gtest.h"
#include "graph.h"


TEST(UndirectedGraph, AddingNodesAndEdges)
{
    epi::Graph<char> graph;
    graph.addNode('A');
    graph.addNode('B');
    graph.addNode('C');
    graph.addEdge('A', 'B');
    graph.addEdge('B', 'C');

    ASSERT_EQ(graph.numNodes(), 3);
    ASSERT_EQ(graph.numEdges(), 2);
    ASSERT_TRUE(graph.areNeighbors('A', 'B'));
    ASSERT_TRUE(graph.areNeighbors('B', 'C'));
    ASSERT_FALSE(graph.areNeighbors('A', 'C'));
}

epi::Graph<char> getGraph() {
    std::vector<std::pair<char, char>> edgeList {
            // Graph with two connected components
            {'A', 'B'}, {'A', 'C'},
            {'B', 'D'}, {'B', 'E'},
            {'D', 'F'}, {'D', 'E'},
            {'E', 'F'}, {'C', 'E'},
            {'G', 'H'}
    };
    return epi::Graph<char> (edgeList);
}


bool verifyNodesPresent(const std::vector<char>& traversal){
    // DFS and BFS output is randomized due to the use of unordered_map
    // and unordered_set. We'll just verify that the nodes are present
    if (std::count(traversal.begin(), traversal.end(), 'A') != 1)
        return false;
    if (std::count(traversal.begin(), traversal.end(), 'B') != 1)
        return false;
    if (std::count(traversal.begin(), traversal.end(), 'C') != 1)
        return false;
    if (std::count(traversal.begin(), traversal.end(), 'D') != 1)
        return false;
    if (std::count(traversal.begin(), traversal.end(), 'E') != 1)
        return false;
    if (std::count(traversal.begin(), traversal.end(), 'F') != 1)
        return false;
    if (std::count(traversal.begin(), traversal.end(), 'G') != 1)
        return false;
    if (std::count(traversal.begin(), traversal.end(), 'H') != 1)
        return false;
    return true;
}


TEST(UndirectedGraph, DepthFirstSearch)
{
    epi::Graph<char> graph {getGraph()};
    std::vector<char> dfs {graph.depthFirstSearch()};
    ASSERT_TRUE(verifyNodesPresent(dfs));
}


TEST(UndirectedGraph, BreadthFirstSearch)
{
    epi::Graph<char> graph {getGraph()};
    std::vector<char> bfs {graph.breadthFirstSearch()};
    ASSERT_TRUE(verifyNodesPresent(bfs));
}