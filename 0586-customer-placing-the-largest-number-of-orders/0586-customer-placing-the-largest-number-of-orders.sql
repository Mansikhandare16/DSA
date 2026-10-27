# Write your MySQL query statement below

#FOLLOW  UP VAALE MEIN WE CAN DO RANK()
WITH count_cust AS (
    SELECT customer_number, COUNT(order_number) AS order_count
    FROM Orders
    GROUP BY customer_number
),
ranked_number AS (
    SELECT customer_number,
        RANK() OVER(ORDER BY order_count DESC) AS rn
    FROM count_cust
)
SELECT customer_number
FROM ranked_number
WHERE rn=1;