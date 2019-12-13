//https://leetcode.com/problems/ugly-number-ii/
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) {
            return 0;
        }

        vector<int> heap = {1};
        unordered_set<int> hValues = {1};

        unsigned long int min = 0;

        while (n > 0) {
            min = extractMin(heap);

            if (hValues.find(min*2) == hValues.end() &&  min*2 < INT_MAX) {
                insert(min*2, heap);
                hValues.insert(min*2);
            }

            if (hValues.find(min*3) == hValues.end() &&  min*3 < INT_MAX) {
                insert(min*3, heap);
                hValues.insert(min*3);
            }

            if (hValues.find(min*5) == hValues.end() &&  min*5 < INT_MAX) {
                insert(min*5, heap);
                hValues.insert(min*5);
            }

            n--;

        }

        return min;

    }
    void siftDown(size_t i, vector<int> & heap) {
        while (2*i + 1 < heap.size()) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            int m = left;
            if (right < heap.size() && heap[right] < heap[left])
                m = right;

            if (heap[i] <= heap[m])
                break;

            swap(heap[i], heap[m]);
            i = m;
        }
    }

    void siftUp(size_t i, vector<int> & heap) {
        int par = (i - 1) / 2;
        while (par >= 0 && heap[i] <= heap[par]) {
            swap(heap[i], heap[par]);
            i = par;
            par = (i - 1) / 2;
        }
    }

    int extractMin(vector<int> & heap) {
        int max = heap[0];

        swap(heap[heap.size() - 1], heap[0]);

        heap.erase(heap.begin() + heap.size() - 1);

        siftDown(0, heap);
        return max;
    }


    void insert(int val, vector<int> & heap) {
        heap.push_back(val);
        siftUp(heap.size() - 1, heap);
    }
};
