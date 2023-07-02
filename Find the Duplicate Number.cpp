// Index Sort Method 
public static int findDuplicate_index_sort(int[] nums) {
      int len = nums.length;
      for (int i = 0; i < len; ) {
          int n = nums[i];
          if (n == i + 1) {
              i++;
          } else if (n == nums[n - 1]) {
              return n;
          } else {
              nums[i] = nums[n - 1];
              nums[n - 1] = n;
          }
      }

      return 0;
  }

// Fast Slow Pointers
    public int findDuplicate_fastSlow(int[] nums) {
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
