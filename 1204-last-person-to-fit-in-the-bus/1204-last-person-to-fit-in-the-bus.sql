# Write your MySQL query statement below
SELECT person_name
FROM (
    SELECT person_name,
    SUM(weight) OVER(ORDER BY turn) AS Total_weight #turn ke hisab se sum
    FROM Queue
)t
WHERE Total_weight<=1000 
ORDER BY Total_weight DESC #answer nikalega
LIMIT 1;