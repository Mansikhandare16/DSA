# Write your MySQL query statement below
SELECT p.product_id, COALESCE(p2.new_price,10) AS price #har product ka price chahiye
FROM (SELECT DISTINCT product_id FROM Products) p #-all products taaki saare products aaye even if change date not 16
LEFT JOIN Products p2 #latest valid change
ON p2.product_id=p.product_id
AND p2.change_date=(
    SELECT MAX(p3.change_date)
    FROM Products p3
    WHERE p3.product_id=p.product_id
    AND p3.change_date<='2019-08-16'
);