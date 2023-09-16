//
// Created by daniel on 13/09/23.
//

#ifndef INTERVIEWPREP_GRAPH_H
#define INTERVIEWPREP_GRAPH_H

#include <queue>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>


namespace epi {

    class InvalidNodeError : public std::invalid_argument {
    public:
        explicit InvalidNodeError(const std::string& message)
                : std::invalid_argument(message) {}
    };


    template<typename data_type>
    class Graph{
        // An undirected graph with no labels or weights
    private:
        // The adjacency list of the graph
        std::unordered_map<data_type, std::unordered_set<data_type>> m_nodes {};
        std::size_t m_edges {0};

        void dfsHelper(data_type node,
                       std::unordered_set<data_type>& visited,
                       std::vector<data_type>& result){
            visited.insert(node);
            result.emplace_back(node);
            for (auto nbr : m_nodes[node]){
                if (visited.find(nbr) == visited.end())
                    dfsHelper(nbr, visited, result);
            }
        }

    public:

        Graph() = default;

        explicit Graph(const std::vector<std::pair<data_type, data_type>>& edgeList){
            for (const auto& edge : edgeList){
                addNode(edge.first);
                addNode(edge.second);
                addEdge(edge.first, edge.second);
            }
        }

        [[nodiscard]] std::size_t numNodes() const { return m_nodes.size(); }
        [[nodiscard]] std::size_t numEdges() const { return m_edges; }
        [[nodiscard]] bool empty() const {return m_nodes.empty(); }

        void addNode(data_type key){
            // Adds a new node with given key to the graph. If it already exists
            // it does not have any effect
            if (m_nodes.count(key) == 0)
                m_nodes[key] = std::unordered_set<data_type>{};
        }

        void addEdge(data_type key1, data_type key2) {
            // Create an edge between the nodes with given key.
            // Throws InvalidNodeError if any of the keys is not present in the graph
            if (m_nodes.count(key1) == 0 || m_nodes.count(key2) == 0)
                throw InvalidNodeError("Invalid node: the given nodes must be present in the graph");
            m_nodes[key1].insert(key2);
            m_nodes[key2].insert(key1);
            ++m_edges;
        }

        bool areNeighbors(data_type key1, data_type key2) {
            if (m_nodes.count(key1) == 0 || m_nodes.count(key2) == 0)
                throw InvalidNodeError("Invalid node: the given nodes must be present in the graph");
            return m_nodes[key1].find(key2) != m_nodes[key1].end();
        }

        std::vector<data_type> depthFirstSearch() {
            // Returns a vector with the nodes ordered as visited in a depth first search
            std::unordered_set<data_type> visited;
            std::vector<data_type> result;
            for (auto nodeList : m_nodes){
                if (visited.find(nodeList.first) == visited.end())
                    dfsHelper(nodeList.first, visited, result);
            }
            return result;
        }

        std::vector<data_type> breadthFirstSearch() {
            // Returns a vector with the nodes ordered as visited in a breadth first search
            std::vector<data_type> result;
            if (empty())
                return result;

            std::unordered_set<data_type> visited;
            std::queue<data_type> queue;

            for (auto node : m_nodes){
                if (visited.find(node.first) == visited.end()){
                    queue.push(node.first);
                    visited.insert(node.first);
                    while (!queue.empty()) {
                        auto currentNode {queue.front()};
                        queue.pop();

                        result.emplace_back(currentNode);

                        for (auto nbr : m_nodes[currentNode]){
                            if (visited.find(nbr) == visited.end()){
                                visited.insert(nbr);
                                queue.push(nbr);
                            }
                        }
                    }
                }
            }
            return result;
        }

    };
}

#endif //INTERVIEWPREP_GRAPH_H
