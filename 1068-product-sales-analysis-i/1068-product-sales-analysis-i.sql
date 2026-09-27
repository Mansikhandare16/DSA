# Write your MySQL query statement below
SELECT p.product_name, s.year, s.price
FROM Sales s
LEFT JOIN Product p
ON p.product_id=s.product_id
WHERE s.sale_id IS NOT NULL;