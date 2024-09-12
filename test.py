def find_best_starting_point(n, t):
    max_complete = 0
    best_id = 0

    for i in range(n):
        complete_count = 0
        for j in range(n):
            student_id = (i + j) % n
            if t[student_id] <= j:
                complete_count += 1

        if complete_count > max_complete:
            max_complete = complete_count
            best_id = i + 1  # IDs are 1-based

    return best_id

# Reading input
n = int(input())
t = list(map(int, input().split()))
# Finding the best starting point
best_starting_point = find_best_starting_point(n, t)
print(best_starting_point)
