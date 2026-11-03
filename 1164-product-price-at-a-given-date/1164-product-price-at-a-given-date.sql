# Write your MySQL query statement below
SELECT p.product_id, COALESCE(p2.new_price,10) AS price #inital product value is 10
FROM(SELECT DISTINCT product_id FROM Products)p #saare products include karega 
LEFT JOIN Products p2 #latest valid change ke liye
ON p.product_id=p2.product_id
AND p2.change_date=(
    SELECT MAX(p3.change_date) 
    FROM Products p3
    WHERE p2.product_id=p3.product_id AND p3.change_date<='2019-08-16'
);