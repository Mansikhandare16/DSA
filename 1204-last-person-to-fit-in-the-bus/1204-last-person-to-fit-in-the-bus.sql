# Write your MySQL query statement below
SELECT person_name
FROM (
    SELECT person_name, 
        SUM(weight) OVER (ORDER BY turn) AS total_weight #turn ke hisab se running sum calculate karega
    FROM Queue
) t
WHERE total_weight<=1000
ORDER BY total_weight DESC  #answer nikalega
LIMIT 1; 