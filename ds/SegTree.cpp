/**
 * point upd range min
 * source: usaco.guide
 */
template <class T> class MinSegmentTree {
  private:
	const T DEFAULT = std::numeric_limits<T>().max();

	int len;
	vector<T> segtree; // 1-indexed

	T combine(const T &a, const T &b) {
        return std::min(a, b);
    }

	void build(const vector<T> &arr, int at, int at_left, int at_right) {
		if (at_left == at_right) {
			segtree[at] = arr[at_left];
			return;
		}
		int mid = (at_left + at_right) >> 1;
		build(arr, at << 1, at_left, mid);
		build(arr, at << 1 | 1, mid + 1, at_right);
		segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
	}

	void set(int ind, T val, int at, int at_left, int at_right) {
		if (at_left == at_right) {
			segtree[at] = val;
			return;
		}
		int mid = (at_left + at_right) >> 1;
		if (ind <= mid) {
			set(ind, val, at << 1, at_left, mid);
		} else {
			set(ind, val, at << 1 | 1, mid + 1, at_right);
		}
		segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
	}

	T range_min(int start, int end, int at, int at_left, int at_right) {
		if (at_right < start || end < at_left) { return DEFAULT; }
		if (start <= at_left && at_right <= end) { return segtree[at]; }
		int mid = (at_left + at_right) >> 1;
		T left_res = range_min(start, end, at << 1, at_left, mid);
		T right_res = range_min(start, end, at << 1 | 1, mid + 1, at_right);
		return combine(left_res, right_res);
	}

  public:
	MinSegmentTree(int len) : len(len) { segtree = vector<T>(len << 2, DEFAULT); };

	MinSegmentTree(const vector<T> &arr) : len(arr.size()) {
		segtree = vector<T>(len << 2, DEFAULT);
		build(arr, 1, 0, len - 1);
	}

	/** Sets the value at ind to val. */
	void set(int ind, T val) {
        set(ind, val, 1, 0, len - 1); 
    }

	/** @return the minimum element in the range [start, end] */
	T range_min(int start, int end) {
        return range_min(start, end, 1, 0, len - 1); 
    }
};