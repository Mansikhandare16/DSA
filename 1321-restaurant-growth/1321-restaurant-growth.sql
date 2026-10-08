# Write your MySQL query statement below
WITH daily AS(
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),
windowed AS (
    SELECT visited_on, SUM(amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount
    FROM daily
)
SELECT visited_on, amount, ROUND(amount/7,2) AS average_amount 
FROM windowed 
WHERE visited_on>=(
    SELECT DATE_ADD(MIN(visited_on),INTERVAL 6 DAY)
    FROM Customer
)
ORDER BY visited_on;