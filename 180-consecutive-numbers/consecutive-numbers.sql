SELECT DISTINCT num AS ConsecutiveNums
FROM (
    SELECT num, 
           LEAD(num, 1) OVER (ORDER BY id) AS next_num, 
           LAG(num, 1) OVER (ORDER BY id) AS prev_num
    FROM Logs
) AS consecutive_logs
WHERE num = next_num AND num = prev_num;
