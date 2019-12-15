//https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = nums.size() / 2 + 1; i >= 0; i--) {
            siftDown(i, nums);
        }

        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }


        int ans;
        for (int i = 0; i < k; i++) {
            ans = extractMax(nums);
        }

        return ans;
    }

    void siftDown(size_t i, vector<int> & heap) {
        while (2*i + 1 < heap.size()) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            int m = left;
            if (right < heap.size() && heap[right] > heap[left])
                m = right;

            if (heap[i] >= heap[m])
                break;

            swap(heap[i], heap[m]);
            i = m;
        }
    }

    int extractMax(vector<int> & heap) {
        int max = heap[0];

        swap(heap[heap.size() - 1], heap[0]);

        heap.erase(heap.begin() + heap.size() - 1);

        siftDown(0, heap);
        return max;
    }
};
