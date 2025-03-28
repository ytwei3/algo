from typing import List


class Solution:
    def kSum(self, nums, target, k):
        nums.sort()
        result = []

        def backtrack(start, path, target, k):
            if k == 2:
                left, right = start, len(nums) - 1
                while left < right:
                    current_sum = nums[left] + nums[right]
                    if current_sum < target:
                        left += 1
                    elif current_sum > target:
                        right -= 1
                    else:
                        result.append(path + [nums[left], nums[right]])
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        left += 1
                        right -= 1
            else:
                for i in range(start, len(nums) - k + 1):
                    if i > start and nums[i] == nums[i - 1]:
                        continue
                    backtrack(i + 1, path + [nums[i]], target - nums[i], k - 1)

        backtrack(0, [], target, k)
        return result

    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        return self.kSum(nums, target, 4)
                     