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