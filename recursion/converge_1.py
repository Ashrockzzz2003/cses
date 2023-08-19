def minStepsToConvergeToOne(n, dp):
    if n == 1:
        return 0
    
    if dp[n] != -1:
        return dp[n]
    
    min_steps = minStepsToConvergeToOne(n - 1, dp) + 1
    if n%3 == 0:
        min_steps = min(min_steps, minStepsToConvergeToOne(n//3, dp) + 1)
    if n%2 == 0:
        min_steps = min(min_steps, minStepsToConvergeToOne(n//2, dp) + 1)

    dp[n] = min_steps

    return min_steps

def minStepsToConvergeToOneNoRec(n):
    if n <= 1:
        return 0
    
    dp = [0]*(n + 1)
    dp[1] = 0

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + 1
        if i%3 == 0:
            dp[i] = min(dp[i], dp[i//3] + 1)
        if i%2 == 0:
            dp[i] = min(dp[i], dp[i//2] + 1)
    return dp[n]


n = 11
print(f"{n} Rec:", minStepsToConvergeToOne(n, [-1]*(n + 1)))
print(f"{n} NoRec:", minStepsToConvergeToOneNoRec(n))

n = 10
print(f"{n} Rec:", minStepsToConvergeToOne(n, [-1]*(n + 1)))
print(f"{n} NoRec:", minStepsToConvergeToOneNoRec(n))