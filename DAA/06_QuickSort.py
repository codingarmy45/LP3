def partition(arr, first, last):
    pivot = arr[last]
    i = first - 1  # i points to the position for elements < pivot

    # j iterates to find elements < pivot
    for j in range(first, last):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Swap elements less than pivot

    # Place pivot in its correct position
    arr[i + 1], arr[last] = arr[last], arr[i + 1]
    return i + 1  # Return the partitioning index

def quick_sort(arr, first, last):
    # Base case: if the subarray has 1 or no element
    if first < last:
        pi = partition(arr, first, last)
        quick_sort(arr, first, pi - 1)  # Sort elements before partition
        quick_sort(arr, pi + 1, last)   # Sort elements after partition

# Example usage
arr = [20, 12, 35, 16, 18, 30]
n = len(arr)

quick_sort(arr, 0, n - 1)

print("Sorted array:", arr)
