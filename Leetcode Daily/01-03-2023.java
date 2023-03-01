class Solution {
    //using heapsort
    void swap(int a, int b, int[] heap){
        heap[a] = heap[a]^heap[b];
        heap[b] = heap[a]^heap[b];
        heap[a] = heap[a]^heap[b];
    }

    void heapify(int node, int size, int[] heap){
        while(node < size){
            int left = 2*node+1, right = 2*node+2, largest = node;
            if(left < size && heap[left]> heap[largest]) largest = left;
            if(right < size && heap[right]> heap[largest]) largest = right;
            if(largest == node) break;

            swap(largest, node, heap);
            node = largest;
        }
    }
    void buildHeap(int[] heap, int size){
        for(int i = size/2; i >= 0; i--){
            heapify(i, size, heap);
        }
    }
    public int[] sortArray(int[] nums) {
        int size = nums.length;
        buildHeap(nums, size);

        while(size>1){
            swap(--size, 0, nums);
            heapify(0, size, nums);
        }
        return nums;
    }
}