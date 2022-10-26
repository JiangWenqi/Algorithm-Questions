import java.io.*;
import java.util.*;

class Solution {

    static class Node {

        int cost;
        Node[] children;
        Node parent;

        Node(int cost) {
            this.cost = cost;
            children = null;
            parent = null;
        }

    }

    static class SalesPath {
        static int cheapestCost = Integer.MAX_VALUE;

        int getCheapestCost(Node rootNode) {
            if (rootNode == null) {
                return 0;
            }
            getCost(rootNode, rootNode.cost);
            return cheapestCost;
        }

        void getCost(Node node, int cost) {
            if (node.children == null) {
                cheapestCost = Math.min(cheapestCost, cost);
            } else {
                for (Node child : node.children) {
                    getCost(child, cost + child.cost);
                }
            }
        }
    }

    /*********************************************
     * Driver program to test above method *
     *********************************************/

    public static void main(String[] args) {
        Node root = new Node(0);
        Node[] children = new Node[5];

        for (int i = 0; i < 5; i++) {
            children[i] = new Node(i);
        }
        root.children = children;
        SalesPath salesPath = new SalesPath();
        int cost = salesPath.getCheapestCost(root);
        System.out.println(cost);
    }
}