ordered_list = [i for i in range(0, int(1.1e7),2)]
x = 65746

def search_binary_recursive(array, item, low=0, high=None):
    if not high:
        high=len(array)-1
    if  high >= low:
        middle_index = (low +  high) //2
        if array[middle_index] == item:
            return middle_index
        
        if array[middle_index] > item:
            return search_binary_recursive(array, item, low, middle_index-1)
        else:
            return search_binary_recursive(array, item, middle_index+1, high)
    return -1

print(f"Item {x} is in index {search_binary_recursive(ordered_list,x)}")

def search_binary_iterative(array, item, low=0, high=None):
    if not high:
        high=len(array)-1
    middle_index=0
    while low <= high:
        middle_index = (low +  high) //2
        if array[middle_index] > item:
            high= middle_index -1
        elif array[middle_index] < item:
            low = middle_index + 1
        else:
            return middle_index
    return -1

print(f"Item {x} is in index {search_binary_iterative(ordered_list,x)}")



import bisect
  
def search_binary_bisect(array, item):
    index_to_insert = bisect.bisect_left(array, item)
    if index_to_insert <= len(array) and array[index_to_insert] == item:
        return index_to_insert
    else:
        return -1

print(f"Item {x} is in index {search_binary_bisect(ordered_list,x)}")

import timeit
print( "iterative",
    timeit.timeit(setup="from __main__ import search_binary_iterative, ordered_list, x",stmt="search_binary_iterative(ordered_list,x)")
    )

print( "recursive",
    timeit.timeit(setup="from __main__ import search_binary_recursive, ordered_list, x",stmt="search_binary_recursive(ordered_list,x)")
    )

print( "bisect",
    timeit.timeit(setup="from __main__ import bisect,search_binary_bisect, ordered_list, x",stmt="search_binary_bisect(ordered_list,x)")
    )