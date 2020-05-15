
class CustomStack {
public:

    vector<int> cn;
    int max = -1, size = 0;
    CustomStack(int maxSize) {
        max = maxSize;
    }

    void push(int x) {
        if (size < max) {
            cn.emplace_back(x);
            size++;
        }
    }

    int pop() {

        if (size <= 0) return -1;
        int val = cn.back();
        cn.pop_back();
        size--;
        return val;
    }

    void increment(int k, int val) {

        int end = k < size ? k : size;
        for (int i = 0; i < end; i++)
            cn[i] += val;
    }
};
