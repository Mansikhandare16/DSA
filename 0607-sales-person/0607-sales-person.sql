# Write your MySQL query statement below
SELECT s.name
FROM SalesPerson s
WHERE NOT EXISTS (
    SELECT 1
    FROM Orders o
    JOIN Company c
    ON o.com_id=c.com_id
    WHERE s.sales_id=o.sales_id AND c.name='RED'
);