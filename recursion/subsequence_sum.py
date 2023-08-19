def all_subsequence_with_sum(arr, index, sub_arr, sum, sum_so_far):
    if index == len(arr):
        if sum_so_far == sum:
            print(sub_arr)
        return
    
    # take
    all_subsequence_with_sum(arr, index + 1, sub_arr + [arr[index]], sum, sum_so_far + arr[index])
    # not take
    all_subsequence_with_sum(arr, index + 1, sub_arr, sum, sum_so_far)

all_subsequence_with_sum([1, 2, 1], 0, [], 2, 0)

