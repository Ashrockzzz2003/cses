def printAllSubsequences(arr, index, sub_arr):
    if index == len(arr):
        if len(sub_arr) > 0:
            print(sub_arr)
        else:
            print("{}")
        return

    # take
    printAllSubsequences(arr, index + 1, sub_arr + [arr[index]])
    # not take
    printAllSubsequences(arr, index + 1, sub_arr)

printAllSubsequences([3, 1, 2], 0, [])