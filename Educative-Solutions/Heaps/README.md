# Max-Heap
## **Building a Max-Heap**

As mentioned in the previous lesson, a Max Heap follows the Max Heap property, which means the key at the parent node is always greater than keys at both child nodes. The following steps illustrate how we build a Max Heap:

1. Create a new node at the end of the heap.
2. Assign a new value to the node.
3. Compare the value of this child node with its parent.
4. If the value of the parent is less than that of the child, then swap them.
5. Repeat steps 3 & 4 until the Heap property holds.

## **Insertion in Max-Heap**

If you want to insert a new element in the Max Heap, you will have to follow a list of steps to make sure the Heap property still holds after adding the element. Here’s the list of steps that you will perform:

1. Create a new child node at the end of the heap.
2. Place the new key at that node.
3. Compare the value with its parent node key.
4. If the key is greater than the key at the parent node, swap values.
5. If both keys at the children nodes are greater than the parent node key, pick the larger one and see if the Heap property is satisfied.
6. Repeat until you reach the root node.

## **Removing an Element from a Max-Heap**

Deletion in a Max-Heap is mainly performed when you want to remove the largest element. In most of the cases, the purpose of a Heap is to work as a priority queue. As an example here, we will take the case of deleting the biggest element here as we are discussing Max Heaps. Given below is the list of steps you will follow to make sure the Heap Property still holds after deleting the root element:

1. Delete the root node
2. Move the key of the last child node at the last level to the root
3. Now compare the key with its children
4. If the key is smaller than the key at any of the child nodes, swap values
5. If both keys at the children nodes are greater than the parent node key, pick the larger one and see if the heap property is satisfied
6. Repeat until you reach the last level

## Implementation

```java
import java.util.Arrays;

public class MaxHeap {

    public void buildMaxHeap(int[] array) {
        // swap largest child to parent node 
        for (int i = (array.length - 1) / 2; i >= 0; i--) {
            maxHeapify(i, array);
        }
    }

    private void maxHeapify(int index, int[] array) {
        int largest = index;
        // check parent nodes only
        while (largest < array.length / 2) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            if (left < array.length && array[left] > array[largest]) {
                largest = left;
            }
            if (right < array.length && array[right] > array[largest]) {
                largest = right;
            }
            if (largest != index) {
                // swap parent with largest child
                int temp = array[largest];
                array[largest] = array[index];
                array[index] = temp;
                index = largest;
            } else {
                // if max heap property is satisfied 
                break;
            }
        }

    }

    public static void main(String[] args) {
        int[] heapArray = { 1, 4, 7, 12, 15, 14, 9, 2, 3, 16 };
        System.out.println("Before heapify: " + Arrays.toString(heapArray));
        new MaxHeap().buildMaxHeap(heapArray);
        System.out.println("After heapify: " + Arrays.toString(heapArray));
    }

}
```
The time complexity of building a heap is `O(n)`